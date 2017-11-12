#ifndef READ_INPUT_H
#define READ_INPUT_H

#define POS_R 0     //position of resistance value in line
#define POS_X 1     //position of reactance value in line
#define POS_DATE 2  //position of date string in line
#define POS_END 3   //position of end of line

extern const char* input_file;

/*
* Function read_input_file
* ------------------------
*/
int read_input_file(user_context_t* user_ctx);

void parse_line(char* line,electrical_measurements_t* meas,int is_first);

int parse_date_simple(char* date_string, date_t *date);

int parse_date_multi(char* date_string, date_t *date, date_format_choice_t format);

int is_float_valid(char* float_string,float* f);

#endif
