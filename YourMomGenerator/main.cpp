//
//  main.cpp
//  YourMomGenerator
//
//  Created by Sean Egger on 4/10/19.
//  Copyright © 2019 Sean Egger. All rights reserved.
//

#include <iostream>
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}

std::string getTextInput() {
    std::cout << "Please input sentence to produce zingers.";
    std::string x = "";
    std::cin >> x;
    return x;
}

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}
