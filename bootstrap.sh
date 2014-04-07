#!/ffp/bin/bash
[ ! -e ./configure ] && autoreconf
mkdir -p scratch
cd scratch
../configure --prefix=$PWD/out
make
make install
