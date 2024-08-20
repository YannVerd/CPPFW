#include "Site.hpp"
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <vector>

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
    /* Creating folders */
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
        this->setHeaderURL(); // switch to Multi Page header
    } else {
        templatehf.open("/home/yann/Prog/CPPFW/templates/hfSP.style.swt");
    }
    this->completeHeader();

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
        Page page(i, this->name, this->getLanguage(), this->headerURL, this->footerURL, this->footerTemplate, this->headerTemplate);
        page.buildPage();
        
    }
}

std::string Site::getLanguage(){
    return this->language;
}

void Site::setLanguage(std::string &choice){
    this->language = choice;
}

void Site::setHeaderURL(){
    this->headerURL = "/home/yann/Prog/CPPFW/templates/headerMP.html.swt";
}

void Site::setName(std::string &newName){
    this->name = newName;
}

void Site::completeHeader()
{
    std::cout << "Starting create Header.." << std::endl;
    std::string nav;
    std::string content;
    
    std::string wordToReplaceAsName = "{{name}}";
    std::string wordToReplaceAsLinks = "{{links}}";
    std::string line;  
    // Check if the file is successfully opened 
    
        
    // template nav construction
    if(this->pagesArray.size()> 1) {
        std::ifstream templateHeader("/home/yann/Prog/CPPFW/templates/headerMP.html.swt");
        if (!templateHeader.is_open()) { 
            std::cerr << "Error opening the file!" << std::endl; 
            return; 
        } 
        std::cout << "create navbar template" << std::endl;
        for(auto itr : this->pagesArray){
            nav += "<a href="+itr+".html"+" >"+itr+"</a>";
            std::cout << "adding link " + nav << std::endl;
        }
        std::cout << "complete header template..." << std::endl;
        while(getline(templateHeader, line)){
            size_t len1 = wordToReplaceAsName.length();
            size_t len2 = wordToReplaceAsLinks.length();
            size_t pos1 = line.find(wordToReplaceAsName);
            size_t pos2 = line.find(wordToReplaceAsLinks);
            if (pos1 != std::string::npos){
                line.replace(pos1, len1, this->getName());
                std::cout << line << std::endl;
            }
            if (pos2 != std::string::npos){
                    line.replace(pos2, len2, nav);
                    std::cout << line << std::endl;
            }
            content += line+"\n";
        }
        templateHeader.close();
        
    }else{ // Single Page build
        std::ifstream templateHeader("/home/yann/Prog/CPPFW/templates/headerSP.html.swt");
        while(getline(templateHeader, line)){
            size_t len = wordToReplaceAsName.length();
            size_t pos = line.find(wordToReplaceAsName);
            if (pos != std::string::npos){
                line.replace(pos, len, this->getName());
                std::cout << line << std::endl;
            }

            content += line+"\n";
        }

        templateHeader.close();
    }           

    std::cout << content << std::endl;

    this->setHeaderTemplate(content);
    
}

void Site::setFooterTemplate(std::string footer){
    this->footerTemplate = footer;
}
std::string Site::getName()
{
    return this->name;
}
void Site::setHeaderTemplate(std::string header)
{
    this->headerTemplate = header;
}