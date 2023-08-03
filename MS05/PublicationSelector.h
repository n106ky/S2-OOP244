// Final Project 
// PublicationSelector
// File PublicationSelector.h
// Version 1.0
// Author	Fardad Soleimanloo
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
//                    
/////////////////////////////////////////////////////////////////
#ifndef SDDS_PUBLICATIONSELECTOR_H
#define SDDS_PUBLICATIONSELECTOR_H
#include "Publication.h"
namespace sdds {
   class PublicationSelector {
      const int allocationUnit{ 10 };
      const int m_pageSize{ };
      const Publication** m_pub{};
      char m_title[81]{};
      int m_currentPage{ 1 };
      int m_arraySize{};
      int m_noOfPubs{};
      void display(int page)const;
      int getSelectedLibRef()const;
   public:
      PublicationSelector(const char* title = "Select a publication: ", int pageSize = 15);
      ~PublicationSelector();
      PublicationSelector(const PublicationSelector&) = delete;
      PublicationSelector& operator=(const PublicationSelector&) = delete;
      PublicationSelector& operator<<(const Publication* pub);         // adds publication to the menu by address
      PublicationSelector& operator<<(const Publication& pub);         // add publication tot he menu by reference     
      operator bool()const;                                            // return true menu is not empty 
      void reset();                                                    // clears all the publications and sets the selector empty and ready to be refilled
      void sort();                                                     // sorts the selections based on date and title
      int run();                                                       // runs the selection return the library reference of the selected publication.
   };
}
#endif // !SDDS_PUBLICATIONSELECTOR_H