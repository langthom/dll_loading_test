
cmake_minimum_required(VERSION 2.8)
project(DLL_Load_Test)

option(BUILD_THIRD_PARTY_STATIC "Build third party library static" ON)
if(BUILD_THIRD_PARTY_STATIC)
  set(THIRD_PARTY_BUILD_TYPE STATIC)
  message(STATUS "Building third party library static.")
else()
  set(THIRD_PARTY_BUILD_TYPE SHARED)
  message(STATUS "Building third party library shared.")
endif()

# ------------------------------------------------------

add_library(thirdparty_lib ${THIRD_PARTY_BUILD_TYPE}
  src/ThirdPartyLib.h
  src/ThirdPartyLib.cpp
)

# ------------------------------------------------------

add_library(our_lib SHARED
  src/MyDLL.h
  src/MyDLL.cpp
)
target_link_libraries(our_lib PRIVATE thirdparty_lib)

# ------------------------------------------------------

add_executable(calling_exe
  src/Main.cpp
)


