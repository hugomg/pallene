local coder = require "titan-compiler.coder"
local util = require "titan-compiler.util"

local c_compiler = {}

c_compiler.CPPFLAGS = "-I./lua/src -I./runtime"
c_compiler.CFLAGS_BASE = "--std=c99 -g "
c_compiler.CFLAGS_WARN = "-Wall -Wno-parentheses-equality"
c_compiler.CFLAGS_OPT = "-O2"
c_compiler.CC = "cc"

local UNAME = util.shell("uname -s")
if string.find(UNAME, "Darwin") then
    c_compiler.CFLAGS_SHARED = "-fPIC -shared -undefined dynamic_lookup"
else
    c_compiler.CFLAGS_SHARED = "-fPIC -shared"
end

local function compile_c(mode, c_filename, out_filename)
    local extra_flags
    if     mode == "so" then
        extra_flags = "runtime/tcore.o"
    elseif mode == "s" then
        extra_flags = "-S"
    else
        error("impossible")
    end

    local args = {
        c_compiler.CC,
        c_compiler.CPPFLAGS,
        c_compiler.CFLAGS_BASE,
        c_compiler.CFLAGS_WARN,
        c_compiler.CFLAGS_OPT,
        c_compiler.CFLAGS_SHARED,
        extra_flags,
        "-o", out_filename,
        "-x", "c",
        c_filename,
    }
    local cmd = table.concat(args, " ")
    local ok = os.execute(cmd)
    if not ok then
        return false, {
            "internal error: gcc failed",
            "compilation line: " .. cmd,
        }
    end

    return true, {}
end

function c_compiler.compile_titan_to_so(titan_filename, input, so_filename)
    local _, ext = util.split_ext(titan_filename)
    assert(ext == "titan")

    local c_filename = os.tmpname()

    local ok, errs =
        c_compiler.compile_titan_to_c(titan_filename, input, c_filename)
    if not ok then return ok, errs end

    local ok, errs =
        c_compiler.compile_c_to_so(c_filename, so_filename)
    if not ok then return ok, errs end

    os.remove(c_filename)

    return true, {}
end

function c_compiler.compile_titan_to_c(titan_filename, input, c_filename)
    local name, ext = util.split_ext(titan_filename)
    assert(ext == "titan")
    local modname = string.gsub(name, "/", "_")

    local code, errors = coder.generate(titan_filename, input, modname)
    if not code then return false, errors end

    local ok, err = util.set_file_contents(c_filename, code)
    if not ok then return nil, {err} end

    return true, {}
end

function c_compiler.compile_c_to_so(c_filename, so_filename)
    return compile_c("so", c_filename, so_filename)
end

function c_compiler.compile_c_to_asm(c_filename, s_filename)
    return compile_c("s", c_filename, s_filename)
end

return c_compiler