#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "string.h"
#include "headers/stringutils.h"
#include "ctype.h"

//char **split(char *string, const char *separator, int *count) {
//    // Count the number of substrings
//    *count = 0;
//    char *token = strtok(string, separator);
//    while (token != NULL) {
//        (*count)++;
//        token = strtok(NULL, separator);
//    }
//
//    // Allocate memory for array of pointers
//    char **result = (char **)malloc((*count) * sizeof(char *));
//    if (result == NULL) {
//        fprintf(stderr, "Memory allocation failed\n");
//        exit(1);
//    }
//
//    // Split the string and store substrings in the array
//    int index = 0;
//    token = strtok(string, separator);
//    while (token != NULL) {
//        result[index] = strdup(token);
//        if (result[index] == NULL) {
//            fprintf(stderr, "Memory allocation failed\n");
//            exit(1);
//        }
//        token = strtok(NULL, separator);
//        index++;
//    }
//
//    return result;
//}

char **split(char *string, const char *seperators, int *count) {
    int len = strlen(string);
    *count = 0;
    int i = 0;
    while (i < len) {
        // Step though seperator
        while (i < len) {
            if (strchr(seperators, string[i]) == NULL)
                break;
            i++;
        }
        // Step through substring
        int old_i = i;
        while (i < len) {
            if (strchr(seperators, string[i]) != NULL)
                break;
            i++;
        }
        // only increment count if substing was actually present (i > old_i)
        // e.g. end of string where it would not incremement
        if (i > old_i) {
            *count = *count + 1;
        }
    }
    // Allocate space for the char array
    char **strings = malloc(sizeof(char *) * *count);
    i = 0;
    char buffer[16384];
    int string_index = 0;
    while (i < len) {
        // Step though seperator
        while (i < len) {
            if (strchr(seperators, string[i]) == NULL)
                break;
            i++;
        }
        // Step through substring and store it this time
        int j = 0;
        while (i < len) {
            if (strchr(seperators, string[i]) != NULL)
                break;
            buffer[j] = string[i];
            i++;
            j++;
        }
        buffer[j] = '\0';
        if (j > 0) {
            // dynamically allocate memory
            int to_allocate = sizeof(char) * (strlen(buffer) + 1);
            strings[string_index] = malloc(to_allocate);
            strcpy(strings[string_index], buffer);
            string_index++;
        }
    }
    return strings;
}


void toLower(char* p) {
    for ( ; *p; ++p) *p = tolower(*p);
}
void toUpper(char* p) {
    for ( ; *p; ++p) *p = toupper(*p);
}

unsigned int hashString(void *key) {
    unsigned char *str = (unsigned char *)key;
    unsigned int hash = 5381;
    int c;

    while ((c = *str++) != '\0') {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash;
}

int compareString(void *a, void *b) {
    return strcmp((char *)a, (char *)b);
}

char *trimString(char *str) {
    if (str == NULL) {
        return NULL;
    }

    // Find the start of the trimmed string
    char *start = str;
    while (isspace(*start)) {
        start++;
    }

    // Find the end of the trimmed string
    char *end = str + strlen(str) - 1;
    while (end > start && isspace(*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *(end + 1) = '\0';

    // Return the trimmed string
    return start;
}

