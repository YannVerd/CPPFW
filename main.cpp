#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <ncurses.h>

#include "class/Site.hpp"

std::vector<std::string> stringToVector(std::string &string){
    std::istringstream stream(string);
    std::string token;
    std::vector<std::string> array;
    while(std::getline(stream, token, ' ')){
        std::cout << "token : " + token <<std::endl;
        array.push_back(token);
    }
    return array;
}

int main()
{

    std::cout << " Welcome to my auto generate static web site" << std::endl;
    std::cout << "Which pages would you like? Please select the pages you would like from the list below (separate names with a space): " << std::endl;
    std::cout << " * home" << std::endl;
    std::cout << " * portfolio" << std::endl;
    std::cout << " * services" << std::endl;
    std::cout << " * contact" << std::endl;
    std::cout << "If you want a Single Page Site, simply write 'home' : " << std::endl;
    std::string pages;
    std::string sections;
    std::getline(std::cin, pages);
    

    // extract pages and add to array
    std::vector<std::string> arrayPages = stringToVector(pages);
   
    
    Site site;
    
    // in case of single page site, ask which section user want
    if(arrayPages.size() == 1){
        std::cout << "Single Page Site detected..." << std::endl;
        arrayPages[0]= "home";
        std::cout << "Which section would you want into your single page site ? (same choice than before)" << std::endl;
        std::getline(std::cin, sections);

        std::vector<std::string> arraySections = stringToVector(sections);

        site.setSectionsArray(arraySections);
    }
    site.setPagesArray(arrayPages);

    // choose name's site
    std::cout << "What is the name of your Site ?";
    std::string nameSite;
    std::getline(std::cin, nameSite);
    std::cout << std::endl;
    site.setName(nameSite);

    site.buildSite();



    return 0;
}