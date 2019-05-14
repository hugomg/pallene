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

static Table * function_makebody_pallene(
    lua_State * L,
    lua_Number x1 /* x */,
    lua_Number x2 /* y */,
    lua_Number x3 /* z */,
    lua_Number x4 /* vx */,
    lua_Number x5 /* vy */,
    lua_Number x6 /* vz */,
    lua_Number x7 /* mass */
){
    CClosure * x8 = clCvalue(s2v(L->ci->func));
    Udata * x9 /* upvalue table */ = uvalue(&x8->upvalue[0]);
    UValue * x10 /* upvalue array */ = x9->uv;
    (void)x10;
    {
        luaC_condGC(L, {
        }, {
        });
        Table * x11 = luaH_new(L);
        luaH_resize(L, x11, 0, 7);
        TValue * x12 =  &x10[10].uv ;
        TString * x13 = tsvalue(x12);
        TValue x14;
        setsvalue(L, &x14, x13);
        TValue * x15 = luaH_newkey(L, x11, &x14);
        setfltvalue(x15, x1);
        TValue * x16 =  &x10[11].uv ;
        TString * x17 = tsvalue(x16);
        TValue x18;
        setsvalue(L, &x18, x17);
        TValue * x19 = luaH_newkey(L, x11, &x18);
        setfltvalue(x19, x2);
        TValue * x20 =  &x10[12].uv ;
        TString * x21 = tsvalue(x20);
        TValue x22;
        setsvalue(L, &x22, x21);
        TValue * x23 = luaH_newkey(L, x11, &x22);
        setfltvalue(x23, x3);
        TValue * x24 =  &x10[13].uv ;
        TString * x25 = tsvalue(x24);
        TValue x26;
        setsvalue(L, &x26, x25);
        TValue * x27 = luaH_newkey(L, x11, &x26);
        setfltvalue(x27, x4);
        TValue * x28 =  &x10[14].uv ;
        TString * x29 = tsvalue(x28);
        TValue x30;
        setsvalue(L, &x30, x29);
        TValue * x31 = luaH_newkey(L, x11, &x30);
        setfltvalue(x31, x5);
        TValue * x32 =  &x10[15].uv ;
        TString * x33 = tsvalue(x32);
        TValue x34;
        setsvalue(L, &x34, x33);
        TValue * x35 = luaH_newkey(L, x11, &x34);
        setfltvalue(x35, x6);
        TValue * x36 =  &x10[16].uv ;
        TString * x37 = tsvalue(x36);
        TValue x38;
        setsvalue(L, &x38, x37);
        TValue * x39 = luaH_newkey(L, x11, &x38);
        setfltvalue(x39, x7);
        return x11;
    }
}

