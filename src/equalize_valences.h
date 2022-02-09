#ifndef EQUALIZE_VALENCES
#define EQUALIZE_VALENCES



#include <Eigen/Core>
__declspec(dllexport)
void equalize_valences(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXi & feature);


#endif
