#include "vec_type.h"
#include <math.h>

void vector_abs(Vec_Type *v, int num_elements) {
    int i;
    for (i = 0; i < num_elements; i++) {
        v[i] = fabs(v[i]);
    }
}

