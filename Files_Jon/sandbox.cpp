#include<iostream>
#include "referenceParameters.h"
#include "cellState.h"
using namespace std;

int main(){
    cout <<rho_ref <<"\n";
    cellState cell(rho_ref, 10, 0, rhoE_ref, gamma, cv);
    cout<<cell.rhoU()<<"\t"<<P_ref<<"\n";
//    cell.rhou()=5;
    cout <<cell.rhoUis(5);
}
