#include "Site.hpp"
#include <iostream>
#include <sys/stat.h>
#include <fstream>

#include "Page.hpp"

void Site::setPagesArray(std::vector<std::string> &arrPages)
{
    this->pagesArray = arrPages;
}

void Site::setSectionsArray(std::vector<std::string> &arrSection)
{

    this->sectionsArray = arrSection;
    
}

Site::~Site(){}

void Site::buildSite()
{   
    /* Creating folder style */
    std::cout << "Creating folder(s)..." << std::endl;
    if (mkdir("./styles", 0777) == 0) { 
        std::cout << "Folder created successfully." << std::endl; 
    } else { 
        std::cout << "Failed to create folder." << std::endl; 
    }

    /* creating and fill styles.css file*/
    std::cout << "Creating stylesheet..." << std::endl;
    std::ifstream templateHome("/home/yann/Prog/CPPFW/templates/base.style.swt");
    std::ifstream templatehf;
    if(this->pagesArray.size() > 1){
        templatehf.open("/home/yann/Prog/CPPFW/templates/hfMP.style.swt");
        this->setHeader(); // switch to Multi Page header
    } else {
        templatehf.open("/home/yann/Prog/CPPFW/templates/hfSP.style.swt");
    }

    std::string content;
    std::string line;
    // Check if the file is successfully opened 
    if (!templateHome.is_open()) { 
        std::cerr << "Error opening the file!" << std::endl; 
        return; 
    } 
    std::cout << "loading file..." << std::endl;
    while(getline(templateHome, line)){
      content += line+"\n";
    }
    while(getline(templatehf, line)){
        content += line+"\n";
    }
    templateHome >> content;
    templateHome.close();

    std::cout << "Creating and fill file..." << std::endl;
    std::ofstream newFile("./styles/style.css");
    newFile << content;
    newFile.close();

    std::cout << "Stylesheet complete..." << std::endl;

    /* building page */
    std::cout << "starting to build Page(s)..." << std::endl;
    for (auto i: this->pagesArray)
    {
        Page page(i, this->name, this->getLanguage(), this->footer, this->header);
        page.buildPage();
        
    }
}

std::string Site::getLanguage(){
    return this->language;
}

void Site::setLanguage(std::string &choice){
    this->language = choice;
}

void Site::setHeader(){
    this->header = "/home/yann/Prog/CPPFW/templates/headerMPhtml.swt";
}

void Site::setName(std::string &newName){
    this->name = newName;
}
