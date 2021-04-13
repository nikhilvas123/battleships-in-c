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
 * Create a user defined datatype for menu options
 * @brief Create a user defined datatype for menu options
 * 
 */
typedef enum option{
    EXIT = 2,
    START = 1,
}option;

typedef enum orientation{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
}orientation;

typedef struct pos{
    int x;
    int y;
}pos;

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
*  Prints the grid
* @param[in] grid 
* @brief Prints the griod
*/
void print_grid(const char grid[10][10]);

void print_ship(ship* s);

int check_collision(ship **ships, ship * s, int ship_no);

int check_collision_ships(ship **ships, ship *s, int ship_no);

pos *ship_coordinates(ship *s);

int check_collision_boundary(ship *s);

int check_hit_update_grid(ship **ships, char grid[10][10], pos p);

ship* generate_ship(ship **ships, int ship_no);

void grid_show_ships(char gird[10][10], ship **ships);

int check_valid_coordinate(char grid[10][10], pos p);

void play_game();

#endif