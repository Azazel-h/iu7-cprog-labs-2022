#include <stdio.h>
#define OK 0
#define INPUT_ERROR -1
#define N 5

typedef struct new_matrix
{
    char data[N][N][N];
} Matrix;

void print_matrix();
void read_matrix();
int check_matrix();

int main(void)
{
    int exit_code = OK;
    Matrix arr;
    read_matrix(&arr);
    print_matrix(&arr);
    return exit_code;
}

void print_matrix(Matrix *arr)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            printf("%s ", arr->data[i][j]);
        }
        printf("\n");
    }
}

void read_matrix(Matrix *arr)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            scanf("%s", arr->data[i][j]);
        }
        printf("\n");
    }
}
