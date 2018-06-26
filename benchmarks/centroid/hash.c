/* This file was generated by the Titan compiler. Do not edit by hand */
/* Indentation and formatting courtesy of titan-compiler/pretty.lua */

#include <string.h>

#include "tcore.h"

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#include "lapi.h"
#include "lfunc.h"
#include "lgc.h"
#include "lobject.h"
#include "lstate.h"
#include "lstring.h"
#include "ltable.h"
#include "lvm.h"

#include "math.h"

static Table * function_new_titan(
    lua_State * L,
    lua_Number x1 /* x */,
    lua_Number x2 /* y */
){
    CClosure * x3 = clCvalue(s2v(L->ci->func));
    Table * x4 /* upvalue table */ = hvalue(&x3->upvalue[0]);
    TValue * x5 /* upvalue array */ = x4->array;
    (void)x5;
    {
        luaC_condGC(L, {
        }, {
        });
        Table * x6 = luaH_new(L);
        luaH_resizearray(L, x6, 2);
        TValue * x7 = x6->array;
        setfltvalue(x7 + 0, x1);
        setfltvalue(x7 + 1, x2);
        return x6;
    }
}

static int function_new_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 2)) {
        titan_runtime_arity_error(L, 2, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttisfloat(x6))) {
        titan_runtime_argument_type_error(L, "x", 1, LUA_TNUMFLT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisfloat(x7))) {
        titan_runtime_argument_type_error(L, "y", 1, LUA_TNUMFLT, x7);
    }
    lua_Number x8 = fltvalue(s2v(x4 + 1));
    lua_Number x9 = fltvalue(s2v(x4 + 2));
    Table * x10 /* ret */ = function_new_titan(L, x8, x9);
    sethvalue(L, s2v(L->top), x10);
    api_incr_top(L);
    return 1;
}

static Table * function_centroid_titan(
    lua_State * L,
    Table * x1 /* points */,
    lua_Integer x2 /* N */
){
    lua_checkstack(L, 1);
    CClosure * x3 = clCvalue(s2v(L->ci->func));
    Table * x4 /* upvalue table */ = hvalue(&x3->upvalue[0]);
    TValue * x5 /* upvalue array */ = x4->array;
    (void)x5;
    {
        lua_Number x6 /* x */ = 0x0p+0 /*0.000000*/;
        lua_Number x7 /* y */ = 0x0p+0 /*0.000000*/;
        lua_Integer x8 /* start */ = 1;
        lua_Integer x9 /* finish */ = x2;
        lua_Integer x10 /* inc */ = 1;
        while ((x10 >= 0 ? x8 <= x9 : x8 >= x9)) {
            lua_Integer x11 /* _ */ = x8;
            (void) x11;
            {
                x6 = 0x0p+0 /*0.000000*/;
                x7 = 0x0p+0 /*0.000000*/;
                lua_Integer x13 = luaH_getn(x1);
                lua_Integer x12 /* start */ = 1;
                lua_Integer x14 /* finish */ = x13;
                lua_Integer x15 /* inc */ = 1;
                while ((x15 >= 0 ? x12 <= x14 : x12 >= x14)) {
                    lua_Integer x16 /* i */ = x12;
                    (void) x16;
                    {
                        lua_Unsigned x17 /* ui */ = ((lua_Unsigned)x16) - 1;
                        const TValue * x18 /* arrslot */;
                        if (TITAN_LIKELY(x17 < x1->sizearray)) {
                            x18 = &x1->array[x17];
                        } else {
                            x18 = luaH_getint(x1, x16);
                        }
                        if (TITAN_UNLIKELY(!ttistable(x18))) {
                            titan_runtime_array_type_error(L, 12, LUA_TTABLE, rawtt(x18));
                        }
                        Table * x19 = hvalue(x18);
                        Table * x20 /* p */ = x19;
                        lua_Unsigned x21 /* ui */ = ((lua_Unsigned)1) - 1;
                        const TValue * x22 /* arrslot */;
                        if (TITAN_LIKELY(x21 < x20->sizearray)) {
                            x22 = &x20->array[x21];
                        } else {
                            x22 = luaH_getint(x20, 1);
                        }
                        if (TITAN_UNLIKELY(!ttisfloat(x22))) {
                            titan_runtime_array_type_error(L, 13, LUA_TNUMFLT, rawtt(x22));
                        }
                        lua_Number x23 = fltvalue(x22);
                        lua_Number x24 = x6 + x23;
                        x6 = x24;
                        lua_Unsigned x25 /* ui */ = ((lua_Unsigned)2) - 1;
                        const TValue * x26 /* arrslot */;
                        if (TITAN_LIKELY(x25 < x20->sizearray)) {
                            x26 = &x20->array[x25];
                        } else {
                            x26 = luaH_getint(x20, 2);
                        }
                        if (TITAN_UNLIKELY(!ttisfloat(x26))) {
                            titan_runtime_array_type_error(L, 14, LUA_TNUMFLT, rawtt(x26));
                        }
                        lua_Number x27 = fltvalue(x26);
                        lua_Number x28 = x7 + x27;
                        x7 = x28;
                    }
                    x12 = intop(+, x12, x15);
                }
            }
            x8 = intop(+, x8, x10);
        }
        luaC_condGC(L, {
            StackValue* x29 = L->top;
            sethvalue(L, s2v(x29), x1); x29++;
            L->top = x29;
        }, {
            L->top -= 1;
        });
        Table * x30 = luaH_new(L);
        luaH_resizearray(L, x30, 2);
        TValue * x31 = x30->array;
        lua_Integer x32 = luaH_getn(x1);
        lua_Number x33 = (lua_Number) x32;
        lua_Number x34 = x6 / x33;
        setfltvalue(x31 + 0, x34);
        lua_Integer x35 = luaH_getn(x1);
        lua_Number x36 = (lua_Number) x35;
        lua_Number x37 = x7 / x36;
        setfltvalue(x31 + 1, x37);
        return x30;
    }
}

