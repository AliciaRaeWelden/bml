#include "bml.h"
#include "bml_test.h"

#include <math.h>
#include <stdlib.h>

int test_function(const int N,
                  const bml_matrix_type_t matrix_type,
                  const bml_matrix_precision_t matrix_precision)
{
    bml_matrix_t *A;
    REAL_TYPE *A_dense;
    REAL_TYPE *B_dense;

    A_dense = bml_allocate_memory(sizeof(REAL_TYPE)*N*N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            A_dense[i+j*N] = rand()/(REAL_TYPE) RAND_MAX;
        }
    }
    A = bml_convert_from_dense(matrix_type, A_dense, 0);
    B_dense = bml_convert_to_dense(A);
    for(int i = 0; i < N*N; i++) {
        if(fabs(A_dense[i]-B_dense[i]) > 1e-12) {
            bml_log(BML_LOG_ERROR, "matrix element mismatch\n");
        }
    }
    return 0;
}