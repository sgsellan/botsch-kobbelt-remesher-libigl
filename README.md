# botsch-kobbelt-remesher-libigl
Implementation of the local remesher from "A Remeshing Approach to Multiresolution Modeling" by M. Botsch and L. Kobbelt, to work with the libigl geometry processing library. In my MacOS I build this by running
```
clang++ -std=c++11 -I libigl/include/ -I /usr/local/Cellar/eigen/ -DNDEBUG -framework Accelerate -O -o remeshmesh remeshmesh.cpp src/remesh_botsch.cpp src/collapse_edges.cpp src/split_edges_until_bound.cpp src/split_edges.cpp src/tangential_relaxation.cpp src/equalize_valences.cpp

```

To run in command line, issue
```
./remeshmesh [input.obj] [output.obj] [-i num_iterations] [-h target_edge_length]
```

