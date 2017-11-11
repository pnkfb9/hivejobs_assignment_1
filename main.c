#include <stdio.h>
#include <stdlib.h>

#include <types.h>
#include <dynamic_float_array.h>
#include <impedance_calculator.h>
#include <read_configuration.h>
#include <read_input.h>

int main(void){

user_context_t* user_context = initialize_user_context();

read_configuration_file(user_context);

read_input_file(user_context);
 /*dynamic_float_array_t res,reac;

 initialize_array(&res,3);
 initialize_array(&reac,3);
 insert_array_element(&res,5.94f);
 insert_array_element(&res,6.01f);
 insert_array_element(&res,4.43f);
 insert_array_element(&res,4.99f);
 //insert_array_element(&res,1.2f);
 //insert_array_element(&res,12.2f);

   insert_array_element(&reac,2.76f);
   insert_array_element(&reac,3.00f);
   insert_array_element(&reac,2.11f);
   insert_array_element(&reac,2.07f);
    //insert_array_element(&reac,1.4f);
     //insert_array_element(&reac,0.2f);

 electrical_measurements_t measurement;
measurement.date =(char*)malloc(sizeof(char)*11);

 measurement.date = "12-12-2012";
 measurement.resistances = res;
 measurement.reactances = reac;
 measurement.num_measurements = (size_t)6;
 measurement.mean_impedance = 0.0f;
 measurement.median_impedance = 0.0f;

 calculate_mean_impedance(&measurement);
 calculate_median_impedance(&measurement);

 printf("calculate_mean_impedance = %.3f\n", measurement.mean_impedance);
 printf("calculate_median_impedance = %.3f\n", measurement.median_impedance);*/
 return 0;

}
