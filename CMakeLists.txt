cmake_minimum_required (VERSION 2.6)

#SET(CMAKE_INCLUDE_PATH ${CMAKE_INCLUDE_PATH} "C:/win32libs/boost")
#SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "C:/win32libs/boost/lib")

#set(BOOST_ROOT "/usr/local/Cellar/boost/1.49.0")

#FIND_PACKAGE(Boost 1.49.0)
#IF (Boost_FOUND)
    #INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
#ENDIF()

INCLUDE_DIRECTORIES("/usr/local/include")
LINK_DIRECTORIES("/usr/local/lib")

project (PropLists)
add_executable(test main.cpp)
target_link_libraries(test gtest)
