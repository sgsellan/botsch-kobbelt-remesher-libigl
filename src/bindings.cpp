#include <npe.h>
#include <remesh_botsch.h>

npe_function(remesh_botsch)
npe_arg(v, dense_double)
npe_arg(f, dense_int)
npe_arg(t, dense_double)
npe_arg(i, int)
npe_arg(ft, dense_int)
npe_begin_code()
    Eigen::MatrixXd V(v);
    Eigen::MatrixXi F(f);
    Eigen::VectorXd target(t);
    Eigen::VectorXi feature(ft);
    remesh_botsch(V, F, target, i, feature);
    return std::make_tuple(npe::move(V), npe::move(F));
npe_end_code()

npe_function(remesh_botsch)
npe_arg(v, dense_double)
npe_arg(f, dense_int)
npe_arg(target, dense_double)
npe_arg(i, int)
npe_begin_code()
    Eigen::MatrixXd V(v);
    Eigen::MatrixXi F(f);
    Eigen::VectorXd t(target);
    remesh_botsch(V, F, t, i);
    return std::make_tuple(npe::move(V), npe::move(F));
npe_end_code()

npe_function(remesh_botsch)
npe_arg(v, dense_double)
npe_arg(f, dense_int)
npe_arg(target, dense_double)
npe_begin_code()
    Eigen::MatrixXd V(v);
    Eigen::MatrixXi F(f);
    Eigen::VectorXd t(target);
    remesh_botsch(V, F, t);
    return std::make_tuple(npe::move(V), npe::move(F));
npe_end_code()

npe_function(remesh_botsch)
npe_arg(v, dense_double)
npe_arg(f, dense_int)
npe_arg(i, int)
npe_arg(h, double)
npe_begin_code()
    Eigen::MatrixXd V(v);
    Eigen::MatrixXi F(f);
    remesh_botsch(V, F, h, i);
    return std::make_tuple(npe::move(V), npe::move(F));
npe_end_code()

npe_function(remesh_botsch)
npe_arg(v, dense_double)
npe_arg(f, dense_int)
npe_arg(h, double)
npe_begin_code()
    Eigen::MatrixXd V(v);
    Eigen::MatrixXi F(f);
    remesh_botsch(V, F, h);
    return std::make_tuple(npe::move(V), npe::move(F));
npe_end_code()

npe_function(remesh_botsch)
npe_arg(v, dense_double)
npe_arg(f, dense_int)
npe_begin_code()
    Eigen::MatrixXd V(v);
    Eigen::MatrixXi F(f);
    remesh_botsch(V, F);
    return std::make_tuple(npe::move(V), npe::move(F));
npe_end_code()
