//Mike W
// This defines flux associated with each cell
// I want this to become part of the cell object

#include <cmath>
#include <vector>

void cell_flux() {
	//Jon, I need your help doing this, but maybe we can encorporate this into the cell object:

	//double F1_Cell() {
	//	return cell_rhoU;
	//}
	//
	//double F2_Cell() {
	//	return cell_rhoU * U + P;
	//}
	//
	//double F3_Cell() {
	//	return cell_rhoU * V;
	//}
	//
	//double F4_Cell() {
	//	return cell_rhoU * H;
	//}
	//
	//double G1_Cell() {
	//	return cell_rhoV;
	//}
	//
	//double G2_Cell() {
	//	return cell_rhoV * V + P;
	//}
	//
	//double G3_Cell() {
	//	return cell_rhoV * U;
	//}
	//
	//double G4_Cell() {
	//	return cell_rhoV * H;
	//}

	// This loops through to populate the fluxes corresponding to each center.
	for (int j = 1; j < J; j++) {
		for (int I = 1; i < I; i++) {

			F1_Cell[i][j] = Cell[i][j].cell_rhoU;
			F2_Cell[i][j] = Cell[i][j].cell_rhoU * Cell[i][j].U + Cell[i][j].P;
			F3_Cell[i][j] = Cell[i][j].cell_rhoU * Cell[i][j].V;
			F4_Cell[i][j] = Cell[i][j].cell_rhoU * Cell[i][j].H;

			G1_Cell[i][j] = Cell[i][j].cell_rhoV;
			G2_Cell[i][j] = Cell[i][j].cell_rhoV * Cell[i][j].V + Cell[i][j].P;
			G3_Cell[i][j] = Cell[i][j].cell_rhoV * Cell[i][j].U;
			G4_Cell[i][j] = Cell[i][j].cell_rhoV * Cell[i][j].H;
		}
	}
}