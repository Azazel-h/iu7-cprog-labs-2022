#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <regex.h>

#define OK 0
#define MAX_STR_LEN 257
#define REG_EXP "[-+]?[0-9]*[.]?[0-9]+([eE][-+]?[0-9]+)?"
#define OVERFLOW_ERROR -1
#define READ_ERROR -2
#define REG_EXP_COMPILATION_ERROR -3
#define EMPTY_STRING_ERROR -4


void get_errors(int rc);
int check_regular(char *raw_string);


int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];
    size_t length;

    if (fgets(raw_string, sizeof(raw_string), stdin) == NULL)
        rc = READ_ERROR;
    else if ((length = strlen(raw_string)) == 1)
        rc = EMPTY_STRING_ERROR;
    else if (length >= MAX_STR_LEN - 1)
        rc = OVERFLOW_ERROR;
    else
        rc = check_regular(raw_string);

    if (rc)
        get_errors(rc);
    return rc;
}


int check_regular(char *raw_string)
{
    int rc = OK;
    regex_t reg_exp;
    int value;
    int compilation_rc = regcomp(&reg_exp, REG_EXP, REG_EXTENDED);

    if (!compilation_rc)
    {
        value = regexec(&reg_exp, raw_string, 0, NULL, 0);
        if (!value)
            printf("YES");
        else
            printf("NO");
    }
    else
        rc = REG_EXP_COMPILATION_ERROR;
    regfree(&reg_exp);
    return rc;
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
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}

