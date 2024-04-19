/*
SDP_module.h
Author: Aman Dubey
*/
/*Prevent Multiple Inclusion*/
#ifndef SDPMODULE_H 
#define SDPMODULE_H

/*C standard libraries*/
#include <stdint.h>  
#include <stdbool.h>

/*Register where the data comes through serial port of SDP*/
#define REGISTER_STR_ADDR 0X20000000 

/* As per increment 0.001 degree change happens*/
#define scalingFactor_specification 0.001 

/*As the output needs to be scaled to 0.1*/
#define scalingFactor_requirement 10 

/*Macro for error state 0x03, Needs to be updated correctly for at least 2 cycles*/
#define update_count 2 

/*Intializing Sensor check*/
#define sensor_init_start 0x01
#define sensor_init_finish 0x02

// Define the struct representing the raw sensor data
typedef struct {
    uint32_t ISB_MessagePart1; // Represents Bytes 0-3 of the ISB message
    uint32_t ISB_MessagePart2; // Represents Bytes 4-7 of the ISB message
} RawSensorDataStruct;

/* Define the Error Requirements as macros*/

#define no_error 0x00
#define senor_mechanical_error 0x01
#define sensor_electrical_error 0x02
#define sensor_update_error 0x03
#define sensor_communication_error 0x04

/*Define the Error specification as macros*/

#define no_error_spec 0x00
#define over_voltage_spec 0x01
#define under_voltage_spec 0x02
#define bus_communication_failure_spec 0x03
#define bus_time_out_spec 0x04
#define mechanical_failure_spec 0x05  // New specification introduced for mechanical error 

/*Function for Scaling the obtained data according to specification and requirements*/
int16_t scaleAngle(int32_t angleValue); 

#endif

