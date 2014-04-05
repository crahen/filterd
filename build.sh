#!/ffp/bin/bash
mkdir -p scratch
cd scratch
../configure --prefix=$PWD/out
make
make install
