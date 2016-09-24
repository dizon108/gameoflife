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

void createGame() {
    
    cout << "Would you like to start with a random configuration (rc), or specify a flatfile configuration (ff). " << endl;
    string answer;
    cin >> answer;
    if (answer == "rc") {
        int rows;
        int columns;
        double density;
        cout << "Enter deimensions:" << '\n';
        cout << "Rows: ";
        cin >> rows ;
        cout << "Columns: ";
        cin >> columns;
        cout << "Density (enter a decimal value greater than 0 and less than or equal to 1): ";
        cin >> density;
        density = round(density*100);
        Grid grid(rows, columns, density);
    } /**else if (answer== "ff") {
        //ifstream input;
        string filename;
        cin >> filename;
        input.open(filename.c_str());
        
        cout << "File opened" << '\n';
    }**/
}
int main(int argc, const char * argv[]) {
    //createGame();
    /** //how to get to next generation
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
     cin >> mode;**/
     Grid x;
     x.gameOfLife();
}






