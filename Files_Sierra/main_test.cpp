//
//  main.cpp
//  HW5_Work
//
//  Created by Sierra Adibi on 3/6/17.
//
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include "grid.h"
#include "CellGeo.h"



using namespace std;


int main(){
    // define the global variables
    // load the grid
    // define the grid geometries
    // define Initial Flow conditions
    // Prescribe the Flow boundary conditions
    // Run Jameson Scheme
    // // Lots of steps here
    // When residuals hit the tolerance
    // Create Plots
    
    string filename1 = "Grid_X_Points.csv";
    string filename2 = "Grid_Y_Points.csv";
    
    grid XgridCorners(filename1, filename2);
    
    cout << XgridCorners.M;
    
    
    
    
    
    
    
    
    
    return 0;
}

