#include "matrix.h"

#define ARG_C 2
#define PATH_POS 1

int main(int argc, char *argv[])
{
    int rc = OK;
    FILE *f_i = NULL;
    if (argc == ARG_C)
    {
        if ((f_i = fopen(argv[PATH_POS], "r")) != NULL)
        {
            int matrix[N][N];
            size_t n, m;
            int min;

            if ((rc = read_sq_matrix_file(f_i, matrix, &n, &m)) == OK)
            {
                for (size_t i = 0; i < n; ++i)
                {
                    for (size_t j = 0; j < m; ++j)
                    {
                        printf("%d ", matrix[i][j]);
                    }
                    printf("\n");
                }

                find_min_under_maind(matrix, n, &min);
                printf("%d", min);
            }
        }
        else
            rc = FILE_ERR;
    }
    else
        rc = ARGC_ERR;

    return rc;
}
