meta:
	ADDON_NAME = ofxTSNEParallel
	ADDON_DESCRIPTION = An Parallel TSNE wrapper.
	ADDON_AUTHOR = Christopher Baker
	ADDON_TAGS = "machine learning" "tsne"
	ADDON_URL = http://github.com/bakercp/ofxTSNEParallel

common:

osx:
	# FOR OPENMP SUPPORT ON OSX
	# brew install llvm
	# Then, use the makefile system to compile the examples.
	# This OPENMP won't work with Xcode currently.
	ADDON_LDFLAGS += -L/usr/local/opt/llvm/lib -lomp
	ADDON_CFLAGS += -fopenmp -I/usr/local/opt/llvm/include
	PROJECT_CXX += /usr/local/opt/llvm/bin/clang++
	PROJECT_CC += /usr/local/opt/llvm/bin/clang

linux64:
	ADDON_LDFLAGS += -lgomp
	ADDON_CFLAGS += -fopenmp
