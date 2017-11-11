#ifndef MY_TYPES_H
#define MY_TYPES_H

typedef struct dynamic_float_array_t{

  float *array;
  size_t size;
  int used;

}dynamic_float_array_t;

typedef struct electrical_measurements_t{

  char* date;
  dynamic_float_array_t resistances;
  dynamic_float_array_t reactances;
  float mean_impedance;
  float median_impedance;

}electrical_measurements_t;

#endif
