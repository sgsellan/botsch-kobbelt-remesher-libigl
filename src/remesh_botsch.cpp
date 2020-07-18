#include "equalize_valences.h"
#include "collapse_edges.h"
#include "tangential_relaxation.h"
#include <igl/is_edge_manifold.h>
#include <igl/writeOBJ.h>
#include "split_edges_until_bound.h"
#include <igl/unique_edge_map.h>
#include <igl/remove_duplicate_vertices.h>
#include <iostream>

void remesh_botsch(Eigen::MatrixXd & V,Eigen::MatrixXi & F, Eigen::VectorXi & feature,Eigen::VectorXd & target,int iters){
    Eigen::MatrixXd V0;
    Eigen::MatrixXi F0;
 
    F0 = F;
    V0 = V;
    Eigen::VectorXd high,low,lambda;
    high = 1.4*target;
    low = 0.7*target;
    
    Eigen::MatrixXd SV;
    Eigen::MatrixXi SVI,SVJ;
   
    for (int i = 0; i<iters; i++) {
//    std::cout << "Start!" << std::endl;
//        std::cout << igl::is_edge_manifold(F) << std::endl;
//        igl::remove_duplicate_vertices(V,0,SV,SVI,SVJ);
//        std::cout << V.rows()-SV.rows() << std::endl;
    //   Split edges
    // igl::unique_edge_map(F,E,uE,EMAP,uE2E);
    split_edges_until_bound(V,F,feature,high,low);
//     std::cout << "Split!" << std::endl;
//        std::cout << igl::is_edge_manifold(F) << std::endl;
//        igl::remove_duplicate_vertices(V,0,SV,SVI,SVJ);
//        std::cout << V.rows()-SV.rows() << std::endl;
    //   Collapse edges
    collapse_edges(V,F,feature,high,low);
//    std::cout << "Collapsed!" << std::endl;
//        std::cout << igl::is_edge_manifold(F) << std::endl;
//        igl::remove_duplicate_vertices(V,0,SV,SVI,SVJ);
//        std::cout << V.rows()-SV.rows() << std::endl;
    //   Flip edges
    // igl::writeOBJ("thing.obj",V,F);
    
    equalize_valences(V,F,feature);
//    std::cout << "Flip!" << std::endl;
//        std::cout << igl::is_edge_manifold(F) << std::endl;
//        igl::remove_duplicate_vertices(V,0,SV,SVI,SVJ);
//        std::cout << V.rows()-SV.rows() << std::endl;
    //   Relaxation
    int n = V.rows();
    lambda = Eigen::VectorXd::Constant(n,0.01);
        F0 = F;
        V0 = V;
    tangential_relaxation(V,F,feature,V0,F0,lambda);
//    std::cout << "Relaxed!" << std::endl;
//        std::cout << igl::is_edge_manifold(F) << std::endl;
//        igl::remove_duplicate_vertices(V,0,SV,SVI,SVJ);
//        std::cout << V.rows()-SV.rows() << std::endl;
    }


}


// g++ -I/usr/local/libigl/external/eigen -I/usr/local/libigl/include -std=c++11 -framework Accelerate main.cpp remesh_botsch.cpp -o main

