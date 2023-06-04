cmake_minimum_required(VERSION 3.25)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
project(homework02 VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)

# Stub, no tests in this homework:
option(WITH_BOOST_TEST "Whether to build Boost test" ON)


add_executable(ip_filter main.cpp ip_filter.cpp)

install(TARGETS ip_filter RUNTIME DESTINATION bin)

if(WITH_BOOST_TEST)
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
    add_executable(test_tuple test_tuple.cpp)
    set_target_properties(test_tuple PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
            COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
            )
    target_link_libraries(test_tuple ${Boost_LIBRARIES})
endif()

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(WITH_BOOST_TEST)
    enable_testing()
    add_test(test_tuple test_tuple)
endif()
