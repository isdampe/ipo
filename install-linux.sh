#!/bin/bash
./build-linux.sh
sudo cp build/ipo /usr/local/bin/ipo
echo "Build and installation complete. Run with \"ipo [hostname] [port] [port] ...\"\n"
