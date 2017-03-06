#include<iostream>
#include<fstream>
#include "referenceParameters.h"
#include "cellState.h"
#include "grid.h"
using namespace std;

const char XFILENAME[]="Grid_X_Points.csv";
const char YFILENAME[]="Grid_Y_Points.csv";

int main(){
//    cout <<rho_ref <<"\n";
//    cellState cell(rho_ref, 10, 0, rhoE_ref, gamma, cv);
//    cout<<cell.rhoU()<<"\t"<<P_ref<<"\n";
////    cell.rhou()=5;
//    cout <<cell.rhoUis(5);
    grid mygrid=grid(XFILENAME, YFILENAME);
    cout << "Grid Size is: " << mygrid.N <<" x "<<mygrid.M<<"\t (N x M)\n";
}
