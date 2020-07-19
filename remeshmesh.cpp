#include <igl/readOBJ.h>
#include "src/remesh_botsch.h"
#include <igl/writeOBJ.h>

using namespace std;

int main(int argc, const char* argv[]){
    
	
    Eigen::MatrixXd V;
    Eigen::VectorXd target;
    Eigen::MatrixXi F;
    string in,out;
    int iterations = 10;
    double h = 0.05;
    out = "output.obj";
	    in = argv[1];
	    int argindex = 1;
	    while(argindex+1<argc){
		    if(strncmp(argv[argindex+1],"-i",2)==0){
			    iterations = atoi(argv[argindex+2]);
		            argindex = argindex+2;
		    }else{
		    if(strncmp(argv[argindex+1],"-h",2)==0){
			    h = atof(argv[argindex+2]);
		            argindex = argindex+2;
		    }else{
		    	    out = argv[argindex+1];
		            argindex = argindex+1;
		    }}
	    }
    igl::readOBJ(in,V,F);
    target = Eigen::VectorXd::Constant(V.rows(),h);
    remesh_botsch(V,F,target,iterations);
    igl::writeOBJ(out,V,F);
}
