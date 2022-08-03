#ifndef SDDS_FULLNAME_H
#define SDDS_FULLNAME_H
  
  #include<iostream>
  #include "Name.h"

  namespace sdds {
    class FullName : public Name {
        char* m_value;
    public:
        FullName();
        FullName(const char* name, const char* lastName);
        // Rule of three goes here:
        ~FullName();
        FullName (const FullName &fname);
        FullName& operator=(const FullName &fname);
        
        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);  

        friend std::ostream &operator<<(std::ostream &os, const FullName &obj);
        friend std::istream &operator>>(std::istream &is, FullName &obj);
    };
  }
  #endif