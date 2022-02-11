#ifndef TANGENTIAL_RELAXATION
#define TANGENTIAL_RELAXATION


#include "macros.h"
#include <Eigen/Core>
BOTSCH_EXPORT
void tangential_relaxation(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXi & feature,
Eigen::MatrixXd & V0 ,Eigen::MatrixXi & F0, Eigen::VectorXd & lambda);


#endif
