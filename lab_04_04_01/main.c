#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <regex.h>
#include <stdbool.h>

#define OK 0
#define MAX_STR_LEN 257
#define MAX_WORD_LEN 18
#define MAX_WORD_NUM 18
#define REG_EXP "^ *[+-]?([0-9]+([.][0-9]*)?([eE][+-]?[0-9]+)?|[.][0-9]+([eE][+-]?[0-9]+)?) *$"
#define OVERFLOW_ERROR -1
#define READ_ERROR -2
#define REG_EXP_COMPILATION_ERROR -3
#define EMPTY_STRING_ERROR -4


typedef struct
{
    char text[MAX_WORD_LEN];
    size_t len;
} word_t;


typedef struct
{
    word_t words[MAX_WORD_NUM];
    size_t len;
} string_t;


void get_errors(int rc);
int check_regular(string_t *string_arr, bool *is_in);
int split(char *raw_string, string_t *string_arr);

int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];
    size_t length;
    bool is_in = false;

    if (fgets(raw_string, sizeof(raw_string), stdin) == NULL)
        rc = READ_ERROR;
    else if ((length = strlen(raw_string)) == 1)
        rc = EMPTY_STRING_ERROR;
    else if (length >= MAX_STR_LEN - 1)
        rc = OVERFLOW_ERROR;
    else
    {
        string_t string_arr = { .len = 0 };
        if (!(rc = split(raw_string, &string_arr)))
        {
            rc = check_regular(&string_arr, &is_in);
        }
    }

    if (is_in)
        printf("YES");
    else
        printf("NO");

    if (rc)
        get_errors(rc);
    return rc;
}


int split(char *raw_string, string_t *string_arr)
{
    int rc = 0;
    char *delim = "\t\n\r .,:;!?-";
    char *token = strtok(raw_string, delim);

    word_t new_word = { .len = 0 };
    while (rc != OVERFLOW_ERROR && token != NULL)
    {
        strcpy(new_word.text, token);
        new_word.len = strlen(token);
        string_arr->words[string_arr->len] = new_word;
        string_arr->len++;
        if (string_arr->len > MAX_WORD_NUM - 2 || new_word.len > MAX_WORD_LEN - 2)
            rc = OVERFLOW_ERROR;
        token = strtok(NULL, delim);
    }
    if (!string_arr->len)
        rc = EMPTY_STRING_ERROR;
    return rc;
}


int check_regular(string_t *string_arr, bool *is_in)
{
    int rc = OK;
    regex_t reg_exp;
    int value;
    int compilation_rc = regcomp(&reg_exp, REG_EXP, REG_EXTENDED|REG_NEWLINE);

    if (!compilation_rc)
    {
        for (size_t i = 0; i < string_arr->len && !*is_in; ++i)
        {
            value = regexec(&reg_exp, string_arr->words[i].text, 0, NULL, 0);
            if (!value)
               *is_in = true;
        }
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

