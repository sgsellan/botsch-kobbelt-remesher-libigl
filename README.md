# Libigl Botsch-Kobbelt Local Remesher
Implementation of the local remesher from "A Remeshing Approach to Multiresolution Modeling" by M. Botsch and L. Kobbelt, to work with the libigl geometry processing library. Can be used as a Command Line Tool, a C++ function and a Matlab mex function. 
## Installation
In my MacOS I build this by running
```
clang++ -std=c++11 -I libigl/include/ -I /usr/local/Cellar/eigen/ -DNDEBUG -framework Accelerate -O3 -o remeshmesh remeshmesh.cpp src/remesh_botsch.cpp src/collapse_edges.cpp src/split_edges_until_bound.cpp src/split_edges.cpp src/tangential_relaxation.cpp src/equalize_valences.cpp

```
You can also find a Mac OS X precompiled binary in `precompiled/osx/bin`.

## Use
To run in command line, issue
```
./remeshmesh [input.ext] [output.ext] [-i num_iterations] [-h target_edge_length]
```
The mesh in input.obj must be closed and manifold. `ext` can be any of `obj`,
`mesh`, `off`, `ply` and `stl`.

To use within your own C++ code, simply the header files in `src/` and
use the function `remesh_botsch` as shown in `remesmesh.cpp`.

I also provide a mex wrapper for Matlab, which can be compiled by running
`mex/build_mex` in the Matlab console. A precompiled Mac OS X mex binary can
also be found in `precompiled/osx/bin`. 
