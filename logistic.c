#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include "vec_type.h"

void logistic(Vec_Type starting_val, Vec_Type *buffer, int iterations) {
    int i;
    Vec_Type x = starting_val;

    for (i = 0; i < iterations; i++) {
        x = 4*x*(1-x);
        buffer[i] = x;
    }
}

Vec_Type v_type_add(Vec_Type a, Vec_Type b) {
    return a + b;
}

int main(int argc, char **argv) {
    int ierr;
    ierr = MPI_Init(&argc, &argv);
    
    int my_rank;  ierr = MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    int ranks;    ierr = MPI_Comm_size(MPI_COMM_WORLD, &ranks);

    const int store_size = 128;
    Vec_Type map_store[store_size];
    Vec_Type root_map[store_size];
    Vec_Type residual[store_size];
    Vec_Type residual_sum;

    logistic(0.2, map_store, store_size);

    if (my_rank == 0) {
        memcpy(root_map, map_store, store_size * sizeof(Vec_Type));
    }
 
    ierr = MPI_Bcast(root_map, store_size, MY_MPI_VEC_TYPE, 0, MPI_COMM_WORLD);
    
    vector_subtract(residual, map_store, root_map, store_size);

    vector_abs(residual, store_size);

    residual_sum = vector_reduce(0.0, residual, &v_type_add, store_size);
    
    printf("%d: %.12g\n", my_rank, residual_sum);

    MPI_Finalize();
    return 0;
}

int serial_main(int argc, char **argv) {
    int i;
    const int store_size = 100;
    Vec_Type map_store[store_size];
    
    logistic(0.2, map_store, store_size);
    
    for (i=0; i<store_size; i++) {
        printf("%.12g \n", map_store[i]);
    }

    return 0;
}
