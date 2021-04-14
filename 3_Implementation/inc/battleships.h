/**
 * @file battleships.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief Classic Battleships Game
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * Batttle ships game on CLI
 */

#ifndef __BATTLESHIPS_H__
#define __BATTLESHIPS_H__

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/**
 * 
 * @brief User defined datatype for menu options
 * @details Option 1 to Start, Option 2 to exit
 */
typedef enum option{
    EXIT = 2,
    START = 1,
}option;

/**
 * @brief User defined datatype for different orientation of ships
 * @details Option 0 for UP, Option 1 for DOWN, Option 2 for LEFT, Option 3 for RIGHT
 */
typedef enum orientation{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
}orientation;

/**
 * @brief Structure for postion of ship
 * @details Stores x,y coordinates
 */
typedef struct pos{
    int x;
    int y;
}pos;


/**
 * @brief Structure for ship
 * @details Contains pos structure, length, orientation, and hit which denotes if ship is all hit
 */
typedef struct ship{
    pos p;
    int len;
    orientation o;
    int hit;
}ship;

/**
*  Prints the game menu
* @brief Prints the game menu
*/
void print_menu();

/**
* @brief Prints the griod
* @param[in] grid 
* 
*/
void print_grid(const char grid[10][10]);


/**
 * @brief Prints the description of ship
 * 
 * @param[in] s 
 */
void print_ship(ship* s);

/**
 * @brief Checks for ship collision with other ships and boundary
 * 
 * @param[in] ships 
 * @param[in] s 
 * @param[in] ship_no 
 * @return Returns 1 if ship has collision with boundary or other ships, else 0 
 */
int check_collision(ship **ships, ship * s, int ship_no);

/**
 * @brief Checks for ship collision with other ships
 * 
 * @param[in] ships 
 * @param[ib] s 
 * @param[ib] ship_no 
 * @return Returns 1 if ship has collision with other ships, else 0 
 */
int check_collision_ships(ship **ships, ship *s, int ship_no);

/**
 * @brief Returns the start and end of ship coordinates
 * 
 * @param[in] s 
 * @return Returns a pointer to array of pos which contains the start and end location of ships 
 */
pos *ship_coordinates(ship *s);

/**
 * @brief Checks for ship collision with boundary
 * 
 * @param[in]] s 
 * @return Returns 1 if ship has collision with boundary, else 0 
 */
int check_collision_boundary(ship *s);

/**
 * @brief Checks if the given coorinates has hit the ship or not. If hit, update grid. Update ship if it has been all hit
 * 
 * @param[in] ships 
 * @param[in] grid 
 * @param[in] p 
 * @return Return 1 if the given coordinates hit the ship, else 0 
 */
int check_hit_update_grid(ship **ships, char grid[10][10], pos p);

/**
 * @brief Creates a ship with random coordinates and orientaiton
 * 
 * @param[in] ships 
 * @param[in] ship_no 
 * @return Returns a pointer to ship created 
 */
ship* generate_ship(ship **ships, int ship_no);

/**
 * @brief Shows ship in grid as '^' instead of '.' in dev mode
 * 
 * @param[in] gird 
 * @param[in] ships 
 */
void grid_show_ships(char gird[10][10], ship **ships);

/**
 * @brief Checks the number of ships hit
 * 
 * @param[in] ships 
 * @param[in] grid 
 * @return Returns the number of ships hit 
 */
int ships_hit(ship **ships, char grid[10][10]);

/**
 * @brief Checks if the input position(x,y) is valid i.e within boundary or if the location is already compromised
 * 
 * @param[in] grid 
 * @param[in] p 
 * @return Returns 1 if the coordinate is valid 
 */
int check_valid_coordinate(char grid[10][10], pos p);

/**
 * @brief Calls all other functions accordigly
 * 
 */
void play_game();

#endif