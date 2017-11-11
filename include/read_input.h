#ifndef READ_INPUT_H
#define READ_INPUT_H

static const char* input_file = "input/input.txt";

int read_input_file(user_context_t* user_ctx);

int parse_line(char* line,dynamic_float_array_t *res,dynamic_float_array_t *reac);

#endif
