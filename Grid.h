//
//  Grid.h
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#ifndef Grid_h
#define Grid_h
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Grid{
public:
    Grid();
    Grid(int r, int col, double d, int p, int m);
    ~Grid();
    int rows;
    int columns;
    int proceed;
    int mode;
    int neighborCount;
    int generate();
    int end;
    int input;
    string fileName;
    string line;
    double density;
    char **grid;
    char **tempGrid;
    bool isEqual();
    void createGrid();
    void createGrid2(string fileName);
    void printGrid();
    void gridAdd(int density);
    void gameOfLife();
    void countNeighbors();
    void updateNeighbors();
    void tempGridAdd(int rows, int columns, int neighborCount);
    void copyTemp();
    void createTempGrid();
    void gamePrompt1();
    void gamePrompt2();
    void selectInput();
    void gridModif();
    
};


#endif /* Grid_h */
