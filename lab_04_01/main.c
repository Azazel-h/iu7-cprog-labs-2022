#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define OK 0

char *my_strpbrk(const char *__s, const char *__charset);
size_t my_strspn(const char *__s, const char *__charset);
size_t my_strcspn(const char *__s, const char *__charset);
char *my_strchr(const char *__s, int __c);
char *my_strrchr(const char *__s, int __c);


int main()
{
    int fails_counter = 0;

    fails_counter += my_strpbrk("hello world, friend of mine!", " ,!") != strpbrk("hello world, friend of mine!", " ,!");
    fails_counter += my_strpbrk("helloworld,friendofmine!", " ,!") != strpbrk("helloworld,friendofmine!", " ,!");
    fails_counter += my_strpbrk("helloworldfriendofmine!", " ,!") != strpbrk("helloworldfriendofmine!", " ,!");
    fails_counter += my_strpbrk("", " ,!") != strpbrk("", " ,!");

    fails_counter += my_strspn("12345", "123") != strspn("12345", "123");
    fails_counter += my_strspn("abc123", "abc") != strspn("abc123", "abc");
    fails_counter += my_strspn("   123", " 123") != strspn("   123", " 123");
    fails_counter += my_strspn("123abc", "abc") != strspn("123abc", "abc");
    fails_counter += my_strspn("", "a") != strspn("", "a");

    fails_counter += my_strcspn("12345", "1") != strcspn("12345", "1");
    fails_counter += my_strcspn("", "1") != strcspn("", "1");
    fails_counter += my_strcspn("12345", "\0") != strcspn("12345", "\0");
    fails_counter += my_strcspn("   23", " 123") != strcspn("   23", " 123");

    fails_counter += my_strchr("12 34", ' ') != strchr("12 34", ' ');
    fails_counter += my_strchr("1234", '1') != strchr("1234", '1');
    fails_counter += my_strchr("1234", '4') != strchr("1234", '4');
    fails_counter += my_strchr("1234", '\0') != strchr("1234", '\0');
    fails_counter += my_strchr("", '1') != strchr("", '1');

    fails_counter += my_strrchr("   ", ' ') != strrchr("   ", ' ');
    fails_counter += my_strrchr("111122", '1') != strrchr("111122", '1');
    fails_counter += my_strrchr("1234", '4') != strrchr("1234", '4');
    fails_counter += my_strrchr("1234", '\0') != strrchr("1234", '\0');
    fails_counter += my_strrchr("", '1') != strrchr("", '1');

    printf("%d", fails_counter);
    return OK;
}


char *my_strpbrk(const char *__s, const char *__charset)
{
    while (*__s != '\0')
    {
        for (const char *ch = __charset; *ch != '\0'; ch++)
        {
            if (*__s == *ch)
            {
                return (char *) (__s);
            }
        }
        __s++;
    }
    return NULL;
}


size_t my_strspn(const char *__s, const char *__charset)
{
    size_t len = 0;
    while (*__s != '\0')
    {
        _Bool should_stop = true;
        for (const char *ch = __charset; *ch != '\0'; ch++)
        {
            if (*__s == *ch)
            {
                len++;
                should_stop = false;
                break;
            }
        }
        if (should_stop)
            break;
        __s++;
    }
    return len;
}


size_t my_strcspn(const char *__s, const char *__charset)
{
    size_t len = 0;
    while (*__s != '\0')
    {
        for (const char *ch = __charset; *ch != '\0'; ch++)
        {
            if (*__s == *ch)
            {
                return len;
            }
        }
        len++;
        __s++;
    }
    return len;
}


char *my_strchr(const char *__s, int __c)
{
    do
    {
        if (*__s == __c)
            return (char *) __s;
    }
    while (*__s++ != '\0');

    return NULL;
}


char *my_strrchr(const char *__s, int __c)
{

    char *result = NULL;

    do
    {
        if (*__s == __c)
            result = (char *) __s;
    }
    while (*__s++ != '\0');

    return result;
}


void get_errors(int status_code)
{
    switch (status_code)
    {
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}

