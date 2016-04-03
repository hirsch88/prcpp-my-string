/*
 * main.cpp
 *
 *  Created on: Mar 29, 2016
 *      Author: hirsch
 */

#include <iostream>
#include "MyString.h"

using namespace std;

/**/
int main() {

//    MyString s1;
    MyString s21("Bubu");
    MyString s31("ASDF");
    MyString s22(s21);
    MyString s32(s21);

    // CharAT
//    cout << s1.charAt(0) << endl;
//    cout << s21.charAt(0) << endl;
//    cout << s21.charAt(1) << endl;
//    cout << s21.charAt(2) << endl;
//    cout << s21.charAt(3) << endl;
//    cout << s21.charAt(4) << endl;
//    cout << s22.charAt(0) << endl;

    // Compare To
    cout << s21.compareTo(s21) << endl;
    cout << s21.compareTo(s31) << endl;
    cout << s31.compareTo(s21) << endl;


    return 0;
}
/**/
