#include <catch2/catch.hpp>
#include "src/ctf.h"

// Simple example function to show off Catch testing
int Factorial( int number ) {
  return number > 1 ? Factorial( number - 1 ) * number : 1;  
}

TEST_CASE( "1: Factorial of 0 is 1", "[multi-file:2]" ) {
    REQUIRE( Factorial(0) == 1 );
}

TEST_CASE( "2: Factorials of 1 and higher are computed", "[multi-file:2]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

//Actually test the getCTF function. You may wish to test the CTF constructor and setters/getters separately.
TEST_CASE( "3: Test getCTF", "[multi-file:2]" ) {
  CTF ctf;
  ctf.setValues(10000.0, 12000.0, 90.0, 300.0, 2.7, 0.1, 0.0, 1.0, 0.0);
  float val = ctf.getCTF(10.0, 10.0);
  REQUIRE(val == Approx(0.59154));
}
