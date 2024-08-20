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
        std::string headerURL = "/home/yann/Prog/CPPFW/templates/headerSP.html.swt"; // path to Single Page (SP) template
        std::string footerURL = "/home/yann/Prog/CPPFW/templates/footer.html.swt";
        std::string footerTemplate;
        std::string headerTemplate;
        void completeHeader();
    public:
        ~Site();
        void buildSite();
        std::string getLanguage();
        void setLanguage(std::string &choice);
        void setHeaderURL();
        void setName(std::string &newName);
        void setPagesArray(std::vector<std::string> &arrPages);
        void setSectionsArray(std::vector<std::string> &arrSections);
        void setHeaderTemplate(std::string header);
        void setFooterTemplate(std::string footer);
        std::string getName();
};

#endif // SITE_HPP

