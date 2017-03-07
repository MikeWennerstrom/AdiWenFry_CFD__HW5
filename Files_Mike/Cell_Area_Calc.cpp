//Mike W
// This defines the area of each cell
// I want this to become part of the geometry object, but this might be difficult 
//since we would have to have xCorner and yCorner already allocated as a multidimensional array/vector.


#include <cmath>
#include <vector>

void defineArea(std::vector<std::vector<double>> & xCorner, std::vector<std::vector<double>> &  yCorner, std::vector<std::vector<double>> &  CellArea) { // returns 1/2 abs(X_AC x X_BD) as the cell area at index


	//needed only for the loop, coding-wise are these private?
	//Preallocating the x and y lines from SE to NW, and NE to SW
	double X_AC;
	double Y_AC;
	double X_BD;
	double Y_BD;

	for (int i = 1; i < I; i++) { // REVISIT- should this be <J+1 and I+1?
		for (int j = 1; j < J; j++) {

			X_AC = (xCorner[i][j] - xCorner[i - 1][j - 1]); //X&Y NE minus X&Y SW 
			Y_AC = (yCorner[i][j] - yCorner[j - 1][i - 1]);

			X_BD = (xCorner[i - 1][j] - xCorner[i][j - 1]); //X&Y NW minus X&Y SE 
			Y_BD = (yCorner[i - 1][j] - yCorner[i][j - 1]);

			CellArea[i - 1][j - 1] = 0.5*abs(X_AC*Y_BD - X_BD*Y_AC);

		}
	}