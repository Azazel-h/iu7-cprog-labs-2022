#include <stdio.h>
#include <stddef.h>


#define N 10
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -12
#define SIZE_INPUT_ERROR -13
#define INVALID_ERROR -14
#define NO_SUITABLE_ELEMENTS_ERROR -15


typedef struct
{
    size_t len;
    int nums[N];
} array;


int read_array(array *arr);
int is_valid(array *arr);
int find_product(array *arr, int *product);

void get_errors(int status_code);

int main()
{
    int status_code = OK, product;
    array arr;
    if ((status_code = read_array(&arr)) || (status_code = is_valid(&arr)))
        get_errors(status_code);
    else
    {
        find_product(&arr, &product);
        printf("%d\n", product);
    }
    return status_code;
}

int read_array(array *arr)
{
    int status_code = OK;
    if (scanf("%zu", &(arr->len)) != 1)
        status_code = SIZE_INPUT_ERROR;
    else if (arr->len < 1 || arr->len > N)
        status_code = SIZE_ERROR;
    else
    {
        for (size_t i = 0; i < arr->len; ++i)
        {
            if (scanf("%d", arr->nums + i) != 1)
            {
                status_code = INPUT_ERROR;
                break;
            }
        }
    }
    return status_code;
}

int is_valid(array *arr)
{
    int status_code = INVALID_ERROR;
    for (size_t i = 0; i < arr->len; ++i)
        if (arr->nums[i] % 2)
        {
            status_code = OK;
            break;
        }
    return status_code;
}

int find_product(array *arr, int *product)
{
    int status_code = NO_SUITABLE_ELEMENTS_ERROR;
    *product = 1;
    for (size_t i = 0; i < arr->len; ++i)
    {
        if (arr->nums[i] % 2)
        {
            *product *= arr->nums[i];
            status_code = OK;
        }
    }
    return status_code;
}

void get_errors(int status_code)
{
    switch (status_code)
    {
        case INPUT_ERROR:
            printf("ERROR: Bad input\n");
            break;
        case SIZE_ERROR:
            printf("ERROR: Bad array size\n");
            break;
        case SIZE_INPUT_ERROR:
            printf("ERROR: Bad input size\n");
            break;
        case INVALID_ERROR:
            printf("ERROR: No one valid element\n");
            break;
        case NO_SUITABLE_ELEMENTS_ERROR:
            printf("ERROR: No necessary elements\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
