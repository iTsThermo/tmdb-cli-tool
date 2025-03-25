#include <stdio.h>
#include <iostream>
// #include <v8/v8-json.h>
#include <string>
#include <bits/stdc++.h> 
#include <array>

void print_help_manual() {
    std::cout << "You can use the following commands to find the latest movies" << std::endl 
    << "\"--type\" " << "followed by:" << std::endl
    << "\"playing\"" << std::endl 
    << "\"popular\"" << std::endl
    << "\"top\"" << std::endl
    << "\"upcoming\"" << std::endl;
}

int main(int argc, char *argv[])
{   
    // Check for CLI arguements
    // If not valid arguements prompt user with manual
    std::cout << "Num of args: " << argc << std::endl;

    if (argc != 3) {
        print_help_manual();
        return 1;
    }

    // std::cout << argv[0] << std::endl;
    // std::cout << argv[1] << std::endl;
    // std::cout << argv[2] << std::endl;

    std::string type_arg_trimmed = argv[1];

    std::cout << type_arg_trimmed << std::endl;

    type_arg_trimmed.erase(std::remove_if(type_arg_trimmed.begin(), type_arg_trimmed.end(), ::isspace), type_arg_trimmed.end());

    if (type_arg_trimmed != "--type") {
        print_help_manual();
        return 1;
    }

    std::string category_arg_lowercase = argv[2];

    std::transform(category_arg_lowercase.begin(), category_arg_lowercase.end(), category_arg_lowercase.begin(), ::tolower); 
    
    category_arg_lowercase.erase(std::remove_if(category_arg_lowercase.begin(), category_arg_lowercase.end(), ::isspace), category_arg_lowercase.end());

    std::string movie_categories[] = {"playing", "popular", "top", "upcoming"};

    bool category_found = false;

    for (int i = 0; i < sizeof(movie_categories); i++) {
        if (movie_categories[i] == category_arg_lowercase) {
            category_found = true;
        }
    }

    std::cout << category_found;

    if (category_found == false) {
        print_help_manual();
        return 1;
    }

    // std::cout << category_arg_lowercase << std::endl;

    // struct {
    //     std::string name;
    //     int8_t age;
    // } person;


    // std::cout << "Hello World" << std::endl;
    return 0;
}