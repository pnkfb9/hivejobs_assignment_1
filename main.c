#include <stdio.h>
#include <stdlib.h>

#include <types.h>
#include <dynamic_float_array.h>
#include <impedance_calculator.h>
#include <read_configuration.h>
#include <read_input.h>
#include <printer.h>

int main(void){

  int return_value = SUCCESS;

  user_context_t* user_context = initialize_user_context();

  return_value = read_configuration_file(user_context);
  if(return_value != SUCCESS)
  {
    return FAILURE;
  }
  
  read_input_file(user_context);

  calculate_mean_impedance(&user_context->daily_measurement);

  calculate_median_impedance(&user_context->daily_measurement);

  print_results(user_context);

 return SUCCESS;

}
