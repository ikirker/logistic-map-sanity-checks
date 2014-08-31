#include "vec_type.h"

void vector_subtract (Vec_Type *vec_result, Vec_Type *vec_a, Vec_Type *vec_b, int num_elements) {
    int i;

    for (i = 0; i < num_elements; i++) {
        vec_result[i] = vec_a[i] - vec_b[i];
    }
}

