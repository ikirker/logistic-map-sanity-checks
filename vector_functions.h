#include "vec_type.h"

void vector_abs(Vec_Type *v, int num_elements);
int vector_compare (Vec_Type *vec_a, Vec_Type *vec_b, int num_elements);
void vector_subtract (Vec_Type *vec_result, Vec_Type *vec_a, Vec_Type *vec_b, int num_elements);

Vec_Type vector_reduce(
        Vec_Type id_element,
        Vec_Type *v,
        Vec_Type (*reduction_function)(Vec_Type, Vec_Type), 
        int number_of_elements
        ); 
