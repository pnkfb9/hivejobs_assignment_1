#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <types.h>
#include <printer.h>

const char* descriptions[] = { "Impedenza calcolata nel giorno ", "Media = ", "\nMediana = ","Computed impedance for the day ", "Mean = ", "\nMedian = "  };
const char* date_string_format[] = {" (DD-MM-YYYY):\n"," (MM-DD-YYYY):\n"," (YYYYMMDD):\n"};

char* date_to_string(date_t *date, date_format_choice_t type){

  char* output = "";
  size_t len_output;
  size_t actual_len;

  switch(type)
  {
    case date_it:
      len_output = strlen(date->day)+1;

      output =(char*)malloc(sizeof(char) * len_output);
      strcpy(output,date->day);

      actual_len = len_output + 2;
      output =(char*)realloc(output,actual_len);

      strcat(output,"-");

      actual_len = strlen(output) + strlen(date->month)+1;
      output =(char*)realloc(output,actual_len);

      strcat(output,date->month);

      actual_len = strlen(output) + 2;

      strcat(output,"-");
      actual_len = strlen(output) + strlen(date->year)+1;
      output =(char*)realloc(output,actual_len);

      strcat(output,date->year);

    break;

    case date_us:

      len_output = strlen(date->month)+1;

      output =(char*)malloc(sizeof(char) * len_output);
      strcpy(output,date->month);

      actual_len = len_output + 2;
      output =(char*)realloc(output,actual_len);

      strcat(output,"-");

      actual_len = strlen(output) + strlen(date->day)+1;
      output =(char*)realloc(output,actual_len);

      strcat(output,date->day);

      actual_len = strlen(output) + 2;

      strcat(output,"-");
      actual_len = strlen(output) + strlen(date->year)+1;
      output =(char*)realloc(output,actual_len);

    strcat(output,date->year);
    break;

    case date_as:

      len_output = strlen(date->year)+1;
      output =(char*)malloc(sizeof(char) * len_output);
      strcpy(output,date->year);

      actual_len = len_output + strlen(date->month) + 1;
      output =(char*)realloc(output,actual_len);
      strcat(output,date->month);

      actual_len = strlen(output) + strlen(date->day)+1;
      output =(char*)realloc(output,actual_len);
      strcat(output,date->day);

    break;

    case date_unknown:
      output = NULL;
    break;
  }
  return output;
}

int print_results(user_context_t* user_ctx)
{
  if(user_ctx == NULL)
  {
    printf("[ERROR] - print_results: Input parameter not set.\n");
    return FAILURE;
  }

  int result = SUCCESS;
  char* output = "\0";

  char* date_string;

  char* mean=(char*)malloc(sizeof(char)*BUF_LEN);
  char* median=(char*)malloc(sizeof(char)*BUF_LEN);

  size_t output_len;
  size_t actual_len;

  date_format_choice_t format = user_ctx->date_format;
  language_choice_t lang = user_ctx->language;
  sprintf(mean,"%.3f",user_ctx->daily_measurement.mean_impedance);
  sprintf(median,"%.3f",user_ctx->daily_measurement.median_impedance);
  date_string = date_to_string(&user_ctx->daily_measurement.date,format);

  switch(lang)
  {
    case lang_it:
      output_len = strlen(descriptions[IT_LOC_OFFSET])+1;
      output = (char*)malloc(sizeof(char)*output_len );
      strcpy(output,descriptions[IT_LOC_OFFSET]);
      actual_len = strlen(output) + strlen(date_string)+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,date_string);
      actual_len = strlen(output) + strlen(date_string_format[format])+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,date_string_format[format]);
      actual_len = strlen(output) + strlen(descriptions[IT_LOC_OFFSET+1])+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,descriptions[IT_LOC_OFFSET+1]);

      actual_len =strlen(output) + strlen(mean)+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,mean);
      actual_len = strlen(output) + strlen(descriptions[IT_LOC_OFFSET+2])+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,descriptions[IT_LOC_OFFSET+2]);
      actual_len = strlen(output) + strlen(median)+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,median);

    break;

    case lang_us:

      output_len = strlen(descriptions[US_LOC_OFFSET])+1;
      output = (char*)malloc(sizeof(char)*output_len );
      strcpy(output,descriptions[US_LOC_OFFSET]);
      actual_len = strlen(output) + strlen(date_string)+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,date_string);
      actual_len = strlen(output) + strlen(date_string_format[format])+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,date_string_format[format]);
      actual_len = strlen(output) + strlen(descriptions[US_LOC_OFFSET+1])+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,descriptions[US_LOC_OFFSET+1]);

      actual_len = strlen(output) + strlen(mean)+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,mean);
      actual_len = strlen(output) + strlen(descriptions[US_LOC_OFFSET+2])+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,descriptions[US_LOC_OFFSET+2]);
      actual_len = strlen(output) + strlen(median)+1;
      output = (char*)realloc(output,actual_len);
      strcat(output,median);

    break;

    case lang_unknown:
      result = FAILURE;
  }

  printf("%s\n",output);
  return result;
}
