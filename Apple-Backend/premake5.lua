project("Apple-Backend")
kind("SharedLib")
language("C++")
cppdialect("C++20")

targetdir("../bin/" .. output_directory .. "/%{prj.name}")
objdir("../build/" .. output_directory .. "/%{prj.name}")

files({
	"source/**.h",
	"source/**.cpp",
})

includedirs({
	"source",
	"../vendor/raylib/include",
})

links({
	"raylib",
})

filter("system:linux")
libdirs({
	"../vendor/raylib/lib/linux",
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
