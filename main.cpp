//
//  main.cpp
//  GameOfLife
//
//  Created by Reese Dizon on 9/16/16.
//  Copyright © 2016 Chapman University. All rights reserved.
//

#include <iostream>
using namespace std;

void gamePrompt(){
    int rows;
    int columns;
    cout << "What dimensions would you like your world to be in?" << endl;
    cout << "Rows: ";
    cin >> rows ;
    cout << "Columns: ";
    cin >> columns;
}

int main(int argc, const char * argv[]) {
    gamePrompt();
}
