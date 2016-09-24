//
//  main.cpp
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
#include <fstream>
#include <random>
#include <ctime>
#include <math.h>
#include <cstdlib>
#include <limits>

using namespace std;

/*void gamePrompt2(){
    cout << "Enter file name: ";
    cin >> fileName;
    gridModif();
    x.createGrid2(fileName);
    
}*/

int main(int argc, const char * argv[]) {

    srand(time(NULL));
    Grid *grid;
    int input;
    int proceed;
    int mode;
    int rows;
    int columns;
    double density;
    string fileName;
    
    cout << "Select input mode:" <<endl;
    cout << "1. Random configuration"<<endl;
    cout<<"2. Flatfile configuration"<<endl;
    cout<<"Enter number: ";
    cin >> input;
    
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
        
    if(input == 1){
        cout << "World Conditions: Enter a number" << endl;
        cout << "Rows: ";
        cin >> rows ;
        cout << "Columns: ";
        cin >> columns;
        cout << "Density (enter a decimal value greater than 0 and less than 1): ";
        cin >> density;
        density = round(density*100);
        grid = new Grid(rows, columns, density, proceed, mode );
        grid->createGrid();
        grid->gridAdd(density);
    }
    else if(input ==2){
        cout << "Enter file name: ";
        cin >> fileName;
        Grid grid = Grid(fileName, mode, proceed);
        grid.createGrid2(fileName);
    }
    int generation = 0;
    cout << "Generation: " + to_string(generation)<< endl;
    grid->printGrid();
    grid->createTempGrid();
    generation = 1;
    while(true){
      grid->countNeighbors();
      if (!grid->isEqual()) {
          grid->copyTemp();
          if (proceed == 1){
              cin.ignore();
              cout<<"Generation: " + to_string(generation)<<endl;
              grid->printGrid();
            }
          else if(proceed == 2){
              this_thread::sleep_for(chrono::seconds(1));
              cout<<"Generation: " + to_string(generation)<<endl;
              grid->printGrid();
            }
            generation++;
        } else {
            if(proceed == 1){
                cout << "Done. Press enter to exit the program." <<endl;
                cin.ignore();
            }
            else if(proceed ==2){
                cout << "Done. Exiting program." <<endl;
            }break;
        }
      }
      
}






