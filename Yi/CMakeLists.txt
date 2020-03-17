# 项目名称
project(Yi)

# 源代码文件
file(GLOB_RECURSE project_headers *.h)
file(GLOB_RECURSE project_cpps *.cpp)
set(${PROJECT_NAME}_SOURCE ${project_headers} ${project_cpps})

source_group_by_dir(${PROJECT_NAME}_SOURCE)

# 头文件搜索目录
include_directories(
	${YiEngine_SOURCE_DIR}/Core
)

# EXE
add_executable(${PROJECT_NAME} WIN32 ${${PROJECT_NAME}_SOURCE})

# 链接的库
set(ALL_LIBS
Core.lib
)

# 链接库搜索目录
target_link_directories(${PROJECT_NAME} PUBLIC ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})
add_dependencies(${PROJECT_NAME}  Core)
