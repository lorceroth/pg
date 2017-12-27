#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "error.h"
#include "args.h"
#include "generator.h"
#include "string_t.h"

int main(int argc, char* argv[]) {
    int  arg_length = 6;
    bool arg_upper_case = false;
    bool arg_numbers = false;
    bool arg_symbols = false;

    for (int i = 0; i < argc; i++) {
        string_t current_arg = *(argv + i);

        if (is_argument(current_arg, "-l") == true || is_argument(current_arg, "--length") == true) {
            string_t arg_value = *(argv + (i + 1));

            if (value_exists(arg_value) == true) {
                arg_length = atoi(arg_value);
            } else {
                print_error("Argument length requires an integer value.");
                return EXIT_FAILURE;
            }
        }

        if (is_argument(current_arg, "-uc") == true || is_argument(current_arg, "--upper-case") == true) {
            arg_upper_case = true;
        }

        if (is_argument(current_arg, "-n") == true || is_argument(current_arg, "--numbers") == true) {
            arg_numbers = true;
        }

        if (is_argument(current_arg, "-s") == true || is_argument(current_arg, "--symbols") == true) {
            arg_symbols = true;
        }
    }

    // The actual result given to the user
    string_t result = generate_password(arg_length, arg_upper_case, arg_numbers, arg_symbols);
    printf(result);

    return EXIT_SUCCESS;
}