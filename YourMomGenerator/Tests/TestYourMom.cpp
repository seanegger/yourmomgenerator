//
//  TestYourMom.cpp
//  YourMomGenerator
//
//  Created by Sean Egger on 4/11/19.
//  Copyright © 2019 Sean Egger. All rights reserved.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "YourMomTextPaser.h"
#include "InputGatherer.hpp"

string test_verb_list_file_name = "all_verbs.txt";
string test_verb_list = "was\nran\n";

TEST_CASE("Testing parse_character_after_verb.") {
    YourMomTextPaser parser = YourMomTextPaser(test_verb_list_file_name);
    REQUIRE(parser.parse_characters_after_verb("He was too fat.") == "Your mom was too fat!");
    REQUIRE(parser.parse_characters_after_verb("Sarah ran away.") == "Your mom ran away!");
}

TEST_CASE("Testing remove_puncuations_succeeding.") {
    YourMomTextPaser parser = YourMomTextPaser(test_verb_list_file_name);
    std::string string_to_remove_punctuation_from = "a!";
    parser.remove_puncuations_succeeding(string_to_remove_punctuation_from);
    REQUIRE(string_to_remove_punctuation_from == "a");
    string_to_remove_punctuation_from = "a.";
    parser.remove_puncuations_succeeding(string_to_remove_punctuation_from);
    REQUIRE(string_to_remove_punctuation_from == "a");
    string_to_remove_punctuation_from = "a?";
    parser.remove_puncuations_succeeding(string_to_remove_punctuation_from);
    REQUIRE(string_to_remove_punctuation_from == "a");
}

TEST_CASE("Testing get_input()") {
    InputGatherer input_gatherer = InputGatherer();
    input_gatherer.set_using_test_input(true);
    
    string expected = "ainfwin4pf.df32f[ f' ;,2  pf3";
    input_gatherer.set_test_input(expected);
    REQUIRE(input_gatherer.get_input() == expected);
    expected = "184u1031029841021029481024";
    input_gatherer.set_test_input(expected);
    REQUIRE(input_gatherer.get_input() == expected);
    expected = "";
    input_gatherer.set_test_input(expected);
    REQUIRE(input_gatherer.get_input() == expected);
    expected = "     ";
    input_gatherer.set_test_input(expected);
    REQUIRE(input_gatherer.get_input() == expected);
}

//TEST_CASE("Testing reading verb file and using function display_verb_file") {
//    YourMomTextPaser parser = YourMomTextPaser(test_verb_list_file_name);
//    REQUIRE(parser.display_all_verbs() == test_verb_list);
//}
