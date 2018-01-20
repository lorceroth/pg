#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "args.h"

command_t* create_command(char short_name[SHORT_NAME_LMT], char long_name[LONG_NAME_LMT], char* description) {
    command_t* c = malloc(sizeof(command_t));
    strcpy(c->short_name, short_name);
    strcpy(c->long_name, long_name);
    strcpy(c->description, description);
    return c;
}

bool is_argument(char* argv, char* short_name, char* long_name) {
    if (strcmp(argv, short_name) == 0 || (NULL != long_name && strcmp(argv, long_name) == 0)) {
        return true;
    }

    return false;
}

bool value_exists(char* argv) {
    if (argv != NULL) {
        return true;
    }

    return false;
}