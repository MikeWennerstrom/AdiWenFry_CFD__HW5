// Calculating Cell Mid-Points and Norms for CFD HW 5
// Sierra A. Adibi
// CPP

// Implementation Notes:
// The vectors X_cp and Y_cp are passed in here, and directly modified through the function.
// The vectors D_S_i and D_S_j are also passed in and modified directly
// The function assumes that X and Y are each arrays, that contain the grid points
// The X and Y arrays are assumed to be global.
// 



void getCenterPoints(vector<vector<double> > & X_cp, vector<vector<double> > & Y_cp, vector<vector<double> > & D_S_i, vector<vector<double> > & D_S_j, vector<vector<double> > Normals_X, vector<vector<double> > Normals_Y){
	int I = 129; // Number of points around an airfoil
	int J = 65;  // Number of radial points
	double x_sw,x_se,x_ne,x_nw,y_sw,y_se,y_ne,y_nw;


	for(int i=1;i<I;i++){
		for(j=1;j<J;j++){
			// Definitions of cell corner points
			x_sw = X[i-1][j-1];
			x_se = X[i][j-1];
			x_ne = X[i][j];
			x_nw = X[i-1][j];
			y_sw = Y[i-1][j-1];
			y_se = Y[i][j-1];
			y_ne = Y[i][j];
			y_nw = Y[i-1][j];
			
			// Calculations of center points
			X_cp[i-1][j-1] = 0.25*(x_sw+x_se+x_ne+x_nw);
			Y_cp[i-1][j-1] = 0.25*(y_sw+y_se+y_ne+y_nw);
			
			// Get averages of cell normals
			// These indices will most likely need to change when this part of the code
			// and the normal calculations are combined
            //**** These need to have x and y components, but I need to find out how we are doing this ****//
			D_S_i[i-1][j-1] = 0.5*(Normals_X[i-1][j] + Normals_X[i][j])
			D_S_j[i-1][j-1] = 0.5*(Normals_Y[i][j-1] + Normals_Y[i][j])
		}
	}
}




// Assuming that CFL is a global variable
double getTau(double c_ij, double u_ij, double v_ij, double dsi_x, double dsi_y, double dsj_x, double dsj_y){
    double abs1, abs2, cu_, cv_
    double tau_ij
    
    cu_ = c_ij + u_ij
    cv_ = c_ij + v_ij
    abs1 = abs(cu_*dsi_x + cv_*dsi_y)
    abs2 = abs(cu_*dsj_x + cv_*dsj_y)
    
    tau_ij = CFL/(abs1+abs2)
    
    return tau_ij
    
    // sum velocity and speed of sound
    // take the dot product of that vector and the normal
    // take the absolute value of that dot product
    // sum the two absolute values
    // Divide the CFL number by that sum
    // This is Tau
    // That should be done for each cell.
}
		
		
