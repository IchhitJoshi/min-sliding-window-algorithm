all: test usecase

test: test_minqueue.cpp
	g++ test_minqueue.cpp -o test

usecase: main.cpp
	g++ main.cpp -o usecase

clean:
	rm -f *.o test usecase

