#include <stdlib.h>
#include <math.h>
#include <types.h>

#define COMPARE(a, b) (((a) > (b)) - ((a) < (b)))

int calculate_mean_impedance(electrical_measurements_t *measurements,int used_elements){

  float impedance_sum = 0.0f;
  //have to add check_array_bounds to check if both arrays have same length
  for(int index = 0; index < used_elements; index++)
  {
    impedance_sum += sqrt(pow(measurements->resistances.array[index],2)+pow(measurements->resistances.array[index],2));
  }
  measurements->mean_impedance = impedance_sum/used_elements;

}

int qsort_asc_comparator(const void* a, const void* b){

  float fa = *(const float*) a;
float fb = *(const float*) b;
return (fa > fb) - (fa < fb);
}


float* sort_electrical_measurements(electrical_measurements_t *measurements)
{
  int actual_size = measurements->reactances.used;
  float* reactances_array = (float*)malloc(sizeof(float)*actual_size);
  for (int index = 0;index < actual_size; index++)
  {
    reactances_array[index] = measurements->reactances.array[index];
  }

  qsort(reactances_array,actual_size,sizeof(float),qsort_asc_comparator);

  return reactances_array;
}


float calculate_median_impedance(electrical_measurements_t *measurements){

   float* sorted_array = sort_electrical_measurements(measurements);

}

int check_array_bounds(electrical_measurements_t *measurements);
