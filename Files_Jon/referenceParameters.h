#ifndef REFERENCEPARAMETERS_H_INCLUDED
#define REFERENCEPARAMETERS_H_INCLUDED

#include<math.h>
//double gamma, cp, cv, R; //thermo constants
//double rho_ref, P_ref, rhou_ref, rhov_ref, rhoE_ref, T_ref, H_ref, c_ref; //reference variables

//Air Properties at STP
double R=8314./28.966; // air gas constant J/Kg-K
double cp=1005.; // J/Kg-K
double cv=cp-R;
double gamma=cp/cv;

//STP Reference Properties
double rho_ref=1.293; // Kg/m^3
double P_ref=101325;// Pa
double ru_ref=sqrt(P_ref*rho_ref); // Kg/m^2-s volumetric-momentum
double T_ref=P_ref/rho_ref; // K
double rhoE_ref=P_ref/(gamma-1)+pow(ru_ref/rho_ref,2)/2; //internal energy KJ/m^3,
double H_ref=(rhoE_ref+P_ref)/rho_ref;
double c_ref=sqrt(gamma*P_ref/rho_ref);
double s_ref=cv*log(T_ref)-R*log(rho_ref);

#endif // REFERENCEPARAMETERS_H_INCLUDED
