#include <catch2/catch.hpp>
#include "src/ctf.h"

// Simple example function to show off Catch testing
int Factorial( int number ) {
  return number > 1 ? Factorial( number - 1 ) * number : 1;  
}

TEST_CASE( " Factorial of 0 is 1", "[multi-file:2]" ) {
    REQUIRE( Factorial(0) == 1 );
}

TEST_CASE( " Factorials of 1 and higher are computed", "[multi-file:2]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}
