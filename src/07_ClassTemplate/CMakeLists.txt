cmake_minimum_required(VERSION 3.5)

set( CMAKE_CXX_FLAGS "-std=c++11" )

set(CMAKE_CONFIGRATION_TYPES "Release" CACHE STRING "" FORCE)

# 查找源文件
aux_source_directory(. DIR_SRCS)

# 生成目标信息
set(EXENAME 07_ClassTemplate)
add_executable(${EXENAME} ${DIR_SRCS})
