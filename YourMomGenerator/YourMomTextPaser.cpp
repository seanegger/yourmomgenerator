#include "YourMomTextPaser.h"

#include<string>
#include<set>
#include<list>

using namespace std;

// Init set object with strings of verbs
YourMomTextPaser::YourMomTextPaser(string file_name)
{
    string dummy_line;
    ifstream file_obj(file_name);
    
    // File error check
    if(file_obj.fail()){
        cout << "ERROR IN OPENING FILE!!!\n";
        throw 0;
    }
    
    // Basic init of set
    while ( getline (file_obj,dummy_line) )
    {
        all_verbs.insert(dummy_line);
    }
}

// Removes all text after puncations and including the puncations
void YourMomTextPaser::remove_puncuations_succeeding(string& input_string){
    
    string puncuations[] = {".","!","?"};
    for(const string &punc : puncuations) {
        input_string = input_string.substr(0, input_string.find(punc));
    }
}


// Removes everything before the verb and then replaces it with "Your mom"
string YourMomTextPaser::parse_characters_after_verb(string input_string) {
    
    remove_puncuations_succeeding(input_string);
    string token;
    size_t pos = 0;
    
    // Tokensize input string; delaminate on spaces
    while ((pos = input_string.find(" ")) != std::string::npos) {
        
        token = input_string.substr(0, pos);
        
        // Check if token is in the
        if (all_verbs.find(token) != all_verbs.end()) {
            
            // Trim whitespace
            input_string = input_string.substr(input_string.find_first_not_of(' '), (input_string.find_last_not_of(' ') - input_string.find_first_not_of(' ')) + 1);
            
            input_string = "Your mom " +  input_string + "!";
            break;
        }
        else {
            // Remove characters
            input_string.erase(0, pos + 1);
        }
    }
    return input_string;
}

// Iterates through list to display the verbs
string YourMomTextPaser::display_all_verbs(){
    string to_return = "";
    for(auto verb : all_verbs) {
        to_return += verb + "\n";
        cout << verb << "\n";
    }
    return to_return;
}
