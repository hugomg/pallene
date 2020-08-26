copy the following template:


```C
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
    if (!isnum) { luaL_error(L, "impossible"); }
    return out;
}

inline
static lua_Number getnumber(lua_State *L, int slot)
{
    int isnum;
    lua_Number out = lua_tonumberx(L, slot, &isnum);
    if (!isnum) { luaL_error(L, "impossible"); }
    return out;
}

YOUR_CONTENT

static luaL_Reg capi_funcs[] = {
    { "EXPORTEDFUNCTIONNAME", FUNCTIONDEFINITION },
    { "EXPORTEDFUNCTIONNAME2", FUNCTIONDEFINITION2 },
    { NULL, NULL }
};

int luaopen_benchmarks_BENCHMARK_capi(lua_State *L)
{
    luaL_newlib(L, capi_funcs);
    return 1;
}
```

1. change BENCHMARK for the name of the benchmark
2. paste the lua implementation on YOUR_CONTENT
3. for each lua function add it at capi_funcs array 
the EXPORTEDFUNCTIONNAME and FUNCTIONDEFINITION
will propably be the same (the function name)

4. then in each function rewrite it in C

   1. change `local function` for `static int`

   2. change the arguments `(a,b,c)` for `(lua_State *L)` and at the start of the function body
`check_nargs(L, N);` with N being the number of arguments (3 in this case). it is good to add a comment such as
        ```
        // 1: a
        // 2: b
        // 3: c
        ```

    1. To get argument values:

        `lua_Integer a = getinteger(L, 1);`

        `lua_Integer b = getinteger(L, 2);`

to get a field of a table:

lets say c is a table (c is index 3)

`c[i]` then will be:
`lua_geti(L, 3, i);`

2. change the rest of syntax (if, while, etc)


returning:
a number
```
lua_pushinteger(L, return_value);
return 1;s
```