% Remeshes a closed, *MANIFOLD* mesh in the way described in "A remeshing
% approach to multiresolution modeling".
%
% Sample call:
%	remeshmesh_mex(V,F)
%	remeshmesh_mex(V,F,h)
%	remeshmesh_mex(V,F,h,iterations)
%	remeshmesh_mex(V,F,h,iterations,fixed_indeces)
%
% INPUTS:
%	V #V by 3 matrix of vertices
%	F #F by 3 matrix of face indeces
%	Optional:
%		h scalar of target edge length OR #V vector with per-vertex
%			target edge lengths 
%		iterations number of local remesher iterations
%		fixed_indeces #fixed_indeces vector of indeces of mesh that must
%			not be touched by remesher
