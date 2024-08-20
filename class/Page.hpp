#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>

class Page
{
    private:
        std::string title; // title of page
        std::string language;
        std::string name; // name of site
        std::string footerURL;
        std::string headerURL;
        std::string headerTemplate;
        std::string footerTemplate;
        void replaceElementByProp(std::string wordToReplace, std::string replacement, std::string& line);
        void replaceElementByTemplate(std::string wordToReplace, std::string url, std::string& line);

    public:
        std::string getTitle();
        Page(std::string title, std::string name, std::string language, std::string headerURL, std::string footerURL,std::string footerTemplate, std::string headerTemplate);
        ~Page();
        void buildPage();
};

#endif // PAGE_HPP