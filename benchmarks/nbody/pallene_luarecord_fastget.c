/* This file was generated by the Pallene compiler. Do not edit by hand */
/* Indentation and formatting courtesy of pallene/pretty.lua */

#include <string.h>

#include "pallene_core.h"

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

/* fixed hash layout for seed = 0
 * sizenode 8
 * pos 0	key string	str y	hash 152            (uv 11)
 * pos 1	key string	str x	hash 153            (uv 10)
 * pos 2	key nil
 * pos 3	key string	str z	hash 155            (uv 12)
 * pos 4	key string	str vz	hash 5916           (uv 15)
 * pos 5	key string	str mass	hash 7956777    (uv 16)
 * pos 6	key string	str vx	hash 5982           (uv 13)
 * pos 7	key string	str vy	hash 6335           (uv 14)
 */

static void dumphashpart(lua_State *L, Table *t) {
    printf("sizenode %d\n", sizenode(t));
    for (int i = 0; i < sizenode(t); i++) {
        Node *n = gnode(t, i);
        int kt = novariant(n->u.key_tt);
        printf("pos %d\t", i);
        printf("key %s\t", ttypename(kt));
        if (kt == LUA_TSTRING) {
            TValue k;
            getnodekey(L, &k, n);
            TString *str = tsvalue(&k);
            printf("str %s\t", svalue(&k));
            printf("hash %d\t", str->hash);
        }
        printf("\n");
    }
    printf("---\n");
}

