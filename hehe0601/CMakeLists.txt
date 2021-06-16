# Project name
project(dt060g_hehe0601v1)

# Minimum required cmake version
cmake_minimum_required(VERSION 3.2)

# Compile with c++ 11 support
set(CMAKE_CXX_STANDARD 11)

# Static inclusion of dependencies required for the executable to be independent
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

# Save name of directories in variables for reuse
set(PROJECT "Project")

# Add source directories for all labs
aux_source_directory(${PROJECT}/src PROJECT_SRC)

# Add executables for all configurations!
add_executable(${PROJECT_NAME}_${PROJECT} ${PROJECT_SRC})

# In order to avoid '../../../' semantics in include paths (relative), we need to add
# target directories to respective run configuration
target_include_directories(${PROJECT_NAME}_${PROJECT} PRIVATE "./${PROJECT}/include")