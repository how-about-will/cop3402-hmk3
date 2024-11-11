#include "symtab.h"
#include "scope.h"
#include "utilities.h"

//symbol table is a stack of scope

// index of the top of the stack of scopes
static int symtab_top = -1;

// the symbol table itself
static scope_t *symtab[MAX_NESTING];

// initialize the symbol table
void symtab_initialize()
{
    // initialize the internal state
    symtab_top = -1;
    for (int i = 0; i < MAX_NESTING; i++) {
	symtab[i] = NULL;
    }
}

//returns number of scopes currently in symtab
unsigned int symtab_size(){
    return symtab_top + 1;
}
//returns true if symtab is empty
bool symtab_empty(){
    return (symtab_size() == 0);
}

