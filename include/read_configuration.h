#ifndef READ_CONFIGURATION_H
#define READ_CONFIGURATION_H

#define LOCALIZATION_IT "it"
#define LOCALIZATION_US "us"
#define LOCALIZATION_AS "as"

static const char* option_file = "config/options.conf";

user_context_t* initialize_user_context();

int read_configuration_file(user_context_t *user_context);

int get_localization_settings(char* line,size_t len,user_context_t* user_ctx,int setting);

#endif
