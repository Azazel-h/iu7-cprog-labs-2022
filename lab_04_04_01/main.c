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
#define REG_EXP_COMPILATION_ERROR -3
#define EMPTY_STRING_ERROR -4


void get_errors(int rc);
bool validate_number(char *s);
char *get_end_of_nums(char *n_beg);
int validate_line(char string[], char *n);


int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];
    char string_starts_num[MAX_STR_LEN] = "";

    if (fgets(raw_string, sizeof(raw_string), stdin) == NULL)
        rc = READ_ERROR;
    else if (validate_line(raw_string, string_starts_num))
        rc = EMPTY_STRING_ERROR;
    else if (strlen(raw_string) >= MAX_STR_LEN - 1)
        rc = OVERFLOW_ERROR;
    else
    {
        if (validate_number(string_starts_num))
            printf("YES");
        else
            printf("NO");
    }

    if (rc)
        get_errors(rc);
    return rc;
}


int validate_line(char string[], char *num_starts)
{
    int rc = OK;
    char *num = strtok(string, " \t\n\v\f\r");
    char *end = strtok(NULL, " \t\n\v\f\r");

    if (end != NULL || num == NULL)
        rc = EMPTY_STRING_ERROR;

    if (!rc)
        strcpy(num_starts, num);
    return rc;
}


char *get_end_of_nums(char *n_beg)
{
    while (isdigit(*n_beg))
        n_beg++;
    return n_beg;
}


bool validate_number(char *s)
{
    bool correct = true;
    char *number_end;

    if (*s == '+' || *s == '-')
        s++;
    if (*s == '.')
    {
        s++;
        number_end = get_end_of_nums(s);
        if (number_end - s > 0)
            s = number_end;
        else
            correct = false;
    }
    else if (isdigit(*s))
    {
        s = get_end_of_nums(s);
        if (*s == '.')
        {
            s++;
            s = get_end_of_nums(s);
        }
    }
    else
        correct = false;

    if (correct && (*s == 'e' || *s == 'E'))
    {
        s++;
        if (*s == '+' || *s == '-')
            s++;
        number_end = get_end_of_nums(s);
        if (number_end - s > 0)
            s = number_end;
        else
            correct = false;
    }
    correct = correct && (*s == '\0' || *s == '\n');
    return correct;
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
        case REG_EXP_COMPILATION_ERROR:
            printf("ERROR: Regular expression wasn\'t compiled\n");
            break;
        case EMPTY_STRING_ERROR:
            printf("ERROR: Empty string error\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
