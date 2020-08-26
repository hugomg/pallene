#include <lua.h>
#include <lauxlib.h>

inline
static void check_nargs(lua_State *L, int expected)
{
    int nargs = lua_gettop(L);
    if (nargs != expected) {
        luaL_error(L, "Expected %d arguments, got %d", expected, nargs);
    }
}

inline
static lua_Integer getinteger(lua_State *L, int slot)
{
    int isnum;
    lua_Integer out = lua_tointegerx(L, slot, &isnum);
    if (!isnum) { luaL_error(L, "impossible Integer"); }
    return out;
}

inline
static lua_Number getnumber(lua_State *L, int slot)
{
    int isnum;
    lua_Number out = lua_tonumberx(L, slot, &isnum);
    if (!isnum) { luaL_error(L, "impossible Number"); }
    return out;
}


static int BottomUpTree(lua_State *L){
    check_nargs(L, 1);
    // // 1: depth
    lua_Integer depth = getinteger(L, 1);
    // //2: BottomUptree
    lua_pushcfunction(L, BottomUpTree);  
    if (depth > 0) {
        depth = depth - 1;
        //3: bottomuptree
        lua_pushvalue(L, 2);
        // 4: depth
        lua_pushinteger(L, depth);
        lua_call(L,1,1);
        // 3: return
        //lua_Integer left = getinteger(L, 3);
        //lua_pop(L, 1);
        // 4: bottomuptree
        lua_pushvalue(L, 2);
        // 5: depth
        lua_pushinteger(L, depth);
        lua_call(L,1,1);
        // 4: return
        //lua_Integer right = getinteger(L, 3);
        //lua_pop(L, 1);
        // 5: table
        lua_newtable(L);
        lua_pushvalue(L, 3);
        lua_seti(L,5,1);
        lua_pushinteger(L, 4);
        lua_seti(L,5,2);
    }else{
        lua_newtable(L);
        lua_pushboolean(L, 0);
        lua_seti(L,3,1);
        lua_pushboolean(L, 0);
        lua_seti(L,3,2);
    }
    return 1;
}

static int ItemCheck(lua_State *L){
    check_nargs(L, 1);
    // 1: tree
    if (lua_istable(L,1)) {
        lua_pushnumber(L, 1);
        return 1;
    }

    //2: ItemCheck
    lua_pushcfunction(L, ItemCheck);
    lua_geti(L, 1, 1);
    //lua_pushinteger(L,tree1);
    int tree1 = lua_gettop(L);
    if (lua_toboolean(L,tree1)) {
        //3
        lua_geti(L, 1, 2);
        int tree2 = lua_gettop(L);
        //4
        lua_pushvalue(L, 2);
        //5
        lua_pushvalue(L, tree1);
        lua_call(L,1,1);
        //4
        lua_Integer ICtree1 = getinteger(L, lua_gettop(L));
        lua_pop(L, 1);
        //4
        lua_pushvalue(L, 2);
        //5
        lua_pushvalue(L, tree2);
        lua_call(L,1,1);
        //4
        lua_Integer ICtree2 = getinteger(L, lua_gettop(L));
        lua_pop(L, 1);
        //3
        lua_pushnumber(L, 1 + ICtree1 + ICtree2);
    }else{
        //3
      lua_pushnumber(L, 1);
    }
    return 1;
}

static int Stress(lua_State *L) {
    // //mindepth, maxdepth, depth
    lua_Integer depth = getinteger(L, 3);
    int iterations = 1 << (getinteger(L, 2) - depth + getinteger(L, 1));
    int check = 0;
    //4: BottomUpTree
    lua_pushcfunction(L, BottomUpTree);
    //5: ItemCheck
    lua_pushcfunction(L, ItemCheck);
     for (int _ = 1; _<iterations;_++) {
        lua_pushvalue(L, 4);
        lua_pushinteger(L, depth);
        lua_call(L,1,1);
        // lua_Integer t = getinteger(L, lua_gettop(L));
        // lua_pop(L,1);
        int t = lua_gettop(L);
        lua_pushvalue(L, 5);
        lua_pushvalue(L, t);
        lua_call(L,1,1);
        lua_Integer ICt = getinteger(L, lua_gettop(L));
        lua_pop(L,1);
        check = check + ICt;
     }
    lua_newtable(L);
    int top = lua_gettop(L);

     lua_pushnumber(L, iterations);
     lua_seti(L,top,1);
     lua_pushnumber(L, check);
     lua_seti(L,top,2);
    return 1;
}


static luaL_Reg capi_funcs[] = {
    { "BottomUpTree", BottomUpTree },
    { "ItemCheck", ItemCheck },
    { "Stress", Stress },
    { NULL, NULL }
};

int luaopen_benchmarks_binarytrees_capi(lua_State *L)
{
    luaL_newlib(L, capi_funcs);
    return 1;
}
