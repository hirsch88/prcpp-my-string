/*
 * MyString.h
 *
 *  Created on: Mar 31, 2016
 *      Author: hirsch
 */

#include <iostream>

#ifndef SRC_MYSTRING_H_
#define SRC_MYSTRING_H_

using namespace std;

class MyString final {

	// private Datenstruktur
	size_t m_len;
	size_t m_start;
//	shared_ptr<char> m_string;
    char* m_string;

	public:

	// Konstruktoren
	MyString();						// Standardkonstruktor
	MyString(const MyString& s);	// Kopierkonstruktor
	MyString(const char* s);		// Typkonvertierungs-Konstruktor

	// Dekonstruktor
	virtual ~MyString();

	// Methoden
	void print();

};

#endif /* SRC_MYSTRING_H_ */