static const TValue *getstrfast(Table *t, TString *key, int hash, int pos)
{
#if 1
  if (pos < sizenode(t)) {
    Node *n = gnode(t, pos);
    if (keyisshrstr(n) && eqshrstr(keystrval(n), key))
      return gval(n);  /* that's it */
  }
#endif
  Node *n = gnode(t, lmod(hash, sizenode(t)));
  for (;;) {  /* check whether 'key' is somewhere in the chain */
    if (keyisshrstr(n) && eqshrstr(keystrval(n), key))
      return gval(n);  /* that's it */
    else {
      int nx = gnext(n);
      if (nx == 0)
        return luaH_emptyobject;  /* not found */
      n += nx;
    }
  }
}


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
    CClosure * x3 = clCvalue(s2v(L->ci->func));
    Udata * x4 /* upvalue table */ = uvalue(&x3->upvalue[0]);
    UValue * x5 /* upvalue array */ = x4->uv;
    (void)x5;
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
                TValue * x16 =  &x5[10].uv ;
                TString * x17 = tsvalue(x16);
                TValue * x18 = (TValue *)getstrfast(x14, x17, 153, 1);
                if (PALLENE_UNLIKELY(!ttisfloat(x18))) {
                    pallene_runtime_lrecord_type_error(
                        L, "x", 14, LUA_TNUMFLT, rawtt(x18)
                    );
                }
                lua_Number x15 = fltvalue(x18);
                lua_Number x19 /* bix */ = x15;
                TValue * x21 =  &x5[11].uv ;
                TString * x22 = tsvalue(x21);
                TValue * x23 = (TValue *)getstrfast(x14, x22, 152, 0);
                if (PALLENE_UNLIKELY(!ttisfloat(x23))) {
                    pallene_runtime_lrecord_type_error(
                        L, "y", 15, LUA_TNUMFLT, rawtt(x23)
                    );
                }
                lua_Number x20 = fltvalue(x23);
                lua_Number x24 /* biy */ = x20;
                TValue * x26 =  &x5[12].uv ;
                TString * x27 = tsvalue(x26);
                TValue * x28 = (TValue *)getstrfast(x14, x27, 155, 3);
                if (PALLENE_UNLIKELY(!ttisfloat(x28))) {
                    pallene_runtime_lrecord_type_error(
                        L, "z", 16, LUA_TNUMFLT, rawtt(x28)
                    );
                }
                lua_Number x25 = fltvalue(x28);
                lua_Number x29 /* biz */ = x25;
                TValue * x31 =  &x5[16].uv ;
                TString * x32 = tsvalue(x31);
                TValue * x33 = (TValue *)getstrfast(x14, x32, 7956777, 5);
                if (PALLENE_UNLIKELY(!ttisfloat(x33))) {
                    pallene_runtime_lrecord_type_error(
                        L, "mass", 17, LUA_TNUMFLT, rawtt(x33)
                    );
                }
                lua_Number x30 = fltvalue(x33);
                lua_Number x34 /* bimass */ = x30;
                TValue * x36 =  &x5[13].uv ;
                TString * x37 = tsvalue(x36);
                TValue * x38 = (TValue *)getstrfast(x14, x37, 5982, 6);
                if (PALLENE_UNLIKELY(!ttisfloat(x38))) {
                    pallene_runtime_lrecord_type_error(
                        L, "vx", 18, LUA_TNUMFLT, rawtt(x38)
                    );
                }
                lua_Number x35 = fltvalue(x38);
                lua_Number x39 /* bivx */ = x35;
                TValue * x41 =  &x5[14].uv ;
                TString * x42 = tsvalue(x41);
                TValue * x43 = (TValue *)getstrfast(x14, x42, 6335, 7);
                if (PALLENE_UNLIKELY(!ttisfloat(x43))) {
                    pallene_runtime_lrecord_type_error(
                        L, "vy", 19, LUA_TNUMFLT, rawtt(x43)
                    );
                }
                lua_Number x40 = fltvalue(x43);
                lua_Number x44 /* bivy */ = x40;
                TValue * x46 =  &x5[15].uv ;
                TString * x47 = tsvalue(x46);
                TValue * x48 = (TValue *)getstrfast(x14, x47, 5916, 4);
                if (PALLENE_UNLIKELY(!ttisfloat(x48))) {
                    pallene_runtime_lrecord_type_error(
                        L, "vz", 20, LUA_TNUMFLT, rawtt(x48)
                    );
                }
                lua_Number x45 = fltvalue(x48);
                lua_Number x49 /* bivz */ = x45;
                lua_Integer x50 = intop(+, x10, 1);
                lua_Integer x52 = luaH_getn(x1);
                lua_Integer x51 /* start */ = x50;
                lua_Integer x53 /* limit */ = x52;
                lua_Integer x54 /* step */ = 1;
                while ((x54 >= 0 ? x51 <= x53 : x51 >= x53)) {
                    lua_Integer x55 /* j */ = x51;
                    (void) x55;
                    {
                        lua_Unsigned x56 /* ui */ = ((lua_Unsigned)x55) - 1;
                        const TValue * x57 /* arrslot */;
                        if (PALLENE_LIKELY(x56 < x1->sizearray)) {
                            x57 = &x1->array[x56];
                        }
                        else {
                            x57 = (TValue *)luaH_getint(x1, x55);
                        }
                        if (PALLENE_UNLIKELY(!ttistable(x57))) {
                            pallene_runtime_array_type_error(L, 22, LUA_TTABLE, rawtt(x57));
                        }
                        Table * x58 = hvalue(x57);
                        Table * x59 /* bj */ = x58;
                        TValue * x61 =  &x5[10].uv ;
                        TString * x62 = tsvalue(x61);
                        TValue * x63 = (TValue *)getstrfast(x59, x62, 153, 1);
                        if (PALLENE_UNLIKELY(!ttisfloat(x63))) {
                            pallene_runtime_lrecord_type_error(
                                L, "x", 23, LUA_TNUMFLT, rawtt(x63)
                            );
                        }
                        lua_Number x60 = fltvalue(x63);
                        lua_Number x64 = x19 - x60;
                        lua_Number x65 /* dx */ = x64;
                        TValue * x67 =  &x5[11].uv ;
                        TString * x68 = tsvalue(x67);
                        TValue * x69 = (TValue *)getstrfast(x59, x68, 152, 0);
                        if (PALLENE_UNLIKELY(!ttisfloat(x69))) {
                            pallene_runtime_lrecord_type_error(
                                L, "y", 24, LUA_TNUMFLT, rawtt(x69)
                            );
                        }
                        lua_Number x66 = fltvalue(x69);
                        lua_Number x70 = x24 - x66;
                        lua_Number x71 /* dy */ = x70;
                        TValue * x73 =  &x5[12].uv ;
                        TString * x74 = tsvalue(x73);
                        TValue * x75 = (TValue *)getstrfast(x59, x74, 155, 3);
                        if (PALLENE_UNLIKELY(!ttisfloat(x75))) {
                            pallene_runtime_lrecord_type_error(
                                L, "z", 25, LUA_TNUMFLT, rawtt(x75)
                            );
                        }
                        lua_Number x72 = fltvalue(x75);
                        lua_Number x76 = x29 - x72;
                        lua_Number x77 /* dz */ = x76;
                        lua_Number x78 = x65 * x65;
                        lua_Number x79 = x71 * x71;
                        lua_Number x80 = x78 + x79;
                        lua_Number x81 = x77 * x77;
                        lua_Number x82 = x80 + x81;
                        lua_Number x83 /* dist2 */ = x82;
                        lua_Number x84 /* mag */ = x83;
                        lua_Number x85 = x84 * x83;
                        lua_Number x86 = x2 / x85;
                        x84 = x86;
                        TValue * x88 =  &x5[16].uv ;
                        TString * x89 = tsvalue(x88);
                        TValue * x90 = (TValue *)getstrfast(x59, x89, 7956777, 5);
                        if (PALLENE_UNLIKELY(!ttisfloat(x90))) {
                            pallene_runtime_lrecord_type_error(
                                L, "mass", 30, LUA_TNUMFLT, rawtt(x90)
                            );
                        }
                        lua_Number x87 = fltvalue(x90);
                        lua_Number x91 = x87 * x84;
                        lua_Number x92 /* bm */ = x91;
                        lua_Number x93 = x65 * x92;
                        lua_Number x94 = x39 - x93;
                        x39 = x94;
                        lua_Number x95 = x71 * x92;
                        lua_Number x96 = x44 - x95;
                        x44 = x96;
                        lua_Number x97 = x77 * x92;
                        lua_Number x98 = x49 - x97;
                        x49 = x98;
                        lua_Number x99 = x34 * x84;
                        x92 = x99;
                        TValue * x101 =  &x5[13].uv ;
                        TString * x102 = tsvalue(x101);
                        TValue * x103 = (TValue *)getstrfast(x59, x102, 5982, 6);
                        if (PALLENE_UNLIKELY(!ttisfloat(x103))) {
                            pallene_runtime_lrecord_type_error(
                                L, "vx", 35, LUA_TNUMFLT, rawtt(x103)
                            );
                        }
                        lua_Number x100 = fltvalue(x103);
                        lua_Number x104 = x65 * x92;
                        lua_Number x105 = x100 + x104;
                        TValue * x106 =  &x5[13].uv ;
                        TString * x107 = tsvalue(x106);
                        TValue * x108 = (TValue *)getstrfast(x59, x107, 5982, 6);
                        if (PALLENE_UNLIKELY(x108 == luaH_emptyobject)) {
                            TValue * x109 =  &x5[13].uv ;
                            TString * x110 = tsvalue(x109);
                            TValue x111;
                            setsvalue(L, &x111, x110);
                            TValue * x112 = luaH_newkey(L, x59, &x111);
                            x108 = x112;
                        }
                        setfltvalue(x108, x105);
                        TValue * x114 =  &x5[14].uv ;
                        TString * x115 = tsvalue(x114);
                        TValue * x116 = (TValue *)getstrfast(x59, x115, 6335, 7);
                        if (PALLENE_UNLIKELY(!ttisfloat(x116))) {
                            pallene_runtime_lrecord_type_error(
                                L, "vy", 36, LUA_TNUMFLT, rawtt(x116)
                            );
                        }
                        lua_Number x113 = fltvalue(x116);
                        lua_Number x117 = x71 * x92;
                        lua_Number x118 = x113 + x117;
                        TValue * x119 =  &x5[14].uv ;
                        TString * x120 = tsvalue(x119);
                        TValue * x121 = (TValue *)getstrfast(x59, x120, 6335, 7);
                        if (PALLENE_UNLIKELY(x121 == luaH_emptyobject)) {
                            TValue * x122 =  &x5[14].uv ;
                            TString * x123 = tsvalue(x122);
                            TValue x124;
                            setsvalue(L, &x124, x123);
                            TValue * x125 = luaH_newkey(L, x59, &x124);
                            x121 = x125;
                        }
                        setfltvalue(x121, x118);
                        TValue * x127 =  &x5[15].uv ;
                        TString * x128 = tsvalue(x127);
                        TValue * x129 = (TValue *)getstrfast(x59, x128, 5916, 4);
                        if (PALLENE_UNLIKELY(!ttisfloat(x129))) {
                            pallene_runtime_lrecord_type_error(
                                L, "vz", 37, LUA_TNUMFLT, rawtt(x129)
                            );
                        }
                        lua_Number x126 = fltvalue(x129);
                        lua_Number x130 = x77 * x92;
                        lua_Number x131 = x126 + x130;
                        TValue * x132 =  &x5[15].uv ;
                        TString * x133 = tsvalue(x132);
                        TValue * x134 = (TValue *)getstrfast(x59, x133, 5916, 4);
                        if (PALLENE_UNLIKELY(x134 == luaH_emptyobject)) {
                            TValue * x135 =  &x5[15].uv ;
                            TString * x136 = tsvalue(x135);
                            TValue x137;
                            setsvalue(L, &x137, x136);
                            TValue * x138 = luaH_newkey(L, x59, &x137);
                            x134 = x138;
                        }
                        setfltvalue(x134, x131);
                    }
                    x51 = intop(+, x51, x54);
                }
                TValue * x139 =  &x5[13].uv ;
                TString * x140 = tsvalue(x139);
                TValue * x141 = (TValue *)getstrfast(x14, x140, 5982, 6);
                if (PALLENE_UNLIKELY(x141 == luaH_emptyobject)) {
                    TValue * x142 =  &x5[13].uv ;
                    TString * x143 = tsvalue(x142);
                    TValue x144;
                    setsvalue(L, &x144, x143);
                    TValue * x145 = luaH_newkey(L, x14, &x144);
                    x141 = x145;
                }
                setfltvalue(x141, x39);
                TValue * x146 =  &x5[14].uv ;
                TString * x147 = tsvalue(x146);
                TValue * x148 = (TValue *)getstrfast(x14, x147, 6335, 7);
                if (PALLENE_UNLIKELY(x148 == luaH_emptyobject)) {
                    TValue * x149 =  &x5[14].uv ;
                    TString * x150 = tsvalue(x149);
                    TValue x151;
                    setsvalue(L, &x151, x150);
                    TValue * x152 = luaH_newkey(L, x14, &x151);
                    x148 = x152;
                }
                setfltvalue(x148, x44);
                TValue * x153 =  &x5[15].uv ;
                TString * x154 = tsvalue(x153);
                TValue * x155 = (TValue *)getstrfast(x14, x154, 5916, 4);
                if (PALLENE_UNLIKELY(x155 == luaH_emptyobject)) {
                    TValue * x156 =  &x5[15].uv ;
                    TString * x157 = tsvalue(x156);
                    TValue x158;
                    setsvalue(L, &x158, x157);
                    TValue * x159 = luaH_newkey(L, x14, &x158);
                    x155 = x159;
                }
                setfltvalue(x155, x49);
                lua_Number x160 = x2 * x39;
                lua_Number x161 = x19 + x160;
                TValue * x162 =  &x5[10].uv ;
                TString * x163 = tsvalue(x162);
                TValue * x164 = (TValue *)getstrfast(x14, x163, 153, 1);
                if (PALLENE_UNLIKELY(x164 == luaH_emptyobject)) {
                    TValue * x165 =  &x5[10].uv ;
                    TString * x166 = tsvalue(x165);
                    TValue x167;
                    setsvalue(L, &x167, x166);
                    TValue * x168 = luaH_newkey(L, x14, &x167);
                    x164 = x168;
                }
                setfltvalue(x164, x161);
                lua_Number x169 = x2 * x44;
                lua_Number x170 = x24 + x169;
                TValue * x171 =  &x5[11].uv ;
                TString * x172 = tsvalue(x171);
                TValue * x173 = (TValue *)getstrfast(x14, x172, 152, 0);
                if (PALLENE_UNLIKELY(x173 == luaH_emptyobject)) {
                    TValue * x174 =  &x5[11].uv ;
                    TString * x175 = tsvalue(x174);
                    TValue x176;
                    setsvalue(L, &x176, x175);
                    TValue * x177 = luaH_newkey(L, x14, &x176);
                    x173 = x177;
                }
                setfltvalue(x173, x170);
                lua_Number x178 = x2 * x49;
                lua_Number x179 = x29 + x178;
                TValue * x180 =  &x5[12].uv ;
                TString * x181 = tsvalue(x180);
                TValue * x182 = (TValue *)getstrfast(x14, x181, 155, 3);
                if (PALLENE_UNLIKELY(x182 == luaH_emptyobject)) {
                    TValue * x183 =  &x5[12].uv ;
                    TString * x184 = tsvalue(x183);
                    TValue x185;
                    setsvalue(L, &x185, x184);
                    TValue * x186 = luaH_newkey(L, x14, &x185);
                    x182 = x186;
                }
                setfltvalue(x182, x179);
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

int luaopen_benchmarks_nbody_pallene_luarecord_fastget(lua_State *L)
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
