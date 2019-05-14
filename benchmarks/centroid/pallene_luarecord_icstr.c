/* This file was generated by the Pallene compiler. Do not edit by hand */
/* Indentation and formatting courtesy of pallene/pretty.lua */

#include <string.h>

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

#include "pallene_core.h"

static Table * function_new_pallene(
    lua_State * L,
    lua_Number x1 /* x */,
    lua_Number x2 /* y */
){
    static TString * x8;
    static TString * x12;
    static int ic = 0;
    if (ic == 0) {
        ic = 1;
        CClosure * x3 = clCvalue(s2v(L->ci->func));
        Udata * x4 /* upvalue table */ = uvalue(&x3->upvalue[0]);
        UValue * x5 /* upvalue array */ = x4->uv;
        TValue * x7 =  &x5[3].uv ;
        x8 = tsvalue(x7);
        TValue * x11 =  &x5[4].uv ;
        x12 = tsvalue(x11);
    }

    {
        luaC_condGC(L, {
        }, {
        });
        Table * x6 = luaH_new(L);
        luaH_resize(L, x6, 0, 2);
        TValue x9;
        setsvalue(L, &x9, x8);
        TValue * x10 = luaH_newkey(L, x6, &x9);
        setfltvalue(x10, x1);
        TValue x13;
        setsvalue(L, &x13, x12);
        TValue * x14 = luaH_newkey(L, x6, &x13);
        setfltvalue(x14, x2);
        return x6;
    }
}