static int function_makebody_lua(lua_State *L)
{
    lua_checkstack(L, 1);
    CClosure * x1 = clCvalue(s2v(L->ci->func));
    Udata * x2 /* upvalue table */ = uvalue(&x1->upvalue[0]);
    UValue * x3 /* upvalue array */ = x2->uv;
    (void)x3;
    StackValue* x4 = L->ci->func;
    int x5 /* nargs */ = cast_int(L->top - (x4 + 1));
    if (PALLENE_UNLIKELY(x5 != 7)) {
        pallene_runtime_arity_error(L, 7, x5);
    }
    TValue* x6 = s2v(x4 + 1);
    if (PALLENE_UNLIKELY(!ttisfloat(x6))) {
        pallene_runtime_argument_type_error(L, "x", 7, LUA_TNUMFLT, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (PALLENE_UNLIKELY(!ttisfloat(x7))) {
        pallene_runtime_argument_type_error(L, "y", 7, LUA_TNUMFLT, x7);
    }
    TValue* x8 = s2v(x4 + 3);
    if (PALLENE_UNLIKELY(!ttisfloat(x8))) {
        pallene_runtime_argument_type_error(L, "z", 7, LUA_TNUMFLT, x8);
    }
    TValue* x9 = s2v(x4 + 4);
    if (PALLENE_UNLIKELY(!ttisfloat(x9))) {
        pallene_runtime_argument_type_error(L, "vx", 7, LUA_TNUMFLT, x9);
    }
    TValue* x10 = s2v(x4 + 5);
    if (PALLENE_UNLIKELY(!ttisfloat(x10))) {
        pallene_runtime_argument_type_error(L, "vy", 7, LUA_TNUMFLT, x10);
    }
    TValue* x11 = s2v(x4 + 6);
    if (PALLENE_UNLIKELY(!ttisfloat(x11))) {
        pallene_runtime_argument_type_error(L, "vz", 7, LUA_TNUMFLT, x11);
    }
    TValue* x12 = s2v(x4 + 7);
    if (PALLENE_UNLIKELY(!ttisfloat(x12))) {
        pallene_runtime_argument_type_error(L, "mass", 7, LUA_TNUMFLT, x12);
    }
    lua_Number x13 = fltvalue(s2v(x4 + 1));
    lua_Number x14 = fltvalue(s2v(x4 + 2));
    lua_Number x15 = fltvalue(s2v(x4 + 3));
    lua_Number x16 = fltvalue(s2v(x4 + 4));
    lua_Number x17 = fltvalue(s2v(x4 + 5));
    lua_Number x18 = fltvalue(s2v(x4 + 6));
    lua_Number x19 = fltvalue(s2v(x4 + 7));
    Table * x20 /* ret */ = function_makebody_pallene(L, x13, x14, x15, x16, x17, x18, x19);
    sethvalue(L, s2v(L->top), x20);
    api_incr_top(L);
    return 1;
}

static void function_advance_pallene(
    lua_State * L,
    Table * x1 /* bodies */,
    lua_Number x2 /* dt */
){

    static TString *x16;
    static TString *x22;
    static TString *x28;
    static TString *x34;
    static TString *x40;
    static TString *x46;
    static TString *x52;
    static int ic = 0;
    if (ic == 0) {
        ic = 1;
        CClosure * x3 = clCvalue(s2v(L->ci->func));
        Udata * x4 /* upvalue table */ = uvalue(&x3->upvalue[0]);
        UValue * x5 /* upvalue array */ = x4->uv;
        x16 =  tsvalue(&x5[10].uv);
        x22 =  tsvalue(&x5[11].uv);
        x28 =  tsvalue(&x5[12].uv);
        x40 =  tsvalue(&x5[13].uv);
        x46 =  tsvalue(&x5[14].uv);
        x52 =  tsvalue(&x5[15].uv);
        x34 =  tsvalue(&x5[16].uv);
    }

    {
        lua_Integer x7 = luaH_getn(x1);
        lua_Integer x6 /* start */ = 1;
        lua_Integer x8 /* limit */ = x7;
        lua_Integer x9 /* step */ = 1;
        while ((x9 >= 0 ? x6 <= x8 : x6 >= x8)) {
            lua_Integer x10 /* i */ = x6;
            (void) x10;
            {
                lua_Unsigned x11 /* ui */ = ((lua_Unsigned)x10) - 1;
                const TValue * x12 /* arrslot */;
                if (PALLENE_LIKELY(x11 < x1->sizearray)) {
                    x12 = &x1->array[x11];
                }
                else {
                    x12 = (TValue *)luaH_getint(x1, x10);
                }
                if (PALLENE_UNLIKELY(!ttistable(x12))) {
                    pallene_runtime_array_type_error(L, 13, LUA_TTABLE, rawtt(x12));
                }
                Table * x13 = hvalue(x12);
                Table * x14 /* bi */ = x13;
                static int x19 = INT_MAX;
                TValue * x18 = pallene_getstr(x14, x16, &x19);
                if (PALLENE_UNLIKELY(!ttisfloat(x18))) {
                    pallene_runtime_lrecord_type_error(
                        L, "x", 14, LUA_TNUMFLT, rawtt(x18)
                    );
                }
                lua_Number x15 = fltvalue(x18);
                lua_Number x20 /* bix */ = x15;
                static int x25 = INT_MAX;
                TValue * x24 = pallene_getstr(x14, x22, &x25);
                if (PALLENE_UNLIKELY(!ttisfloat(x24))) {
                    pallene_runtime_lrecord_type_error(
                        L, "y", 15, LUA_TNUMFLT, rawtt(x24)
                    );
                }
                lua_Number x21 = fltvalue(x24);
                lua_Number x26 /* biy */ = x21;
                static int x31 = INT_MAX;
                TValue * x30 = pallene_getstr(x14, x28, &x31);
                if (PALLENE_UNLIKELY(!ttisfloat(x30))) {
                    pallene_runtime_lrecord_type_error(
                        L, "z", 16, LUA_TNUMFLT, rawtt(x30)
                    );
                }
                lua_Number x27 = fltvalue(x30);
                lua_Number x32 /* biz */ = x27;
                static int x37 = INT_MAX;
                TValue * x36 = pallene_getstr(x14, x34, &x37);
                if (PALLENE_UNLIKELY(!ttisfloat(x36))) {
                    pallene_runtime_lrecord_type_error(
                        L, "mass", 17, LUA_TNUMFLT, rawtt(x36)
                    );
                }
                lua_Number x33 = fltvalue(x36);
                lua_Number x38 /* bimass */ = x33;
                static int x43 = INT_MAX;
                TValue * x42 = pallene_getstr(x14, x40, &x43);
                if (PALLENE_UNLIKELY(!ttisfloat(x42))) {
                    pallene_runtime_lrecord_type_error(
                        L, "vx", 18, LUA_TNUMFLT, rawtt(x42)
                    );
                }
                lua_Number x39 = fltvalue(x42);
                lua_Number x44 /* bivx */ = x39;
                static int x49 = INT_MAX;
                TValue * x48 = pallene_getstr(x14, x46, &x49);
                if (PALLENE_UNLIKELY(!ttisfloat(x48))) {
                    pallene_runtime_lrecord_type_error(
                        L, "vy", 19, LUA_TNUMFLT, rawtt(x48)
                    );
                }
                lua_Number x45 = fltvalue(x48);
                lua_Number x50 /* bivy */ = x45;
                static int x55 = INT_MAX;
                TValue * x54 = pallene_getstr(x14, x52, &x55);
                if (PALLENE_UNLIKELY(!ttisfloat(x54))) {
                    pallene_runtime_lrecord_type_error(
                        L, "vz", 20, LUA_TNUMFLT, rawtt(x54)
                    );
                }
                lua_Number x51 = fltvalue(x54);
                lua_Number x56 /* bivz */ = x51;
                lua_Integer x57 = intop(+, x10, 1);
                lua_Integer x59 = luaH_getn(x1);
                lua_Integer x58 /* start */ = x57;
                lua_Integer x60 /* limit */ = x59;
                lua_Integer x61 /* step */ = 1;
                while ((x61 >= 0 ? x58 <= x60 : x58 >= x60)) {
                    lua_Integer x62 /* j */ = x58;
                    (void) x62;
                    {
                        lua_Unsigned x63 /* ui */ = ((lua_Unsigned)x62) - 1;
                        const TValue * x64 /* arrslot */;
                        if (PALLENE_LIKELY(x63 < x1->sizearray)) {
                            x64 = &x1->array[x63];
                        }
                        else {
                            x64 = (TValue *)luaH_getint(x1, x62);
                        }
                        if (PALLENE_UNLIKELY(!ttistable(x64))) {
                            pallene_runtime_array_type_error(L, 22, LUA_TTABLE, rawtt(x64));
                        }
                        Table * x65 = hvalue(x64);
                        Table * x66 /* bj */ = x65;
                        static int x71 = INT_MAX;
                        TValue * x70 = pallene_getstr(x66, x16, &x71);
                        if (PALLENE_UNLIKELY(!ttisfloat(x70))) {
                            pallene_runtime_lrecord_type_error(
                                L, "x", 23, LUA_TNUMFLT, rawtt(x70)
                            );
                        }
                        lua_Number x67 = fltvalue(x70);
                        lua_Number x72 = x20 - x67;
                        lua_Number x73 /* dx */ = x72;
                        static int x78 = INT_MAX;
                        TValue * x77 = pallene_getstr(x66, x22, &x78);
                        if (PALLENE_UNLIKELY(!ttisfloat(x77))) {
                            pallene_runtime_lrecord_type_error(
                                L, "y", 24, LUA_TNUMFLT, rawtt(x77)
                            );
                        }
                        lua_Number x74 = fltvalue(x77);
                        lua_Number x79 = x26 - x74;
                        lua_Number x80 /* dy */ = x79;
                        static int x85 = INT_MAX;
                        TValue * x84 = pallene_getstr(x66, x28, &x85);
                        if (PALLENE_UNLIKELY(!ttisfloat(x84))) {
                            pallene_runtime_lrecord_type_error(
                                L, "z", 25, LUA_TNUMFLT, rawtt(x84)
                            );
                        }
                        lua_Number x81 = fltvalue(x84);
                        lua_Number x86 = x32 - x81;
                        lua_Number x87 /* dz */ = x86;
                        lua_Number x88 = x73 * x73;
                        lua_Number x89 = x80 * x80;
                        lua_Number x90 = x88 + x89;
                        lua_Number x91 = x87 * x87;
                        lua_Number x92 = x90 + x91;
                        lua_Number x93 /* dist2 */ = x92;
                        lua_Number x94 /* mag */ = x93;
                        lua_Number x95 = x94 * x93;
                        lua_Number x96 = x2 / x95;
                        x94 = x96;
                        static int x101 = INT_MAX;
                        TValue * x100 = pallene_getstr(x66, x34, &x101);
                        if (PALLENE_UNLIKELY(!ttisfloat(x100))) {
                            pallene_runtime_lrecord_type_error(
                                L, "mass", 30, LUA_TNUMFLT, rawtt(x100)
                            );
                        }
                        lua_Number x97 = fltvalue(x100);
                        lua_Number x102 = x97 * x94;
                        lua_Number x103 /* bm */ = x102;
                        lua_Number x104 = x73 * x103;
                        lua_Number x105 = x44 - x104;
                        x44 = x105;
                        lua_Number x106 = x80 * x103;
                        lua_Number x107 = x50 - x106;
                        x50 = x107;
                        lua_Number x108 = x87 * x103;
                        lua_Number x109 = x56 - x108;
                        x56 = x109;
                        lua_Number x110 = x38 * x94;
                        x103 = x110;
                        static int x115 = INT_MAX;
                        TValue * x114 = pallene_getstr(x66, x40, &x115);
                        if (PALLENE_UNLIKELY(!ttisfloat(x114))) {
                            pallene_runtime_lrecord_type_error(
                                L, "vx", 35, LUA_TNUMFLT, rawtt(x114)
                            );
                        }
                        lua_Number x111 = fltvalue(x114);
                        lua_Number x116 = x73 * x103;
                        lua_Number x117 = x111 + x116;
                        static int x121 = INT_MAX;
                        TValue * x120 = pallene_getstr(x66, x40, &x121);
                        if (PALLENE_UNLIKELY(x120 == luaH_emptyobject)) {
                            TValue x124;
                            setsvalue(L, &x124, x40);
                            TValue * x125 = luaH_newkey(L, x66, &x124);
                            x120 = x125;
                        }
                        setfltvalue(x120, x117);
                        static int x130 = INT_MAX;
                        TValue * x129 = pallene_getstr(x66, x46, &x130);
                        if (PALLENE_UNLIKELY(!ttisfloat(x129))) {
                            pallene_runtime_lrecord_type_error(
                                L, "vy", 36, LUA_TNUMFLT, rawtt(x129)
                            );
                        }
                        lua_Number x126 = fltvalue(x129);
                        lua_Number x131 = x80 * x103;
                        lua_Number x132 = x126 + x131;
                        static int x136 = INT_MAX;
                        TValue * x135 = pallene_getstr(x66, x46, &x136);
                        if (PALLENE_UNLIKELY(x135 == luaH_emptyobject)) {
                            TValue x139;
                            setsvalue(L, &x139, x46);
                            TValue * x140 = luaH_newkey(L, x66, &x139);
                            x135 = x140;
                        }
                        setfltvalue(x135, x132);
                        static int x145 = INT_MAX;
                        TValue * x144 = pallene_getstr(x66, x52, &x145);
                        if (PALLENE_UNLIKELY(!ttisfloat(x144))) {
                            pallene_runtime_lrecord_type_error(
                                L, "vz", 37, LUA_TNUMFLT, rawtt(x144)
                            );
                        }
                        lua_Number x141 = fltvalue(x144);
                        lua_Number x146 = x87 * x103;
                        lua_Number x147 = x141 + x146;
                        static int x151 = INT_MAX;
                        TValue * x150 = pallene_getstr(x66, x52, &x151);
                        if (PALLENE_UNLIKELY(x150 == luaH_emptyobject)) {
                            TValue x154;
                            setsvalue(L, &x154, x52);
                            TValue * x155 = luaH_newkey(L, x66, &x154);
                            x150 = x155;
                        }
                        setfltvalue(x150, x147);
                    }
                    x58 = intop(+, x58, x61);
                }
                static int x159 = INT_MAX;
                TValue * x158 = pallene_getstr(x14, x40, &x159);
                if (PALLENE_UNLIKELY(x158 == luaH_emptyobject)) {
                    TValue x162;
                    setsvalue(L, &x162, x40);
                    TValue * x163 = luaH_newkey(L, x14, &x162);
                    x158 = x163;
                }
                setfltvalue(x158, x44);
                static int x167 = INT_MAX;
                TValue * x166 = pallene_getstr(x14, x46, &x167);
                if (PALLENE_UNLIKELY(x166 == luaH_emptyobject)) {
                    TValue x170;
                    setsvalue(L, &x170, x46);
                    TValue * x171 = luaH_newkey(L, x14, &x170);
                    x166 = x171;
                }
                setfltvalue(x166, x50);
                static int x175 = INT_MAX;
                TValue * x174 = pallene_getstr(x14, x52, &x175);
                if (PALLENE_UNLIKELY(x174 == luaH_emptyobject)) {
                    TValue x178;
                    setsvalue(L, &x178, x52);
                    TValue * x179 = luaH_newkey(L, x14, &x178);
                    x174 = x179;
                }
                setfltvalue(x174, x56);
                lua_Number x180 = x2 * x44;
                lua_Number x181 = x20 + x180;
                static int x185 = INT_MAX;
                TValue * x184 = pallene_getstr(x14, x16, &x185);
                if (PALLENE_UNLIKELY(x184 == luaH_emptyobject)) {
                    TValue x188;
                    setsvalue(L, &x188, x16);
                    TValue * x189 = luaH_newkey(L, x14, &x188);
                    x184 = x189;
                }
                setfltvalue(x184, x181);
                lua_Number x190 = x2 * x50;
                lua_Number x191 = x26 + x190;
                static int x195 = INT_MAX;
                TValue * x194 = pallene_getstr(x14, x22, &x195);
                if (PALLENE_UNLIKELY(x194 == luaH_emptyobject)) {
                    TValue x198;
                    setsvalue(L, &x198, x22);
                    TValue * x199 = luaH_newkey(L, x14, &x198);
                    x194 = x199;
                }
                setfltvalue(x194, x191);
                lua_Number x200 = x2 * x56;
                lua_Number x201 = x32 + x200;
                static int x205 = INT_MAX;
                TValue * x204 = pallene_getstr(x14, x28, &x205);
                if (PALLENE_UNLIKELY(x204 == luaH_emptyobject)) {
                    TValue x208;
                    setsvalue(L, &x208, x28);
                    TValue * x209 = luaH_newkey(L, x14, &x208);
                    x204 = x209;
                }
                setfltvalue(x204, x201);
            }
            x6 = intop(+, x6, x9);
        }
    }
}

static int function_advance_lua(lua_State *L)
{
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
        pallene_runtime_argument_type_error(L, "bodies", 11, LUA_TTABLE, x6);
    }
    TValue* x7 = s2v(x4 + 2);
    if (PALLENE_UNLIKELY(!ttisfloat(x7))) {
        pallene_runtime_argument_type_error(L, "dt", 11, LUA_TNUMFLT, x7);
    }
    Table * x8 = hvalue(s2v(x4 + 1));
    lua_Number x9 = fltvalue(s2v(x4 + 2));
    function_advance_pallene(L, x8, x9);
    return 0;
}

int luaopen_benchmarks_nbody_pallene_luarecord_icstr(lua_State *L)
{
    lua_checkstack(L, 4);
    /* Allocate upvalue table */
    /* ---------------------- */
    Udata * x1 = luaS_newudata(L, 0, 19);
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
    TString * x8 = luaS_new(L, "z");
    setsvalue(L,  &x2[5].uv , x8);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x8))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x9 = luaS_new(L, "vx");
    setsvalue(L,  &x2[6].uv , x9);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x9))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x10 = luaS_new(L, "vy");
    setsvalue(L,  &x2[7].uv , x10);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x10))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x11 = luaS_new(L, "vz");
    setsvalue(L,  &x2[8].uv , x11);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x11))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x12 = luaS_new(L, "mass");
    setsvalue(L,  &x2[9].uv , x12);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x12))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x13 = luaS_new(L, "x");
    setsvalue(L,  &x2[10].uv , x13);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x13))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x14 = luaS_new(L, "y");
    setsvalue(L,  &x2[11].uv , x14);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x14))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x15 = luaS_new(L, "z");
    setsvalue(L,  &x2[12].uv , x15);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x15))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x16 = luaS_new(L, "vx");
    setsvalue(L,  &x2[13].uv , x16);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x16))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x17 = luaS_new(L, "vy");
    setsvalue(L,  &x2[14].uv , x17);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x17))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x18 = luaS_new(L, "vz");
    setsvalue(L,  &x2[15].uv , x18);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x18))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    TString * x19 = luaS_new(L, "mass");
    setsvalue(L,  &x2[16].uv , x19);
    if (isblack(obj2gco(x1)) && iswhite(obj2gco(x19))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* makebody */
    CClosure* x20 = luaF_newCclosure(L, 1);
    x20->f = function_makebody_lua;
    setuvalue(L, &x20->upvalue[0], x1);
    TValue x21; setclCvalue(L, &x21, x20);
    setobj(L,  &x2[17].uv , &x21);
    if (iscollectable(&x21) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x21))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* advance */
    CClosure* x22 = luaF_newCclosure(L, 1);
    x22->f = function_advance_lua;
    setuvalue(L, &x22->upvalue[0], x1);
    TValue x23; setclCvalue(L, &x23, x22);
    setobj(L,  &x2[18].uv , &x23);
    if (iscollectable(&x23) && isblack(obj2gco(x1)) && iswhite(gcvalue(&x23))) {
        luaC_barrierback_(L, obj2gco(x1));
    }
    /* Create exports table */
    /* -------------------- */
    StackValue* x24 = L->top;
    setuvalue(L, s2v(x24), x1); x24++;
    L->top = x24;
    lua_createtable(L, 0, 2);
    lua_pushstring(L, "makebody");
    setobj(L, s2v(L->top),  &x2[17].uv ); api_incr_top(L);
    lua_settable(L, -3);
    lua_pushstring(L, "advance");
    setobj(L, s2v(L->top),  &x2[18].uv ); api_incr_top(L);
    lua_settable(L, -3);
    return 1;
}
