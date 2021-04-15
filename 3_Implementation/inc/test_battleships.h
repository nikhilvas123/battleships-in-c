/**
 * @file test_battleships.h
 * @author Nikhil Nevin Vas (nikhilvas123@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-15
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef __TEST_BATTLESHIPS_H__
#define __TEST_BATTLESHIPS_H__

#include "battleships.h"
#include "unity.h"

/* Prototypes for all the test functions */
void test_check_collision();

void test_check_collision_ships();

void test_ship_coordinates();

void test_check_collision_boundary();

void test_check_hit_update_grid();

void test_generate_ship();

void test_ships_hit();

void test_check_valid_coordinate();

#endif