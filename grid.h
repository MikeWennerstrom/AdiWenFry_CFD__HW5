#ifndef GRID_H
#define GRID_H
#include<fstream>
#include<cstdlib>
#include<algorithm>
#include<vector>

class grid{
//Reads external grid files, computes additional grid data, holds geometric data
//Any particular flow problem should only need one grid
    typedef std::vector< std::vector<double> > vec2D;
    public:
        grid(std::string xfilename, std::string yfilename){
            loadGrid(xfilename, yfilename); //sets x and y corner points
            //defineEdgePoints();
            //defineCenterPoints();
        }
        vec2D xCorner, yCorner, xCenter, yCenter;
        int N, M; //number of points in the xi, and eta directions
    private:
        double **dx, **dy; //length parameters of cells between corners. Indices match edge-point indices.
        void loadGrid(std::string xfilename, std::string yfilename){ //Define N and M in here; x_corners = new double[][]; more initializing stuff
            std::ifstream xfile, yfile;
            std::string readin;
            int lineNum=0;
            xfile.open(xfilename.c_str());
            yfile.open(yfilename.c_str());

            //Figure out size of the csv table
            getline(xfile, readin);
            lineNum++;
            N=std::count(readin.begin(),readin.end(),',')+1;
            while(xfile.good()){
                getline(xfile, readin);
                lineNum++;
            }
            M=lineNum;
            xfile.seekg(0, xfile.beg);//restart xfile from the beginning

            //Start Loading in data now that we know how much information there is
            //Allocate the correct amount of memory for xCorners and yCorners
            xCorner.resize(N, std::vector<double>(M));
            yCorner.resize(N, std::vector<double>(M));

            for(int i=0; i<N; i++){
                //read all data entries except the last in the line (the last line is the only one that doesnt have a comma at the end of it)
                for(int j=0; j<M-1; j++){
                    getline(xfile,readin,',');
                    xCorner[i][j]=atof(readin.c_str());
                    getline(yfile,readin,',');
                    yCorner[i][j]=atof(readin.c_str());
                }
                getline(xfile,readin);
                xCorner[i][M-1]=atof(readin.c_str());
                getline(yfile,readin);
                yCorner[i][M-1]=atof(readin.c_str());
            }
            xfile.close();
            yfile.close();
        }
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
