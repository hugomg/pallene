path=$1
#filename="${fullpath##*/}"                      # Strip longest match of */ from start
#dir="${fullpath:0:${#fullpath} - ${#filename}}" # Substring from 0 thru pos of filename
#base="${filename%.[^.]*}"                       # Strip shortest match of . plus at least one non-dot char from end
#ext="${filename:${#base} + 1}"    
N=3
./pallenec ${path}/pallene.pln --emit-c

if [ ! -f ${path}/pallene_mod.c ]; then
    cp ${path}/pallene.c ${path}/pallene_mod.c
    sed -i "s/luaopen_${path//\//_}_pallene/luaopen_${path//\//_}_pallene_mod/" ${path}/pallene_mod.c
fi
./pallenec ${path}/pallene.c --compile-c
./pallenec ${path}/pallene_mod.c --compile-c
if [ -f ${path}/capi.c ]; then
    ./pallenec ${path}/capi.c --compile-c
fi
if [ -f ${path}/lua.lua ]; then
    sudo perf stat -r $N -o log ./lua/src/lua ${path}/main.lua ${path//\//.}.lua > /dev/null  && tail -3 log 
elif [ -f ${path}/lua_puc.lua ]; then
    sudo perf stat -r $N -o log ./lua/src/lua ${path}/main.lua ${path//\//.}.lua_puc > /dev/null  && tail -3 log
fi
#./lua/src/lua -l${path//\//.}.pallene ${path}/main.lua ${path//\//.}.pallene  > /dev/null
sudo perf stat -r $N -o log ./lua/src/lua -l${path//\//.}.pallene ${path}/main.lua ${path//\//.}.pallene  > /dev/null  && tail -3 log
sudo perf stat -r $N -o log ./lua/src/lua -l${path//\//.}.pallene_mod ${path}/main.lua ${path//\//.}.pallene_mod  > /dev/null  && tail -3 log

if [ -f ${path}/jit.lua ]; then
    #echo "JIT"
    sudo perf stat -r $N -o log  luajit ${path}/main.lua ${path//\//.}.jit > /dev/null  && tail -3 log
elif [ -f ${path}/lua_luajit.lua ]; then
    #echo "LUAJIT"
    sudo perf stat -r $N -o log  luajit ${path}/main.lua ${path//\//.}.lua_luajit > /dev/null  && tail -3 log
elif [ -f ${path}/lua.lua ]; then
    #echo "LUA"
    sudo perf stat -r $N -o log luajit ${path}/main.lua ${path//\//.}.lua > /dev/null && tail -3 log 
fi
# if [ -f ${path}/capi.so ]; then
#     sudo perf stat -r $N -o log ./lua/src/lua -l${path//\//.}.capi ${path}/main.lua ${path//\//.}.capi  > /dev/null && tail -3 log 
# fi