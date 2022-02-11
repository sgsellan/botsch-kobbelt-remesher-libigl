#ifndef SPLIT_EDGES
#define SPLIT_EDGES


#include "macros.h"
#include <Eigen/Core>
BOTSCH_EXPORT
void split_edges(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::MatrixXi & E0, Eigen::MatrixXi & uE, Eigen::VectorXi & EMAP0, std::vector<std::vector<int>> & uE2E,Eigen::VectorXd & high, Eigen::VectorXd & low,const std::vector<int> & edges_to_split);


#endif
