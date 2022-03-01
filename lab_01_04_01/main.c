#include <stdio.h>

void calculate(int room_num, int* floor_num, int* entrance_num);

int main(void)
{
    int room_num, floor_num, entrance_num;
    printf("Введите номеру квартиры девятиэтажного дома: ");
    scanf("%d", &room_num);
    calculate(room_num, &floor_num, &entrance_num);
    printf("Подъезд %d, Этаж %d", entrance_num, floor_num);
}

void calculate(int room_num, int* floor_num, int* entrance_num)
{
    int number_of_rooms = 4, number_of_floors = 9, number_of_all_rooms = (number_of_rooms * number_of_floors);
    *entrance_num = (room_num - 1) / number_of_all_rooms + 1;
    *floor_num = 1 + ((room_num - 1) % number_of_all_rooms) / number_of_rooms;
}