cmake_minimum_required(VERSION 3.25)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(homework02 VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)

# Stub, no tests in this homework
option(WITH_BOOST_TEST "Whether to build Boost test" ON)

add_executable(ip_filter main.cpp ip_filter.cpp)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)
