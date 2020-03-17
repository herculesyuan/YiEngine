# 项目名称
project(Core)

# 源代码文件
file(GLOB_RECURSE project_headers *.h)
file(GLOB_RECURSE project_cpps *.cpp)
set(${PROJECT_NAME}_SOURCE ${project_headers} ${project_cpps})

source_group_by_dir(${PROJECT_NAME}_SOURCE)

# library
add_library(${PROJECT_NAME} ${${PROJECT_NAME}_SOURCE})

