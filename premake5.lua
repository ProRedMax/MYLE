workspace "MYLE"
    architecture "x64"
    startproject "MYLE-Examples"

    configurations
    {
        "Debug",
        "Release"
    }

    outputdirTarget = "bin/%{cfg.buildcfg}/%{cfg.system}"
    outputdirObject = "bin-int/%{cfg.buildcfg}/%{cfg.system}"

project "MYLE"
    location "%{prj.name}"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir (outputdirTarget .. "/%{prj.name}")
    objdir (outputdirObject .. "/%{prj.name}")

    files
    {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.cpp"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    links 
    {
	"ThirdPart/pcre2/pcre3.dll"
    }

    filter "system:windows"
        systemversion "latest"

        includedirs
        {
            "%{prj.name}/include",
	    "ThirdParty/jpcre2/src/"
        }

        defines
        {
            "NOMINMAX"
        }

    filter "system:macosx"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/include",
	    "ThirdParty/jpcre2/src/"
        }

    filter "system:linux"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/include",
	    "ThirdParty/jpcre2/src/"
        }

    filter "configurations:Debug"
        defines "MYLE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MYLE_RELEASE"
        runtime "Release"
        symbols "on"

project "MYLE-Examples"
    location "%{prj.name}"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir (outputdirTarget .. "/%{prj.name}")
    objdir (outputdirObject .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    links
    {
        "MYLE"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    filter "system:windows"
        systemversion "latest"

        includedirs
        {
            "%{prj.name}/src",
			"MYLE/include"
        }

        defines
        {
            "NOMINMAX"
        }

    filter "system:macosx"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/src",
			"MYLE/include"
        }

    filter "system:linux"
        systemversion "latest"
        toolset "clang"

        sysincludedirs
        {
            "%{prj.name}/src",
			"MYLE/include"
        }

    filter "configurations:Debug"
        defines "MYLE_DEBUG"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "MYLE_RELEASE"
        runtime "Release"
        symbols "on"
