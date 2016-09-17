
//
//  main.cpp
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include "Grid.h"
#include <iostream>
#include <random>
#include <ctime>
#include <math.h>

using namespace std;

int generate() {
    return rand() % 101;
}

// These two methods would save lives for neighborCount operation, I'll leave them up for now.
/*
 //If neighbor is on grid and active, returns 1. Otherwise, returns 0.
 int isActive(int x, int y, int row, int column, char grid[][]) {
	if (x > 0 && x < row && y > 0 && y < column) {
 if (grid[x][y] == 'x') {
 return 1;
 }
	}
	return 0;
 }
 //Takes in a coordinate. Checks each neighbor. If active, adds to count. Returns count.
 int countNeighbors(int x, int y, int row, int column, char grid[][]) {
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
 }
 */

int main(int argc, const char * argv[]) {
    int rows;
    int columns;
    double density;
    cout << "What dimensions would you like your world to be in?" << endl;
    cout << "Rows: ";
    cin >> rows ;
    cout << "Columns: ";
    cin >> columns;
    cout << "Desnity: ";
    cin >> density;
    density = round(density*100);
    
    char grid[rows][columns];
    char tempGrid[rows][columns];
    
    srand (time(NULL));
    
    // Iniatlizes the grid representing the initial population density
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (generate() <= density) {
                grid[i][j] = 'x';
            } else {
                grid[i][j] = '-';
            }
        }
    }
    
    // Prints grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    //this is here for testing purposes
    cout<<'\n';
    cout<<"temporary grid"<<endl;
    
    //Counts the neighbors of each Cell
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int neighborCount = 0;
            int pseudoI = i;
            int pseudoJ = j;
            if (pseudoI-1 >= 0 && pseudoI-1 < rows && pseudoJ-1 >= 0 && pseudoJ-1 < columns) {
                if (grid[pseudoI-1][pseudoJ-1] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI-1 >= 0 &&pseudoI-1< rows && pseudoJ >= 0 && pseudoJ < columns) {
                if (grid[pseudoI-1][pseudoJ] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI-1 >= 0 && pseudoI-1 < rows && pseudoJ+1 >= 0 && pseudoJ+1 < columns) {
                if (grid[pseudoI-1][pseudoJ+1] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI >= 0 && pseudoI < rows && pseudoJ+1 >= 0 && pseudoJ+1 < columns) {
                if (grid[pseudoI][pseudoJ+1] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI+1 >= 0 && pseudoI+1 < rows && pseudoJ+1 >= 0 && pseudoJ+1 < columns) {
                if (grid[pseudoI+1][pseudoJ+1] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI+1 >= 0 && pseudoI+1 < rows && pseudoJ >= 0 && pseudoJ < columns) {
                if (grid[pseudoI+1][pseudoJ] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI+1 >= 0 && pseudoI+1 < rows && pseudoJ-1 >= 0 && pseudoJ-1 < columns) {
                if (grid[pseudoI+1][pseudoJ-1] == 'x') {
                    neighborCount++;
                }
            }
            if (pseudoI >= 0 && pseudoI < rows && pseudoJ-1 >= 0 && pseudoJ-1 < columns) {
                if (grid[pseudoI][pseudoJ-1] == 'x') {
                    neighborCount++;
                }
            }
            //REESE: neighborCount here will equal the correct amount of 
            //neighbors that the cell grid[i][j] has.
            //If you want to test uncomment this line:
            //cout << " " << neighborCount << " ";
    
        //creates temporary grid
            if  (neighborCount <= 1 ){
                if (grid[i][j] == 'x'){
                    tempGrid[i][j] = '-';
                }
                else if (grid[i][j] == '-'){
                    tempGrid[i][j] = '-';
                }
            }
            if (neighborCount == 2){
                if (grid[i][j] == '-'){
                    tempGrid[i][j] = '-';
                }
                else if (grid[i][j] == 'x'){
                    tempGrid[i][j] = 'x';
                }
            }
            if (neighborCount == 3){
                if (grid[i][j] == '-'){
                    tempGrid[i][j] = 'x';
                }
                else if (grid[i][j] == 'x'){
                    tempGrid[i][j] = 'x';
                }
            }
            if  (neighborCount >= 4){
                if (grid[i][j] == 'x'){
                    tempGrid[i][j] = '-';
                }
                else if (grid[i][j] == '-'){
                    tempGrid[i][j] = '-';
                }
            }
            //for testing purposes. uncomment to see temporary grid
            //cout << tempGrid[i][j];
        }
        cout << '\n';
    }

    
}
