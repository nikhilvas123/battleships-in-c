#include "test_battleships.h"
int dev = 1;
char grid[10][10];
int ship_sizes[5]={2,2,3,4,6};
ship *ships[5], *ships2[5];
pos *p;
/* Required by the unity test framework */
void setUp(){
    grid_init(grid);
}
/* Required by the unity test framework */
void tearDown(){}
/* Start of the application test */
int main(void)
{
  int i;
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();
  
/* Run Test functions */
  RUN_TEST(test_check_collision);
  RUN_TEST(test_check_collision_ships);
  RUN_TEST(test_ship_coordinates);
  RUN_TEST(test_check_collision_boundary);
  RUN_TEST(test_check_hit_update_grid);
//   RUN_TEST(test_generate_ship);
//   RUN_TEST(test_ships_hit);
//   RUN_TEST(test_check_valid_coordinate);

  /* Close the Unity Test Framework */
  for(i=0; i<5; i++)
    free(ships[i]);

  for(i=0; i<3; i++)
    free(ships2[i]);
  free(p);

  return UNITY_END();
}

void grid_init(char grid[10][10]){
    memset(grid,'.',100);

    /* Correct ship placement */
    ships[0] = (ship *)malloc(sizeof(ship));
    ships[0]->len = ship_sizes[0];
    ships[0]->p.x = 5;
    ships[0]->p.y = 0;
    ships[0]->o = RIGHT;
    ships[0]->hit = 1;

    ships[1] = (ship *)malloc(sizeof(ship));
    ships[1]->len = ship_sizes[1];
    ships[1]->p.x = 1;
    ships[1]->p.y = 2;
    ships[1]->o = RIGHT;
    ships[1]->hit = 0;

    ships[2] = (ship *)malloc(sizeof(ship));
    ships[2]->len = ship_sizes[2];
    ships[2]->p.x = 4;
    ships[2]->p.y = 3;
    ships[2]->o = RIGHT;
    ships[2]->hit = 0;

    ships[3] = (ship *)malloc(sizeof(ship));
    ships[3]->len = ship_sizes[3];
    ships[3]->p.x = 5;
    ships[3]->p.y = 1;
    ships[3]->o = LEFT;
    ships[3]->hit = 1;

    ships[4] = (ship *)malloc(sizeof(ship));
    ships[4]->len = ship_sizes[4];
    ships[4]->p.x = 0;
    ships[4]->p.y = 3;
    ships[4]->o = DOWN;
    ships[4]->hit = 0;
    
    /* Colliding ships*/
    ships2[0] = (ship *)malloc(sizeof(ship));
    ships2[0]->len = ship_sizes[0];
    ships2[0]->p.x = 5;
    ships2[0]->p.y = 2;
    ships2[0]->o = UP;
    ships2[0]->hit = 0;

    ships2[1] = (ship *)malloc(sizeof(ship));
    ships2[1]->len = ship_sizes[1];
    ships2[1]->p.x = 5;
    ships2[1]->p.y = 2;
    ships2[1]->o = UP;
    ships2[1]->hit = 0;

    /* Ships out of bound */
    ships2[2] = (ship *)malloc(sizeof(ship));
    ships2[2]->len = ship_sizes[2];
    ships2[2]->p.x = 15;
    ships2[2]->p.y = 15;
    ships2[2]->o = RIGHT;
    ships2[2]->hit = 0;

    grid_show_ships(grid,ships);

    /* HITS */
    /* Ship 1*/
    grid[0][5] = 'x';
    grid[0][6] = 'x';
    
    /* Ship 3*/
    grid[3][4] = 'x';

    /* Ship 4*/
    grid[1][2] = 'x';
    grid[1][3] = 'x';
    grid[1][4] = 'x';
    grid[1][5] = 'x';
    /* Ship 5*/
    grid[5][0] = 'x';
    grid[8][0] = 'x';

    /* MISSES */
    grid[9][9] = 'o';
    grid[8][9] = 'o';
    grid[3][7] = 'o';
    grid[2][3] = 'o';

}

