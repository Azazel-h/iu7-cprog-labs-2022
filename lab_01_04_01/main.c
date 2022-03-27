#include <stdio.h>
#define NUMBER_OF_ROOMS 4
#define NUMBER_OF_FLOORS 9
#define NUMBER_OF_ALL_ROOMS 36

void calculate(int room_num, int *floor_num, int *entrance_num);

int main(void)
{
    int room_num, floor_num, entrance_num;
    printf("Введите номеру квартиры девятиэтажного дома: ");
    scanf("%d", &room_num);
    calculate(room_num, &floor_num, &entrance_num);
    printf("Подъезд - %d \nЭтаж - %d", entrance_num, floor_num);
}

void calculate(int room_num, int *floor_num, int *entrance_num)
{
    *entrance_num = (room_num - 1) / NUMBER_OF_ALL_ROOMS + 1;
    *floor_num = 1 + ((room_num - 1) % NUMBER_OF_ALL_ROOMS) / NUMBER_OF_ROOMS;
}
