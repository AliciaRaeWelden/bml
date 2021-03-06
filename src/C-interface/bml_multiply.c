#include "bml_multiply.h"
#include "bml_introspection.h"
#include "bml_logger.h"
#include "dense/bml_multiply_dense.h"
#include "ellpack/bml_multiply_ellpack.h"
#include "ellsort/bml_multiply_ellsort.h"

#include <stdlib.h>

/** Matrix multiply.
 *
 * \f$ C \leftarrow \alpha \, A \, B + \beta C \f$
 *
 * \ingroup multiply_group_C
 *
 * \param A Matrix A
 * \param B Matrix B
 * \param C Matrix C
 * \param alpha Scalar factor that multiplies A * B
 * \param beta Scalar factor that multiplies C
 * \param threshold Threshold for multiplication
 */
void
bml_multiply(
    const bml_matrix_t * A,
    const bml_matrix_t * B,
    bml_matrix_t * C,
    const double alpha,
    const double beta,
    const double threshold)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_multiply_dense(A, B, C, alpha, beta);
            break;
        case ellpack:
            bml_multiply_ellpack(A, B, C, alpha, beta, threshold);
            break;
        case ellsort:
            bml_multiply_ellsort(A, B, C, alpha, beta, threshold);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
}

/** Matrix multiply.
 *
 * \f$ X^2 \leftarrow X \, X \f$
 *
 * \ingroup multiply_group_C
 *
 * \param X Matrix X
 * \param X2 MatrixX2
 * \param threshold Threshold for multiplication
 */
void *
bml_multiply_x2(
    const bml_matrix_t * X,
    bml_matrix_t * X2,
    const double threshold)
{
    switch (bml_get_type(X))
    {
        case dense:
            return bml_multiply_x2_dense(X, X2);
            break;
        case ellpack:
            return bml_multiply_x2_ellpack(X, X2, threshold);
            break;
        case ellsort:
            return bml_multiply_x2_ellsort(X, X2, threshold);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
    return NULL;
}

/** Matrix multiply.
 *
 * C = A * B
 *
 * \ingroup multiply_group_C
 *
 * \param A Matrix A
 * \param B Matrix B
 * \param C Matrix C
 * \param threshold Threshold for multiplication
 */
void
bml_multiply_AB(
    const bml_matrix_t * A,
    const bml_matrix_t * B,
    bml_matrix_t * C,
    const double threshold)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_multiply_AB_dense(A, B, C);
            break;
        case ellpack:
            bml_multiply_AB_ellpack(A, B, C, threshold);
            break;
        case ellsort:
            bml_multiply_AB_ellsort(A, B, C, threshold);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
}

/** Matrix multiply with threshold adjustment.
 *
 * C = A * B
 *
 * \ingroup multiply_group_C
 *
 * \param A Matrix A
 * \param B Matrix B
 * \param C Matrix C
 * \param threshold Threshold for multiplication
 */
void
bml_multiply_adjust_AB(
    const bml_matrix_t * A,
    const bml_matrix_t * B,
    bml_matrix_t * C,
    const double threshold)
{
    switch (bml_get_type(A))
    {
        case dense:
            bml_multiply_adjust_AB_dense(A, B, C);
            break;
        case ellpack:
            bml_multiply_adjust_AB_ellpack(A, B, C, threshold);
            break;
        case ellsort:
            bml_multiply_adjust_AB_ellsort(A, B, C, threshold);
            break;
        default:
            LOG_ERROR("unknown matrix type\n");
            break;
    }
}
