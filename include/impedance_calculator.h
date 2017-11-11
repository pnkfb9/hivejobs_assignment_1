#ifndef IMPEDANCE_CALCULATOR_H
#define IMPEDANCE_CALCULATOR_H

#include <types.h>

int check_array_bounds(electrical_measurements_t *measurements);

int calculate_mean_impedance(electrical_measurements_t *measurements);

void sort_electrical_measurements(electrical_measurements_t *measurements);

float calculate_median_impedance(electrical_measurements_t *measurements);


#endif
