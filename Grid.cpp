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
    while(getline(gameFile, line)){
        int i = 0;
        char *cstr = new char[line.length() + 1];
        grid[i] = strcpy(cstr, line.c_str());
        ++i;
    }
}
//add to grid
void Grid::gridAdd(int density){
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

void Grid::selectInput(){
    cout << "Select input mode:" <<endl;
    cout << "1. Random configuration"<<endl;
    cout<<"2. Flatfile configuration"<<endl;
    cout<<"Enter number: ";
    cin >> input;
}
void Grid::gridModif(){
    //how to get to next generation
    cout <<"How do you want to proceed to the next generation?" << endl;
    cout << "1. Press 'enter'"<<endl;
    cout << "2. Generate automatically"<<endl;
    cout << "3. Output to file"<<endl;
    cout << "Enter number: ";
    cin >> proceed;
    
    //mode selection
    cout<<"Select a mode:"<<endl;
    cout<<"1. Classic"<<endl;
    cout<<"2. Doughnut"<<endl;
    cout<<"3. Mirror"<<endl;
    cout<<"Enter number: ";
    cin >> mode;
}
void Grid::gamePrompt1(){
    //if random configuration
        cout << "World Conditions: Enter a number" << endl;
        cout << "Rows: ";
        cin >> rows ;
        cout << "Columns: ";
        cin >> columns;
        cout << "Density (enter a decimal value greater than 0 and less than 1): ";
        cin >> density;
        density = round(density*100);
    gridModif();
    createGrid();
    gridAdd(density);
    
}
void Grid:: gamePrompt2(){
    cout << "Enter file name: ";
    cin >> fileName;
    gridModif();
    createGrid2(fileName);
    
}

void Grid::gameOfLife(){
    selectInput();
    if(input == 1){
        gamePrompt1();
    }
    else if(input ==2){
        gamePrompt2();
    }
    int generation = 0;
    cout << "Generation: " + to_string(generation)<< endl;
    printGrid();
    createTempGrid();
    generation = 1;
    while(true){
        countNeighbors();
        if (!isEqual()) {
            copyTemp();
            if (proceed == 1){
                cin.ignore();
                cout<<"Generation " + to_string(generation)<<endl;
                printGrid();
            }
            else if(proceed == 2){
                this_thread::sleep_for(chrono::seconds(1));
                cout<<"Generation: " + to_string(generation)<<endl;
                printGrid();
            }
            generation++;
        } else {
            cout << "Done. Press enter to exit the program." <<endl;
            cin.ignore();
            break;
        }
    }
    
}
