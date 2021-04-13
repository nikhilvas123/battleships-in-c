#include<battleships.h>

#define ATTEMPTS 15 
#define GRID_SIZE 10
#define NO_OF_SHIPS 5

const int SHIP_SIZES[NO_OF_SHIPS]={2,2,3,4,6};

extern int dev;

void print_menu(){
    printf("*************************************************\n");
    if(dev){
        printf(" D  E  V    M  O  D  E\n");
        printf("*************************************************\n");
    }
    printf("\nWelcome to Battleships!\n\nHOW TO PLAY:There is a grid of 10x10.");
    printf(" The computer places all the ships in random location. You are promted to enter coordinates to guess where the ship is.");
    printf("Enter x cordinate space and then y coordinate(Ex: 2 3). The coordinates are (1,1) for top left and (10,10) for bottom right.");
    printf("You have 15 miss hits. Ships are\n--      x2\n---     x1\n----    x1\n------  x1\n");
    printf("*************************************************\n\n");
    printf("Main Menu\n\n1: Play\n2: Quit\n");
}

void print_grid(const char grid[GRID_SIZE][GRID_SIZE]){
    int i, j;
    printf("   ");
    for(i=0; i<GRID_SIZE; i++)
        printf("%d ",i+1);
    printf("\n");
    for(i=0; i<GRID_SIZE; i++){
        printf("%d ",i+1);
        if(i!=GRID_SIZE -1)
            printf(" ");
        for(j=0; j<GRID_SIZE; j++)
            printf("%c ",grid[i][j]);
    printf("\n");
    }    
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

void print_ship(ship *s){   
    char ch[6];
    pos *p = ship_coordinates(s);
    printf("Ship Location:%d,%d\nShip size:%d\n",s->p.x, s->p.y, s->len);
    printf("Ship coordinates:(%d,%d)->(%d,%d)\n",p[0].x,p[0].y,p[1].x,p[1].y);
    free(p);
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

int check_collision_ships(ship **ships, ship *s, int ship_no){
    int i,col = 0;
    pos *pos1, *pos2;
    pos1 = ship_coordinates(s);
    for(i=0; i<ship_no; i++){
        pos2 = ship_coordinates(ships[i]);
        if(pos1[0].x > pos2[1].x || pos1[1].x < pos2[0].x || pos1[0].y > pos2[1].y || pos1[1].y < pos2[0].y){
            col = 0;
        }
        else{   
            col = 1;
            free(pos2);
            break;
        }
        free(pos2);
    }
    free(pos1);
    return col;
}

void grid_show_ships(char grid[GRID_SIZE][GRID_SIZE], ship **ships){
    pos *p;
    int i,j,k;
    for(i=0; i<NO_OF_SHIPS; i++){
        p = ship_coordinates(ships[i]);
        for(j=p[0].x; j<=p[1].x; j++)
            for(k=p[0].y; k<=p[1].y; k++)
                grid[k][j] = '^';
    }
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
        s->hit = 0;
    }while(check_collision(ships,s,ship_no));
    return s;
}

int check_hit_update_grid(ship **ships, char grid[GRID_SIZE][GRID_SIZE], pos p){
    int i, j, ship_hit = 0, hit = 0;
    pos *s_p;

    for(i=0; i<NO_OF_SHIPS; i++){
        s_p = ship_coordinates(ships[i]);
        if((p.x - 1 >= s_p[0].x && p.x - 1 <= s_p[1].x) && (p.y - 1 >= s_p[0].y && p.y - 1 <= s_p[1].y)){    
            free(s_p);
            hit = 1;
            break;
        }
        else
            hit = 0;
    }
    if(hit)
        grid[p.y-1][p.x-1] = 'x';
    else
        grid[p.y-1][p.x-1] = 'o';

    for(i=0; i<NO_OF_SHIPS; i++){
        if(!ships[i]->hit){
            s_p = ship_coordinates(ships[i]);
            for(j=0; j<ships[i]->len; j++){
                if(s_p[0].x == s_p[1].x){
                    if(grid[s_p[0].y + j][s_p[0].x] != 'x'){
                        ship_hit = 0;
                        break;
                    }
                    else
                        ship_hit = 1;
                }
                else{
                    if(grid[s_p[0].y][s_p[0].x + j] != 'x'){
                        ship_hit = 0;
                        break;
                    }
                    else ship_hit = 1;
                }
            }
            if(ship_hit)
                ships[i]->hit = 1;
        }
    }
    return hit;
}

int check_valid_coordinate(char grid[GRID_SIZE][GRID_SIZE], pos p){
    if(p.x < 1 || p.x > GRID_SIZE || p.y < 1 || p.y > GRID_SIZE)
        return 0;
    if(grid[p.y - 1][p.x - 1] == 'x' || grid[p.y - 1][p.x - 1] =='o')
        return 0;
    else
        return 1;
}

int ships_hit(ship **ships, char grid[GRID_SIZE][GRID_SIZE]){
    int count=0;
    int i;
    for(i=0; i<NO_OF_SHIPS; i++){
        if(ships[i]->hit)
            count++;
    }
    return count;
}

void play_game(){
    pos p;
    srand(time(0));
    int hit = 0;
    int att = ATTEMPTS;
    int i;
    char grid[GRID_SIZE][GRID_SIZE];
    ship* ships[NO_OF_SHIPS];
    
    for(i=0; i<NO_OF_SHIPS; i++){
        ships[i] = generate_ship(ships,i);
    }
    // for(i=0; i<NO_OF_SHIPS; i++){
    //     print_ship(ships[i]);
    // }
    memset(grid,'.',GRID_SIZE*GRID_SIZE);
    if(dev)
        grid_show_ships(grid,ships);
    while(att){
        printf("Hits left: %d\n", att);
        printf("Ships left %d\n", NO_OF_SHIPS - hit);
        print_grid(grid);
        printf("Enter coordinates(x y): ");
        scanf("%d %d", &p.x, &p.y);
        while(!check_valid_coordinate(grid, p)){
            printf("Invalid coordinates, try again!\nEnter coordinates(x y): ");
            scanf("%d %d", &p.x, &p.y);
        }
        if(check_hit_update_grid(ships, grid, p)){
            printf("Nice shot!!\n");
            grid[p.y-1][p.x-1] = 'x';
        }
        else{ 
            printf("Missed!!\n");  
            grid[p.y-1][p.x-1] = 'o'; 
            att--;
        }
        hit =  ships_hit(ships, grid); 
        if(hit == NO_OF_SHIPS){
            printf("You Won!!\n");
            return;
        }
    }
    if(hit == NO_OF_SHIPS)
        printf("You Won!!\n");
    else
        printf("You Lost!\n");
}