cmake_minimum_required(VERSION 3.9)
project(newtest)

# Download automatically, you can also just copy the conan.cmake file
 if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
 endif()

 include(${CMAKE_BINARY_DIR}/conan.cmake)

 conan_cmake_run(CONANFILE conanfile.txt
                 BASIC_SETUP
                 BUILD missing)

set(CMAKE_CXX_STANDARD 11)

#set(Boost_USE_STATIC_LIBS OFF)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)
#find_package(Boost 1.45.0 COMPONENTS filesystem regex)
#
#if(Boost_FOUND)
#    add_executable(newtest main.cpp myclass.cpp myclass.h b.cpp b.h)
#    target_link_libraries(newtest ${Boost_LIBRARIES})
#endif()

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()

set(SOURCE_FILES main.cpp)
add_executable(newtest ${SOURCE_FILES})
target_link_libraries(newtest ${CONAN_LIBS})
