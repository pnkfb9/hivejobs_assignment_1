#include <stdlib.h>
#include <math.h>

int calculate_mean_impedance(electrical_measurements_t *measurements,int used_elements){


  float impedance_sum = 0.0f;
  //have to add check_array_bounds to check if both arrays have same length
  for(index = 0; index < used_elements; index++)
  {
    impedance_sum += math.sqrt(math.pow(measurements->resistances->array[index],2)+math.pow(measurements->resistances->array[index]));
  }
  measurements->mean_impedance = impedance_sum/used_elements;

}

void sort_electrical_measurements(electrical_measurements_t *measurements);

float calculate_median_impedance(electrical_measurements_t *measurements);

int check_array_bounds(electrical_measurements_t *measurements);
