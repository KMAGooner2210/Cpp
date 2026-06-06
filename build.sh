#!/bin/bash
mkdir -p build
cd build

cmake -DCMAKE_C_COMPILER=gcc-13 -DCMAKE_CXX_COMPILER=g++-13 ..
make -j$(nproc)
echo "===BIEN DICH HOAN TAT ==="

