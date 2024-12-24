// C++ STL std::vector<void*> wrapper for C API usage
// This code provides a set of C-compatible functions to interact with C++
// std::vector, allowing C programs to create, manipulate, and manage vectors of
// void pointers.

#include <vector>

// C-style API wrapper for C++ std::vector<void*> operations
extern "C" {
#include "std_vector.h"
}

// Creates a new std::vector<void*> and returns a pointer to it
std_vector_t* std_vector_create() {
  return reinterpret_cast<std_vector_t*>(new std::vector<void*>());
}

// Pushes a new element (void*) to the back of the std::vector
void std_vector_push_back(std_vector_t* std_vector, void* data) {
  reinterpret_cast<std::vector<void*>*>(std_vector)->push_back(data);
}

// Pops the last element from the std::vector
void std_vector_pop_back(std_vector_t* std_vector) {
  reinterpret_cast<std::vector<void*>*>(std_vector)->pop_back();
}

// Returns the size (number of elements) of the std::vector
size_t std_vector_size(std_vector_t* std_vector) {
  return reinterpret_cast<std::vector<void*>*>(std_vector)->size();
}

// Destroys the std::vector and frees its memory
void std_vector_destroy(std_vector_t* std_vector) {
  delete reinterpret_cast<std::vector<void*>*>(std_vector);
}

// Returns the element at the specified index (i) in the std::vector
void* std_vector_at(std_vector_t* std_vector, int i) {
  return reinterpret_cast<std::vector<void*>*>(std_vector)->at(i);
}

// Returns the capacity of the std::vector (allocated space)
size_t std_vector_capacity(std_vector_t* std_vector) {
  return reinterpret_cast<std::vector<void*>*>(std_vector)->capacity();
}

// Returns a pointer to the underlying data array of the std::vector
void* std_vector_data(std_vector_t* std_vector) {
  return reinterpret_cast<std::vector<void*>*>(std_vector)->data();
}

// Shrinks the std::vector's capacity to fit its size
void std_vector_shrink_to_fit(std_vector_t* std_vector) {
  reinterpret_cast<std::vector<void*>*>(std_vector)->shrink_to_fit();
}

// Returns the last element of the std::vector
void* std_vector_back(std_vector_t* std_vector) {
  return reinterpret_cast<std::vector<void*>*>(std_vector)->back();
}

// Returns the first element of the std::vector
void* std_vector_front(std_vector_t* std_vector) {
  return reinterpret_cast<std::vector<void*>*>(std_vector)->front();
}
