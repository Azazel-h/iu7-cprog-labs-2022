#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>


#define N 10
#define OK 0
#define INPUT_ERROR -11
#define SIZE_ERROR -13
#define SIZE_INPUT_ERROR -14

int read_matrix(int matrix[][N], size_t *n, size_t *m);
int is_symmetrical(int main_matrix[][N], size_t len, size_t index);

void form_result_array_from_matrix(int *result_arr, size_t len, int main_matrix[][N], int (*check)(int [][N], size_t, size_t));
void print_array(int *arr, size_t len);
void get_errors(int status_code);


int main()
{
    int status_code = OK;
    int matrix[N][N];
    size_t n, m;
    if ((status_code = read_matrix(matrix, &n, &m)))
        get_errors(status_code);
    else
    {
        int result_arr[N];
        form_result_array_from_matrix(result_arr, n, matrix, is_symmetrical);
        print_array(result_arr, n);
    }
    return status_code;
}


int read_matrix(int matrix[][N], size_t *n, size_t *m)
{
    int status_code = OK;
    if (scanf("%zu%zu", n, m) != 2)
        status_code = SIZE_INPUT_ERROR;
    else if ((*n < 1 || *n > N) || (*m < 1 || *m > N))
        status_code = SIZE_ERROR;
    else
    {
        for (size_t i = 0; i < *n; ++i)
        {
            for (size_t j = 0; j < *m; ++j)
            {
                if (scanf("%d", &matrix[i][j]) != 1)
                {
                    status_code = INPUT_ERROR;
                    break;
                }
            }
        }
    }
    return status_code;
}


int is_symmetrical(int main_matrix[][N], size_t len, size_t row_index)
{
    int is_symmetrical = true;
    for (size_t i = 0; i < len / 2 + 1; ++i)
    {
        if (main_matrix[row_index][i] != main_matrix[row_index][len - i - 1])
        {
            is_symmetrical = false;
            break;
        }
    }
    return is_symmetrical;
}


void form_result_array_from_matrix(int *result_arr, size_t len, int main_matrix[][N], int (*check)(int [][N], size_t, size_t))
{
    for (size_t i = 0; i < len; ++i)
    {
        result_arr[i] = check(main_matrix, len, i);
    }
}


void print_array(int *arr, size_t len)
{
    for (size_t i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void get_errors(int status_code)
{
    switch (status_code)
    {
        case INPUT_ERROR:
            printf("ERROR: Bad input\n");
            break;
        case SIZE_ERROR:
            printf("ERROR: Bad matrix size\n");
            break;
        case SIZE_INPUT_ERROR:
            printf("ERROR: Bad input size\n");
            break;
        default:
            printf("ERROR: Unknown error\n");
            break;
    }
}
