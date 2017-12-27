#include <stdbool.h>
#include <string.h>
#include "args.h"

bool is_argument(char* argv, char* expect) {
    if (strcmp(argv, expect) == 0) {
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