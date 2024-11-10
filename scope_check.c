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