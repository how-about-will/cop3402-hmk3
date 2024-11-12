#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "id_attrs.h"
#include "file_location.h"
#include "ast.h"
#include "utilities.h"
#include "symtab.h"
#include "scope_check.h"



block_t scope_check_program(block_t prog){
    symtab_enter_scope();

    scope_check_const_decls(prog.const_decls);
    scope_check_var_decls(prog.var_decls);
    scope_check_proc_decls(prog.proc_decls);
    scope_check_stmts(prog.stmts);

    symtab_leave_scope();
    return prog;
}

//scope checks const_decls
void scope_check_const_decls(const_decls_t decls){
    const_decl_t* constDecl = decls.start;
    unsigned int offset_count = 0;
    while(constDecl != NULL){
        //chech each def in def_list
        const_def_t* constDef = constDecl->const_def_list.start;

        while(constDef != NULL){
            const char* name = constDef->ident.name;

            id_attrs *attrs = create_id_attrs(*constDef->ident.file_loc, constant_idk, offset_count);

            //check for already declared error
            if(!symtab_declared_in_current_scope(name) && attrs != NULL){
                symtab_insert(name, attrs);
            }
            else{
                bail_with_error("Constant '%s' is already declared in this scope", name);
            }
            //scope_check_const_delc(*constDecl->next); I don't think we need this
            constDef = constDef->next;
            offset_count++;
        }
        constDecl = constDecl->next;
    }
}

void scope_check_var_decls(var_decls_t decls)
{
    
}

void scope_check_proc_decls(proc_decls_t decls)
{

}

void scope_check_stmts(stmts_t stmts)
{

}
