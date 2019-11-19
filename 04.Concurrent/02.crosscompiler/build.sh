#./bootstrap.sh -with-toolset=gcc

#PATH=/opt/tooling/bosch/OSTC_5.4/aarch64-none-linux-gnueabi/bin:$PATH

PATH=/home/etr1hc/samba/view/gcc-linaro-arm-linux-master/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabihf/bin:$PATH
 
export PAT

#./bootstrap.sh -with-toolset=aarch64-none-linux-gnueabi-gcc
./b2 --clean
./b2  toolset=gcc-arm
 

#https://boostorg.github.io/build/manual/develop/index.html#bbv2.tasks.crosscompile
#https://github.com/boostorg/build/issues/385
