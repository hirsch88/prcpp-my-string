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

    m_len = strlen(s) + 1;
    m_string = new char(m_len);
    for (int i = 0; i < m_len; ++i) {
        m_string[i] = s[i];
    }

//    unique_ptr<char[]> u_ptr(new char[m_len]);
//    for (int i = 0; i < m_len; ++i) {
//        u_ptr[i] = s[i];
//        cout << u_ptr[i] << endl;
//    }
//    m_string = make_shared<char>(u_ptr);

//    shared_ptr<char> ptr(unique_ptr<char[]>(new char[3]));
//    m_string = ptr;

};

// Dekonstruktor
MyString::~MyString() {
    // TODO Auto-generated destructor stub
}

void MyString::print() {
    cout << "Hello, World!" << endl;
}
