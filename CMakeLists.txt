
cmake_minimum_required(VERSION 3.8.0)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
cmake_policy(SET CMP0003 NEW)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Use relative paths
# This is mostly to reduce path size for command-line limits on windows
if(WIN32)	
	add_compile_options("/std:c++17")
	add_compile_options("/MP")
	
	add_definitions(/D _UNICODE)
	
	# copy .clang-format to cmake solution directory	
	string(COMPARE NOTEQUAL "${YiEngine_BINARY_DIR}" "" result)
	if(result)
		file(COPY ${YiEngine_SOURCE_DIR}/.clang-format DESTINATION ${YiEngine_BINARY_DIR})
	endif()
	
endif()

project(YiEngine)

# Specify build paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${YiEngine_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${YiEngine_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${YiEngine_BINARY_DIR}/bin")


macro(source_group_by_dir source_files)
    if(MSVC)
        set(sgbd_cur_dir ${CMAKE_CURRENT_SOURCE_DIR})
        foreach(sgbd_file ${${source_files}})
            string(REGEX REPLACE ${sgbd_cur_dir}/\(.*\) \\1 sgbd_fpath ${sgbd_file})			
            string(REGEX REPLACE "\(.*\)/.*" \\1 sgbd_group_name ${sgbd_fpath})			
            string(COMPARE EQUAL ${sgbd_fpath} ${sgbd_group_name} sgbd_nogroup)
            string(REPLACE "/" "\\" sgbd_group_name ${sgbd_group_name})
            if(sgbd_nogroup)
				get_filename_component(file_ext ${sgbd_group_name} EXT)
				if (${file_ext} MATCHES ".[hH]")
					set(sgbd_group_name "Header Files")
				endif()
				
				if (${file_ext} STREQUAL ".cpp")
					set(sgbd_group_name "Source Files")
				endif() 
            endif(sgbd_nogroup)
            source_group(${sgbd_group_name} FILES ${sgbd_file})
        endforeach(sgbd_file)
    endif(MSVC)
endmacro(source_group_by_dir)

add_subdirectory(Core)
add_subdirectory(Yi)

#add_subdirectory(OpenGL)
#add_subdirectory(Vulkan)







