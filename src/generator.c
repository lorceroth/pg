#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "string_t.h"
#include "generator.h"

string_t generate_password(int arg_length, bool arg_upper_case, bool arg_numbers, bool arg_symbols) {
    string_t result;
    string_t charlist;

    char chl_upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char chl_lower[] = "abcdefghijklmnopqrstuvwxyz";
    char chl_numbers[] = "0123456789";
    char chl_symbols[] = "$#@&-_*";

    result = malloc((sizeof(char) * arg_length) + 1);
    charlist = malloc(sizeof(char) * (
        strlen(chl_lower)
        + strlen(chl_upper)
        + strlen(chl_numbers)
        + strlen(chl_symbols)
        + 1
    ));

    strcpy(result, "");
    strcpy(charlist, "");

    strcat(charlist, chl_lower);

    if (arg_upper_case == true) {
        strcat(charlist, chl_upper);
    }

    if (arg_numbers == true) {
        strcat(charlist, chl_numbers);
    }

    if (arg_symbols == true) {
        strcat(charlist, chl_symbols);
    }

    srand(time(NULL));

    for (int i = 0; i < arg_length; i++) {
        char c[2] = { charlist[rand() % (strlen(charlist) - 1)], '\0' };
        strcat(result, c);
    }

    free(charlist);

    return result;
}