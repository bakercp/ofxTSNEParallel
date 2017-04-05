# ofxTSNEParallel

A parallel version of ofxTSNE.

It simply wraps [Multicore-TSNE](https://github.com/DmitryUlyanov/Multicore-TSNE) and should be API compatible with [ofxTSNE](https://github.com/genekogan/ofxTSNE).

## Instructions
### OSX
[Multicore-TSNE](https://github.com/DmitryUlyanov/Multicore-TSNE) uses OpenMP, which is unsupported by default on OSX (at this point at least). In order to run on OSX, do the following:

1. Install [homebrew](https://brew.sh/).
2. Install `llvm` via `brew install llvm`.
3. Run the example via the `Makefile` system (Xcode is not currently working).
  - Special flags are listed in the `addon_config.mk` file that allows the `Makefile` to use the appropriate brew-installed OpenMP-compatible `llvm` compiler.
4. `cd example/`
5. `make -j4 -s`
6. `make run` to run the example.

### Linux

1. It should run. :smile:

### Window

1. I doubt it will run without some work.

