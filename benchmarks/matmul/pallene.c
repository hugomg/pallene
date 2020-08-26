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
static Table * function_02(
    lua_State *L,
    Udata *G,
    StackValue *base,
    Table *x1, /* A */
    Table *x2  /* B */
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
    ptrdiff_t base_offset = savestack(L, base);
    	
}

/* matmul benchmarks/matmul/pallene.pln:1 */
static Table * function_02(
    lua_State *L,
    Udata *G,
    StackValue *base,
    Table *x1, /* A */
    Table *x2  /* B */
) {
    luaD_checkstack(L, 2);
    ptrdiff_t base_offset = savestack(L, base);
    	
    Table *x3; /* C */
    lua_Integer x4; /* NI */
    lua_Integer x5; /* NK */
    lua_Integer x6; /* NJ */
    Table *x7;
    lua_Integer x8; /* i */
    Table *x9; /* line */
    lua_Integer x10; /* j */
    lua_Integer x11; /* k */
    Table *x12; /* Bk */
    lua_Integer x13; /* i */
    lua_Number x14; /* Aik */
    Table *x15;
    Table *x16; /* Ci */
    lua_Integer x17; /* j */
    lua_Number x18;
    lua_Number x19;
    lua_Number x20;
    lua_Number x21;
    	
    x3 = pallene_createtable(L, 0, 0);
    sethvalue(L, s2v(base + 0), x3);
    luaC_condGC(L, L->top = base + 1, (void)0);
    if (x1->metatable) {
        pallene_runtime_array_metatable_error(L, 3);
    }
    x4 = luaH_getn(x1);
    if (x2->metatable) {
        pallene_runtime_array_metatable_error(L, 4);
    }
    x5 = luaH_getn(x2);
    {
        pallene_renormalize_array(L, x2, 1, 5);
        TValue *slot = &x2->array[1 - 1];
        if (PALLENE_UNLIKELY(!ttistable(slot))) {
            pallene_runtime_tag_check_error(L,
                5, LUA_TTABLE, rawtt(slot),
                "array element");
        }
        x7 = hvalue(slot);
    }
    if (x7->metatable) {
        pallene_runtime_array_metatable_error(L, 5);
    }
    x6 = luaH_getn(x7);
    PALLENE_INT_FOR_LOOP_BEGIN(x8, 1, x4, 1)
    {
        x9 = pallene_createtable(L, 0, 0);
        sethvalue(L, s2v(base + 1), x9);
        luaC_condGC(L, L->top = base + 2, (void)0);
        PALLENE_INT_FOR_LOOP_BEGIN(x10, 1, x6, 1)
        {
            {
                pallene_renormalize_array(L, x9, x10, 9);
                TValue *slot = &x9->array[x10 - 1];
                setfltvalue(slot, 0.0);
            }
        }
        PALLENE_INT_FOR_LOOP_END
        {
            pallene_renormalize_array(L, x3, x8, 11);
            TValue *slot = &x3->array[x8 - 1];
            sethvalue(L, slot, x9);
            pallene_barrierback_unboxed(L, obj2gco(x3), obj2gco(x9));
        }
    }
    PALLENE_INT_FOR_LOOP_END
    PALLENE_INT_FOR_LOOP_BEGIN(x11, 1, x5, 1)
    {
        {
            pallene_renormalize_array(L, x2, x11, 14);
            TValue *slot = &x2->array[x11 - 1];
            if (PALLENE_UNLIKELY(!ttistable(slot))) {
                pallene_runtime_tag_check_error(L,
                    14, LUA_TTABLE, rawtt(slot),
                    "array element");
            }
            x12 = hvalue(slot);
        }
        PALLENE_INT_FOR_LOOP_BEGIN(x13, 1, x4, 1)
        {
            {
                pallene_renormalize_array(L, x1, x13, 16);
                TValue *slot = &x1->array[x13 - 1];
                if (PALLENE_UNLIKELY(!ttistable(slot))) {
                    pallene_runtime_tag_check_error(L,
                        16, LUA_TTABLE, rawtt(slot),
                        "array element");
                }
                x15 = hvalue(slot);
            }
            {
                pallene_renormalize_array(L, x15, x11, 16);
                TValue *slot = &x15->array[x11 - 1];
                if (PALLENE_UNLIKELY(!ttisfloat(slot))) {
                    pallene_runtime_tag_check_error(L,
                        16, LUA_VNUMFLT, rawtt(slot),
                        "array element");
                }
                x14 = fltvalue(slot);
            }
            {
                pallene_renormalize_array(L, x3, x13, 17);
                TValue *slot = &x3->array[x13 - 1];
                if (PALLENE_UNLIKELY(!ttistable(slot))) {
                    pallene_runtime_tag_check_error(L,
                        17, LUA_TTABLE, rawtt(slot),
                        "array element");
                }
                x16 = hvalue(slot);
            }
            PALLENE_INT_FOR_LOOP_BEGIN(x17, 1, x6, 1)
            {
                {
                    pallene_renormalize_array(L, x16, x17, 19);
                    TValue *slot = &x16->array[x17 - 1];
                    if (PALLENE_UNLIKELY(!ttisfloat(slot))) {
                        pallene_runtime_tag_check_error(L,
                            19, LUA_VNUMFLT, rawtt(slot),
                            "array element");
                    }
                    x19 = fltvalue(slot);
                }
                {
                    pallene_renormalize_array(L, x12, x17, 19);
                    TValue *slot = &x12->array[x17 - 1];
                    if (PALLENE_UNLIKELY(!ttisfloat(slot))) {
                        pallene_runtime_tag_check_error(L,
                            19, LUA_VNUMFLT, rawtt(slot),
                            "array element");
                    }
                    x21 = fltvalue(slot);
                }
                x20 = x14 * x21;
                x18 = x19 + x20;
                {
                    pallene_renormalize_array(L, x16, x17, 19);
                    TValue *slot = &x16->array[x17 - 1];
                    setfltvalue(slot, x18);
                }
            }
            PALLENE_INT_FOR_LOOP_END
        }
        PALLENE_INT_FOR_LOOP_END
    }
    PALLENE_INT_FOR_LOOP_END
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
    if (PALLENE_UNLIKELY(nargs != 2)) {
        pallene_runtime_arity_error(L, "matmul", 2, nargs);
    }
    	
    Table *x1;
    Table *x2;
    	
    if (PALLENE_UNLIKELY(!ttistable(s2v(base + 1)))) {
        pallene_runtime_tag_check_error(L,
            1, LUA_TTABLE, rawtt(s2v(base + 1)),
            "argument '%s'", "A");
    }
    x1 = hvalue(s2v(base + 1));
    	
    if (PALLENE_UNLIKELY(!ttistable(s2v(base + 2)))) {
        pallene_runtime_tag_check_error(L,
            1, LUA_TTABLE, rawtt(s2v(base + 2)),
            "argument '%s'", "B");
    }
    x2 = hvalue(s2v(base + 2));
    	
    Table *ret1;
    ret1 = function_02(L, G, L->top, x1, x2);
    sethvalue(L, s2v(L->top), ret1);
    L->top++;
    return 1;
}

int luaopen_benchmarks_matmul_pallene(lua_State *L)
{
    luaL_checkversion(L);
    	
    /* Constants */
    	
    lua_newuserdatauv(L, 0, 1);
    int globals = lua_gettop(L);
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_02_lua, 1);
    lua_setiuservalue(L, globals, 1);
    	
    /* Variables & Initializers */
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_01_lua, 1);
    lua_call(L, 0, 0);
    	
    /* Exports */
    	
    lua_newtable(L);
    int export_table = lua_gettop(L);
    	
    lua_pushstring(L, "matmul");
    lua_getiuservalue(L, globals, 1);
    lua_settable(L, export_table);
    	
    lua_pushvalue(L, export_table);
    return 1;
}

