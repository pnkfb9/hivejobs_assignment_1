#ifndef MY_TYPES_H
#define MY_TYPES_H

#define SUCCESS 0
#define FAILURE 1

#define IT_LOC_OFFSET 0
#define US_LOC_OFFSET 3

typedef enum languages{
  lang_unknown = -1,
  lang_it,
  lang_us
}language_choice_t;

typedef enum date_formats{
  date_unknown = -1,
  date_it,
  date_us,
  date_as
}date_format_choice_t;

typedef struct date_t{

  char* day;
  char* month;
  char* year;

}date_t;

typedef struct dynamic_float_array_t{

  float *array;
  size_t size;
  size_t used;

}dynamic_float_array_t;

typedef struct electrical_measurements_t{

  date_t date;

  dynamic_float_array_t resistances;
  dynamic_float_array_t reactances;

  size_t num_measurements;

  float mean_impedance;
  float median_impedance;

}electrical_measurements_t;

typedef struct user_context_t{

  language_choice_t language;
  date_format_choice_t date_format;

  electrical_measurements_t daily_measurement;

}user_context_t;

#endif
