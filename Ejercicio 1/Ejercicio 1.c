#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>

char *string_concat(const char *, const char *);
void string_concat_dynamic(const char *first, const char *second, char **result);
void mail_split(const char *mail, char **user, char **dominio);

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

    string_concat_dynamic(strvar1, strvar2, &strvar5);
    printf("\n%s", strvar5);

    char *strvar6;

    string_concat_dynamic("Hola ", nombre, &strvar6);
    printf("\n%s", strvar6);
    printf("\n");
    char *mail = "ritchie@ansic.com.ar";
    char *user;
    char *domain;

    mail_split(mail, &user, &domain);
    printf("\n%s", user);
    printf("\n%s", domain);

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

void string_concat_dynamic(const char *first, const char *second, char **result)
{
    int firstMax = strlen(first);
    int max = firstMax + strlen(second);
    (*result) = malloc(sizeof(char) * max);
    for (int i = 0; i < max; i++)
    {
        if (i < firstMax)
        {
            *((*result) + i) = first[i];
        }
        else
        {
            *((*result) + i) = second[i - firstMax];
        }
    }
}

void mail_split(const char *mail, char **user, char **dominio)
{

    int max = strlen(mail);
    int flag = 0;
    int arroba = 0;
    printf("Allocating memory: \n");
    for (int i = 0; i < max; i++)
    {
        if (mail[i] == '@')
        {
            (*user) = malloc(sizeof(char) * (i - 1));
            (*dominio) = malloc(sizeof(char) * (max - i));
            break;
        }
    }
    printf("Memory allocated successfully \n");
    for (int i = 0; i < max; i++)
    {
        if (mail[i] == '@')
        {
            flag = 1;
            arroba = i;
            continue;
        }
        if (flag != 1)
        {
            *((*user) + i) = mail[i];
        }
        else
        {
            *((*dominio) + i - arroba - 1) = mail[i];
        }
    }
}
