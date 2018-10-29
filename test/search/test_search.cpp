#include <vector>


#define CATCH_CONFIG_MAIN
#include "../../thirdparty/catch.hpp"

#include "linear_search.hpp"
#include "binary_search.hpp"
#include "jump_search.hpp"
#include "fibonacci_search.hpp"
#include "exponential_search.hpp"
#include "interpolation_search.hpp"


/**
 * test cases for linear_search
 *
 */

TEST_CASE("LinearSearch", "[linear_search]") {
  std::vector<int> v;

  REQUIRE(-1 == linear_search(v, 0));

  SECTION("only one element in vector") {
    v.push_back(10);
    REQUIRE(-1 == linear_search(v, 0));
    REQUIRE(0 == linear_search(v, 10));
  }

  SECTION("all same elements in vector") {
    v.push_back(10);
    v.push_back(10);

    REQUIRE(0 == linear_search(v, 10));
  }

  SECTION("match the last element") {
    v.clear();
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    REQUIRE(2 == linear_search(v, 3));
  }

  SECTION("find missing element in vector") {
    v.push_back(100);
    REQUIRE(-1 == linear_search(v, 200));
  }
}


// test binary_search
TEST_CASE("test binary_search", "[binary_search]") {
  SECTION("empty vector") {
    std::vector<int> v;
    REQUIRE(-1 == binary_search(v, 0, v.size()-1, 0));
  }

  SECTION("find a existed element in vector") {
    std::vector<int> v2 = {1, 2, 3, 4};
    REQUIRE(3 == binary_search(v2, 0, v2.size() - 1, 4));
  }

  SECTION("searching a missing element in vector") {
    std::vector<int> v3 = {1, 2, 3, 4};
    REQUIRE(-1 == binary_search(v3, 0, v3.size() - 1, 100));
  }

  SECTION("all elements are same in vector") {
    std::vector<int> v4 = {1,1,1,1};
    REQUIRE(1 == binary_search(v4, 0, v4.size() - 1, 1));
  }
}


// test jump_search
TEST_CASE("test jump_search", "[jump_search]") {
  SECTION("empty vector") {
    std::vector<int> v;
    REQUIRE(-1 == jump_search(v, 0));
  }

  SECTION("only one element in vector") {
    std::vector<int> v{1};
    REQUIRE(0 == jump_search(v, 1));
  }

  SECTION("all elements are same in vector") {
    std::vector<int> v{1, 1, 1};
    REQUIRE(0 == jump_search(v, 1));
  }

  SECTION("find missing element in vector") {
    std::vector<int> v{1, 2, 3};
    REQUIRE(-1 == jump_search(v, 0));
  }

  SECTION("find existed element in vector") {
    std::vector<int> v{1, 2, 3};
    REQUIRE(1 == jump_search(v, 2));
  }
}