/* Write all the test functions */ 
void test_check_collision(){
    print_grid(grid);
    TEST_ASSERT_EQUAL(0, check_collision(ships, ships[0],0));
    TEST_ASSERT_EQUAL(0, check_collision(ships, ships[1],1));
    TEST_ASSERT_EQUAL(0, check_collision(ships, ships[2],2));
    TEST_ASSERT_EQUAL(0, check_collision(ships, ships[3],3));
    TEST_ASSERT_EQUAL(0, check_collision(ships, ships[4],4));
    TEST_ASSERT_EQUAL(1, check_collision(ships2, ships2[1],1));
    TEST_ASSERT_EQUAL(1, check_collision(ships2, ships2[2],1));    
}

void test_check_collision_ships(){
    TEST_ASSERT_EQUAL(0, check_collision_ships(ships, ships[0],0));
    TEST_ASSERT_EQUAL(0, check_collision_ships(ships, ships[1],1));
    TEST_ASSERT_EQUAL(0, check_collision_ships(ships, ships[2],2));
    TEST_ASSERT_EQUAL(0, check_collision_ships(ships, ships[3],3));
    TEST_ASSERT_EQUAL(0, check_collision_ships(ships, ships[4],4));
    TEST_ASSERT_EQUAL(1, check_collision_ships(ships2, ships2[1],1));
}

void test_ship_coordinates(){
    p = (pos *)malloc(sizeof(pos) * 2);
    pos *temp;
    p[0].x = 5;
    p[0].y = 0;
    p[1].x = 6;
    p[1].y = 0;
    TEST_ASSERT_EQUAL_MEMORY(p, temp = ship_coordinates(ships[0]), sizeof(pos)*2);
    free(temp);
    p[0].x = 2;
    p[0].y = 1;
    p[1].x = 5;
    p[1].y = 1;
    TEST_ASSERT_EQUAL_MEMORY(p, temp = ship_coordinates(ships[3]), sizeof(pos)*2);
    free(temp);
    p[0].x = 0;
    p[0].y = 3;
    p[1].x = 0;
    p[1].y = 8;
    TEST_ASSERT_EQUAL_MEMORY(p, temp = ship_coordinates(ships[4]), sizeof(pos)*2);
    free(temp);
    p[0].x = 5;
    p[0].y = 1;
    p[1].x = 5;
    p[1].y = 2;
    TEST_ASSERT_EQUAL_MEMORY(p, temp = ship_coordinates(ships2[0]), sizeof(pos)*2);
    free(temp);
}

void test_check_collision_boundary(){
    TEST_ASSERT_EQUAL(0, check_collision_boundary(ships[0]));
    TEST_ASSERT_EQUAL(0, check_collision_boundary(ships[1]));
    TEST_ASSERT_EQUAL(0, check_collision_boundary(ships[2]));
    TEST_ASSERT_EQUAL(0, check_collision_boundary(ships[3]));
    TEST_ASSERT_EQUAL(0, check_collision_boundary(ships[4]));
    TEST_ASSERT_EQUAL(1, check_collision_boundary(ships2[2]));
}

void test_check_hit_update_grid(){
    pos p;
    p.x = 3;
    p.y = 3;
    TEST_ASSERT_EQUAL(1, check_hit_update_grid(ships,grid,p));
    TEST_ASSERT_EQUAL('x',grid[p.y - 1][p.x - 1]);
    p.x = 2;
    TEST_ASSERT_EQUAL(1, check_hit_update_grid(ships,grid,p));
    TEST_ASSERT_EQUAL('x',grid[p.y - 1][p.x - 1]);
    TEST_ASSERT_EQUAL(1,ships[1]->hit);
    grid_init(grid);
    p.x = 8;
    p.y = 6;
    TEST_ASSERT_EQUAL(0, check_hit_update_grid(ships,grid,p));
    TEST_ASSERT_EQUAL('o',grid[p.y-1][p.x-1]);
}

void test_generate_ship(){

}

void test_ships_hit(){

}

void test_check_valid_coordinate(){

}