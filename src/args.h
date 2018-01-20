#include <stdbool.h>
#include "string_t.h"

#define SHORT_NAME_LMT 4
#define LONG_NAME_LMT 16

typedef struct {
    char short_name[SHORT_NAME_LMT];
    char long_name[LONG_NAME_LMT];
    string_t description;
} command_t;

command_t* create_command(char short_name[SHORT_NAME_LMT], char long_name[LONG_NAME_LMT], char* description);

bool is_argument(char* argv, char* short_name, char* long_name);

bool value_exists(char* argv);