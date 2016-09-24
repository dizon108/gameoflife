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
#include <random>
#include <ctime>
#include <math.h>

using namespace std;

Grid::Grid(){
    
}

Grid::~Grid(){
    
}
Grid::Grid(int r, int col, int density) {
    rows = r;
    columns = col;
    createGrid();
    gridAdd(density);
    printGrid();
}

int Grid:: generate() {
    return rand() % 101;
}


//create grid
void Grid::createGrid(){
    grid = new char*[rows];
    //CREATES ARRAY TO HOLD REFLECTION/DONUT NEIGHBORS FOR TOP&BOT OF GRID
    topBot = new int*[2];
    cout << '\n';
    topBot[0] = new int[columns];
    topBot[1] = new int[columns];
    for (int i = 0; i < 2; i++) {
    	for (int j = 0; j < columns; j++) {
    		topBot[i][j] = 0;
    		cout << topBot[i][j];
    	}
    	cout << '\n';
    }
    //CREATES ARRAY TO HOLD REFLECTION/DONUT NEIGHBORS FOR SIDES OF GRID
    sides = new int*[columns];
    for (int i = 0; i < columns; i++) {
    	sides[i] = new int[2];
    }
    for (int i = 0; i < columns; i++) {
    	for (int j = 0; j < 2; j++) {
    		sides[i][j] = 0;
    		cout << sides[i][j];
    	}
    	cout << '\n';
    }


    for(int i = 0; i < rows; ++i){
        grid[i] = new char[columns];
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

void Grid::updateTopBotMirror(int currentRow, int tB) {
	if (grid[currentRow][0] == 'x') {
		topBot[tB][0] += 3;
		topBot[tB][1]++;
	}
	for (int i = 1; i < columns-1; i++) {
		int temp = i;
		if (grid[currentRow][i] == 'x') {
			topBot[tB][temp-1]++;
			topBot[tB][i]++;
			topBot[tB][temp+1]++;
		}
	}
	if (grid[currentRow][columns-1] == 'x') {
		topBot[tB][columns-1]+= 3;
		topBot[tB][columns-2]++;
	}
}

void Grid::clearMirror() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < columns; j++) {
			topBot[i][j] = 0;
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < 2; j++) {
			sides[i][j] = 0;
		}
	}
}

void Grid::updateSidesMirror(int currentCol, int lR) {
	if (grid[0][currentCol] == 'x') {
		sides[0][lR] += 3;
		sides[1][lR]++;
	}
	for (int i = 1; i < rows-1; i++) {
		int temp = i;
		if (grid[i][currentCol] == 'x') {
			sides[temp-1][lR]++;
			sides[i][lR]++;
			sides[temp+1][lR]++;
		}
	}
	if (grid[rows-1][currentCol] == 'x') {
		sides[rows-1][lR]+= 3;
		sides[rows-2][lR]++;
	}
}

// Prints the current "reflection" neighbors of the edge cells.
void Grid::printMirror(){
	for (int i = 0; i < 2; i++) {
       	for (int j = 0; j < columns; j++) {
            cout << topBot[i][j];
        }
        cout << '\n';
    }
    cout << '\n';
    for (int i = 0; i < rows; i++) {
       	for (int j = 0; j < 2; j++) {
            cout << sides[i][j];
        }
        cout << '\n';
    }
}

void Grid::tempGridAdd(int rows, int columns, int neighborCount){
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
    	if (i == 0) {

    	}
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

void Grid::gameOfLife(){
    cout << "World Conditions: Enter a number" << endl;
    cout << "Rows: ";
    cin >> rows ;
    cout << "Columns: ";
    cin >> columns;
    cout << "Density (enter a decimal value greater than 0 and less than 1): ";
    cin >> density;
    density = round(density*100);
    
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
    
    createGrid();
    gridAdd(density);
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
                updateTopBotMirror(0,0);
            	updateTopBotMirror(rows-1, 1);
            	updateSidesMirror(0,0);
            	updateSidesMirror(columns-1, 1);
            	int topLeft = (topBot[0][0]%3);
				int topRight = (topBot[0][columns-1]%3);
				int botLeft = (topBot[1][0]%3);
				int botRight = (topBot[1][columns-1]%3);
	
				sides[0][0] += topLeft;
				sides[0][1] += topRight;
				sides[rows-1][0] += botLeft;
				sides[rows-1][1] += botRight;

				topBot[0][0] = sides[0][0];
				topBot[0][columns-1] = sides[0][1];
				topBot[1][0] = sides[rows-1][0];
				topBot[1][columns-1] = sides[rows-1][1];
            	printMirror();
            	clearMirror();
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
