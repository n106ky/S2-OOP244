/*
    OOP244 NEE WS09
    MOHAMMAD SHAMAS

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    Completed date: 2023 JULY 26
*/
#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
namespace sdds {
    class Text {
        char* m_filename{};          // Hold the name of the file dynamically
        char* m_content{};           // Holds the content of the text file dynamically
        int getFileLength()const;    // It returns the length (size) of the text file on the disk
    protected:
        const char& operator[](int index)const;
        int getContentLen() const;   // Getter for child class
    public:
        Text(const char* filename = nullptr);

        // RULE OF THREE
        Text(const Text& x);
        Text& operator=(const Text& x);
        ~Text();

        // DISPLAY & READ
        void read();
        virtual void write(std::ostream& os)const;
    };
    // INSERTION OVERLOAD
    std::ostream& operator<<(std::ostream& os, const Text& x);
}
#endif // !SDDS_PERSON_H__

