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


// Los que tienen el tipo de objeto definido son input, el resto output??

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    using namespace igl;
    using namespace igl::matlab;
   // using namespace igl::copyleft::cgal;
    using namespace Eigen;
    MatrixXd V,U;
    MatrixXi F,G,E,uE,EI,EF;
    VectorXi EMAP,feature,I,J;
    VectorXd target;
    
    
    
    igl::matlab::MexStream mout;
    std::streambuf *outbuf = std::cout.rdbuf(&mout);
    
    
    mexErrMsgTxt(nrhs>=2,"nrhs should be >= 2");
    parse_rhs_double(prhs,V); // Aquí se pasa del prhs a la matriz V de Eigen
    parse_rhs_index(prhs+1,F); // Aquí se pasa del prhs a la matriz F de Eigen
    mexErrMsgTxt(V.cols()==3,"V must be #V by 3");
    mexErrMsgTxt(F.cols()==3,"F must be #F by 3");
    parse_rhs_index(prhs+2,feature);
    parse_rhs_double(prhs+3,target);
    int iters = (int)*mxGetPr(prhs[4]);

    remesh_botsch(V,F,feature,target,iters);
    
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
