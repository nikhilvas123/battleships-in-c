## SDLC based implementation of Battleships game

A simple implementation of the classic Batleships game. There is a grid of 10x10. There are 5 ships in total.
#### The dimensions are
Ship size  |Number of ships 
-----------|---------------
2          |2           
3          |1           
4          |1           
6          |1           

The computer places all the ships at random in any orientation. The player has to hit all the ships (guess the location of all the ships). Correct hit will be denoted as 'x', miss hit will be denoted as 'o'.

   ![Battleships](https://github.com/nikhilvas123/battleships-in-c/blob/main/1_Requirements/battleships.png?w=500&h=500&q=100)

## How to build
1. make
2. make run (Normal Mode)
3. make dev (Development Mode)

Development mode shows all the ships as '^' while playing.

Build | Code Quality | Unity | Git Instpector 
|-----|--------------|-------|----------------
[![C/C++ CI](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/c-cpp.yml)|[![Static Check](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/arc-cppcheck.yml/badge.svg)](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/arc-cppcheck.yml) [![Dynamic Code Check](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/dynamic-code-check.yml/badge.svg)](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/dynamic-code-check.yml) [![Codacy Badge](https://app.codacy.com/project/badge/Grade/40bc107218b441f5b104fe14d08c92b5)](https://www.codacy.com/gh/nikhilvas123/battleships-in-c/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=nikhilvas123/battleships-in-c&amp;utm_campaign=Badge_Grade) [![CI-Coverage](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/ci-coverage.yml/badge.svg)](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/ci-coverage.yml) | [![Unit Testing - Unity](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/unit-testing.yml/badge.svg)](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/unit-testing.yml) | [![Git Inspector CI](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/arc-gitinspector.yml/badge.svg)](https://github.com/nikhilvas123/battleships-in-c/actions/workflows/arc-gitinspector.yml) | 

## Folder Structure
Folder               | Description
---------------------| -----------------------------------------
`1_Requirements`     | Documents detailing requirements and research
`2_Architecture`     | Documents specifying design and architecture details
`3_Implementation`   | All code and documentation
`4_TestPlanAndOutput`| Documents with test plans and procedures
`5_Report`           | Report documents
`6_ImagesAndVideos`  | Reference images and videos
`7_Other`            | Other details

## Contributors List and Summary

SF Id. |  Name   |    Features    | Issuess Raised |Issues Resolved|No Test Cases|Test Case Pass
-------|---------|----------------|----------------|---------------|-------------|--------------
`258149` | Nikhil Nevin Vas  | All features   | 3    | 2   |8   |8     
   

## Challenges Faced and How Was It Overcome

1. Found it hard to specify array size of grid variable. As of now hard coded it to a constant.
2. Faced multiple problems when integrating all the functions together. Used printf statements, and debugger to solve these issues.
3. Found hard to debug memory leak.
