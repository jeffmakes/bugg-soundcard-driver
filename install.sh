#!/bin/bash
# Install script for the project

echo "Entering the codec directory"
cd codec
make install
cd ..

echo "Entering the device tree directory"
cd dt
make install
cd ..