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

// Return the current scope's next location count (of variables).
unsigned int symtab_scope_loc_count(){
    return scope_loc_count(symtab[symtab_top]);
}

// Return the current scope's size (the number of declared ids).
unsigned int symtab_scope_size(){
    return scope_size(symtab[symtab_top]);
}

//checks if the current scope is full
bool symtab_scope_full(){
    return scope_full(symtab[symtab_top]);
}

// Return the current nesting level of the symbol table.
// The first enterscope will have this return 0 as its nesting level.
unsigned int symtab_current_nesting_level(){
    // assert(symtab_top_idx >= 0);
    return symtab_top;
}

//checks if the symboltable is full
bool symtab_full(){
    return symtab_current_nesting_level() == MAX_NESTING - 1;
}

//checks if a name was declared in any scope in the symbol table
bool symtab_declared(const char *name){
    return symtab_lookup(name) != NULL;
}

//checks if a name was declared in the current scope
bool symtab_declared_in_current_scope(const char *name)
{
    id_attrs *attrs = scope_lookup(symtab[symtab_top], name);
    return attrs != NULL;
}
