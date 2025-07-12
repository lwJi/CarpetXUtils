#!/bin/bash

set -ex

export CARPETXUTILSSPACE="$PWD"
export WORKSPACE="$PWD/../workspace"
mkdir -p "$WORKSPACE"
cd "$WORKSPACE"

# Check out Cactus
wget https://raw.githubusercontent.com/gridaphobe/CRL/master/GetComponents
chmod a+x GetComponents
./GetComponents --no-parallel --shallow "$CARPETXUTILSSPACE/scripts/carpetxutils.th"

cd Cactus

# Create a link to the CarpetXUtils repository
ln -s "$CARPETXUTILSSPACE" repos
# Create links for the CarpetXUtils thorns
mkdir -p arrangements/CarpetXUtils
pushd arrangements/CarpetXUtils
ln -s ../../repos/CarpetXUtils/* .
popd
