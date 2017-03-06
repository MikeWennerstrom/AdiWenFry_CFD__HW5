#ifndef GRID_H
#define GRID_H
#include<fstream>

class grid{
//Reads external grid files, computes additional grid data, holds geometric data
//Any particular flow problem should only need one grid
    public:
        grid(std::fstream& gridfile){
            loadGrid(gridfile); //sets x and y corner points
            defineEdgePoints();
            defineCenterPoints();
        }
        double xEdge(int i, int j){
            return x_edges[i][j];
        }
        double yEdge(int i, int j){
            return y_edges[i][j];
        }
        double xCorner();
        double yCorner();
        double xCenter();
        double yCenter();
    private:
        int N, M; //number of points in the xi, and eta directions
        double **x_corners, **y_corners, **x_edges, **y_edges, **x_centers, **y_centers; //grid points
        double **dx, **dy; //length parameters of cells between corners. Indices match edge-point indices.
        void loadGrid(std::fstream& gridfile); //Define N and M in here; x_corners = new double[][]; more initializing stuff
        void defineEdgePoints(); //interpolate edge midpoints
        void defineCenterPoints(); //interpolate cell centers
        void defineSideLengths();
        void defineSideNormals(){
//            for(int i=0; i<N; i++){
//                for(int j=0; j<M; j++){
//                    length=RMS(sidelength_x, sidelength_y)
//                    normal_x = -sidelength_y/length;
//                    normal_y = sidelength_x/length;
//                }
//            }
//            return;
        }
};

#endif // GRID_H
