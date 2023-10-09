#include <string>
#include "ClothingManager.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


TEST_CASE( "simple" )
{
    std::string toRev = "Hello";

    std::string res = get_string(toRev);

    REQUIRE( res == "Hello" );
}

