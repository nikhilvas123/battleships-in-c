#include<battleships.h>

#define ATTEMPTS 15 
#define GRID_SIZE 10
#define NO_OF_SHIPS 5

const int SHIP_SIZES[NO_OF_SHIPS]={2,2,3,4,6};

void print_menu(){
    printf("*************************************************\n\n");
    printf("Welcome to Battleships!\n\nHOW TO PLAY:There is a grid of 10x10.");
    printf(" The computer places all the ships in random location. You are promted to enter coordinates to guess where the ship is.");
    printf("Enter x cordinate space and then y coordinate(Ex: 2 3). The coordinates are (1,1) for top left and (10,10) for bottom right.");
    printf("You have 15 miss hits. Ships are\n--      x2\n---     x1\n----    x1\n------  x1\n");
    printf("*************************************************\n\n");
    printf("Main Menu\n\n1: Play\n2: Quit\n");
}

void print_grid(const char grid[GRID_SIZE][GRID_SIZE]){
    int i, j;
    for(i=0; i<GRID_SIZE; i++){
        for(j=0; j<GRID_SIZE; j++)
            printf("%c ",grid[i][j]);
    printf("\n");
    }    
}

int check_collision(ship **ships, ship * s, int ship_no){
    return 0;
}

ship* generate_ship(ship **ships, int ship_no){
    int _x,_y;
    srand(time(0));
    ship *s;
    s = (ship *) malloc(sizeof(ship) * 1);
    do{
        s->len = SHIP_SIZES[ship_no];
        _x = rand()%GRID_SIZE;
        _y = rand()%GRID_SIZE;
        s->p.x = _x;
        s->p.y = _y;
    }while(check_collision(ships,s,ship_no));
    return s;
}

void play_game(){
    int att = ATTEMPTS;
    int i;
    char grid[GRID_SIZE][GRID_SIZE];
    ship* s[NO_OF_SHIPS];
    
    for(i=0; i<NO_OF_SHIPS; i++){
        s[i] = generate_ship(s,i);
    }
    
    memset(grid,'.',GRID_SIZE*GRID_SIZE);
    printf("Hits left: %d\n",att);
    print_grid(grid);
}