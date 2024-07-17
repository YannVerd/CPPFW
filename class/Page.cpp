#include "Page.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string Page::getTitle()
{
    return this->title;
}

Page::Page(std::string title, std::string language)
{
    this->title = title;
    this->language = language;
}

Page::~Page(){}

void Page::buildPage()
{
    std::cout << "build page work in progress" << std::endl;
    std::ifstream templateHome("/home/yann/Prog/CPPFW/templates/base.html.swt");
    std::string content;
    std::string line;
    // Check if the file is successfully opened 
    if (!templateHome.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    } 

    while(getline(templateHome, line)){
      this->replaceElement("{{language}}", this->language, line);
      content += line+"\n";
    }
    templateHome >> content;
    templateHome.close();
    
    // create html file
    std::ofstream newFile(this->getTitle()+".html");
    newFile << content;
    newFile.close();

    std::cout << this->getTitle() + " page created" << std::endl;
}

void replaceElement(std::string wordToReplace, std::string replacement, std::string line)
{
    size_t len = wordToReplace.length();
    size_t pos = line.find(wordToReplace);
            if (pos != std::string::npos){
                line.replace(pos, len, replacement);
            }

}