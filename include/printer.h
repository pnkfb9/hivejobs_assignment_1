#ifndef PRINTER_H
#define PRINTER_H

#define BUF_LEN 10

char* date_to_string(date_t *date, date_format_choice_t type);
int print_results(user_context_t* user_ctx);


#endif
