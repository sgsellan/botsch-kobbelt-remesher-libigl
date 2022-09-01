#ifndef REMESH_BOTSCH
#define REMESH_BOTSCH


#include "macros.h"
#include <Eigen/Core>
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F,Eigen::VectorXd & target,int iters, Eigen::VectorXi & feature, bool project);

BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F,Eigen::VectorXd & target,int iters, Eigen::VectorXi & feature);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXd & target,int iters);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXd & target,int iters, bool project);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXd & target);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, double target_double,int iters);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, double target_double,int iters, bool project);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, double target_double);
BOTSCH_EXPORT
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F);



#endif
