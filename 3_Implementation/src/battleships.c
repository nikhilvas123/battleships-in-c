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

void print_ship(ship *s){   
    char ch[6];
    printf("Ship Location:%d %d\nShip size:%d\n",s->p.x, s->p.y, s->len);
    switch(s->o){
        case UP:
            sprintf(ch,"%s","UP");
            break;
        case DOWN:
            sprintf(ch,"%s","DOWN");
            break;
        case LEFT:
            sprintf(ch,"%s","LEFT");
            break;
        case RIGHT:
            sprintf(ch,"%s","RIGHT");
            break;
    }
    printf("Ship orientation:%s\n",ch);
}

int check_collision_boundary(ship * s){
    switch(s->o){
        case UP:
            if(s->p.y - s->len + 1 < 0)
                return 1;
            break;
        case DOWN:
            if(s->p.y + s->len - 1 >= GRID_SIZE)
                return 1;
            break;
        case LEFT:
            if(s->p.x - s->len + 1 < 0)
                return 1;
            break;
        case RIGHT:
            if(s->p.x + s->len -1 >= GRID_SIZE)
                return 1;
            break;
    }
    return 0;
}

pos *ship_coordinates(ship *s){
    pos *p;
    p = (pos *)malloc(sizeof(pos)*2);
    switch(s->o){
        case UP:
            p[0].x = s->p.x;
            p[0].y = s->p.y - s->len + 1;
            p[1].x = s->p.x;
            p[1].y = s->p.y;
            break;

        case DOWN:
            p[0].x = s->p.x;
            p[0].y = s->p.y;
            p[1].x = s->p.x;
            p[1].y = s->p.y + s->len - 1;
            break;

        case LEFT:
            p[0].x = s->p.x - s->len + 1;
            p[0].y = s->p.y;
            p[1].x = s->p.x;
            p[1].y = s->p.y;
            break;

        case RIGHT:
            p[0].x = s->p.x;
            p[0].y = s->p.y;
            p[1].x = s->p.x + s->len - 1;
            p[1].y = s->p.y;
            break;
    }
    return p;
}

int check_collision_ships(ship **ships, ship *s, int ship_no){
    int i,col = 0;
    pos *pos1, *pos2;
    pos1 = ship_coordinates(s);
    for(i=0; i<ship_no; i++){
        pos2 = ship_coordinates(ships[i]);
        if(pos1[0].x > pos2[1].x || pos1[1].x < pos2[0].x || pos1[0].x > pos2[1].y || pos1[1].y < pos2[0].y)
            col = 0;
        else   
            col = 1;
    }
    return col;
}

int check_collision(ship **ships, ship *s,int ship_no){
    if(check_collision_boundary(s))
        return 1;
    if(check_collision_ships(ships, s, ship_no))
        return 1;
    return 0;
}

ship* generate_ship(ship **ships, int ship_no){
    int _x,_y;
    orientation _o;
    ship *s;
    s = (ship *) malloc(sizeof(ship) * 1);
    do{
        s->len = SHIP_SIZES[ship_no];
        _x = rand()%GRID_SIZE;
        _y = rand()%GRID_SIZE;
        _o = rand()%4;
        s->p.x = _x;
        s->p.y = _y;
        s->o = _o;
    }while(check_collision(ships,s,ship_no));
    return s;
}

void play_game(){
    srand(time(0));
    int att = ATTEMPTS;
    int i;
    char grid[GRID_SIZE][GRID_SIZE];
    ship* s[NO_OF_SHIPS];
    
    for(i=0; i<NO_OF_SHIPS; i++){
        s[i] = generate_ship(s,i);
    }
    
    for(i=0; i<NO_OF_SHIPS; i++){
        print_ship(s[i]);
    }

    memset(grid,'.',GRID_SIZE*GRID_SIZE);
    printf("Hits left: %d\n",att);
    print_grid(grid);
}