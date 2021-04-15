#include "test_battleships.h"
int dev = 0;
char grid[10][10];
int ship_sizes[5]={2,2,3,4,6};

/* Required by the unity test framework */
void setUp(){
    grid_init(grid);
    grid[0][0] = 'x';
    grid[9][9] = 'o';

    ship* ships[5];

    ships[0] = (ship *)malloc(sizeof(ship));
    ships[0]->len = ship_sizes[0];
    ships[0]->p.x = 0;
    ships[0]->p.y = 0;
    ships[0]->o = RIGHT;
    ships[0]->hit = 0;

    ships[1] = (ship *)malloc(sizeof(ship));
    ships[1]->len = ship_sizes[0];
    ships[1]->p.x = 0;
    ships[1]->p.y = 0;
    ships[1]->o = RIGHT;
    ships[1]->hit = 0;

    ships[2] = (ship *)malloc(sizeof(ship));
    ships[2]->len = ship_sizes[0];
    ships[2]->p.x = 0;
    ships[2]->p.y = 0;
    ships[2]->o = RIGHT;
    ships[2]->hit = 0;

    ships[3] = (ship *)malloc(sizeof(ship));
    ships[3]->len = ship_sizes[0];
    ships[3]->p.x = 0;
    ships[3]->p.y = 0;
    ships[3]->o = RIGHT;
    ships[3]->hit = 0;

    ships[4] = (ship *)malloc(sizeof(ship));
    ships[4]->len = ship_sizes[0];
    ships[4]->p.x = 0;
    ships[4]->p.y = 0;
    ships[4]->o = RIGHT;
    ships[4]->hit = 0;
}
/* Required by the unity test framework */
void tearDown(){}
/* Start of the application test */
int main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_check_collision);
//   RUN_TEST(test_check_collision_ships);
//   RUN_TEST(test_ship_coordinates);
//   RUN_TEST(test_check_collision_boundary);
//   RUN_TEST(test_check_hit_update_grid);
//   RUN_TEST(test_generate_ship);
//   RUN_TEST(test_ships_hit);
//   RUN_TEST(test_check_valid_coordinate);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

void grid_init(char grid[10][10]){
    memset(grid,'.',100);
}

/* Write all the test functions */ 
void test_check_collision(){
    TEST_ASSERT_EQUAL(1,1); 
}

void test_check_collision_ships(){

}

void test_ship_coordinates(){

}

void test_check_collision_boundary(){

}

void test_check_hit_update_grid(){

}

void test_generate_ship(){

}

void test_ships_hit(){

}

void test_check_valid_coordinate(){

}