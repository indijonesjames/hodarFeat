cmake_minimum_required( VERSION 2.8 )
project(hodarfeat)

#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11 -O3" )

find_package( OpenCV 3.1 REQUIRED )

include_directories( 
    ${OpenCV_INCLUDE_DIRS} 
    ${G2O_INCLUDE_DIRS}
    ${CSPARSE_INCLUDE_DIR}
    "/usr/include/eigen3/"
)

add_library(hodarfeat.h)

set_target_properties(hodarfeat.h PROPERTIES LINKER_LANGUAGE CXX)

add_executable( feature_extraction feature_extration.cpp hodarfeat.cpp )
target_link_libraries(feature_extraction ${OpenCV_LIBS} )
