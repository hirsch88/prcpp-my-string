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
    char *m_string;

public:

    // Konstruktoren
    MyString();                     // Standardkonstruktor
    MyString(const MyString &s);    // Kopierkonstruktor
    MyString(const char *s);        // Typkonvertierungs-Konstruktor

    // Dekonstruktor
    virtual ~MyString();

    // Methoden
    void print();

    size_t length() const;

    char charAt(size_t index) const;

    int compareTo(const MyString &s) const;

    MyString concat(char c) const;

    MyString concat(const MyString &s) const;

    MyString subString(size_t beg, size_t end) const;


    // Gleichheitsoperator (Inline-Implementation schon gegeben)
//    bool operator==(const MyString &s) const {
//        return compareTo(s) == 0;
//    }
//
//    // Zuweisungsoperator
//    MyString &operator=(MyString const &rh) {
//        return *this;
//    }

    // Indexoperator -> CharAt
//    char operator[](size_t const &index) const {
//        return charAt(index);
//    }

    // Ausgabe-Operator für Output-Streams (Inline-Implementation schon gegeben)
//    friend ostream &operator<<(ostream &os, const MyString &s) {
//        const size_t end = s.m_start + s.m_len;
//        const char *const sc = s.m_string.get();
//        for (size_t i = s.m_start; i < end; i++) os << sc[i];
//        return os;
//    }

    // Klassen-Methode
//    static MyString valueOf(int i); // erzeugt eine String-Repräsentation von i

};

#endif /* SRC_MYSTRING_H_ */
