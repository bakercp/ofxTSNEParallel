# ofxTSNEParallel

A parallel version of ofxTSNE.

It simply wraps a slightly modified version of [Multicore-TSNE](https://github.com/DmitryUlyanov/Multicore-TSNE) and should be API compatible with [ofxTSNE](https://github.com/genekogan/ofxTSNE).

It offers 2-5x speed boost for the standard ofxTSNE.

It is limited to 2D embeddings.

Parallel acceleration applies to the tree-building and refinement portions of the algorithm. The initial segment is still single threaded.

## Instructions
### OSX
[Multicore-TSNE](https://github.com/DmitryUlyanov/Multicore-TSNE) uses OpenMP, which is unsupported by default on OSX (at this point at least). In order to run on OSX, do the following:

1. Install [homebrew](https://brew.sh/).
2. Install `llvm` via `brew install llvm`.

#### Makefile (Command Line)

Special flags are listed in the `addon_config.mk` file that allows the `Makefile` to use the appropriate brew-installed OpenMP-compatible `llvm` compiler.

  1. `cd example/`
  2. `make -j4 -s`
  3. `make run` to run the example.

#### Xcode

Xcode requires configuration in addition to using the standard openFrameworks Project Generator app. Thanks @crecord.

  1. See instructions [here](http://antonmenshov.com/2017/09/09/clang-openmp-setup-in-xcode/) and [discussion](https://github.com/bakercp/ofxTSNEParallel/issues/1).

###

### Linux

1. It should run. :smile:

### Window

1. I doubt it will run without some work.

