#include<iostream>
#include<cstring>
#include <sstream>
#include "FullName.h"


namespace sdds {
        FullName::FullName() {
            m_value = new char[1];
            strcpy(m_value, "");
        }

        FullName::FullName(const char* name, const char* lastName): Name(name) {
            m_value = new char[255];
            strcpy(m_value, lastName);
        }

        // Rule of three goes here:
        FullName::~FullName() {
            delete [] m_value;
        }

        FullName::FullName (const FullName &fname) {
            m_value = new char[255];
            strcpy(m_value, fname.m_value);
        }

        FullName& FullName::operator=(const FullName &fname){
            delete [] this->m_value;
            m_value = new char[255];
            set(fname.Name::operator const char *());
            strcpy(m_value, fname.m_value);
            return *this;
        }
        
        FullName::operator const char* ()const {
            return m_value;
        }
        FullName::operator bool()const {
            if( m_value != nullptr && Name::operator bool()) {
                return true;
            } 
                return false;
        }

        std::ostream& FullName::display(std::ostream& ostr)const {
            if(operator bool()) {
                ostr<<Name::operator const char *()<<" "<<m_value;
            }
            return ostr;
        }

        std::istream& FullName::read(std::istream& istr) {
            std::string line;
            char name[255], lname[255];
            std::getline(istr, line);
            std::istringstream iss(line);
            iss>>name;
            iss.ignore();
            iss.getline(lname,255);
            iss.ignore(10000,'\n');
            m_value = new char[255];
            strcpy(m_value,lname);
            set(name);
            return istr;
        } 

        std::ostream &operator<<(std::ostream &os, const FullName &obj) {
            return obj.display(os);
         }
         
         std::istream &operator>>(std::istream &is, FullName &obj) {
            return obj.read(is);
         }
}