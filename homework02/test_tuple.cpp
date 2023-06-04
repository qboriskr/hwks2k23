#define BOOST_TEST_MODULE test_version

#include <functional>
#include <iostream>
#include <string>
#include <tuple>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_tuple)


struct foo {
    int id;
    std::string name;
};

auto foo(int, int) {
    return std::make_tuple(std::string("surname"), 19);
}


BOOST_AUTO_TEST_CASE(test_valid_version) {
        auto r = foo(1, 2);
        std::string sn;
        int old;
        std::make_tuple(std::ref(sn), std::ref(old)) = foo(1, 2);
        std::tie(sn, old) = foo(1, 2);
        BOOST_CHECK(sn=="surnam);
        BOOST_CHECK(old==19);
}

BOOST_AUTO_TEST_SUITE_END()

