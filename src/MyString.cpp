/*
 * MyString.cpp
 *
 *  Created on: Mar 31, 2016
 *      Author: hirsch
 */

#include <iostream>
#include <memory>
#include <stdio.h>
#include <stdlib.h>

#include "MyString.h"

using namespace std;

// Standardkonstruktor
MyString::MyString() : m_len(0), m_start(0), m_string(new char(0)) { }

// Kopierkonstruktor
MyString::MyString(const MyString &s) : m_len(s.m_len), m_start(s.m_start), m_string(s.m_string) {
}

// Typkonvertierungskonstruktor
MyString::MyString(const char *s) : m_start(0), m_len(0) {

    // Länge berrechnen
    while(s[m_len] != '\0'){
        m_len++;
    }

//    shared_ptr<char> ptr (unique_ptr<char[]>(new char[m_len]));

    // Normal Pointer
    m_string = new char(m_len);
    for (int i = 0; i < m_len; ++i) {
        m_string[i] = s[i];
    }

    // Unique Pointer
    m_stringU = unique_ptr<char[]>(new char(m_len));
    for (size_t i = 0; i < m_len; ++i) {
        *(m_stringU.get() + i) = *(s++);
    }

    // Shared Pointer aber nicht stabil
    shared_ptr<char> pointer(new char[m_len]);
    m_stringS = pointer;

    // Array fuellen
    for (size_t i = 0; i < m_len; i++) {
        *(m_stringS.get() + i * sizeof(char)) = s[i];
    }

};

// Dekonstruktor
MyString::~MyString() {
    m_string = nullptr;
}

void MyString::print() {
    cout << m_string << endl;
//    cout << m_stringS << endl;
//    cout << m_stringU.get() << endl;
}

size_t MyString::length() const {
    return m_len;
}

char MyString::charAt(const size_t index) const {
    if (index < 0 || index > (m_len - 1)) {
        throw out_of_range("Invalid Index");
    }
    if (m_string == nullptr) {
        return '\0';
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
        return (this->m_len > s.m_len) ? 1 : -1;
    }

    if (s.m_string[idx] < m_string[idx]) {
        return 1;
    }

    if (s.m_string[idx] > m_string[idx]) {
        return -1;
    }

    return 0;
}

int MyString::toInt() const {
    return atoi(m_string);
}

unique_ptr<char[]> MyString::toCString() const {
    unique_ptr<char[]> r = unique_ptr<char[]>(new char[m_len + 1]);
    for (size_t i = 0; i < m_len; ++i) {
        *(r.get() + i) = m_string[i];
    }
    r[m_len] = '\0';
    return move(r);
}

MyString MyString::concat(char c) const {
    char *newString = new char(m_len + 1);
    for (int i = 0; i < m_len; ++i) {
        newString[i] = m_string[i];
    }
    newString[m_len] = c;
    return move(MyString(newString));
}

MyString MyString::concat(const MyString &s) const {
    int len = (int) (m_len + s.m_len);
    char *newString = new char(len);

    int i = 0;
    while (i < m_len) {
        newString[i] = m_string[i];
        i++;
    }

    int k = 0;
    int n = (int) m_len;
    while (k < len) {
        newString[n] = s.m_string[k];
        k++;
        n++;
    }

    return MyString(newString);
}

MyString MyString::substring(size_t beg, size_t end) const {
    int len = (int) (end - beg);
    char *newString = new char(len);

    if (len <= 0) {
        return MyString("");
    }

    int i = 0;
    while (i < len) {
        newString[i++] = m_string[beg++];
    }
    return move(MyString(newString));
}

MyString MyString::valueOf(int i) {
    int size = 0;
    int tmpSize = i;
    int p = 0;
    bool isNegative = false;

    // i ist null
    if (i == 0) {
        size = 1;

    } else {
        while (tmpSize != 0) {
            tmpSize /= 10;
            size++;
        }
    }

    isNegative = i < 0;

    int arr[size];

    if (i == 0) {
        arr[0] = 0;
    }

    if(isNegative){
        i = i * (-1);
    }
    int tmp = i;
    while (tmp != 0 && p < size) {
        arr[p] = tmp % 10;
        tmp = (tmp - arr[p]) / 10;
        p++;
    }

    int j = 0;
    if(isNegative){
        size++;
    }

    char *s = new char[size];
    if(isNegative){
        *(s + j++) = '-';
        --size;
    }
    int k = size - 1;
    while (j <= size && k >=0) {
        *(s + j++) = arr[k--] + 48;
    }

    return move(MyString(s));
}
