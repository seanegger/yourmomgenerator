
#ifndef YourMomTextPaser_h
#define YourMomTextPaser_h

#include<iostream>
#include<fstream>
#include<string>
#include<set>

using namespace std;

class YourMomTextPaser
{
    private:
        /********* Private members *********/
        set<string> all_verbs;

        /********* Private functions *********/
    
    public:
    
        // Override Constructor
        YourMomTextPaser(string file_name);
    
        /********* Public functions *********/
        string parse_characters_after_verb(string);
        void remove_puncuations_succeeding(string&); // made this public just so we have more to test
        string display_all_verbs();
    
};


#endif /* double_linked_list_hpp */
