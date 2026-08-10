#!/bin/bash
wget https://archive.org/download/animal-crossing-usa/Animal%20Crossing%20%28USA%29.iso -O orig/GAFE01_00/GAFE01_00.iso
./setup_build_linux32.sh
meson compile -C build_linux32
