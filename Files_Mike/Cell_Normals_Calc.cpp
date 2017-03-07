//Mike W
// This defines the north and east normal (delta S) of each cell
// I want this to become part of the geometry object

#include <cmath>
#include <vector>

void defineSideNormals(std::vector<std::vector<double>> & xCorner, std::vector<std::vector<double>> &  yCorner, 
	std::vector<std::vector<double>> &  X_NORMAL_EAST, std::vector<std::vector<double>> &  Y_NORMAL_EAST, 
	std::vector<std::vector<double>> &  X_NORMAL_NORTH, std::vector<std::vector<double>> &  Y_NORMAL_NORTH)
{

	//preallocating parts needed for loop. May not need this when we put this in object form

	double sidelength_x_EAST;
	double sidelength_y_EAST;
	double length_EAST;

	double sidelength_x_NORTH;
	double sidelength_y_NORTH;
	double length_NORTH;

	for (int i = 1; i<I; i++) {
		for (int j = 1; j<J; j++) {

			// The East normal

			sidelength_x_EAST = xCorner[i][j] - xCorner[i][j - 1]; // subtract the x and y components
			sidelength_y_EAST = yCorner[i][j] - yCorner[i][j - 1];
			length_EAST = sqrt(pow(sidelength_x_EAST, 2) + pow(sidelength_y_EAST, 2)); // take the RMS
			X_NORMAL_EAST[i-1][j-1] = sidelength_y_EAST / length_EAST; // Putting the normalized normals in (y,-x) form
			Y_NORMAL_EAST[i-1][j-1] = -sidelength_x_EAST / length_EAST;

			//THe North normal

			sidelength_x_NORTH = xCorner[i - 1][j] - xCorner[i][j]; //same process as above
			sidelength_y_NORTH = yCorner[i - 1][j] - yCorner[i][j];
			length_NORTH = sqrt(pow(sidelength_x_NORTH, 2) + pow(sidelength_y_NORTH, 2));
			X_NORMAL_NORTH[i - 1][j - 1] = sidelength_y_NORTH / length_NORTH;
			Y_NORMAL_NORTH[i - 1][j - 1] = -sidelength_x_NORTH / length_NORTH;

		}
	}