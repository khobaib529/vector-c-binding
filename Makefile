std_vector_test: std_vector_test.o std_vector.o
	g++ -Wall std_vector.o std_vector_test.o -o std_vector_test

std_vector.o: std_vector.cc std_vector.h
	g++ -Wall -c std_vector.cc -o std_vector.o

std_vector_test.o: std_vector_test.c std_vector.h
	gcc -Wall -c std_vector_test.c -o std_vector_test.o

clean:
	rm std_vector_test.o std_vector.o std_vector_test
