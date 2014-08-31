#include "vec_type.h"

const Vec_Type epsilon = 1e-10;

int vector_compare (Vec_Type *vec_a, Vec_Type *vec_b, int num_elements) {
    int i;

    for (i = 0; i < num_elements; i++) {
        if (vec_a[i] - vec_b[i] > epsilon) {
            return 0;
        }
    }

    return 1;
}

