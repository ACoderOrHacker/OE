--- OE xmake configuration ---
--- Copyright (C) ACoderOrHacker

set_xmakever("2.2.5")
set_project("OE")
set_license("Apache-2.0")

--- include directories ---
add_includedirs("include")

--- set languages ---
set_languages("c++20")

--- compile_commands generation ---
add_rules("plugin.compile_commands.autoupdate", { outputdir = "build" })

--- modes ---

add_rules("mode.debug", "mode.release")

--- build options ---

option("shared")
    set_default(false)
    set_showmenu(true)
    set_description("Build shared library")
    add_defines("OE_SHARED")
option_end()

option("modules")
    set_default(false)
    set_showmenu(true)
    set_description("Build with C++20 modules")

    add_defines("OE_USE_MODULES")
option_end()

option("stdmodules")
    set_default(false)
    set_showmenu(true)
    set_description("Build with C++23 std modules")

    add_defines("OE_USE_STD_MODULES")
option_end()

includes("xmake/libs.lua")
local libs = libs_string:split(";")
for _, name in ipairs(libs) do
    option(name)
        set_default(true)
        set_showmenu(true)
        set_category("modules")
        set_description("Build with " .. name)
        set_configvar("OE_" .. name:upper() .. "ENABLED", 1)
    option_end()
end

--- configfiles ---
set_configdir("$(projectdir)")
add_configfiles("include/oe/oe/configs.h.in",
    { prefixdir = "include/oe/oe" })

if is_mode("debug") then
    add_defines("OE_DEBUG")
end

--- targets ---

-- oe for c++
target("oecpp")
    add_options("shared")
    if has_config("shared") then
        set_kind("shared")
        add_rules("utils.symbols.export_all")
    else
        set_kind("static")
    end

    add_headerfiles("include/(**.hpp)")

    add_rules("utils.install.cmake_importfiles")
    add_rules("utils.install.pkgconfig_importfiles")
target_end()

-- oe for dlang
target("oed")
    add_options("shared")
    if has_config("shared") then
        set_kind("shared")
        add_rules("utils.symbols.export_all")
    else
        set_kind("static")
    end

    add_headerfiles("source/(**.d)")
    add_rules("utils.install.cmake_importfiles")
    add_rules("utils.install.pkgconfig_importfiles")
target_end()

--- tests and benchmarks ---

option("tests")
    set_default(false)
    target("test-cpp")
        set_kind("binary")

        add_files("tests/test.cpp")
        add_deps("oecpp")

    target("test-d")
        set_kind("binary")

        add_files("tests/test.d")
        add_deps("oed")
option_end()
