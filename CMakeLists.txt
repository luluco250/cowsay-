cmake_minimum_required(VERSION 3.15)
project(cowsay)

if(CMAKE_BUILD_TYPE MATCHES Debug)
	set(debug TRUE)
	set(out_dir "${CMAKE_SOURCE_DIR}/bin_d")
else()
	set(debug FALSE)
	set(out_dir "${CMAKE_SOURCE_DIR}/bin")
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/src)

set_target_properties(cowsay PROPERTIES
	CXX_STANDARD 17
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${out_dir}
)