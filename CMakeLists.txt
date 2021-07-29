cmake_minimum_required(VERSION 3.17)
project(sim)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(MINGW_ROOT A:/msys64/mingw64)
set(SFML_ROOT A:/SFML-64)

add_executable(sim main.cpp headers/Window.hpp "components/view/window/Window.cpp" "tests/bubbleSort.cpp" "components/view/shapes/GRectangle.cpp" headers/GRectangle.hpp "components/view/utils/GVertex.cpp" headers/GVertex.hpp "components/view/color/GColor.cpp" headers/GColor.hpp tests/SteeringBehaviours.cpp components/view/utils/GVector.cpp headers/GVector.hpp components/view/utils/GMatrix.cpp headers/GMatrix.hpp)

include_directories(headers ${SFML_ROOT}/include)

find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(sim ${SFML_LIBRARIES})
endif ()

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "${MINGW_ROOT}/mingw32/i686-w64-mingw32/lib/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
