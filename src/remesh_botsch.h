#ifndef REMESH_BOTSCH
#define REMESH_BOTSCH



#include <Eigen/Core>

void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXi & feature,Eigen::VectorXd & target,int iters);


#endif
