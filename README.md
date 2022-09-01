# Libigl Botsch-Kobbelt Local Remesher

Implementation of the local remesher from "A Remeshing Approach to
Multiresolution Modeling" by M. Botsch and L. Kobbelt, to work with the libigl
geometry processing library. Can be used as a Command Line Tool, a C++ function,
a Matlab mex function and a python function. Python bindings can be built from this repository, or found as part of [gpytoolbox](https://github.com/sgsellan/gpytoolbox)

# Important note

An up-to-date, maintained version of this code is implemented into our new python geometry processing library [Gpytoolbox](https://gpytoolbox.org). See the remesher documentation and examples [here](https://gpytoolbox.org/remesh_botsch/).

## Installation

Clone this repo and its submodules:
```
git clone --recursive git@github.com:sgsellan/botsch-kobbelt-remesher-libigl.git
```

To build this project, do the usual CMake dance:

```
mkdir build
cd build
cmake ..
make -j
```

### Installing on Windows

The usual CMake dance changes a little on Windows. Instead of using `make -j`, on Windows, CMake will produce a visual studio solution that you can use to build the project. The following procedure was tested on Windows 10 using Visual Studio 2022.

1. Open the Remesher.sln solution in Visual Studio.
2. Build the `ALL_BUILD` project.
3. The `.pyd` file will be in `build/[Debug OR Release]`. Add this directory to your path.

#### Troubleshooting

- The `remesh` project needs to output a static library (`.lib`) but by default may output a dynamic library (`.dll`). To fix this, open the project properties and change `Configuration Properties > General > Configuration Type` to `Static Library (.lib)` and change `Configuration Properties > Advanced > Target File Extension` to `.lib`.
- The `pyremesh` project needs to find python on the path to build. The simplest (but probably wrong) way seems to be: disable the `python` execution alias in `System Settings > Manage App Execution Aliases` (OS settings, not visual studio). And then manually add a python executable to the system path.
- There is currently [a pybind11 bug](https://github.com/pybind/pybind11/issues/3459) that causes errors on debug builds. Simplest fix: build with a Release config.


### Setting the Path

Once you built the project, a script `setpath.sh` will be copied to your build
folder. Run `source setpath.sh` to add the path to the build folder to your
system PATH and PYTHONPATH environment variables.

## Use
To run in command line, issue
```
remeshmesh [input.ext] [output.ext] [-i num_iterations] [-h target_edge_length]
[-p]
```
The mesh in input.obj must be closed and manifold. `ext` can be any of `obj`,
`mesh`, `off`, `ply` and `stl`. `-p` tells the remesher to project to the
original mesh.

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

