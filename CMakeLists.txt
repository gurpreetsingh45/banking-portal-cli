cmake_minimum_required(VERSION 3.10)

project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable and list all your source files
add_executable(bankPortalCli
    src/main.cpp
)

# Include header directories
target_include_directories(bankPortalCli PUBLIC include/)