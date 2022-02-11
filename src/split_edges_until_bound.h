#ifndef SPLIT_EDGES_UNTIL_BOUND
#define SPLIT_EDGES_UNTIL_BOUND


#include "macros.h"
#include <Eigen/Core>
BOTSCH_EXPORT
void split_edges_until_bound(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXi & feature, Eigen::VectorXd & high, Eigen::VectorXd & low);


#endif
