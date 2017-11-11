#include <stdlib.h>
#include <math.h>
#include <types.h>

int calculate_mean_impedance(electrical_measurements_t *measurements){

  size_t used_elements = measurements->num_measurements;
  float impedance_sum = 0.0f;
  //have to add check_array_bounds to check if both arrays have same length
  for(int index = 0; index < used_elements; index++)
  {
    impedance_sum += sqrt(pow(measurements->resistances.array[index],2)+pow(measurements->reactances.array[index],2));
  }
  measurements->mean_impedance = impedance_sum/(int)used_elements;

}

int qsort_asc_comparator(const void* a, const void* b){

  float fa = *(const float*) a;
float fb = *(const float*) b;
return (fa > fb) - (fa < fb);
}


float* sort_electrical_measurements(float *to_sort_array,size_t size)
{

  qsort(to_sort_array,size,sizeof(float),qsort_asc_comparator);

  return to_sort_array;
}


float calculate_median_impedance(electrical_measurements_t *measurements){

  float computed_median = 0.0f;
  size_t used_elements = measurements->reactances.used;
  float* sorted_array;
  float* non_sorted_array = (float*)malloc(sizeof(float)*used_elements);

  for(int index = 0; index < used_elements; index++)
  {
    non_sorted_array[index]= (float)sqrt(pow(measurements->resistances.array[index],2)+pow(measurements->reactances.array[index],2));
  }

  sorted_array = sort_electrical_measurements(non_sorted_array,used_elements);

  if(used_elements % 2 == 0)  //if are even numbers, then the median is computed as (a[n/2]+a[n/2+1]) / 2
  {
    measurements->median_impedance = (sorted_array[(used_elements/2)-1] + sorted_array[used_elements/2])/2;
  }
  else  //else, give the value in the middle of the array
  {
    measurements->median_impedance = sorted_array[used_elements/2];
  }
}

int check_array_bounds(electrical_measurements_t *measurements);
