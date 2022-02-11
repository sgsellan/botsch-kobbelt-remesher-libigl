#ifndef EQUALIZE_VALENCES
#define EQUALIZE_VALENCES


#include "macros.h"
#include <Eigen/Core>
BOTSCH_EXPORT
void equalize_valences(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXi & feature);


#endif
