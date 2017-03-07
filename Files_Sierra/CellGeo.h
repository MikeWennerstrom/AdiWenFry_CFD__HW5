// Class to define cell geometric properties
// Sierra A. Adibi
// AA 543 HW5



#ifndef CELLGEO_H
#define CELLGEO_H
#include <math.h>
#include <vector.h>

class cellGeo{
    // For each cell, we need: edge definitions, centerpoints, indices, areas, normals
    // For boundary cells, if we only define two edge normals, we will still need to define the outer normals.

    public:
    double x_SE, x_SW, x_NE, x_NW, x_CP, y_SE, y_SW, y_NE, y_NW, y_CP;  // cell corner and center points
    double area;        // area of cell
    int xi, eta;        // indices of cell
    vector<double> normal_N;
    vector<double> normal_S;
    vector<double> normal_E;
    vector<double> normal_W;
    vector<double> normal_CP_i;
    vector<double> normal_CP_j;
    
    
    void getCenterPoint();  // Sierra wrote this code
    void getArea();         // Mike wrote this code
    vector<double> getNormal(double x1, double x2, double y1, double y2);      // Mike wrote this code
    vector<double> getNormalCenter(vector<double> normBig, vector<double> normSmall);
    
    void initialize(int i_, int j_);
    

};

void cellGeo::getCenterPoint(){
    
    x_CP = 0.25*(x_SW+x_SE+x_NE+x_NW);
    y_CP = 0.25*(y_SW+y_SE+y_NE+y_NW);
}

void cellGeo::getArea(){    //****************** Mike --  Please check this for me
    double ax,ay,bx,by;
    
    ax = x_NE - x_SW;
    ay = y_NE - y_SW;
    bx = x_SE - x_NW;
    by = y_SE - y_NW;
    
    area = 0.5*abs(ax*by - bx*ay);
    
}

vector<double> cellGeo::getNormal(double x1, double x2, double y1, double y2){
    double nx,ny;
    vector<double> norm;
    
    nx = y2 - y1;
    ny = -(x2 - x1);
    
    norm.pushback(nx);
    norm.pushback(ny);
    
    return norm;
}

vector<double> cellGeo::getNormalCenter(vector<double> normBig, vector<double> normSmall){
    double ave1, ave2;
    vector<double> normCenter;
    
    ave1 = 0.5*(normBig.at(0)+normSmall.at(0));
    ave2 = 0.5*(normBig.at(1)+normSmall.at(1));
    
    normCenter.pushback(ave1);
    normCenter.pushback(ave2);
    
    return normCenter;
}

void cellGeo::initialize(int i_, int j_){
    xi = i_;
    eta = j_;
    
    // Assuming that X and Y are globally available here, otherwise they will need to be imported in
    // This indexing is done differently than what we had agreed on before. Check in with Mike & Jon about this.
    x_SE = X[i_][j_]
    x_SW = X[i_+1][j_]
    x_NE = X[i_][j_+1]
    x_NW = X[i_+1][j_+1]
    
    y_SE = Y[i_][j_]
    y_SW = Y[i_+1][j_]
    y_NE = Y[i_][j_+1]
    y_NW = Y[i_+1][j_+1]
    
    getArea();
    getCenterPoint();
    
    normal_N = getNormal(x_NW,x_NE,y_NW,y_NE);
    normal_S = getNormal(x_SW,x_SE,y_SW,y_SE);
    normal_E = getNormal(x_SE,x_NE,y_SE,y_NE);
    normal_W = getNormal(x_SW,x_NW,y_SW,y_NW);
    normal_CP_i = getNormalCenter(normal_E,normal_W);
    normal_CP_j = getNormalCenter(normal_N,normal_S);
    
}

#endif // CELLGEO_H