static int function_new_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Udata * x2 /* upvalue table */ = uvalue(&x1->upvalue[0]);
    UValue * x3 /* upvalue array */ = x2->uv;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (PALLENE_UNLIKELY(x5 != 2)) {
        pallene_runtime_arity_error(L, 2, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (PALLENE_UNLIKELY(!ttisfloat(x6))) {
        pallene_runtime_argument_type_error(L, "x", 2, LUA_TNUMFLT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (PALLENE_UNLIKELY(!ttisfloat(x7))) {
        pallene_runtime_argument_type_error(L, "y", 2, LUA_TNUMFLT, x7);
    }
    lua_Number x8 = fltvalue(s2v(x4 + 1));
    lua_Number x9 = fltvalue(s2v(x4 + 2));
    Table * x10 /* ret */ = function_new_pallene(L, x8, x9);
    sethvalue(L, s2v(L->top), x10);
    api_incr_top(L);
    return 1;
}

static Table * function_centroid_pallene(
    lua_State * L,
    Table * x1 /* points */,
    lua_Integer x2 /* nrep */
){
    lua_checkstack(L, 1);

    static TString * x24;
    static TString * x30;
    static TString * x39;
    static TString * x45;
    static int ic = 0;
    if (ic == 0) {
        ic = 1;
        CClosure * x3 = clCvalue(s2v(L->ci->func));
        Udata * x4 /* upvalue table */ = uvalue(&x3->upvalue[0]);
        UValue * x5 /* upvalue array */ = x4->uv;
        TValue * x23 =  &x5[3].uv ;
        x24 = tsvalue(x23);
        TValue * x29 =  &x5[4].uv ;
        x30 = tsvalue(x29);
        TValue * x38 =  &x5[3].uv ;
        x39 = tsvalue(x38);
        TValue * x44 =  &x5[4].uv ;
        x45 = tsvalue(x44);
    }

    {
        lua_Number x6 /* x */ = 0x0p+0 /*0.000000*/;
        lua_Number x7 /* y */ = 0x0p+0 /*0.000000*/;
        lua_Integer x8 = luaH_getn(x1);
        lua_Integer x9 /* npoints */ = x8;
        lua_Integer x10 /* start */ = 1;
        lua_Integer x11 /* limit */ = x2;
        lua_Integer x12 /* step */ = 1;
        while ((x12 >= 0 ? x10 <= x11 : x10 >= x11)) {
            lua_Integer x13 /* _ */ = x10;
            (void) x13;
            {
                x6 = 0x0p+0 /*0.000000*/;
                x7 = 0x0p+0 /*0.000000*/;
                lua_Integer x14 /* start */ = 1;
                lua_Integer x15 /* limit */ = x9;
                lua_Integer x16 /* step */ = 1;
                while ((x16 >= 0 ? x14 <= x15 : x14 >= x15)) {
                    lua_Integer x17 /* i */ = x14;
                    (void) x17;
                    {
                        lua_Unsigned x18 /* ui */ = ((lua_Unsigned)x17) - 1;
                        const TValue * x19 /* arrslot */;
                        if (PALLENE_LIKELY(x18 < x1->sizearray)) {
                            x19 = &x1->array[x18];
                        }
                        else {
                            x19 = (TValue *)luaH_getint(x1, x17);
                        }
                        if (PALLENE_UNLIKELY(!ttistable(x19))) {
                            pallene_runtime_array_type_error(L, 14, LUA_TTABLE, rawtt(x19));
                        }
                        Table * x20 = hvalue(x19);
                        Table * x21 /* p */ = x20;
                        static int x26 = INT_MAX;
                        TValue * x25 = pallene_getstr(x21, x24, &x26);
                        if (PALLENE_UNLIKELY(!ttisfloat(x25))) {
                            pallene_runtime_lrecord_type_error(
                                L, "x", 15, LUA_TNUMFLT, rawtt(x25)
                            );
                        }
                        lua_Number x22 = fltvalue(x25);
                        lua_Number x27 = x6 + x22;
                        x6 = x27;
                        static int x32 = INT_MAX;
                        TValue * x31 = pallene_getstr(x21, x30, &x32);
                        if (PALLENE_UNLIKELY(!ttisfloat(x31))) {
                            pallene_runtime_lrecord_type_error(
                                L, "y", 16, LUA_TNUMFLT, rawtt(x31)
                            );
                        }
                        lua_Number x28 = fltvalue(x31);
                        lua_Number x33 = x7 + x28;
                        x7 = x33;
                    }
                    x14 = intop(+, x14, x16);
                }
            }
            x10 = intop(+, x10, x12);
        }
        luaC_condGC(L, {
            StackValue* x34 = L->top;
            sethvalue(L, s2v(x34), x1); x34++;
            L->top = x34;
        }, {
            L->top -= 1;
        });
        Table * x35 = luaH_new(L);
        luaH_resize(L, x35, 0, 2);
        lua_Number x36 = (lua_Number) x9;
        lua_Number x37 = x6 / x36;
        TValue x40;
        setsvalue(L, &x40, x39);
        TValue * x41 = luaH_newkey(L, x35, &x40);
        setfltvalue(x41, x37);
        lua_Number x42 = (lua_Number) x9;
        lua_Number x43 = x7 / x42;
        TValue x46;
        setsvalue(L, &x46, x45);
        TValue * x47 = luaH_newkey(L, x35, &x46);
        setfltvalue(x47, x43);
        return x35;
    }
}

static int function_centroid_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Udata * x2 /* upvalue table */ = uvalue(&x1->upvalue[0]);
    UValue * x3 /* upvalue array */ = x2->uv;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (PALLENE_UNLIKELY(x5 != 2)) {
        pallene_runtime_arity_error(L, 2, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (PALLENE_UNLIKELY(!ttistable(x6))) {
        pallene_runtime_argument_type_error(L, "points", 6, LUA_TTABLE, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (PALLENE_UNLIKELY(!ttisinteger(x7))) {
        pallene_runtime_argument_type_error(L, "nrep", 6, LUA_TNUMINT, x7);
    }
    Table * x8 = hvalue(s2v(x4 + 1));
    lua_Integer x9 = ivalue(s2v(x4 + 2));
    Table * x10 /* ret */ = function_centroid_pallene(L, x8, x9);
    sethvalue(L, s2v(L->top), x10);
    api_incr_top(L);
    return 1;
}

int luaopen_benchmarks_centroid_pallene_luarecord_icstr(lua_State *L)
{
    lua_checkstack(L, 4);
    /* Allocate upvalue table */
    /* ---------------------- */
    Udata * x1 = luaS_newudata(L, 0, 7);
    UValue * x2 = x1->uv;
    /* Initialize upvalues */
    /* ------------------- */
    TString * x3 = luaS_new(L, "__index");
    setsvalue(L,  &x2[0].uv , x3);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x3))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x4 = luaS_new(L, "__newindex");
    setsvalue(L,  &x2[1].uv , x4);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x4))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x5 = luaS_new(L, "__metatable");
    setsvalue(L,  &x2[2].uv , x5);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x5))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x6 = luaS_new(L, "x");
    setsvalue(L,  &x2[3].uv , x6);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x6))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x7 = luaS_new(L, "y");
    setsvalue(L,  &x2[4].uv , x7);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x7))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* new */
    CClosure* x8 = luaF_newCclosure(L, 1);
    x8->f = function_new_lua;
    setuvalue(L, &x8->upvalue[0], x1);
    TValue x9; setclCvalue(L, &x9, x8);
    setobj(L,  &x2[5].uv , &x9);
    if (iscollectable(&x9) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x9))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* centroid */
    CClosure* x10 = luaF_newCclosure(L, 1);
    x10->f = function_centroid_lua;
    setuvalue(L, &x10->upvalue[0], x1);
    TValue x11; setclCvalue(L, &x11, x10);
    setobj(L,  &x2[6].uv , &x11);
    if (iscollectable(&x11) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x11))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* Create exports table */
    /* -------------------- */
    StackValue* x12 = L->top;
    setuvalue(L, s2v(x12), x1); x12++;
    L->top = x12;
    lua_createtable(L, 0, 2);
    lua_pushstring(L, "new");
    setobj(L, s2v(L->top),  &x2[5].uv ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "centroid");
    setobj(L, s2v(L->top),  &x2[6].uv ); api_incr_top(L);
    lua_settable(L, -3);
    return 1;
}
