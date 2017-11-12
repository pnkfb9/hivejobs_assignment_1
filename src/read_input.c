#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <types.h>
#include <read_input.h>
#include <dynamic_float_array.h>

const char* input_file = "input/input.txt";

int read_input_file(user_context_t* user_ctx){

  if(user_ctx == NULL )
  {
    printf("[ERROR] - read_input_file: One or more input parameter not set.\n");
      return FAILURE;
  }
  FILE *fp;
  char* line;
  int is_first = 1;
  size_t length = 0;
  ssize_t read;
  electrical_measurements_t* user_meas = &(user_ctx->daily_measurement);
  fp = fopen(input_file, "r");

    if (fp == NULL)
    {
      printf("[ERROR] - read_input_file: Cannot open configuration file! Leaving...\n");
      return FAILURE;
    }

    while ((read = getline(&line, &length, fp)) != -1) {

        parse_line(line,user_meas,is_first);
        if(is_first)
          is_first = 0;
    }

    fclose(fp);
    if (line)
        free(line);

    return SUCCESS;

}

void parse_line(char* line, electrical_measurements_t* meas,int is_first){

  if(line == NULL || meas == NULL)
  {
    printf("[ERROR] - parse_line: One or more input parameter not set.\n");
      return;
  }
    const char separator[2] = " ";
    char *token;
    int result = SUCCESS;
    float r = 0.0;
    float x = 0.0;
    int position = POS_R;
   /* get the first token */
   token = strtok(line, separator);

   /* walk through other tokens */
   while( token != NULL  && position < POS_END) {

        if(position == POS_R)
          result |= is_float_valid(token,&r);
        if(position == POS_X)
          result |= is_float_valid(token,&x);
        if(position == POS_DATE && is_first){
          result |= parse_date_simple(token,&meas->date);
        }
      position++;
      token = strtok(NULL, separator);
   }

   if(result == SUCCESS)
   {
      insert_array_element(&meas->resistances,r);
      insert_array_element(&meas->reactances,x);
      meas->num_measurements++;
   }
   else
     printf("[WARNING] - parse_line: Skipping line, malformed string, check input file for errors.\n");

}

int is_float_valid(char* float_string,float* f){

  if(float_string == NULL || f == NULL)
  {
    printf("[ERROR] - is_float_valid: One or more input parameter not set.\n");
      return FAILURE;
  }

    char* end_ptr;
    *f = strtof(float_string, &end_ptr);
    if(*end_ptr !=0 )
    {
      *f = 0.0f;
      return FAILURE;
    }

    return SUCCESS;

}
int parse_date_simple(char* date_string, date_t *date){

  if(date_string == NULL || date == NULL)
  {
    printf("[ERROR] - parse_date_simple: One or more input parameter not set.\n");
      return FAILURE;
  }

  int result = SUCCESS;
  const char* regex = "%[^-]-%[^-]-%[^;]";

  if(sscanf(date_string, regex , date->day, date->month, date->year) != POS_END)
    result = FAILURE;

  return result;
}

int parse_date_multi(char* date_string, date_t *date, date_format_choice_t format){

  if(date_string == NULL || date == NULL)
  {
      printf("[ERROR] - parse_date_multi: One or more input parameter not set.\n");
      return FAILURE;
  }

  int result = SUCCESS;
  const char* regex_it_us = "%[^-]-%[^-]-%[^;]";
  const char* regex_as ="%s";
  switch (format) {
    case date_it:
      if(sscanf(date_string, regex_it_us , date->day, date->month, date->year) != POS_END)
        result = FAILURE;
    break;
    case date_us:
      if(sscanf(date_string,  regex_it_us , date->month, date->day, date->year) != POS_END)
        result = FAILURE;
    break;
    case date_as:     //have to modify
      if(sscanf(date_string, regex_as, date->year, date->month, date->day) == EOF)
        result = FAILURE;
    break;

    case date_unknown:
      result = FAILURE;
    break;
  }

  return result;

}
