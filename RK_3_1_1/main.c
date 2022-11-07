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
            int **matrix = NULL;
            int min;
            size_t n, m;

            if ((rc = read_matrix_file(f_i, &matrix, &n, &m)) == OK)
            {
                if (is_matrix_sq(n, m))
                {
                    if ((rc = find_min_odd_under_maind_sq(matrix, n, &min)) == OK)
                        printf("%d\n", min);
                }
                else
                    rc = NOT_SQ_ERR;
                free_matrix(matrix, n);
            }
            fclose(f_i);
        }
        else
            rc = FILE_ERR;
    }
    else
        rc = ARGC_ERR;

    return rc;
}
