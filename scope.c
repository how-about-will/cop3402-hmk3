#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "scope.h"
#include "utilities.h"

//allocates a new scope symbol table and returns a pointer to it.
scope_t* scope_create(){
    scope_t* new_s = malloc(sizeof(scope_t));
    if(new_s == NULL){
        bail_with_error("No space for new scope_t!");
    }
    new_s->size = 0;
    new_s->loc_count = 0;
    for(int i = 0; i < MAX_SCOPE_SIZE; i++){
        new_s->entries[i] = NULL;
    }
}