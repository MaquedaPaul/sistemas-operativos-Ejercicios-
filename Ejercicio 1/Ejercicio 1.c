#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *string_concat(const char *, const char *);
void string_concat_result(const char *first, const char *second, char **result);

int main()
{
    // printf("Enter two strings: ");
    char *strvar1 = "abc";
    char *strvar2 = "defg";

    char *strvar3 = string_concat(strvar1, strvar2);
    printf("\n%s", strvar3);
    char *nombre = "Ritchie";
    char *strvar4 = string_concat("Hola ", nombre);
    printf("\n%s", strvar4);
    free(strvar3);
    free(strvar4);

    char *strvar5;

    string_concat_result(strvar1, strvar2, &strvar5);
    printf("\n%s", strvar5);

    char *strvar6;

    string_concat_result("Hola ", nombre, &strvar6);
    printf("\n%s", strvar6);

    return 0;
}

char *string_concat(const char *first, const char *second)
{
    int firstMax = strlen(first);
    int max = firstMax + strlen(second);

    char *result = malloc(sizeof(char) * max);

    for (int i = 0; i < max; i++)
    {
        if (i < firstMax)
        {
            result[i] = first[i];
        }
        else
        {
            result[i] = second[i - firstMax];
        }
    }
    return result;
}

void string_concat_result(const char *first, const char *second, char **result)
{
    int firstMax = strlen(first);
    int max = firstMax + strlen(second);
    for (int i = 0; i < max; i++)
    {
        if (i < firstMax)
        {
            result[i] = first[i];
        }
        else
        {
            result[i] = second[i - firstMax];
        }
    }
}
