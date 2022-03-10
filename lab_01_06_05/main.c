#include <stdio.h>
#include <math.h>
#define EPS 1e-7

float det(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
int point_check(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
int cramers_rule(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float det);

int main(void)
{
    float xp, yp, xq, yq;
    float xr, yr, xs, ys;
    int rc1, rc2;

    rc1 = scanf("%f%f%f%f", &xp, &yp, &xq, &yq);
    if (rc1 != 4)
        return -100;

    rc2 = scanf("%f%f%f%f", &xr, &yr, &xs, &ys);
    if (rc2 != 4)
        return -100;

    float determinant = det(xp, yp, xq, yq, xr, yr, xs, ys);
    if (fabs(determinant) <= EPS)
    {
        if (point_check(xp, yp, xq, yq, xr, yr, xs, ys))
            printf("1");
        else
            printf("0");
    }
    else
    {
        if (cramers_rule(xp, yp, xq, yq, xr, yr, xs, ys, determinant))
            printf("1");
        else
            printf("0");
    }
    return 0;
}

float det(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    return (y4 - y3) * (x1 - x2) - (x4 - x3) * (y1 - y2);
}

int point_check(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    return fabs((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1)) <= EPS &&
           fabs((x1 * y2 - x2 * y1) * (y4 - y3) - (x3 * y4 - x4 * y3) * (y2 - y1)) <= EPS;
}

int cramers_rule(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float det)
{
    float u_a, u_b, a, b;
    a = (x4 - x2) * (y4 - y3) - (x4 - x3) * (y4 - y2);
    b = (x1 - x2) * (y4 - y2) - (x4 - x2) * (y1 - y2);
    u_a = a / det;
    u_b = b / det;
    if (u_a + EPS >= 0 && u_a - EPS <= 1 && u_b + EPS >= 0 && u_b - EPS <= 1)
        return 1;
    else
        return 0;
}


