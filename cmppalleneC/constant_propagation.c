/* This file was generated by the Pallene compiler. Do not edit by hand" */
/* Indentation and formatting courtesy of pallene/C.lua */

#include "pallene_core.h"

/* ------- */
/* Records */
/* ------- */

/* ------------------- */
/* Function Prototypes */
/* ------------------- */

static void function_01(
    lua_State *L,
    Udata *G,
    StackValue *base
);
static lua_Integer function_02(
    lua_State *L,
    Udata *G,
    StackValue *base
);
static lua_Integer function_03(
    lua_State *L,
    Udata *G,
    StackValue *base
);
static lua_Integer function_04(
    lua_State *L,
    Udata *G,
    StackValue *base
);

/* ------------------------ */
/* Function Implementations */
/* ------------------------ */

/* $init */
static void function_01(
    lua_State *L,
    Udata *G,
    StackValue *base
) {
    	
}

/* simple cmppalleneC/constant_propagation.pln:1 */
static lua_Integer function_02(
    lua_State *L,
    Udata *G,
    StackValue *base
) {
    lua_Integer x1; /* x */
    lua_Integer x2; /* y */
    	
    x1 = 3;
    x2 = intop(+, x1, 4);
    return x2;
}

/* control cmppalleneC/constant_propagation.pln:7 */
static lua_Integer function_03(
    lua_State *L,
    Udata *G,
    StackValue *base
) {
    lua_Integer x1; /* x */
    lua_Integer x2; /* y */
    int x3;
    	
    x1 = 3;
    x2 = 0;
    x3 = (x1 < 5);
    if (x3) {
        x2 = intop(+, x1, 4);
    } else {
        x2 = intop(+, x1, 5);
    }
    return x2;
}

/* alias cmppalleneC/constant_propagation.pln:18 */
static lua_Integer function_04(
    lua_State *L,
    Udata *G,
    StackValue *base
) {
    lua_Integer x1; /* x */
    lua_Integer x2; /* z */
    lua_Integer x3; /* y */
    int x4;
    	
    x1 = 3;
    x2 = x1;
    x3 = 0;
    x4 = (x1 < 5);
    if (x4) {
        x3 = intop(+, x2, 4);
    } else {
        x3 = intop(+, x2, 5);
    }
    return x3;
}

/* ------- */
/* Exports */
/* ------- */

static int function_01_lua(lua_State *L)
{
    StackValue *base = L->ci->func;
    CClosure *func = clCvalue(s2v(base));
    Udata *G = uvalue(&func->upvalue[0]);
    	
    int nargs = lua_gettop(L);
    if (PALLENE_UNLIKELY(nargs != 0)) {
        pallene_runtime_arity_error(L, "$init", 0, nargs);
    }
    	
    function_01(L, G, L->top);
    return 0;
}

static int function_02_lua(lua_State *L)
{
    StackValue *base = L->ci->func;
    CClosure *func = clCvalue(s2v(base));
    Udata *G = uvalue(&func->upvalue[0]);
    	
    int nargs = lua_gettop(L);
    if (PALLENE_UNLIKELY(nargs != 0)) {
        pallene_runtime_arity_error(L, "simple", 0, nargs);
    }
    	
    lua_Integer ret1;
    ret1 = function_02(L, G, L->top);
    setivalue(s2v(L->top), ret1);
    L->top++;
    return 1;
}

static int function_03_lua(lua_State *L)
{
    StackValue *base = L->ci->func;
    CClosure *func = clCvalue(s2v(base));
    Udata *G = uvalue(&func->upvalue[0]);
    	
    int nargs = lua_gettop(L);
    if (PALLENE_UNLIKELY(nargs != 0)) {
        pallene_runtime_arity_error(L, "control", 0, nargs);
    }
    	
    lua_Integer ret1;
    ret1 = function_03(L, G, L->top);
    setivalue(s2v(L->top), ret1);
    L->top++;
    return 1;
}

static int function_04_lua(lua_State *L)
{
    StackValue *base = L->ci->func;
    CClosure *func = clCvalue(s2v(base));
    Udata *G = uvalue(&func->upvalue[0]);
    	
    int nargs = lua_gettop(L);
    if (PALLENE_UNLIKELY(nargs != 0)) {
        pallene_runtime_arity_error(L, "alias", 0, nargs);
    }
    	
    lua_Integer ret1;
    ret1 = function_04(L, G, L->top);
    setivalue(s2v(L->top), ret1);
    L->top++;
    return 1;
}

int luaopen_cmppalleneC_constant_propagation(lua_State *L)
{
    luaL_checkversion(L);
    	
    lua_newuserdatauv(L, 0, 0);
    int globals = lua_gettop(L);
    	
    lua_createtable(L, 4, 0);
    int closures = lua_gettop(L);
    	
    lua_newtable(L);
    int export_table = lua_gettop(L);
    	
    /* Closures */
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_01_lua, 1);
    lua_seti(L, closures, 1);
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_02_lua, 1);
    lua_seti(L, closures, 2);
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_03_lua, 1);
    lua_seti(L, closures, 3);
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_04_lua, 1);
    lua_seti(L, closures, 4);
    	
    /* Global values */
    	
    // Run toplevel statements & initialize globals
    lua_geti(L, closures, 1);
    lua_call(L, 0, 0);
    	
    /* Exports */
    	
    lua_pushstring(L, "simple");
    lua_geti(L, closures, 2);
    lua_settable(L, export_table);
    	
    lua_pushstring(L, "control");
    lua_geti(L, closures, 3);
    lua_settable(L, export_table);
    	
    lua_pushstring(L, "alias");
    lua_geti(L, closures, 4);
    lua_settable(L, export_table);
    	
    lua_pushvalue(L, export_table);
    return 1;
}

