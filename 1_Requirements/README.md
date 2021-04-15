# Requirements
## Introduction
 * An implementation of battleships game in C.
 * This topic was chosen because it gives me an opportunity to implement efficient data. structures and provides me flexibilty to understand multiple C programming concepts.

## Research
Battleship is known worldwide as a pencil and paper game which dates from World War I. It was published by various companies as a pad-and-pencil game in the 1930s, and was released as a plastic board game by Milton Bradley in 1967. The game has spawned electronic versions, video games, smart device apps and a film. This game is also available on PS2 and Wii which suggests many kids are interested in this game.

## Cost and Features
### Cost
* Requires little or no money.
* Requires few people working on the project.

### Features
* *Menu*: Shows the game menu.
  * *New game*: Starts a new game.
  * *Quit*: Quits the game.
* Game screen consisting of 10x10 gird of '.' (dot).
* Input from player for coordinates.
* Grid updates after each input.
* Can run as developer mode.

## Defining The System

![Description](https://github.com/nikhilvas123/battleships-in-c/blob/main/1_Requirements/system.png?w=500&h=500&q=100)

### Explanation:
* Input block takes input from keyboard.
* Game instance performs i/o and incorporates game logic.
* Output block prints output on console.

## SWOT ANALYSIS
![SWOT Analysis](https://github.com/nikhilvas123/battleships-in-c/blob/main/1_Requirements/swot.png?w=500&h=500&q=100)

# 4W&#39;s and 1&#39;H

## Who:
* Kids aged 12+

## What:
* Kids love games and waste time. This game helps the kid to gain insgiht in logical thinking.

## When:
* Recent studies show many kids wasting time playing games.

## Where:
* Based on survey, video games are ubiquitous.

## How:
* Parents always complain about their kids about playing video games, and this is a global problem.

# Detail requirements
## High Level Requirements: 
| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | Menu Screen | Techincal | Implemented | 
| HR02 | Grid Display | Techincal | Implemented |
| HR03 | Coordinate input from user | Techincal | Implemented |
| HR04 | Can take argument to run the game in development mode | Techincal | Implemented |
| HR05 | User can restart the game or quit | Techincal | Implemented |
| HR06 | Implement GUI | Techincal | Future |
| HR07 | Implement 2 player | Technical | Future |
| HR08 | Add sound effects | Technical | Future|
##  Low level Requirements:
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LR01 | Menu screen options are Start game, Quit  | HR01 | Implemented  |
| LR02 | Displays '.' after starting the game, 'x' for correct hit, 'o' for miss hit| HR02 | Implemented |
| LR03 | User inputs x,y coordinates when promted with space in between | HR03 | Implemented |
| LR04 | While running use "dev" as command line argument | HR04 | Implemented |
| LR05 | After finishing the game, user can play again or quit. Waits for input from user | HR05 | Implemented  |
| LR06 | Use GTK for gui based application | HR06 | Future  |
| LR07 | Modify the code to support 2 player game, where players can palce the ships or randomize them | HR07 | Future |
| LR08 | Use library to play sound effects during hit or miss | HR08 | Future |