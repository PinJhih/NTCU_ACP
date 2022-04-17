date: date.o

test: date_test.exe

date.o: date.cpp
	g++ -c date.cpp

date_test.exe: test_date.cpp date.o
	g++ -o test_date.exe test_date.cpp date.o
