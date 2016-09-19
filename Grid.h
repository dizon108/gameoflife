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
    ~Grid();
    int rows;
    int columns;
  //  int countNeighbors(int x, int y, int row, int column, char grid[][]);
  //  int isActive(int x, int y, int row, int column, char grid[][]);
    char **grid;
    char **tempGrid;
    int generate();
    double density;
    void createGrid(int rows, int columns);
    void printGrid();
    void gridAdd();
    void run();
    int countNeighbors();
    int neighborCount;
    void tempGridAdd(int rows, int columns, int neighborCount);
    void copyTemp();
    void duplicateGrid();
};


#endif /* Grid_h */
