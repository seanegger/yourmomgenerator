//
//  InputGatherer.cpp
//  YourMomGenerator
//
//  Created by Sean Egger on 4/11/19.
//  Copyright © 2019 Sean Egger. All rights reserved.
//

#include "InputGatherer.hpp"

InputGatherer::InputGatherer() {
    using_test_input = false;
}

void InputGatherer::set_using_test_input(bool using_test_input) {
    this->using_test_input = using_test_input;
}

void InputGatherer::set_test_input(string test_input) {
    this->test_input = test_input;
}

string InputGatherer::get_input() {
    // For testing purposes return predefined string if testing
    if (using_test_input) {
        return test_input;
    }
    // User input loop
    string user_input;
    while (true) {
        
        user_input = "Default val";
        
        cout << "Press Q/q to quit\n" <<"Input: ";
        getline(cin, user_input);
        
        // User input handling
        if (user_input == "Default val") {
            cout << "Please put in a dumb phrase so we can do dumb things with it...\n";
        }
        else if(user_input == "") {
            cout << "Don't just put nothing...god dam jackass....\n";
        }
        else if (user_input == "q" || user_input == "Q" ){
            cout << "Ok we will make fun of your mother another time!\n";
            break;
        }
        // Possible dumb input we can do dumb things with
        else{
            return user_input;
        }
    }
    return nullptr;
}
