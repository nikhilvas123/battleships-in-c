#include "test_battleships.h"

int dev = 0;

char grid[10][10];
// memset(grid,'.',10*10);
// grid[0][0] = 'x';
// grid[9][9] = 'o';

// ship* ships[5];
// ships[0] = (ship *)malloc(sizeof(ship));
// ships[0]->len = SHIP_SIZES[0];
// ships[0]->p.x = 0;
// ships[0]->p.y = 0;
// ships[0]->o = RIGHT;
// ships[0]->hit = 0;

/* Required by the unity test framework */
void setUp(){}
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