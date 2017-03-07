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
    
    // Define Freestream Air Conditions
    const int AOA = 0;          // 0 angle of attack
    const double Mach_inf = 0.8;  // Free stream Mach number
    const double gamma = 1.4;     //
    const double rho_inf = 1.23;  // kg/m^3
    const double T_inf = 288;     // Kelvin
    const double P_inf = 101300;  // N/m^2
    const double R_max = 0.000001; // Residual threshold
//    const double Imax =
//    const double Jmax =
//    vector<double> alpha = //{0.125, 0.306,0.587,1}
    
    // load the grid
    // Define cell geometric properties
    
    // Impose Initial Conditions: Freestream air properties throughout volume
        // U = rho, rho*u, rho*v, rho*E
    
    // R = 1
    // While R > R_max:
//        double R_ = 0
        // for(int i=0; i<Imax; i++):
            // for(int j=0; j<Jmax; j++):
                // If cell is at a boundary:
                    // Impose Boundary Conditions
                // else:
                    // Continue
                // tau_ij_ = getTau()
                // for(int RKc=0;RKc<4;RKc++):
                    // R_ij_ = getNumericalFlux(U_ij)
                    // U_ij = U_ij - tau_ij_*alpha.at(RKc)*R_ij_
                // R_ = R_ + R_ij_
    // When residuals hit the tolerance
    // Create Plots
    
    string filename1 = "Grid_X_Points.csv";
    string filename2 = "Grid_Y_Points.csv";
    
    grid XgridCorners(filename1, filename2);
    
    cout << XgridCorners.M;
    
    
    
    
    
    
    
    
    
    return 0;
}

