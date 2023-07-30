/*
    OOP244 NEE WS09
    MOHAMMAD SHAMAS

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Completed date: 2023 JULY 26
*/
#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include "Text.h"
namespace sdds {

    class HtmlText : public Text {
        char* m_title{}; // Holds the title of the HTML conversion dynamically.
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);

        // RULE OF THREE
        HtmlText(const HtmlText& ht);
        HtmlText& operator=(const HtmlText& ht);
        ~HtmlText();

        // TEXT OVERRIDE
        void write(std::ostream& os)const;
    };
}
#endif // !SDDS_HTMLTEXT_H__
