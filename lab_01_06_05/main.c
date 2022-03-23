#include <stdio.h>
#include <math.h>
#define EPS 0.000001

int intersect_main(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy);
double v_create(double ax, double ay, double bx, double by);

int main(void)
{
    double px, py, qx, qy;
    double rx, ry, sx, sy;
    int check_first_inp, check_second_inp;

    printf("Введите координаты первого отрезка: ");
    check_first_inp = scanf("%lf%lf%lf%lf", &px, &py, &qx, &qy);
    if (check_first_inp != 4 || (fabs(px - qx) < EPS && fabs(py - qy) < EPS))
        return -100;

    printf("Введите координаты второго отрезка: ");
    check_second_inp = scanf("%lf%lf%lf%lf", &rx, &ry, &sx, &sy);
    if (check_second_inp != 4 || (fabs(px - qx) < EPS && fabs(py - qy) < EPS))
        return -100;

    printf("%d", intersect_main(px, py, qx, qy, rx, ry, sx, sy));
    return 0;
}

double v_create(double ax, double ay, double bx, double by)
{
    return ax * ay - bx * by;
}

int intersect_main(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
{
    double first_vector = v_create(dx - cx, dy - cy, ax - cx, ay - cy);
    double second_vector = v_create(dx - cx, dy - cy, bx - cx, by - cy);
    double third_vector = v_create(bx - ax, by - ay, cx - ax, cy - ay);
    double fourth_vector = v_create(bx - ax, by - ay, dx - ax, dy - ay);
    if ((first_vector * second_vector < 0) && (third_vector * fourth_vector < 0))
        return 1;
    else
        return 0;
}



