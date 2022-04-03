#include <stdio.h>
#define STANDARD_SIZE 10

int main(void)
{
    int arr[STANDARD_SIZE];
    for (int i = 0; i < STANDARD_SIZE; ++i)
    {
        scanf("%d", &arr[i])
    }
    for (int i = 0; i < STANDARD_SIZE; ++i)
    {
        printf("%d", arr[i])
    }
}