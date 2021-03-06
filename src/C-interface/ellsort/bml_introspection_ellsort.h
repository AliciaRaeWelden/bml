#ifndef __BML_INTROSPECTION_ELLSORT_H
#define __BML_INTROSPECTION_ELLSORT_H

#include "bml_types_ellsort.h"

bml_matrix_precision_t bml_get_precision_ellsort(
    const bml_matrix_ellsort_t * A);

bml_distribution_mode_t bml_get_distribution_mode_ellsort(
    const bml_matrix_ellsort_t * A);

int bml_get_N_ellsort(
    const bml_matrix_ellsort_t * A);

int bml_get_M_ellsort(
    const bml_matrix_ellsort_t * A);

int bml_get_row_bandwidth_ellsort(
    const bml_matrix_ellsort_t * A,
    const int i);

int bml_get_bandwidth_ellsort(
    const bml_matrix_ellsort_t * A);

#endif
