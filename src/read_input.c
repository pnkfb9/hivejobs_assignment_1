#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <types.h>
#include <read_input.h>

int read_input_file(user_context_t* user_ctx){

  FILE *fp;
  char* line;
  int error = 0;
  size_t length = 0;
  ssize_t read;
  electrical_measurements_t* user_meas = &(user_ctx->daily_measurement);
  fp = fopen(input_file, "r");

    if (fp == NULL)
    {
      printf("Cannot open configuration file! Leaving...\n");
      return -1;
    }

    while (!error && ((read = getline(&line, &length, fp)) != -1)) {

        error = parse_line();
    }
    if (error)
    {
      printf("Error in reading input file. Leaving...\n");
      return -1;
    }
    fclose(fp);
    if (line)
        free(line);

    return 0;

}

int parse_line(char* line,dynamic_float_array_t *res,dynamic_float_array_t *reac);
