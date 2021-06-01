# Libigl Botsch-Kobbelt Local Remesher
Implementation of the local remesher from "A Remeshing Approach to
Multiresolution Modeling" by M. Botsch and L. Kobbelt, to work with the libigl
geometry processing library. Can be used as a Command Line Tool, a C++ function,
a Matlab mex function and a python function.

## Installation

Clone this repo and its submodules:
```
git clone --recursive git@github.com:bathal1/botsch-kobbelt-remesher-libigl.git
```

To build this project, do the usual CMake dance:

```
mkdir build
cd build
cmake ..
make -j
```

### Setting the Path

Once you built the project, a script `setpath.sh` will be copied to your build
folder. Run `source setpath.sh` to add the path to the build folder to your
system PATH and PYTHONPATH environment variables.

## Use
To run in command line, issue
```
remeshmesh [input.ext] [output.ext] [-i num_iterations] [-h target_edge_length]
```
The mesh in input.obj must be closed and manifold. `ext` can be any of `obj`,
`mesh`, `off`, `ply` and `stl`.

To use within your own C++ code, simply the header files in `src/` and
use the function `remesh_botsch` as shown in `remesmesh.cpp`.

Python bindings are also available:
```python
from pyremesh import remesh_botsch
v_new, f_new = remesh_botsch(v, f, target, steps)
```

I also provide a mex wrapper for Matlab, which can be compiled by running
`mex/build_mex` in the Matlab console. A precompiled Mac OS X mex binary can
also be found in `precompiled/osx/bin`.

