#ifndef SDDS_NAME_H
#define SDDS_NAME_H

#include<iostream>

namespace sdds {
    class Name {
        char* m_value;
    public:
        Name();  
        Name(const char* name);
        // Rule of three goes here:
        ~Name();
         Name (const Name &name);
         Name& operator=(const Name &name);

        operator const char* ()const;
        virtual operator bool()const;
        virtual std::ostream& display(std::ostream& ostr = std::cout)const;
        virtual std::istream& read(std::istream& istr = std::cin);  
        void set(const char* name);

        friend std::ostream &operator<<(std::ostream &os, const Name &obj);
        friend std::istream &operator>>(std::istream &is, Name &obj);
    };
}

#endif