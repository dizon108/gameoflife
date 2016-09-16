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

//If neighbor is off grid, 
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

    //New Generation
    for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < columns; j++) {
    		int x = 0;
    		x = countNeighbors(i, j, rows, columns, grid) {
    	}
    	cout << '\n';
    }
}
}

