#include <stdio.h>

int intersect_main(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy);
int v_create(int ax, int ay, int bx, int by);

int main(void)
{
    int px, py, qx, qy;
    int rx, ry, sx, sy;
    int check_first_inp, check_second_inp;

    printf("Введите координаты первого отрезка: ");
    check_first_inp = scanf("%d%d%d%d", &px, &py, &qx, &qy);
    if (check_first_inp != 4)
        return -100;

    printf("Введите координаты второго отрезка: ");
    check_second_inp = scanf("%d%d%d%d", &rx, &ry, &sx, &sy);
    if (check_second_inp != 4)
        return -100;

    if ((px == qx && py == qy) || (rx == sx && ry == sy))
        return -100;

    printf("%d", intersect_main(px, py, qx, qy, rx, ry, sx, sy));
    return 0;
}

int v_create(int ax, int ay, int bx, int by)
{
    return ax * by - bx * ay;
}

int intersect_main(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
    int first_vector = v_create(dx - cx, dy - cy, ax - cx, ay - cy);
    int second_vector = v_create(dx - cx, dy - cy, bx - cx, by - cy);
    int third_vector = v_create(bx - ax, by - ay, cx - ax, cy - ay);
    int fourth_vector = v_create(bx - ax, by - ay, dx - ax, dy - ay);
    if ((first_vector * second_vector < 0) && (third_vector * fourth_vector < 0))
        return 1;
    else
        return 0;
}

