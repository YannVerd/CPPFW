#ifndef SITE_HPP
#define SITE_HPP

#include <string>
#include <vector>

class Site
{
    private:
        std::vector<std::string> pagesArray;
        std::string name; // site's name
        std::string language = "eng";
        std::vector<std::string> sectionsArray;
        std::string header = "/home/yann/Prog/CPPFW/templates/headerSP.html.swt"; // path to Single Page (SP) template
        std::string footer = "/home/yann/Prog/CPPFW/templates/footer.html.swt";
        void completeNavbar();
    public:
        ~Site();
        void buildSite();
        std::string getLanguage();
        void setLanguage(std::string &choice);
        void setHeader();
        void setName(std::string &newName);
        void setPagesArray(std::vector<std::string> &arrPages);
        void setSectionsArray(std::vector<std::string> &arrSections);
};

#endif // SITE_HPP

