//
//  Grid.cpp
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include <stdio.h>
#include "Grid.h"
#include <thread>
#include <chrono>

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <math.h>
#include <cstdlib>
#include <limits>

using namespace std;

Grid::Grid(){
    
}

Grid::~Grid(){
    
}
Grid::Grid(int r, int col, double d, int m, int p) {
    rows = r;
    columns = col;
    density = d;
    mode = m;
    proceed = p;
    createGrid();
    gridAdd(density);
}
Grid::Grid(string fileName, int m, int p){
    createGrid2(fileName);
    mode = m;
    proceed = p;
}

int Grid:: generate() {
    return rand() % 101;
}


//create grid
void Grid::createGrid(){
    grid = new char*[rows];
    for(int i = 0; i < rows; ++i){
        grid[i] = new char[columns];
    }
}

void Grid::createGrid2(string fileName){
    ifstream gameFile(fileName);
    getline(gameFile, line);
    rows = stoi(line); //stoi converts string to int
    getline(gameFile,line);
    columns = stoi(line);
    createGrid();
    for (int i = 0; i < rows; ++i){
        if(gameFile >> line){
            for(int j = 0; j < columns; ++j){
                grid[i][j] = line[j];
            }
        }else break;
    }
}
//add to grid
void Grid::gridAdd(double density){
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

void Grid::printGrid(){ //prints the grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << grid[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
}
void Grid::createTempGrid(){ //creates memory allocation for temporary grid
    tempGrid = new char*[rows];
    for(int i = 0; i < rows; ++i){
        tempGrid[i] = new char[columns];
    }

}
void Grid::countNeighbors(){ //counts and creates temp grid
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
            tempGridAdd(i,j,neighborCount);
        }
        
    }
}
void Grid::tempGridAdd(int rows, int columns, int neighborCount){ //updates grid after counting neighbors
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
}


void Grid:: copyTemp(){ //copy's temporary grid and makes it the new grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            grid[i][j] = tempGrid[i][j];
            
        }
        
    }
}

bool Grid::isEqual(){
    for(int i = 0; i < rows; ++i){
        for(int j=0; j < columns; ++j){
            if(grid[i][j] != tempGrid[i][j]){
                return false;
            }
        }
    }
    return true;
}

//if edge cell
void Grid::updateNeighbors(){
    for(int i = 0; i < rows; ++i){
        if(grid[i][0] || grid[i][rows-1]){
            //do stuff
            //+= countNeighbors() ?? this'll depend on what your doughnut/mirror method returns
        }else{
            countNeighbors();
        }
    }
    for(int i = 0; i < columns; ++i){
        if(grid[0][i] || grid[columns-1][i]){
            //do stuff
            //+= countNeighbors() ?? this'll depend on what your doughnut/mirror method returns
        }else{
            countNeighbors();
        }
    }
}



    

