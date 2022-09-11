#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define OK 0
#define MAX_STR_LEN 256
#define MAX_WORD_NUM 17
#define MAX_WORD_LEN 17
#define OVERFLOW_ERROR -1
#define EMPTY_STRING_ERROR -2


typedef struct
{
    char text[MAX_STR_LEN];
    size_t len;
} word_t;


typedef struct
{
    word_t words[MAX_WORD_NUM];
    size_t len;
} string_t;


int split(char *raw_string, string_t *string_arr);
void form_string(char *new_string, string_t *string_arr);
void clear_array(string_t *string_arr, char *last);
void delete_word(string_t *string_arr, size_t index);

int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];

    if (fgets(raw_string, sizeof(raw_string), stdin) == NULL)
        rc = EMPTY_STRING_ERROR;
    else if (strlen(raw_string) >= MAX_STR_LEN - 1)
        rc = OVERFLOW_ERROR;
    else
    {
        string_t string_arr = { .len = 0 };
        char new_string[MAX_STR_LEN] = "";
        if (!(rc = split(raw_string, &string_arr)))
        {
            char *last = string_arr.words[string_arr.len - 1].text;
            clear_array(&string_arr, last);
            form_string(new_string, &string_arr);
            printf("Result: %s\n", new_string);
        }
    }
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
        if (string_arr->len >= MAX_WORD_NUM - 1 || new_word.len >= MAX_WORD_LEN - 1)
            rc = OVERFLOW_ERROR;
        token = strtok(NULL, delim);
    }
    if (!string_arr->len)
        rc = EMPTY_STRING_ERROR;
    return rc;
}


void delete_word(string_t *string_arr, size_t index)
{
    for (size_t i = index; i < string_arr->len - 1; ++i)
        strcpy(string_arr->words[i].text, string_arr->words[i + 1].text);
    string_arr->len--;

}


void clear_array(string_t *string_arr, char *last)
{
    size_t i = 0;
    while (i < string_arr->len)
    {
        if (!strcmp(string_arr->words[i].text, last))
        {
            delete_word(string_arr, i--);
            i--;
        }
        i++;
    }
}


void form_string(char *new_string, string_t *string_arr)
{
    for (size_t i = string_arr->len; i-->0;)
    {
        strcat(new_string, string_arr->words[i].text);
        if (i != 0)
            strcat(new_string, " ");
    }
}
