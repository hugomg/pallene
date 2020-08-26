#rm benchmarks/binsearch/pallene.so 
#rm benchmarks/centroid/pallene.so 
#rm benchmarks/conway/pallene.so 
#rm benchmarks/nbody/pallene.so 
#./pallenec benchmarks/binsearch/pallene.pln 
#./pallenec benchmarks/centroid/pallene.pln 
#./pallenec benchmarks/conway/pallene.pln 
#./pallenec benchmarks/nbody/pallene.pln 
#sudo perf stat -r 10 -d ./lua/src/lua -lbenchmarks.binsearch.pallene benchmarks/binsearch/main.lua benchmarks.binsearch.pallene > /dev/null
#sudo perf stat -r 10 -d ./lua/src/lua -lbenchmarks.centroid.pallene benchmarks/centroid/main.lua benchmarks.centroid.pallene > /dev/null
#sudo perf stat -r 10 -d ./lua/src/lua -lbenchmarks.conway.pallene benchmarks/conway/main.lua benchmarks.conway.pallene > /dev/null
#sudo perf stat -r 10 -d ./lua/src/lua -lbenchmarks.nbody.pallene benchmarks/nbody/main.lua benchmarks.nbody.pallene > /dev/null
#
#
sudo perf stat -r 10 -d ./lua/src/lua benchmarks/binsearch/main.lua benchmarks.binsearch.lua_puc > /dev/null
sudo perf stat -r 3 -d ./lua/src/lua benchmarks/centroid/main.lua benchmarks.centroid.lua > /dev/null
sudo perf stat -r 3 -d ./lua/src/lua benchmarks/conway/main.lua benchmarks.conway.lua > /dev/null
sudo perf stat -r 10 -d ./lua/src/lua benchmarks/nbody/main.lua benchmarks.nbody.lua > /dev/null
