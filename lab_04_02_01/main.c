#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define OK 0
#define MAX_STR_LEN 257
#define MAX_WORD_NUM 18
#define MAX_WORD_LEN 18
#define OVERFLOW_ERROR -1
#define EMPTY_STRING_ERROR -2
#define READ_ERROR -3


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


int split(char *raw_string, string_t *string_arr);
int cmp(const void *first, const void *second);
void print_words_array(string_t *string_arr);
void get_errors(int rc);
bool already_in(string_t *string_arr, char *it, size_t shift);


int main()
{
    int rc = OK;
    char raw_string[MAX_STR_LEN];

    if (fgets(raw_string, MAX_STR_LEN, stdin) == NULL)
        rc = READ_ERROR;
    else if (strlen(raw_string) >= MAX_STR_LEN - 1)
        rc = OVERFLOW_ERROR;
    else
    {
        string_t string_arr = { .len = 0 };

        if (!(rc = split(raw_string, &string_arr)))
        {
            qsort(string_arr.words, string_arr.len, sizeof(word_t), cmp);
            print_words_array(&string_arr);
        }
    }

    if (rc)
        get_errors(rc);
    return rc;
}


bool already_in(string_t *string_arr, char *it, size_t shift)
{
    bool already_in = false;
    for (size_t i = 0; i < string_arr->len && !already_in; ++i)
        if (!strncmp(it, string_arr->words[i].text, shift))
            already_in = true;
    return already_in;
}


int split(char *raw_string, string_t *string_arr)
{
    int rc = 0;
    char *delim = "\t\n\r .,:;!?-";
    char *it = raw_string;

    word_t new_word = { .len = 0 };
    size_t shift;
    while (rc != OVERFLOW_ERROR && strcmp(it, "") != 0)
    {
        shift = strcspn(it, delim);
        if (shift)
        {
            if (!already_in(string_arr, it, shift))
            {
                strncpy(new_word.text, it, shift);
                new_word.len = shift;
                new_word.text[new_word.len] = '\0';
                string_arr->words[string_arr->len] = new_word;
                string_arr->len++;
            }
        }
        if (string_arr->len > MAX_WORD_NUM - 2 || new_word.len > MAX_WORD_LEN - 2)
            rc = OVERFLOW_ERROR;
        it += (shift + 1);
    }
    if (!string_arr->len)
        rc = EMPTY_STRING_ERROR;
    return rc;
}


int cmp(const void *first, const void *second)
{
    word_t *data_1 = (word_t *)first;
    word_t *data_2 = (word_t *)second;
    return strcmp(data_1->text, data_2->text);
}


void print_words_array(string_t *string_arr)
{
    printf("Result: ");
    for (size_t i = 0; i < string_arr->len; ++i)
        printf("%s ", string_arr->words[i].text);
    printf("\n");
}


void get_errors(int rc)
{
    switch (rc)
    {
        case OVERFLOW_ERROR:
            printf("ERROR: Overflow error\n");
            break;
        case EMPTY_STRING_ERROR:
            printf("ERROR: Empty string error\n");
            break;
        case READ_ERROR:
            printf("ERROR: Read error\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
