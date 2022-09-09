#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define OK 0
#define MAX_STR_LEN 258
#define MAX_WORD_NUM 16
#define OVERFLOW_ERROR -1
#define EMPTY_STRING_ERROR -2

typedef struct {
    char text[MAX_STR_LEN];
    size_t len;
} word_t;


typedef struct
{
    word_t words[MAX_WORD_NUM];
    size_t len;
} string_t;


int split(char *raw_string, string_t *words);
int cmp(const void *first, const void *second);
void print_words_array(string_t *string_arr);

int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];
    raw_string[MAX_STR_LEN - 1] = '0';

    if (fgets(raw_string, sizeof(raw_string), stdin) == NULL)
        rc = EMPTY_STRING_ERROR;
    else if (raw_string[MAX_STR_LEN - 1] == '\0')
        rc = OVERFLOW_ERROR;
    else {
        string_t string_arr = {.len = 0};

        if (!(rc = split(raw_string, &string_arr)))
        {
            if (string_arr.len > 0)
            {
                qsort(string_arr.words, string_arr.len, sizeof(word_t), cmp);
                print_words_array(&string_arr);
            }
            else
                rc = EMPTY_STRING_ERROR;
        }
    }
    return rc;
}


int split(char *raw_string, string_t *string_arr)
{
    int rc = 0;
    char *delim = "\t\n\r .,:;!?-";
    char *it = raw_string;
    bool already_in;


    word_t new_word = { .len = 0 };
    while (!rc && strcmp(it, ""))
    {
        size_t x = strcspn(it, delim);
        if (x)
        {
            already_in = false;
            for (size_t i = 0; i < string_arr->len; ++i)
            {
                if (!strncmp(it, string_arr->words[i].text, x))
                {
                    already_in = true;
                    break;
                }
            }
            if (!already_in)
            {
                strncpy(new_word.text, it, x);
                new_word.len = x;
                new_word.text[new_word.len] = '\0';
                string_arr->words[string_arr->len] = new_word;
                string_arr->len++;
            }
        }
        if (string_arr->len > MAX_WORD_NUM)
            rc = OVERFLOW_ERROR;
        it += (x + 1);
    }
    return rc;
}

int cmp(const void *first, const void *second)
{
    word_t *data_1 = (word_t *)first;
    word_t *data_2 = (word_t *)second;
    return strcmp(data_2->text, data_1->text);
}


void print_words_array(string_t *string_arr)
{
    printf("Result: ");
    for (size_t i = 0; i < string_arr->len; ++i)
    {
        printf("%s ", string_arr->words[i].text);
    }
}
