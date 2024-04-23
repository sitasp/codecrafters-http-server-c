
#ifndef CODECRAFTERS_HTTP_SERVER_C_STRINGUTILS_H
#define CODECRAFTERS_HTTP_SERVER_C_STRINGUTILS_H

#include "stdio.h"
#include "stdlib.h"
#include "strings.h"
#include "string.h"
#include "ctype.h"

char **split(char *string, const char *separator, int *count);
void toLower(char* s);
void toUpper(char* s);
unsigned int hashString(void *key);
int compareString(void *a, void *b);
char *trimString(char *str);



#endif //CODECRAFTERS_HTTP_SERVER_C_STRINGUTILS_H
