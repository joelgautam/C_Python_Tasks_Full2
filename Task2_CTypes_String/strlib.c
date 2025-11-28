#include <string.h>
#include <stdlib.h>

char* reverse_string(const char* input) {
    int len = strlen(input);
    char* out = (char*)malloc(len + 1);
    for (int i = 0; i < len; i++)
        out[i] = input[len - i - 1];
    out[len] = '\0';
    return out;
}
