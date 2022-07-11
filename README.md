# RapidLibBela

## Context

### RapidLib

[![GitHub license](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://github.com/mzed/RapidLib/blob/master/LICENSE)

#### main
![Linux Build](https://github.com/mzed/RapidLib/workflows/Linux%20Build/badge.svg?branch=main)  
![Windows Build](https://github.com/mzed/RapidLib/workflows/Windows%20Build/badge.svg?branch=main)  
![MacOS Build](https://github.com/mzed/RapidLib/workflows/Mac%20Build/badge.svg?branch=main)

#### dev
![Linux Build](https://github.com/mzed/RapidLib/workflows/Linux%20Build/badge.svg?branch=dev)  
![Windows Build](https://github.com/mzed/RapidLib/workflows/Windows%20Build/badge.svg?branch=dev)  
![MacOS Build](https://github.com/mzed/RapidLib/workflows/Mac%20Build/badge.svg?branch=dev)

RapidLib is a lightweight library for interactive machine learning. It currently features classification (using kNN), regression (multilayer perceptron), and series classification (using dynamic time warping).

More at: https://mzed.github.io/RapidLib/

### Bela

Bela is a platform for ultra-low latency audio and sensor processing.

http://bela.io

## Install

See Releases.

## Build

- Requires "experimental" Bela image with recent CMake: https://github.com/BelaPlatform/bela-image-builder/releases/tag/v0.5.0alpha2.
- Highly recommended to install `distcc` ([guide](https://gist.github.com/jarmitage/2a5dffbcfdd5532371f097e9bb80e4b0)).
- `git clone` RapidLib onto Bela ([connecting to network on Bela](https://learn.bela.io/using-bela/bela-techniques/connecting-to-wifi))
- Comment out DTW multi-threading test (see https://github.com/mzed/RapidLib/issues/20).
- Build commands from inside `RapidLib` dir:

```sh
mkdir build && cd build
CC="distcc-clang" CXX="distcc-clang++" cmake -DCMAKE_CXX_FLAGS="-Werror" ..
CC="distcc-clang" CXX="distcc-clang++" cmake
ctest
```
- `make` parameters for RapidLib projects (see [Bela Blog](https://blog.bela.io/using-an-external-library-with-bela/)):

```
LDFLAGS=-L/root/RapidLib/build;LDLIBS=-lrapidLib;CPPFLAGS=-I/root/RapidLib/src;
```

## Examples

Currently very simple, based on https://github.com/mzed/ofxRapidLib

## Todo

- [ ] Benchmark RapidLib performance on Bela
- [ ] Add C++ examples using `AuxiliaryTask`
- [ ] Add C++ examples using sensor inputs and audio outputs
- [ ] Add C++ examples with Bela GUIs
- [ ] Add `install` to CMake to simplify installation
- [ ] Scope out SuperCollider / Pure Data support and examples
