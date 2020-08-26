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
static void function_02(
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

/* mandelbrot benchmarks/mandelbrot/pallene.pln:1 */
static void function_02(
    lua_State *L,
    Udata *G,
    StackValue *base,
    lua_Integer x1  /* N */
) {
    luaD_checkstack(L, 1);
    ptrdiff_t base_offset = savestack(L, base);
    	
    lua_Integer x2; /* bits */
    lua_Integer x3; /* nbits */
    lua_Number x4; /* delta */
    lua_Number x5;
    lua_Integer x6;
    lua_Integer x7; /* y */
    lua_Number x8; /* Ci */
    lua_Number x9;
    lua_Number x10;
    lua_Integer x11;
    lua_Integer x12; /* x */
    lua_Number x13; /* Cr */
    lua_Number x14;
    lua_Number x15;
    lua_Integer x16; /* bit */
    lua_Number x17; /* Zr */
    lua_Number x18; /* Zi */
    lua_Number x19; /* Zr2 */
    lua_Number x20; /* Zi2 */
    lua_Integer x21; /* _ */
    lua_Number x22;
    lua_Number x23;
    lua_Number x24;
    int x25;
    lua_Number x26;
    lua_Integer x27;
    int x28;
    TString *x29;
    int x30;
    lua_Integer x31;
    TString *x32;
    	
    x2 = 0;
    x3 = 0;
    x5 = (lua_Number) x1;
    x4 = 2.0 / x5;
    x6 = intop(-, x1, 1);
    PALLENE_INT_FOR_LOOP_BEGIN(x7, 0, x6, 1)
    {
        x10 = (lua_Number) x7;
        x9 = x10 * x4;
        x8 = x9 - 1.0;
        x11 = intop(-, x1, 1);
        PALLENE_INT_FOR_LOOP_BEGIN(x12, 0, x11, 1)
        {
            x15 = (lua_Number) x12;
            x14 = x15 * x4;
            x13 = x14 - 1.5;
            x16 = 1;
            x17 = 0.0;
            x18 = 0.0;
            x19 = 0.0;
            x20 = 0.0;
            PALLENE_INT_FOR_LOOP_BEGIN(x21, 1, 50, 1)
            {
                x23 = 2.0 * x17;
                x22 = x23 * x18;
                x18 = x22 + x8;
                x24 = x19 - x20;
                x17 = x24 + x13;
                x20 = x18 * x18;
                x19 = x17 * x17;
                x26 = x20 + x19;
                x25 = (x26 > 4.0);
                if (x25) {
                    x16 = 0;
                    break;
                }
            }
            PALLENE_INT_FOR_LOOP_END
            x27 = pallene_shiftL(x2, 1);
            x2 = intop(|, x27, x16);
            x3 = intop(+, x3, 1);
            x28 = (x3 == 8);
            if (x28) {
                x29 = pallene_string_char(L, x2, 31);
                setsvalue(L, s2v(base + 0), x29);
                luaC_condGC(L, L->top = base + 1, (void)0);
                pallene_io_write(L, x29);
                x2 = 0;
                x3 = 0;
            }
        }
        PALLENE_INT_FOR_LOOP_END
        x30 = (x3 > 0);
        if (x30) {
            x31 = intop(-, 8, x3);
            x2 = pallene_shiftL(x2, x31);
            x32 = pallene_string_char(L, x2, 39);
            setsvalue(L, s2v(base + 0), x32);
            luaC_condGC(L, L->top = base + 1, (void)0);
            pallene_io_write(L, x32);
            x2 = 0;
            x3 = 0;
        }
    }
    PALLENE_INT_FOR_LOOP_END
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
    if (PALLENE_UNLIKELY(nargs != 1)) {
        pallene_runtime_arity_error(L, "mandelbrot", 1, nargs);
    }
    	
    lua_Integer x1;
    	
    if (PALLENE_UNLIKELY(!ttisinteger(s2v(base + 1)))) {
        pallene_runtime_tag_check_error(L,
            1, LUA_VNUMINT, rawtt(s2v(base + 1)),
            "argument '%s'", "N");
    }
    x1 = ivalue(s2v(base + 1));
    	
    function_02(L, G, L->top, x1);
    return 0;
}

int luaopen_benchmarks_mandelbrot_pallene(lua_State *L)
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
    	
    lua_pushstring(L, "mandelbrot");
    lua_getiuservalue(L, globals, 1);
    lua_settable(L, export_table);
    	
    lua_pushvalue(L, export_table);
    return 1;
}

