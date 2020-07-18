#include <igl/readOBJ.h>
#include "src/remesh_botsch.h"
#include <igl/writeOBJ.h>

using namespace std;

int main(){
    Eigen::MatrixXd V,PD1,PD2,Vtest;
    Eigen::VectorXd PC1,PC2,target;
    Eigen::VectorXi feature;
    Eigen::MatrixXi F,Ftest;
    igl::readOBJ("data/bunny.obj",V,F);
    feature.resize(0);
    target = Eigen::VectorXd::Constant(V.rows(),0.01);
    remesh_botsch(V,F,feature,target,1);
    igl::writeOBJ("output.obj",V,F);
    return 0;
}
