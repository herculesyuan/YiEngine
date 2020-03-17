# 项目名称
project(OpenGL)

# 源代码文件
file(GLOB_RECURSE project_headers *.h)
file(GLOB_RECURSE project_cpps *.cpp)
set(${PROJECT_NAME}_SOURCE ${project_headers} ${project_cpps})

source_group_by_dir(${PROJECT_NAME}_SOURCE)

# 头文件搜索目录
include_directories(
)

# 预定义宏
add_definitions()

# DLL
add_library(${PROJECT_NAME} MODULE ${${PROJECT_NAME}_SOURCE})

# multi-thread DLL
if (MSVC)
endif(MSVC)

# 链接的库
set(ALL_LIBS
)

# 链接库搜索目录
#target_link_directories(${PROJECT_NAME} PUBLIC ${VSV_SOURCE_DIR}/dependencies/$(Platform)$(Configuration))
target_link_libraries(${PROJECT_NAME} ${ALL_LIBS})

# post build event for Visual Studio
if (MSVC)
endif(MSVC)
