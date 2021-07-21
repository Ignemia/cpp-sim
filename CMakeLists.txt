cmake_minimum_required(VERSION 3.17)
project(sim)

set(CMAKE_CXX_STANDARD 20)

add_executable(sim main.cpp headers/Window.hpp " components/view/window/Window.cpp" tests/bubbleSort.cpp " components/view/shapes/GRectangle.cpp" headers/GRectangle.hpp " components/view/utils/GVertex.cpp" headers/GVertex.hpp)

include_directories(headers a:/SFML-64/include)

set(SFML_ROOT a:/SFML-64)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(sim ${SFML_LIBRARIES})
endif ()

if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/Program Files/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/x86_64-w64-mingw32/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
