#include "Page.hpp"
#include <iostream>
#include <fstream>

using namespace std;

string Page::getTitle()
{
    return this->title;
}

Page::Page(std::string title, std::string name, std::string language, std::string headerURL, std::string footerURL, std::string footerTemplate, std::string headerTemplate)
{
    this->title = title;
    this->name = name;
    this->language = language;
    this->footerURL = footerURL;
    this->headerURL = headerURL;
    this->headerTemplate = headerTemplate;
    this->footerTemplate = footerTemplate;
    
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
      this->replaceElementByProp("{{language}}", this->language, line);
      this->replaceElementByProp("{{name}}", this->name, line);
      this->replaceElementByTemplate("{{footer}}", this->footerURL, line);
      this->replaceElementByProp("{{header}}", this->headerTemplate, line);
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

void Page::replaceElementByProp(std::string wordToReplace, std::string replacement, std::string& line)
{
    size_t len = wordToReplace.length();
    size_t pos = line.find(wordToReplace);
            if (pos != std::string::npos){
                line.replace(pos, len, replacement);
            }

}

void Page::replaceElementByTemplate(std::string wordToReplace, std::string url, std::string &line)
{
    /* creating and fill styles.css file*/
    std::cout << "replace "+wordToReplace+" by template" << std::endl;
    std::ifstream templateUse(url);
    std::string content;
    std::string lineFile;
    // Check if the file is successfully opened 
    if (!templateUse.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    } 
    std::cout << "loading file..." << std::endl;
    while(getline(templateUse, lineFile)){
      content += lineFile+"\n";
    }
    templateUse >> content;
    templateUse.close();
    this->replaceElementByProp(wordToReplace, content, line);
}
