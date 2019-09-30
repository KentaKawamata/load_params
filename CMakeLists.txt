cmake_minimum_required(VERSION 3.5)

set(SOURCE_NAME
        src/main.cpp
        include/loadParams.hpp)

if(NOT PROJECT_NAME)
    get_filename_component(DEFAULT_PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME_WE)
    set(PROJECT_NAME ${DEFAULT_PROJECT_NAME} CACHE STRING "Project name" FORCE)
endif(NOT PROJECT_NAME)
project(${PROJECT_NAME} C CXX)

set(USE_Boost 1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CXX_SOURCE_FILE_EXTS cpp;cxx)
set(CXX_INCLUDE_FILE_EXTS hpp;h)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)

#Boostライブラリを探す
if(USE_Boost)
    find_package(Boost REQUIRED)
    if(Boost_FOUND)
        message("---- Found Boost ${Boost_INCLUDE_DIRS}")
        include_directories(${Boost_INCLUDE_DIRS})
        link_directories(${Boost_LIBRARY_DIRS})
        add_definitions(${Boost_DEFINITIONS})
    else(Boost_FOUND)
        message(FATAL_ERROR " ---- Not Found Boost")
    endif(Boost_FOUND)
endif(USE_Boost)

#ビルドの対象と実行ファイル名
add_executable(${PROJECT_NAME} ${SOURCE_NAME})

target_link_libraries(${PROJECT_NAME} 
                        ${Boost_LIBRARIES}
                        -lpthread -lm)
