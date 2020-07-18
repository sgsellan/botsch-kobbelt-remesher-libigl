#include <igl/readOBJ.h>
#include "src/remesh_botsch.h"
#include <igl/writeOBJ.h>

using namespace std;

int main(int argc, const char* argv[]){
    
	
    Eigen::MatrixXd V;
    Eigen::VectorXd target;
    Eigen::VectorXi feature;
    Eigen::MatrixXi F;
    string in,out;
    int iterations = 1;
    double h = 0.05;

    if(argc>2){
	    in = argv[1];
	    out = argv[2];
	    int argindex = 2;
	    while(argindex+1<argc){
		    if(strncmp(argv[argindex+1],"-i",2)==0){
			    iterations = atoi(argv[argindex+2]);
		    }
		    if(strncmp(argv[argindex+1],"-h",2)==0){
			    h = atof(argv[argindex+2]);
		    }
		    argindex = argindex+2;
	    }
    }else{
	    in = argv[1];
	    out = "output.obj";
    }
    igl::readOBJ(in,V,F);
    feature.resize(0);
    target = Eigen::VectorXd::Constant(V.rows(),h);
    remesh_botsch(V,F,feature,target,iterations);
    igl::writeOBJ(out,V,F);
}
