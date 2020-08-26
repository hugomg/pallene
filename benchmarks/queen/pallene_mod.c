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
static int function_02(
    lua_State *L,
    Udata *G,
    StackValue *base,
    Table *x1, /* a */
    lua_Integer x2, /* n */
    lua_Integer x3  /* c */
);
static void function_03(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1, /* N */
    Table *x2  /* a */
);
static void function_04(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1, /* N */
    Table *x2, /* a */
    lua_Integer x3  /* n */
);
static void function_05(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1  /* N */
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

/* isplaceok benchmarks/queen/pallene.pln:2 */
static int function_02(
    lua_State *L,
    Udata *G,
    StackValue *base,
    Table *x1, /* a */
    lua_Integer x2, /* n */
    lua_Integer x3  /* c */
) {
    ptrdiff_t base_offset = savestack(L, base);
    	
    lua_Integer x4;
    lua_Integer x5; /* i */
    lua_Integer x6; /* d */
    int x7;
    int x8;
    int x9;
    lua_Integer x10;
    lua_Integer x11;
    int x12;
    lua_Integer x13;
    lua_Integer x14;
    	
    x4 = intop(-, x2, 1);
    PALLENE_INT_FOR_LOOP_BEGIN(x5, 1, x4, 1)
    {
        {
            pallene_renormalize_array(L, x1, x5, 4);
            TValue *slot = &x1->array[x5 - 1];
            if (PALLENE_UNLIKELY(!ttisinteger(slot))) {
                pallene_runtime_tag_check_error(L,
                    4, LUA_VNUMINT, rawtt(slot),
                    "array element");
            }
            x6 = ivalue(slot);
        }
        x8 = (x6 == x3);
        x7 = x8;
        if (!x7) {
            x10 = intop(-, x6, x5);
            x11 = intop(-, x3, x2);
            x9 = (x10 == x11);
            x7 = x9;
        }
        if (!x7) {
            x13 = intop(+, x6, x5);
            x14 = intop(+, x3, x2);
            x12 = (x13 == x14);
            x7 = x12;
        }
        if (x7) {
            return 0;
        }
    }
    PALLENE_INT_FOR_LOOP_END
    return 1;
}

/* printsolution benchmarks/queen/pallene.pln:16 */
static void function_03(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1, /* N */
    Table *x2  /* a */
) {
    ptrdiff_t base_offset = savestack(L, base);
    	
    lua_Integer x3; /* i */
    lua_Integer x4; /* ai */
    lua_Integer x5; /* j */
    int x6;
    	
    PALLENE_INT_FOR_LOOP_BEGIN(x3, 1, x1, 1)
    {
        {
            pallene_renormalize_array(L, x2, x3, 18);
            TValue *slot = &x2->array[x3 - 1];
            if (PALLENE_UNLIKELY(!ttisinteger(slot))) {
                pallene_runtime_tag_check_error(L,
                    18, LUA_VNUMINT, rawtt(slot),
                    "array element");
            }
            x4 = ivalue(slot);
        }
        PALLENE_INT_FOR_LOOP_BEGIN(x5, 1, x1, 1)
        {
            x6 = (x4 == x5);
            if (x6) {
                pallene_io_write(L, tsvalue(&G->uv[0].uv));
            } else {
                pallene_io_write(L, tsvalue(&G->uv[1].uv));
            }
            pallene_io_write(L, tsvalue(&G->uv[2].uv));
        }
        PALLENE_INT_FOR_LOOP_END
        pallene_io_write(L, tsvalue(&G->uv[3].uv));
    }
    PALLENE_INT_FOR_LOOP_END
    pallene_io_write(L, tsvalue(&G->uv[3].uv));
}

/* addqueen benchmarks/queen/pallene.pln:34 */
static void function_04(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1, /* N */
    Table *x2, /* a */
    lua_Integer x3  /* n */
) {
    ptrdiff_t base_offset = savestack(L, base);
    	
    int x4;
    lua_Integer x5; /* c */
    int x6;
    lua_Integer x7;
    	
    x4 = (x3 > x1);
    if (x4) {
        function_03(L, G, base + 0, x1, x2);
        base = restorestack(L, base_offset);
    } else {
        PALLENE_INT_FOR_LOOP_BEGIN(x5, 1, x1, 1)
        {
            x6 = function_02(L, G, base + 0, x2, x3, x5);
            base = restorestack(L, base_offset);
            if (x6) {
                {
                    pallene_renormalize_array(L, x2, x3, 40);
                    TValue *slot = &x2->array[x3 - 1];
                    setivalue(slot, x5);
                }
                x7 = intop(+, x3, 1);
                function_04(L, G, base + 0, x1, x2, x7);
                base = restorestack(L, base_offset);
            }
        }
        PALLENE_INT_FOR_LOOP_END
    }
}

/* nqueens benchmarks/queen/pallene.pln:48 */
static void function_05(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1  /* N */
) {
    luaD_checkstack(L, 1);
    ptrdiff_t base_offset = savestack(L, base);
    	
    Table *x2;
    	
    x2 = pallene_createtable(L, 0, 0);
    sethvalue(L, s2v(base + 0), x2);
    luaC_condGC(L, L->top = base + 1, (void)0);
    function_04(L, G, base + 1, x1, x2, 1);
    base = restorestack(L, base_offset);
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

static int function_05_lua(lua_State *L)
{
    StackValue *base = L->ci->func;
    CClosure *func = clCvalue(s2v(base));
    Udata *G = uvalue(&func->upvalue[0]);
    	
    int nargs = lua_gettop(L);
    if (PALLENE_UNLIKELY(nargs != 1)) {
        pallene_runtime_arity_error(L, "nqueens", 1, nargs);
    }
    	
    lua_Integer x1;
    	
    if (PALLENE_UNLIKELY(!ttisinteger(s2v(base + 1)))) {
        pallene_runtime_tag_check_error(L,
            48, LUA_VNUMINT, rawtt(s2v(base + 1)),
            "argument '%s'", "N");
    }
    x1 = ivalue(s2v(base + 1));
    	
    function_05(L, G, L->top, x1);
    return 0;
}

int luaopen_benchmarks_queen_pallene_mod(lua_State *L)
{
    luaL_checkversion(L);
    	
    /* Constants */
    	
    lua_newuserdatauv(L, 0, 5);
    int globals = lua_gettop(L);
    	
    lua_pushstring(L, "X");
    lua_setiuservalue(L, globals, 1);
    	
    lua_pushstring(L, "-");
    lua_setiuservalue(L, globals, 2);
    	
    lua_pushstring(L, " ");
    lua_setiuservalue(L, globals, 3);
    	
    lua_pushstring(L, "\n");
    lua_setiuservalue(L, globals, 4);
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_05_lua, 1);
    lua_setiuservalue(L, globals, 5);
    	
    /* Variables & Initializers */
    	
    lua_pushvalue(L, globals);
    lua_pushcclosure(L, function_01_lua, 1);
    lua_call(L, 0, 0);
    	
    /* Exports */
    	
    lua_newtable(L);
    int export_table = lua_gettop(L);
    	
    lua_pushstring(L, "nqueens");
    lua_getiuservalue(L, globals, 5);
    lua_settable(L, export_table);
    	
    lua_pushvalue(L, export_table);
    return 1;
}

