project(bx)
cmake_minimum_required(VERSION 3.8)

set(BX_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" CACHE STRING "Description")

file(GLOB_RECURSE BX_SRC
	"src/*.inl"
	"src/*.h"
	"src/*.hpp"
	"src/*.c"
	"src/*.cpp"

	"3rdparty/*.inl"
	"3rdparty/*.h"
	"3rdparty/*.hpp"
	"3rdparty/*.c"
	"3rdparty/*.cpp"

	"include/*.inl"
	"include/*.h"
	"include/*.hpp"
	"include/*.c"
	"include/*.cpp"
)

include_directories( include )
include_directories( 3rdparty )

add_definitions(
#	-DBX_CONFIG_DEBUG=1
)

if(MSVC)
	set(CMAKE_STATIC_LINKER_FLAGS_RELEASE "${CMAKE_STATIC_LINKER_FLAGS_RELEASE} /ignore:4221")
	set(CMAKE_STATIC_LINKER_FLAGS_DEBUG "${CMAKE_STATIC_LINKER_FLAGS_DEBUG} /ignore:4221")
endif()

add_library(bx STATIC
	${BX_SRC} 
)

set_target_properties(bx PROPERTIES
	CLEAN_DIRECT_OUTPUT 1
)
