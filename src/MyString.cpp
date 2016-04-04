/*
 * MyString.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: hirsch
 */

#include <iostream>
#include "MyString.h"

using namespace std;

// Standardkonstruktor
MyString::MyString() : m_len(0), m_start(0), m_string(new char(0)) { }

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
    m_string = nullptr;
}

void MyString::print() {
    std::cout << m_string << std::endl;
}

size_t MyString::length() const {
    return m_len;
}

char MyString::charAt(const size_t index) const {
    if (index < 0 || index > (m_len - 1)) {
        throw out_of_range("Invalid Index");
    }
    return m_string[index];
}

int MyString::compareTo(const MyString &s) const {
    int idx = 0;
    size_t minLen = (this->m_len < s.m_len) ? this->m_len : s.m_len;
    while (idx < minLen && s.charAt(idx) == this->charAt(idx)) {
        idx++;
    }

    if (minLen == idx && this->m_len != s.m_len) {
        return (this->m_len > s.m_len) ? -1 : 1;
    }

    if (s.m_string[idx] < m_string[idx]) {
        return 1;
    }

    if (s.m_string[idx] > m_string[idx]) {
        return -1;
    }

    return 0;
}

MyString MyString::concat(char c) const {
    char *newString = new char(m_len + 1);
    for (int i = 0; i < m_len; ++i) {
        newString[i] = m_string[i];
    }
    newString[m_len] = c;
    return MyString(newString);
}

MyString MyString::concat(const MyString &s) const {
    int len = (int) (m_len + s.m_len);
    char *newString = new char(len);

    int i = 0;
    while (i < m_len) {
        newString[i] = m_string[i++];
    }

    int k = 0;
    int n = (int) m_len;
    while (k < len) {
        newString[n++] = s.m_string[k++];
    }

    return MyString(newString);
}

MyString MyString::substring(size_t beg, size_t end) const {
    int len = (int) (end - beg);
    char *newString = new char(len);

    if(len <= 0){
        return MyString("");
    }

    int i = 0;
    while (i < len) {
        newString[i++] = m_string[beg++];
    }
    return MyString(newString);
}
