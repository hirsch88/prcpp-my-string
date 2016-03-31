/*
 * MyString.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: hirsch
 */

#include <iostream>
#include <src/MyString.h>

using namespace std;

// Standardkonstruktor
MyString::MyString(): m_len(0), m_start(0), m_string (nullptr) {}

// Kopierkonstruktor
MyString::MyString(const MyString& s): m_len(s.m_len), m_start(s.m_start), m_string(s.m_string){}

// Typkonvertierungskonstruktor
MyString::MyString(const char* s): m_start(0), m_len(0) {

	// Berrechnet die Länge des char Arrays
	while(s[m_len] != '\0'){
		m_len++;
	}

};

// Dekonstruktor
MyString::~MyString() {
	// TODO Auto-generated destructor stub
}

void MyString::print(){
	cout << "Hello, World!" << endl;
}
