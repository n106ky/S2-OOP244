/*
    OOP244 MS3

    KA YING, CHAN #123231227
    kchan151@myseneca.ca

    MOHAMMAD SHAMAS
    NEE

    I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
    COMPLETED: 2023 JULY 21
*/
#ifndef SDDS_STREAMABLE_H_
#define SDDS_STREAMABLE_H_

namespace sdds {

    // STREAMABLE INTERFACE MODULES - LIB:
    class Streamable {
    public:
        // STREAMABLE PURE VIRTUAL FUNCTIONS

        /*
        read pure virtual function
        read receives and returns a reference of an istream object.
        Functions overriding this function will read from an istream object.
        */
        virtual std::istream& read(std::istream& in) = 0;

        /*
        write pure virtual function
        This method is not capable of modifying the Streamable object.write receives and returns a reference of an ostream object.
        Functions overriding this function will write into an ostream object.
        */
        virtual std::ostream& write(std::ostream& os)const = 0;

        /*
        conIO
        This method is not capable of modifying the Streamable object.conIo receives a reference of an ios object and returns a Boolean.
        Functions overriding this function will determine if the incoming ios object is a console IO object or not.
        */
        virtual bool conIO(std::ios& obj)const = 0;

        /*
        Boolean conversion operator overload (pure virtual)
        Boolean conversion overloads of this method will return if the Streamable object is in a valid state or not.
        */
        virtual operator bool() const = 0;

        /*
        destructor
        Add an empty virtual destructor to this interface to guaranty that the descendants of the Streamable are removed from memory with no leak.
        */
        virtual ~Streamable() = 0;
    };

    /*
    Insertion operator overload
    Overload the insertion operator so a constant object of type Streamable can be written on an ostream object only if the Streamable object is in a valid state.
    Otherwise, the function will quietly ignore the insertion action.
    */
    std::istream& operator>>(std::istream& is, Streamable& s);

    /*
    Extraction operator overload
    Overload the extraction operator so an object of type Streamable can be read from an istream object.
    */
    std::ostream& operator<<(std::ostream& os, const Streamable& s);
}
#endif // !SDDS_LIB_H_
