#ifndef _SCOPE_H
#define _SCOPE_H

#include <stdbool.h>
#include "ast.h"
#include "machine_types.h"
#include "id_attrs.h"

//max number of declarations in one scope
#define MAX_SCOPE_SIZE 4096

typedef struct {
    const char *id;
    id_attrs *attrs;
} scope_assoc_t;

// Invariant: 0 <= size < MAX_SCOPE_SIZE;
typedef struct scope_s {
    unsigned int size;
    // num. of associations in this scope
    unsigned int loc_count;
    scope_assoc_t
                *entries[MAX_SCOPE_SIZE];
} scope_t;






#endif