#include <stdio.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int area(int ax, int ay, int bx, int by, int cx, int cy);
void swap(int *a, int *b);
int intersect_sub(int a, int b, int c, int d);
int intersect_main(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy);

int main(void)
{
    int px, py, qx, qy;
    int rx, ry, sx, sy;
    int check_first_inp, check_second_inp;

    printf("Введите координаты первого отрезка: ");
    check_first_inp = scanf("%d%d%d%d", &px, &py, &qx, &qy);
    if (check_first_inp != 4 || (px == qx && py == qy))
        return -100;

    printf("Введите координаты второго отрезка: ");
    check_second_inp = scanf("%d%d%d%d", &rx, &ry, &sx, &sy);
    if (check_second_inp != 4 || (rx == ry && sx == sy))
        return -100;

    printf("%d", intersect_main(px, py, qx, qy, rx, ry, sx, sy));
    return 0;
}

int area(int ax, int ay, int bx, int by, int cx, int cy)
{
    return (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int intersect_sub(int a, int b, int c, int d)
{
    if (a > b)
        swap(&a, &b);
    if (c > d)
        swap(&c, &d);
    return MAX(a, c) <= MIN(b, d);
}

int intersect_main(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
    return intersect_sub(ax, bx, cx, dx)
        && intersect_sub(ay, by, cy, dy)
        && area(ax, ay, bx, by, cx, cy) * area(ax, ay, bx, by, dx, dy) <= 0
        && area(cx, cy, dx, dy, ax, ay) * area(cx, cy, dx, dy, bx, by) <= 0;
}



