//
//  Grid.cpp
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include <stdio.h>
#include "Grid.h"

#include <iostream>
#include <random>
#include <ctime>
#include <math.h>

using namespace std;

Grid::Grid(){
    
}

Grid::~Grid(){
    
}

int Grid:: generate() {
    return rand() % 101;
}

//If neighbor is on grid and active, return 1. Otherwise return 0.
/**int Grid :: isActive(int x, int y, int row, int column, char grid[][]) {
    if (x > 0 && x < row && y > 0 && y < column) {
        if (grid[x][y] == 'x') {
            return 1;
        }
    }
    return 0;
}

//Takes in a coordinate. Checks each neighbor. If active, adds to count. Returns count.
int Grid :: countNeighbors(int x, int y, int row, int column, char grid[][]) {
    int neighborCount = 0;
    neighborCount += isActive(x--,y--, row, column, grid);
    neighborCount += isActive(x--,y, row, column, grid);
    neighborCount += isActive(x--,y++, row, column, grid);
    neighborCount += isActive(x,y++, row, column, grid);
    neighborCount += isActive(x++,y++, row, column, grid);
    neighborCount += isActive(x++,y, row, column, grid);
    neighborCount += isActive(x++,y--, row, column, grid);
    neighborCount += isActive(x,y--, row, column, grid);
    return neighborCount;
}**/
//create grid
void Grid::createGrid(int rows, int columns){
    grid = new char*[rows];
    for(int i = 0; i < rows; ++i){
        grid[i] = new char[columns];
    }
}

//add to grid
void Grid::gridAdd(){
    srand (time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (generate() <= density) {
                grid[i][j] = 'x';
            } else {
                grid[i][j] = '-';
            }
        }
        
    }
}
void Grid::printGrid(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

//create/update grid2
//rules (changes will be made to grid2)
void Grid::updateGrid2(int rows,int columns, int neighborCount){
    if  (neighborCount <= 1 || neighborCount >= 4){
        if (grid2[rows][columns] == 'x'){
            grid2[rows][columns] = '-';
        }
    }
    if (neighborCount == 3){
        if (grid2[rows][columns] == '-'){
            grid2[rows][columns] = 'x';
        }
    }
}

//copy grid2 to grid
void Grid::copyGrid(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = grid2[i][j];
        }
    }
}
