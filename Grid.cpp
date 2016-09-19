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
    /**for(int i = 0; i< rows; ++i){
        for(int j = 0; j < rows; ++j ){
            grid[i][j] = '-';
        }
    }**/
}

//add to grid
void Grid::gridAdd(){
    srand(time(NULL));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (generate() <= density) {
                grid[i][j] = 'x';
            } else {
                grid[i][j] = '-';
            }
        }
        
    }
}
void Grid::printGrid(){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
}
void Grid::duplicateGrid(){
    tempGrid = new char*[rows];
    for(int i = 0; i < rows; ++i){
        tempGrid[i] = new char[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tempGrid[i][j] = grid[i][j];
            
        }
        
    }

}
int Grid::countNeighbors(){ //counts and created temp grid
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
        
    }return neighborCount;
}
/**void Grid::tempGridAdd(int rows, int columns, int neighborCount){
            if  (neighborCount <= 1 ){
                if (grid[rows][columns] == 'x'){
                    tempGrid[rows][columns] = '-';
                }
                else if (grid[rows][columns] == '-'){
                    tempGrid[rows][columns] = '-';
                }
            }
            if (neighborCount == 2){
                if (grid[rows][columns] == '-'){
                    tempGrid[rows][columns] = '-';
                }
                else if (grid[rows][columns] == 'x'){
                    tempGrid[rows][columns] = 'x';
                }
            }
            if (neighborCount == 3){
                if (grid[rows][columns] == '-'){
                    tempGrid[rows][columns] = 'x';
                }
                else if (grid[rows][columns] == 'x'){
                    tempGrid[rows][columns] = 'x';
                }
            }
            if  (neighborCount >= 4){
                if (grid[rows][columns] == 'x'){
                    tempGrid[rows][columns] = '-';
                }
                else if (grid[rows][columns] == '-'){
                    tempGrid[rows][columns] = '-';
                }
            }
            //for testing purposes. uncomment to see temporary grid
            //cout << tempGrid[i][j];
}**/


void Grid:: copyTemp(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = tempGrid[i][j];
            
        }
        
    }
}

void Grid::run(){
    cout << "World Conditions: Enter a number" << endl;
    cout << "Rows: ";
    cin >> rows ;
    cout << "Columns: ";
    cin >> columns;
    cout << "Density (enter a decimal value greater than 0 and less than 1): ";
    cin >> density;
    density = round(density*100);
    
    //how to get to next generation
   /** int proceed;
    cout <<"How do you want to proceed to the next generation?" << endl;
    cout << "1. Press 'enter'"<<endl;
    cout << "2. Generate automatically"<<endl;
    cout << "3. Output to file"<<endl;
    cout << "Enter number: ";
    cin >> proceed;
    
    //mode selection
    int mode;
    cout<<"Select a mode:"<<endl;
    cout<<"1. Classic"<<endl;
    cout<<"2. Doughnut"<<endl;
    cout<<"3. Mirror"<<endl;
    cout<<"Enter number: ";
    cin >> mode;**/
    
    createGrid(rows,columns);
    gridAdd();
    printGrid();
    duplicateGrid();
    countNeighbors();
    //tempGridAdd();
    copyTemp();
    cout<<"new gen: "<<endl;
    printGrid();
    
    
}
