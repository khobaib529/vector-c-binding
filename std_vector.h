// C++ STL std::vector<void*> wrapper for C API usage
// This code provides a set of C-compatible functions to interact with C++ std::vector,
// allowing C programs to create, manipulate, and manage vectors of void pointers.

#ifndef STD_VECTOR_H_
#define STD_VECTOR_H_

#include<stddef.h>

/** Opaque type representing the vector (internal structure is hidden). */
typedef struct std_vector_t std_vector_t;

/** Creates a new vector. Returns NULL on failure. */
std_vector_t* std_vector_create(void);

/** Adds an element to the back of the vector. */
void std_vector_push_back(std_vector_t* std_vector, void* data);

/** Removes the last element of the vector. */
void std_vector_pop_back(std_vector_t* std_vector);

/** Returns the current size of the vector. */
size_t std_vector_size(std_vector_t* std_vector);

/** Returns the element at the specified index. */
void* std_vector_at(std_vector_t* std_vector, int i);

/** Returns the capacity of the vector. */
size_t std_vector_capacity(std_vector_t* std_vector);

/** Returns a pointer to the vector's raw data. */
void* std_vector_data(std_vector_t* std_vector);

/** Shrinks the vector's capacity to fit its size. */
void std_vector_shrink_to_fit(std_vector_t* std_vector);

/** Returns a pointer to the first element, or NULL if empty. */
void* std_vector_front(std_vector_t* std_vector);

/** Returns a pointer to the last element, or NULL if empty. */
void* std_vector_back(std_vector_t* std_vector);

/** Destroys the vector and frees its memory. */
void std_vector_destroy(std_vector_t* std_vector);

#endif // STD_VECTOR_H_
