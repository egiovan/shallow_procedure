#include <stdio.h>
#include "ISO_Fortran_binding.h"
#define SHALLOW_FAILURE -100

int reorder_dim(CFI_cdesc_t *v, int order[], int n) {
    CFI_dim_t dim[CFI_MAX_RANK];
    int copied[CFI_MAX_RANK] = {0};

    if (n <= 0) return CFI_SUCCESS;

    // n can be less then rank in this case the first n dimensions are modified
    if (n > v->rank) return SHALLOW_FAILURE;

    for(int i=0; i < n; i++) {
        if (order[i] < 0 | order[i] >= n) return SHALLOW_FAILURE;
        int k = order[i];
        copied[k] = 1;

        dim[i].extent = v->dim[k].extent;
        dim[i].lower_bound = v->dim[k].lower_bound;
        dim[i].sm = v->dim[k].sm;
    }
    // check that all dims have been copied
    for(int i=0; i<n; i++) {
        if (copied[i] == 0) return SHALLOW_FAILURE;
    }
    // update the descriptor
    // This part is not conforming
    for(int i=0; i<n; i++) {
        v->dim[i].extent = dim[i].extent;
        v->dim[i].lower_bound = dim[i].lower_bound;
        v->dim[i].sm = dim[i].sm;
    }

    return CFI_SUCCESS;
}

void shallow_transpose(CFI_cdesc_t *src, CFI_cdesc_t *dst, int *status) {
    int order[2] = {1,0};

    *status = CFI_setpointer(dst, src, 0);
    if (*status != CFI_SUCCESS) return;
    
    *status = reorder_dim(dst, order, 2);
}
