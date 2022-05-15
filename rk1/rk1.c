// Вариант 1

#include <stdio.h>
#define OK 0
#define INPUT_ERROR -100
#define MAX_LENGTH 10

int arr_input(int *arr, int n);
void print_arr(int *arr, int n);
void group_arr(int *arr, int n);


int main()
{
    int arr[MAX_LENGTH];
    int n, status_code = OK;
    
    printf("INPUT ARR LENGTH [1; 10]: ");
    scanf("%d\n", &n);
    
    if (n >= 1 && n <= 10)
        status_code = arr_input(arr, n);
    else
        status_code = INPUT_ERROR;
        
    if (status_code == OK)
        group_arr(arr, n);
    
    return status_code;
}

int arr_input(int *arr, int n)
{
    int check_input, status_code = OK;
    for (int i = 0; i < n; ++i)
    {
        check_input = scanf("%d", arr + i);
        if (check_input != 1)
            status_code = INPUT_ERROR;
    }
    return status_code;
}

void print_arr(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void group_arr(int *arr, int n)
{
    int new_arr[MAX_LENGTH];
    int arr_zeros[MAX_LENGTH], arr_negative[MAX_LENGTH], arr_positive[MAX_LENGTH];
    int zeros = 0, negative = 0, positive = 0;
    
    // Group array
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == 0) 
        {
            arr_zeros[zeros] = arr[i];
            ++zeros;
        }
        else if (arr[i] < 0)
        {
            arr_negative[negative] = arr[i];
            ++negative;
        }
        else if (arr[i] > 0)
        {
            arr_positive[positive] = arr[i];
            ++positive;
        }
    }
    
    // Trying to make main array from groups
    int main_counter = 0;
    for (int z = 0; z < zeros; ++z)
    {
        new_arr[main_counter] = arr_zeros[z];
        ++main_counter;
    }
    
    for (int neg = 0; neg < negative; ++neg)
    {
        new_arr[main_counter] = arr_negative[neg];
        ++main_counter;
    }
    
    for (int pos = 0; pos < positive; ++pos)
    {
        new_arr[main_counter] = arr_positive[pos];
        ++main_counter;
    }
    print_arr(new_arr, n);
}


