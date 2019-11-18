g++ -std=c++11  -I /home/etr1hc/samba/view/boost main.cpp -L /home/etr1hc/samba/view/boost/stage/lib -lboost_thread -pthread 


LD_LIBRARY_PATH=/home/etr1hc/samba/view/boost/stage/lib:$LD_LIBRARY_PATH
export LD_LIBRARY_PATH

./a.out 

