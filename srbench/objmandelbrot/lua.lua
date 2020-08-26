local function new(x, y)
    return { x, y }
end

local function clone(x)
    return new(x[1], x[2])
end

local function conj(x)
    return new(x[1], -x[2])
end

local function add(x,y)
    return new(x[1] + y[1], x[2] + y[2])
end

local function mul(x,y)
    return new(x[1] * y[1] - x[2] * y[2], x[1] * y[2] + x[2] * y[1])
end

local function norm2(x)
    local n = mul(x, conj(x))
    return n[1]
end

local function all(N)
    local function level(x, y)
        local c = new(x, y)
        local z = clone(c)
        local l = 0
        repeat
            z = add(mul(z, z), c)
            l = l + 1
        until norm2(z) > 4.0 or l > 255
        return l - 1    
    end
    
    local xmin = -2.0
    local xmax = 2.0
    local ymin = -2.0
    local ymax = 2.0
    
    local dx = (xmax - xmin) / N
    local dy = (ymax - ymin) / N
    
    print("P2")
    print(N, N, 255)
    
    for i = 1, N do
        local x = xmin + (i - 1) * dx
        for j = 1, N do
            local y = ymin + (j - 1) * dy
            print(level(x, y))
        end
    end
end

return {
    all = all,
    new = new,
    clone = clone,
    conj = conj,
    add = add,
    mul = mul,
    norm2 = norm2,
}
