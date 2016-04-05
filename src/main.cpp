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

    MyString s0;
    MyString s1("");
    MyString s21("Bubu");
    MyString s31("Bubu!");
    MyString s22(s21);
    MyString s32(s21);

    // Length
//    cout << s0.length() << endl;
//    cout << s1.length() << endl;
//    cout << s21.length() << endl;
//    cout << s31.length() << endl;
//    cout << s22.length() << endl;
//    cout << s32.length() << endl;

    // CharAT
//    cout << s0.charAt(0) << endl;
//    cout << s1.charAt(0) << endl;
//    cout << s21.charAt(0) << endl;
//    cout << s21.charAt(1) << endl;
//    cout << s21.charAt(2) << endl;
//    cout << s21.charAt(3) << endl;
//    cout << s21.charAt(4) << endl;
//    cout << s22.charAt(0) << endl;

//    // Compare To
//    cout << s21.compareTo(s21) << endl;
//    cout << s21.compareTo(s31) << endl;
//    cout << s31.compareTo(s21) << endl;
//
//    // ConcatTo
//    MyString s41 = s21.concat(s21);
//    MyString s42 = s21.concat('!');
//    s41.print();
//    s42.print();

    //Substring
//    MyString s51 = s21.substring(1, 4);
//    s51.print();

    // ValueOf
//    MyString s61 = MyString::valueOf(-0);
//    s61.print();

    MyString s62 = MyString::valueOf(-10);
    s62.print();

    // ToInt
//    MyString s71 = MyString("123");
//    cout << s71.toInt() << endl;

    return 0;
}
/**/
