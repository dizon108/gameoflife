//
//  Grid.h
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#ifndef Grid_h
#define Grid_h
class Grid{
public:
    Grid();
    Grid(int r, int col, int d);
    ~Grid();
    int rows;
    int columns;
    int proceed;
    int mode;
    int neighborCount;
    int generate();
    double density;
    char **grid;
    char **tempGrid;
    bool isEqual();
    void createGrid();
    void printGrid();
    void gridAdd(int density);
    void gameOfLife();
    void countNeighbors();
    void tempGridAdd(int rows, int columns, int neighborCount);
    void copyTemp();
    void createTempGrid();
    
};


#endif /* Grid_h */
