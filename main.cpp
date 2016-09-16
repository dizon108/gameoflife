//
//  main.cpp
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

//#include "Grid.h"
#include <iostream>
#include <random>
#include <ctime>
#include <math.h>

using namespace std;

int generate() {
    return rand() % 101;
}

//int countNeighbors

int main(int argc, const char * argv[]) {
   //prompt user
    int rows;
    int columns;
    double density;
    cout << "World Conditions: Enter a number" << endl;
    cout << "Rows: ";
    cin >> rows ;
    cout << "Columns: ";
    cin >> columns;
    cout << "Density (enter a decimal value greater than 0 and less than 1): ";
    cin >> density;
    density = round(density*100);
    
    //how to get to next generation
    int proceed;
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
    cin >> mode;
    
    //grid and grid copy
    char grid[rows][columns];
    char grid2[rows][columns];
    
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
    
    //create/update grid2
    /**  //rules (changes will be made to grid2)
     int neighbors = 0;
     if  (neighbors <= 1 || > = 4){
     if grid2[i][j] = 'x'{
     grid2[i][j] = '-';
     }
     }
     if (neighbors == 3){
     if grid[i][j] = '-'{
     grid2[i][j] = 'x';
     }
     }
     if (neighbors >= 4){
     if grid2[i][j] = '-'{
     grid2[i][j] = 'x';
     }
     }
     
     
     //next generation**/
    //copy grid2 to grid
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = grid2[i][j];
        }
    }
    //print updated grid
}






