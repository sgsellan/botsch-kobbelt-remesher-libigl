#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <list>
#include <cmath>
#include <limits>
#include <set>
// #include <matlab>
// Lib IGL includes
#include <igl/C_STR.h>
#include <igl/mat_max.h>
#include <igl/matlab/mexErrMsgTxt.h>
#include <igl/matlab/MexStream.h>
#include <igl/matlab/parse_rhs.h>
#include <igl/matlab/prepare_lhs.h>
#include <igl/matlab/validate_arg.h>
#include "../src/remesh_botsch.h"
#include <igl/avg_edge_length.h>

// Los que tienen el tipo de objeto definido son input, el resto output??

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    using namespace igl;
    using namespace igl::matlab;
   // using namespace igl::copyleft::cgal;
    using namespace Eigen;
    MatrixXd V,U;
    MatrixXi F,G;
    VectorXi feature;
    VectorXd target;
    
    
    
    igl::matlab::MexStream mout;
    std::streambuf *outbuf = std::cout.rdbuf(&mout);
    
    
    
    parse_rhs_double(prhs,V); // Aquí se pasa del prhs a la matriz V de Eigen
    parse_rhs_index(prhs+1,F); 
    
    int iters = 10;
    feature.resize(0); 
    double h = igl::avg_edge_length(V,F);
    int n = V.rows();
    target = Eigen::VectorXd::Constant(n,h);
   
    // remeshmesh_mex(V,F,target,iters,feature); 
    switch(nrhs)
    {
	    case 5:
    		parse_rhs_index(prhs+4,feature);
	    case 4:
    		iters = (int)*mxGetPr(prhs[3]);
	    case 3:
    		parse_rhs_double(prhs+2,target);
    }

	if(target.size()==1){
    		VectorXd target_copy;
		target_copy = Eigen::VectorXd::Constant(n,target(0));
		target = target_copy;
	}
    
	
	
    remesh_botsch(V,F,target,iters,feature);
    
    U = V;
    G = F;
    

    
    switch(nlhs)
    {
        case 2:
            prepare_lhs_index(G,plhs+1); // Sustituir G con las direcciones?
        case 1:
            prepare_lhs_double(U,plhs+0); // Sustituir W con las curvaturas?
        default:break;
    }
    
    // Restore the std stream buffer Important!
    std::cout.rdbuf(outbuf);
    
}
