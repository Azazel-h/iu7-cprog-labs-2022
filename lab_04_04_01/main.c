#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define OK 0
#define MAX_STR_LEN 257
#define OVERFLOW_ERROR -1
#define READ_ERROR -2
#define INPUT_STRING_ERROR -4
#define EMPTY_STRING_ERROR -5


void get_errors(int rc);
void skip_spaces(char *str, size_t *i);
int validate_string(char *str, size_t *string_len);
bool check_if_only_spaces(char *str, size_t start);
bool e_check(char *str, size_t *i);
bool validate_number(char *str);

int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];
    size_t string_len = 0;

    if (fgets(raw_string, sizeof(raw_string), stdin) == NULL)
        rc = READ_ERROR;
    else if (validate_string(raw_string, &string_len))
        rc = INPUT_STRING_ERROR;
    else
    {

        if (validate_number(raw_string))
            printf("YES");
        else
            printf("NO");
    }

    if (rc)
        get_errors(rc);
    return rc;
}


int validate_string(char *str, size_t *string_len)
{
    *string_len = strlen(str);
    if ((*string_len) >= MAX_STR_LEN - 1)
        return OVERFLOW_ERROR;
    if (!(*string_len) || str[0] == '\n')
        return EMPTY_STRING_ERROR;

    if (str[*string_len - 1] == '\n')
        str[--(*string_len)] = '\0';
    return OK;
}


bool check_if_only_spaces(char *str, size_t start)
{
    size_t i = start;
    while (isspace(str[i]) && str[i] != '\0')
        i++;
    if (str[i] == '\0')
        return true;

    return false;
}


void skip_spaces(char *str, size_t *i)
{
    do
        (*i)++;
    while(isspace(str[*i]));
}


bool e_check(char *str, size_t *i)
{
    if ((str[*i] == 'e') || (str[*i] == 'E'))
    {
        (*i)++;
        if (str[*i] == '+' || str[*i] == '-')
            (*i)++;

        if (!(isdigit(str[*i])))
            return false;
        else
            while (isdigit(str[*i]))
                (*i)++;
    }
    return true;
}


bool validate_number(char *str)
{
    size_t i = 0;
    if (isspace(str[0]))
        skip_spaces(str, &i);
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (isdigit(str[i]))
    {
        while (isdigit(str[i]))
            i++;
        if (check_if_only_spaces(str, i))
            return true;
        if (str[i] == '.')
        {
            i++;
            if (isdigit(str[i]))
                while (isdigit(str[i]))
                    i++;
        }
        if (check_if_only_spaces(str, i))
            return true;
        if (!e_check(str, &i))
            return false;
        if (check_if_only_spaces(str, i))
            return true;
    }
    else if ((str[i] == '.') && (isdigit(str[i + 1])))
    {
        i++;
        while (isdigit(str[i]))
            i++;
        if (!e_check(str, &i))
            return false;
        if (check_if_only_spaces(str, i))
            return true;
    }
    return false;
}


void get_errors(int rc)
{
    switch (rc)
    {
        case OVERFLOW_ERROR:
            printf("ERROR: Overflow error\n");
            break;
        case READ_ERROR:
            printf("ERROR: Read error\n");
            break;
        case INPUT_STRING_ERROR:
            printf("ERROR: Input string error\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
