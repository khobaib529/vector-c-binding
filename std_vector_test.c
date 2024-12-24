// Tests for the C API wrapper of C++ std::vector<void*>
// Verifies basic vector operations (create, insert, retrieve, destroy) and
// ensures the vector can store any data type using void*.

#include "std_vector.h"

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create a new empty std::vector using the C-style API
  std_vector_t* std_vector = std_vector_create();

  // Dynamically allocate an array of 10 integers and initialize it with some
  // values
  int* arr = (int*)malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; ++i) {
    arr[i] = i * i + 10 * i + 7;  // Assign values 7 18 31 to the array
  }

  // Push each element of the array into the std::vector
  for (int i = 0; i < 10; ++i) {
    std_vector_push_back(std_vector, (void*)&arr[i]);
  }

  // Print the contents of the vector (casting the void pointers back to
  // integers)
  printf("[ ");
  for (int i = 0; i < 10; ++i) {
    printf("%d ", *((int*)std_vector_at(
                      std_vector, i)));  // Dereference each element as an int
  }
  printf("]");

  printf("\n\n");

  // Print the size and capacity of the vector
  printf("size: %ld\n", std_vector_size(std_vector));
  printf("capacity: %ld\n", std_vector_capacity(std_vector));

  // Print the first and last elements of the vector
  printf("front: %d\n",
         *((int*)std_vector_front(std_vector)));  // Dereference front element
  printf("back: %d\n",
         *((int*)std_vector_back(std_vector)));  // Dereference back element

  // Clean up by destroying the vector and freeing the dynamically allocated
  // array
  std_vector_destroy(std_vector);
  free(arr);

  return 0;
}
