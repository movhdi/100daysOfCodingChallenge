#!/bin/bash
echo "${BASH_SOURCE[0]}"
echo "$(dirname -- "${BASH_SOURCE[0]}")"
SCRIPT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)
rm -rf $SCRIPT_DIR/build
mkdir $SCRIPT_DIR/build
cd $SCRIPT_DIR/build
cmake .. 
cmake --build .

$SCRIPT_DIR/build/target
