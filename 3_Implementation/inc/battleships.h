/**
 * @file battleships.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
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
}ship;

/**
*  Updates the n'th line with given character c at coordinates x and y
* @param[in] grid 
* @param[in] n
* @param[in] c
* @param[in] x
* @param[in] y
* @brief Updates the n'th line with given character c at coordinates x and y
*/
void update_line(char **grid, int n, char c, int x, int y);

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

int check_collision(ship **ships, ship * s, int ship_no);

int check_hit(ship **ships, int x, int y);

ship* generate_ship(ship **ships, int ship_no);

void play_game();

#endif