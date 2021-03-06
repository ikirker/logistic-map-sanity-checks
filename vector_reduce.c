#include "vec_type.h"

#include <stdio.h>

Vec_Type vector_reduce(
        Vec_Type id_element,
        Vec_Type *v,
        Vec_Type (*reduction_function)(Vec_Type, Vec_Type), 
        int number_of_elements
        ) 
{
    int i;
    Vec_Type running_value = id_element;

    for (i = 0; i < number_of_elements; i++) {
        running_value = (*reduction_function)(running_value, v[i]);
    }

    return running_value;
}

