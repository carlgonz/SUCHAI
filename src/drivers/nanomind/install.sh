#!/bin/sh
echo "Checking avr32-gcc Version..."
avr32-gcc --version
avr32-as --version

echo "Downloading OBC drivers SDK..."
if [ ! -d "suchai-drivers-obc" ]; then
    git clone https://github.com/spel-uchile/suchai-drivers-obc
else
    cd suchai-drivers-obc
    git pull
    cd -
fi

echo "Linking source code into SDK..."
cd suchai-drivers-obc
mv src/ src.old/
ln -s -f ../../../../src
cd -

echo "Downloading BUS drivers..."
if [ ! -d "suchai-drivers-bus" ]; then
    git clone https://github.com/spel-uchile/suchai-drivers-bus suchai-drivers-bus
else
    cd suchai-drivers-bus
    git pull
    cd -
fi

echo "Linking BUS drivers into SDK"
cd suchai-drivers-obc/lib/
# Link all bus libraries
# for f in ../../suchai-drivers-bus/lib/*; do ln -s -f $f; done
# Link only used bus libraries
ln -s -f ../../suchai-drivers-bus/lib/libgssb_client
ln -s -f ../../suchai-drivers-bus/lib/libparam_client
ln -s -f ../../suchai-drivers-bus/lib/nanocom-ax_client
ln -s -f ../../suchai-drivers-bus/lib/nanopower-bpx_client
ln -s -f ../../suchai-drivers-bus/lib/nanopower_client
cd -

echo "Preparing build tools"
cd suchai-drivers-obc
python2 ./tools/buildtools/gsbuildtools_bootstrap.py

cd -
