cmake_minimum_required(VERSION 3.10)

# set the project name
project(GO_Engine VERSION 1.0)

#target_compile_features(${PROPERTIES} cxx_std_17)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++17" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++17")
    endif()
endif()

if(MSVC)
set(CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif()

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
endif()

include_directories("GO/include"
"Dependencies/OpenGL/include"
"Dependencies/OpenAL/include"
"Dependencies/STB_IMAGE"
"Dependencies/FreeType/include"
"Dependencies/dr_libs")

set ( PROJECT_LINK_LIBS glfw3.lib 
						OpenAL32.lib 
						common.lib
						ex-common.lib
						freetype.lib )

link_directories("Dependencies/OpenGL/lib"
				 "Dependencies/OpenAL/lib"
				 "Dependencies/FreeType/lib"
				 "Dependencies/OpenGL/lib")

file(GLOB SOURCES
"GO/src/Audio/*.cpp"
"GO/src/Core/*.cpp"
"GO/src/Graphics/*.cpp"
"GO/src/Input/*.cpp"
"GO/src/Window/*.cpp"
"glad.c")


add_library(engine SHARED ${SOURCES} ${PROPERTIES})
target_link_libraries(engine ${PROJECT_LINK_LIBS})
install(TARGETS engine DESTINATION usr/lib)