#ifndef REMESH_BOTSCH
#define REMESH_BOTSCH



#include <Eigen/Core>
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F,Eigen::VectorXd & target,int iters, Eigen::VectorXi & feature, bool project);

__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F,Eigen::VectorXd & target,int iters, Eigen::VectorXi & feature);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXd & target,int iters);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXd & target,int iters, bool project);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXd & target);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, double target_double,int iters);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, double target_double,int iters, bool project);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, double target_double);
__declspec(dllexport)
void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F);



#endif
