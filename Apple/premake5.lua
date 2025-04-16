project("Apple")
kind("ConsoleApp")
language("C++")
cppdialect("C++20")

targetdir("../bin/" .. output_directory .. "/%{prj.name}")
objdir("../build/" .. output_directory .. "/%{prj.name}")

files({
	"source/**.h",
	"source/**.cpp",
})

includedirs({
	"../Apple-Backend/source",
	"../vendor/raylib/include",
})

links({
	"Apple-Backend",
	"raylib",
})

filter("system:linux")
libdirs({
	"../vendor/raylib/lib/linux",
})
postbuildcommands({
	"cp ../vendor/raylib/lib/linux/* %{cfg.buildtarget.directory}",
})
defines({
	"PLATFORM_LINUX",
})

filter("system:windows")
defines({
	"PLATFORM_WINDOWS",
})

filter({ "configurations:Debug" })
defines("DEBUG")
symbols("on")

filter({ "configurations:Release" })
defines("RELEASE")
optimize("on")

filter({ "configurations:Dist" })
defines("DIST")
optimize("on")
