
#define WINDOW_INTERVAL  100 // we will average the output in this window 
#define EXP 0.8// it is smoothing factor for exponential smoothing 

float signal_buffer[WINDOW_INTERVAL]; /*Buffer to store recent signal samples*/ 
int i = 0; // Index to keep track of the current position in the buffer
float average_sum = 0.0; // Running sum of the signal samples
float last_filtered_value= 0.0; // Last filtered measurement

#define THRESHOLD 1000 // It is the value above which the signal is not considered valid
#define NEW_EXP  0.01  /* New factor will make sure that the filtering considers the previous value 
instead of current as it is erroneous*/

float ac_couple_filter(float new_measurement) {
    
    /*Remove the old value and add the new value to the running sum 
    in order to move the averaging */
    if(new_measurement>THRESHOLD || new_measurement < (-THRESHOLD) ){
        EXP = 0
    }
    average_sum = average_sum - signal_buffer[i];
    signal_buffer[i] = new_measurement;
    average_sum = average_sum + new_measurement;


    /* Increment the buffer value and keep it within window size*/
    i = (i + 1) % WINDOW_INTERVAL;

     /*Calculate the average value*/
    float average = average_sum / WINDOW_INTERVAL;

    /*Subtract the average value from the new measurement to remove DC component*/
    float ac_coupled = new_measurement - average;

    float filtered_value;

    if(new_measurement>THRESHOLD || new_measurement < (-THRESHOLD) ){
        filtered_value =   NEW_EXP * ac_coupled + (1 - NEW_EXP) * last_filtered_value;
    }else
    {
        filtered_value = EXP * ac_coupled + (1 - EXP) * last_filtered_value;
    }


    /* Update */
    last_filtered_value = filtered_value;

    return filtered_value;  // return 
}


float calculate_rms(float *voltage_array) {
    float square_value = 0.0;
    int j = 0;

    // Calculate the sum of squares of the voltages in the array
    while (voltage_array[j] != -1) {
        square_value += voltage_array[array_length] * voltage_array[array_length];
        array_length++;
    }

    // Calculate the average of the squares
    float average_value_rms = square_value / j;
    
    // Return the square root of the average of the squares
    return sqrt(average_value_rms);
}




