#include<iostream>
#include<cstring>
#include "Name.h"

namespace sdds {
        Name::Name() {
            m_value = new char[1];
            strcpy(m_value, "");
        }

        Name::Name(const char* name) {
            m_value = new char[255];
            strcpy(m_value, name);
        }

        // Rule of three goes here:
        Name::~Name() {
            delete [] m_value;
        }

        Name:: Name (const Name &name) {
            m_value = new char[255];
            strcpy(m_value, name.m_value);
        }

        Name& Name::operator=(const Name &name) {
            delete [] m_value;
            m_value = new char[255];
            m_value =  name.m_value;
            return *this;
        }

        Name::operator const char* ()const {
            return m_value;
        }

        Name::operator bool()const {
            if( m_value ==nullptr) {
                return false;
            }
            return true;
        }

        std::ostream& Name::display(std::ostream& ostr)const {
            if(operator bool()) {
                ostr<<m_value;
            }
            return ostr;
        }

        std::istream& Name::read(std::istream& istr) {
            istr>>m_value;
            if(!istr.fail())  {
                istr.ignore();
            }
            return istr;
        }

        void Name::set(const char* name) {
            delete [] m_value;
            m_value = new char[255];
            strcpy(m_value, name);
        }

         std::ostream &operator<<(std::ostream &os, const Name &obj) {
            return obj.display(os);
         }
         
         std::istream &operator>>(std::istream &is, Name &obj) {
            return obj.read(is);
         }
}