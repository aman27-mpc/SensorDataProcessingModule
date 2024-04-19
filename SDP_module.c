/*
SDP_module.c
Author: Aman Dubey
*/
#include <SDP_module.h> //Header file with macros and function declaration



// Function to scale the angle value to 0.001 degree per increment
int16_t scaleAngle(int32_t angleValue) {
    /* Scaling factor for angle (0.001 degree per increment) and multiply it by the inverse of scaling value present in requirement 3.*/ 
     
    int16_t scaledAngle = angleValue * scalingFactor_specification * scalingFactor_requirement;
    return scaledAngle;
}


void SDP(RawSensorDataStruct * RawSensorData, uint16_t * Angle_Value, bool * Angle_Valid, uint8_t *Error)
{
    /*First Read the data from the memory Register address  */
    volatile uint64_t *address = (volatile uint64_t *)REGISTER_STR_ADDR; // address pointing to register 

    uint64_t reg_value = *address; // put the address in reg_value

    memcpy(RawSensorData, &reg_value,sizeof(RawSensorDataStruct));  // Put the data inside the struct
    uint8_t count;
    /*Store the data seperately in each byte*/
    uint8_t byte0 = (RawSensorData->ISB_MessagePart1 >> 24) & 0xFF; //Check the sensor initilization using byte0
    uint8_t byte1 = (RawSensorData->ISB_MessagePart1 >> 16) & 0xFF; //Store the data individually in each byte
    uint8_t byte2 = (RawSensorData->ISB_MessagePart1 >> 8) & 0xFF;
    uint8_t byte3 = (RawSensorData->ISB_MessagePart1 ) & 0xFF;

    int32_t angle = (int32_t)(RawSensorData->ISB_MessagePart2); 

    if(byte0 == sensor_init_start)   /*Intialization state*/
    {
       *Angle_Valid= false;
       /*Wait for initialization to finish*/
       count = 0;
       return 0;
    }
    if(byte0 == sensor_init_finish) /*Initialization Finished*/
    {
        /*Sensor is running, initialization finished*/
        switch (byte1) /*Check byte 1 first*/
        {
        case 0xFF:  /*Each error is starting with 0XFF*/
            switch (byte2) /*Check byte 2*/
            {
            /*Cases are assigned according to priority order*/    
            case bus_communication_failure_spec:     //  Bus Communication failure 
                *Error = sensor_communication_error;  // Set Bus communication error
                *Angle_Valid = false; /*Signal with error can not be trusted*/
                /* code */
                break;
            case bus_time_out_spec:
                /*Implement a counter to check for at least 2 cycles the bus timeout error is popped up*/
                count++; // Increment the counter 
                if(count> update_count ){   // check for the count to be greater that 2 which implies 
                    *Error = sensor_update_error;   //Set Sensor Update Error
                    count  = 0;
                }
                *Angle_Valid = false; /*Signal with error can not be trusted*/
                break;
            case over_voltage_spec: /*Check for overvoltage*/
                *Error = sensor_electrical_error;  //Set Sensor electrical error
                *Angle_Valid = false;  /*Signal with error can not be trusted*/
                break;
            case under_voltage_spec:  /*Check for undervoltage*/
                *Error = sensor_electrical_error;  //Set Sensor electrical error 
                *Angle_Valid = false; /*Signal with error can not be trusted*/
                break;
            case mechanical_failure_spec:    //New specification for mechanical error considering it to be independent of another error
                
                *Error = senor_mechanical_error;  //Set Sensor mechanical error 
                *Angle_Valid = false; /*Signal with error can not be trusted*/
                break;
            case no_error_spec:  // check for 0x00 
                  
                *Error = no_error;  // set error to be 0x00 i.e. no error 
                *Angle_Valid = true; //Data can be trusted so Angle valid set to true
                break;
            default:
                
                *Error= no_error; // No other error state can be determined
                *Angle_Valid = true;  //Data can be trusted so Angle valid set to true
                break;
            }
        
        default:
            *Error = no_error; // No other error state can be determined
            *Angle_Valid = true; //Data can be trusted so Angle valid set to true
            break;
        }
    
    *Angle_Value = scaleAngle(angle); /*Calculate the angle value using function scaleangle*/

    } 

}