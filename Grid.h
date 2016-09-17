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
    void copyGrid();
    void updateGrid2(int rows,int columns, int neighborCount);
  //  int countNeighbors(int x, int y, int row, int column, char grid[][]);
  //  int isActive(int x, int y, int row, int column, char grid[][]);
    char **grid;
    char **grid2;
    int generate();
    int density;
    void createGrid(int rows, int columns);
    void printGrid();
    void gridAdd();
};


#endif /* Grid_h */
