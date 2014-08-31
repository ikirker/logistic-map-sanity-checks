#include "vec_type.h"
#include <stdlib.h>

int vector_abs(Vec_Type *v, int num_elements) {
    int i;
    for (i = 0; i < num_elements; i++) {
        v[i] = abs(v[i]);
    }
}

