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
    int end;
    double density;
    char **grid;
    char **tempGrid;
    int **topBot;
    int **sides;

    //Update Functions for Mirror Mode
    void updateTopBot(int currentRow, int tB);
    void updateSides(int currentCol, int lR);
    void updateCornersDonut();
    void updateCornersMirror();
    void clearEdges();
    void printEdges();

    bool isEqual();
    void createGrid();
    void printGrid();
    void gridAdd(int density);
    void gameOfLife();
    void countNeighbors();
    void updateNeighbors();
    void tempGridAdd(int rows, int columns, int neighborCount);
    void copyTemp();
    void createTempGrid();
};


#endif /* Grid_h */
