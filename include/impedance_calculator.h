#ifndef IMPEDANCE_CALCULATOR_H
#define IMPEDANCE_CALCULATOR_H

#include <types.h>

int calculate_mean_impedance(electrical_measurements_t *measurements);

int qsort_asc_comparator(const void* a, const void* b);

void sort_electrical_measurements(float* to_sort_array,size_t size);

int calculate_median_impedance(electrical_measurements_t *measurements);


#endif
