#ifndef PAGE_HPP
#define PAGE_HPP

#include <string>

class Page
{
    private:
        std::string title;
        std::string language;
        void replaceElement(std::string wordToReplace, std::string replacement, std::string line);

    public:
        std::string getTitle();
        Page(std::string title, std::string language);
        ~Page();
        void buildPage();


};

#endif // PAGE_HPP