#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "error.h"
#include "args.h"
#include "generator.h"
#include "string_t.h"

#define NAME "PG"
#ifndef VERSION
    #define VERSION "0.0"
#endif

#define ARG_LENGTH_DFL 6
#define ARG_UPPER_CASE_DFL false
#define ARG_NUMBERS_DFL false
#define ARG_SYMBOLS_DFL false

int main(int argc, char* argv[]) {
    int  arg_length = ARG_LENGTH_DFL;
    bool arg_upper_case = ARG_UPPER_CASE_DFL;
    bool arg_numbers = ARG_NUMBERS_DFL;
    bool arg_symbols = ARG_SYMBOLS_DFL;

    for (int i = 0; i < argc; i++) {
        string_t current_arg = *(argv + i);

        if (is_argument(current_arg, "-l", "--length") == true) {
            string_t arg_value = *(argv + (i + 1));

            if (value_exists(arg_value) == true) {
                arg_length = atoi(arg_value);
            } else {
                print_error("Argument length requires an integer value.");
                return EXIT_FAILURE;
            }
        }

        if (is_argument(current_arg, "-uc", "--uppercase") == true) {
            arg_upper_case = true;
        }

        if (is_argument(current_arg, "-n", "--numbers") == true) {
            arg_numbers = true;
        }

        if (is_argument(current_arg, "-s", "--symbols") == true) {
            arg_symbols = true;
        }
    }

    string_t result = generate_password(arg_length, arg_upper_case, arg_numbers, arg_symbols);
    printf(result);

    return EXIT_SUCCESS;
}