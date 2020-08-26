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

static int fannkuch(N){

    //local initial_perm = {}
    for( int i = 1; i < N ; i++){
        //initial_perm[i] = i
    }

    //local perm = {} -- Work copy, allocated once

    //local count = {}
    //count[1] = 0
    int r = N;

    int perm_count = 0;
    int max_flips = 0;
    int checksum = 0;

    while(1) {

        //-- Flip the pancakes, working on a copy of the permutation

        {
            for ( int i = 1; i < N ; i++) {
                //perm[i] = initial_perm[i]
            }

            int flips_count = 0;
            //int h = perm[1];
            while( h > 1) {
                 int i = 1
                 int j = h
                 repeat
                    local a = perm[i]
                    local b = perm[j]
                    perm[i] = b
                    perm[j] = a
                    i = i + 1
                    j = j - 1
                until i >= j

                flips_count = flips_count + 1
                h = perm[1]
            }

            if flips_count > max_flips {
                max_flips = flips_count
            }

            if perm_count % 2 == 0 {
                checksum = checksum + flips_count
            else
                checksum = checksum - flips_count
            }
        }

        // Go to next permutation

        while r > 1 {
            count[r] = r
            r = r - 1
        }

        while true {
            if r == N {
                return { checksum, max_flips }
            }

            local tmp = initial_perm[1]
            for i = 1, r {
                initial_perm[i] = initial_perm[i+1]
            }
            initial_perm[r+1] = tmp

            local r1 = r+1
            count[r1] = count[r1] - 1
            if count[r1] > 0 { break }
            r = r1
        }
        perm_count = perm_count + 1
    }
}


static luaL_Reg capi_funcs[] = {
    { "fannkuch", fannkuch },
    { NULL, NULL }
};

int luaopen_benchmarks_BENCHMARK_capi(lua_State *L)
{
    luaL_newlib(L, capi_funcs);
    return 1;
}