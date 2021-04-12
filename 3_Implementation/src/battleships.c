#include<battleships.h>

void print_menu(){
    printf("*************************************************\n\n");
    printf("Welcome to Battleships!\n\nHOW TO PLAY:There is a grid of 10x10.");
    printf(" The computer places all the ships in random location. You are promted to enter coordinates to guess where the ship is.");
    printf("Enter x cordinate space and then y coordinate(Ex: 2 3). The coordinates are (1,1) for top left and (10,10) for bottom right.");
    printf("You have 15 miss hits. Ships are\n--      x2\n---     x1\n----    x1\n------  x1\n");
    printf("*************************************************\n\n");
    printf("Main Menu\n\n1: Play\n2: Quit\n");
}