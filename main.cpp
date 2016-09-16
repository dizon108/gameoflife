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

    char grid[rows][columns];

    srand (time(NULL));

    cout << "Generated Random Numbers: " << '\n';
    for (int i = 0; i < 5; i++) {
    	int x = generate();
    	cout << x;
    	cout << '\n';
    }

    for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < columns; j++) {
    		grid[i][j] = 'x';
    	}
    }

    for (int i = 0; i < rows; i++) {
    	for (int j = 0; j < columns; j++) {
    		cout << grid[i][j];
    	}
    	cout << '\n';
    }


}
