workspace("Apple-Catcher")
architecture("x64")

configurations({
	"Debug",
	"Release",
	"Dist",
})

output_directory = "%{cfg.buildcfg}-%{cfg.system}"

include("Apple-Backend")
include("Apple")
