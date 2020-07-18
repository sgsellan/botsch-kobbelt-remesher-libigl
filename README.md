# Libigl Botsch-Kobbelt Local Remesher
mplementation of the local remesher from "A Remeshing Approach to Multiresolution Modeling" by M. Botsch and L. Kobbelt, to work with the libigl geometry processing library. 
## Installation
In my MacOS I build this by running
```
clang++ -std=c++11 -I libigl/include/ -I /usr/local/Cellar/eigen/ -DNDEBUG -framework Accelerate -O -o remeshmesh remeshmesh.cpp src/remesh_botsch.cpp src/collapse_edges.cpp src/split_edges_until_bound.cpp src/split_edges.cpp src/tangential_relaxation.cpp src/equalize_valences.cpp

```
You can also find a Mac OS X precompiled binary in `precompiled/osx/bin`.

## Use
To run in command line, issue
```
./remeshmesh [input.obj] [output.obj] [-i num_iterations] [-h target_edge_length]
```
To use within your own C++ code, simply include the header files in `src/` and
use the function `remesh_botsch` as shown in `remesmesh.cpp`. 
