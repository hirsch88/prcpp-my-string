/*
 * MyString.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: hirsch
 */

#include <iostream>
#include <memory>
#include "MyString.h"

using namespace std;

// Standardkonstruktor
MyString::MyString() : m_len(0), m_start(0), m_string(nullptr) { }

// Kopierkonstruktor
MyString::MyString(const MyString &s) : m_len(s.m_len), m_start(s.m_start), m_string(s.m_string) { }

// Typkonvertierungskonstruktor
MyString::MyString(const char *s) : m_start(0), m_len(0) {

    // Normal Pointer
    m_len = strlen(s);
    m_string = new char(m_len);
    for (int i = 0; i < m_len; ++i) {
        m_string[i] = s[i];
    }

    // With smart-pointers
//    unique_ptr<char[]> u_ptr(new char[m_len]);
//    for (int i = 0; i < m_len; ++i) {
//        u_ptr[i] = s[i];
//        cout << u_ptr[i] << endl;
//    }
//    m_string = make_shared<char>(u_ptr);

//    shared_ptr<char> ptr(unique_ptr<char[]>(new char[m_len]));
//    m_string = ptr;

};

// Dekonstruktor
MyString::~MyString() {
    // TODO Auto-generated destructor stub
}

char MyString::charAt(size_t index) const {
    if (index < 0 || index > (m_len - 1)) {
        throw out_of_range("Invalid Index");
    }
    return m_string[index];
}

int MyString::compareTo(const MyString &s) const {
    int idx = 0;
    size_t minLen;

    minLen = this->m_len > s.m_len ? this->m_len : s.m_len;
    while (idx < (minLen-1) && s.charAt(idx) == this->charAt(idx)) {
        idx++;
    }

    if (s.charAt(idx) < this->charAt(idx)) {
        return 1;
    }

    if (s.charAt(idx) > this->charAt(idx)) {
        return -1;
    }

    return 0;
}


