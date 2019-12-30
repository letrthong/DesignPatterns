g++ mock_turtle_test.cpp -I /usr/local/include/  -L /usr/local/lib/  -lgmock -lgmock_main   -lgtest_main  -lgtest  -lpthread 

PATH=$PATH:/usr/local/lib/ ; 
export PATH 
./a.out 

