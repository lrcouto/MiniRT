#!/bin/bash

#Install MiniLibX dependencies.
apt-get install -y gcc \
make \
libxext-dev \
libxrandr-dev \
libx11-dev \
libbsd-dev \
libssl-dev

#Go to MiniLibX folder.
cd ./libs/minilibx-linux/

#Compile MiniLibX.
make

#Create folder for MiniLibX manual
mkdir -p /usr/local/man/man1
sudo cp man/man1/* /usr/local/man/man1/

#INstall MiniLibX
sudo cp libmlx.a /usr/local/lib/
sudo cp mlx.h /usr/local/include/
sudo cp mlx_int.h /usr/local/include/

