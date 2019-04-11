//
//  InputGatherer.hpp
//  YourMomGenerator
//
//  Created by Sean Egger on 4/11/19.
//  Copyright © 2019 Sean Egger. All rights reserved.
//

#ifndef InputGatherer_hpp
#define InputGatherer_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class InputGatherer
{
private:
    /********* Private members *********/
    string test_input;
    bool using_test_input;
    
  
public:
    // Override Constructor
    InputGatherer();
    
    /********* Public functions *********/
    void set_using_test_input(bool using_test_input);
    
    void set_test_input(string test_input);
    
    string get_input();
};

#endif /* InputGatherer_hpp */