static int function_centroid_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Table * x2 /* upvalue table */ = hvalue(&x1->upvalue[0]);
    TValue * x3 /* upvalue array */ = x2->array;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (TITAN_UNLIKELY(x5 != 2)) {
        titan_runtime_arity_error(L, 2, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (TITAN_UNLIKELY(!ttistable(x6))) {
        titan_runtime_argument_type_error(L, "points", 5, LUA_TTABLE, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (TITAN_UNLIKELY(!ttisinteger(x7))) {
        titan_runtime_argument_type_error(L, "N", 5, LUA_TNUMINT, x7);
    }
    Table * x8 = hvalue(s2v(x4 + 1));
    lua_Integer x9 = ivalue(s2v(x4 + 2));
    Table * x10 /* ret */ = function_centroid_titan(L, x8, x9);
    sethvalue(L, s2v(L->top), x10);
    api_incr_top(L);
    return 1;
}

int luaopen_benchmarks_centroid_hash(lua_State *L)
{
    lua_checkstack(L, 4);
    /* Allocate upvalue table */
    /* ---------------------- */
    Table * x1 = luaH_new(L);
    luaH_resizearray(L, x1, 4);
    TValue * x2 = x1->array;
    /* Initialize upvalues */
    /* ------------------- */
    TString * x3 = luaS_new(L, "__index");
    setsvalue(L,  &x2[0] , x3);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x3))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x4 = luaS_new(L, "__metatable");
    setsvalue(L,  &x2[1] , x4);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x4))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* new */
    CClosure* x5 = luaF_newCclosure(L, 1);
    x5->f = function_new_lua;
    sethvalue(L, &x5->upvalue[0], x1);
    TValue x6; setclCvalue(L, &x6, x5);
    setobj(L,  &x2[2] , &x6);
    if (iscollectable(&x6) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x6))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* centroid */
    CClosure* x7 = luaF_newCclosure(L, 1);
    x7->f = function_centroid_lua;
    sethvalue(L, &x7->upvalue[0], x1);
    TValue x8; setclCvalue(L, &x8, x7);
    setobj(L,  &x2[3] , &x8);
    if (iscollectable(&x8) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x8))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* Create exports table */
    /* -------------------- */
    StackValue* x9 = L->top;
    sethvalue(L, s2v(x9), x1); x9++;
    L->top = x9;
    lua_createtable(L, 0, 2);
    lua_pushstring(L, "new");
    setobj(L, s2v(L->top),  &x2[2] ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "centroid");
    setobj(L, s2v(L->top),  &x2[3] ); api_incr_top(L);
    lua_settable(L, -3);
    return 1;
}

