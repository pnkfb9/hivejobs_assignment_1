#ifndef DYNAMIC_FLOAT_ARRAY_H
#define DYNAMIC_FLOAT_ARRAY_H

#include <types.h>

#define true 1
#define false 0

void initialize_array(dynamic_float_array_t *ar,size_t size);

void insert_array_element(dynamic_float_array_t *ar, float element);

float get_array_element_at(dynamic_float_array_t *ar, int index);

int is_valid_array_index(dynamic_float_array_t *ar, int index);

void free_array(dynamic_float_array_t *ar);

#endif
