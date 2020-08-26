local point = require(arg[1])
local N     = tonumber(arg[2]) or 10000
local nrep  = tonumber(arg[3]) or 100000

local r = point.all(N, nrep)
print(r[1], r[2])
