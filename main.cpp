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
    



}
