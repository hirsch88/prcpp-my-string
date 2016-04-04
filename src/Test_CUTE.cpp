/******************************************************************************/
/*  unit test for prcpp.excercise_1                             eclipse/cute  */
/* -------------------------------------------------------------------------- */
/*  2012-2016  - C.Stamm / H.Veitschegger                                     */
/******************************************************************************/

#include "./../cute/cute.h"
#include "./../cute/ide_listener.h"
#include "./../cute/xml_listener.h"
#include "./../cute/cute_runner.h"

#include "MyString.h"

void test_length() {
    ASSERT(MyString().length() == 0);
    ASSERT(MyString("").length() == 0);
    ASSERT(MyString("abc").length() == 3);
}

//void test_toCString(){
//	MyString s1;
//	MyString s2("abc");
//	ASSERT_EQUAL(MyString(s1.toCString().get()), s1);
//	ASSERT_EQUAL(MyString(s2.toCString().get()), s2);
//}

void test_equals() {
    MyString s("abc");
    ASSERT(MyString() == MyString(""));
    ASSERT(MyString("") == MyString());
    ASSERT(s == s);
    ASSERT(!(s == MyString("ab")));
}

void test_compare() {
    MyString s("abc");
    ASSERT_EQUAL(MyString().compareTo(""), 0);
    ASSERT(s.compareTo("bcd") < 0);
    ASSERT(s.compareTo("abde") < 0);
    ASSERT(s.compareTo("abcd") < 0);
    ASSERT(s.compareTo("abbb") > 0);
    ASSERT(s.compareTo("ABC") > 0);
    ASSERT(s.compareTo("") > 0);
    ASSERT(MyString().compareTo(s) < 0);
}

void test_concat() {
    MyString s;
    ASSERT(s.concat("") == "");
    ASSERT(s.concat('a') == "a");
    ASSERT(MyString("a").concat("") == "a");
    ASSERT(MyString("ab").concat('c') == "abc");
    ASSERT(MyString("ab").concat("cde") == "abcde");
    ASSERT(s.concat("abc").concat(s).concat("") == "abc");
}

void test_substring() {
    MyString s("abcd");
    ASSERT(s.substring(0, 2) == "ab");
    ASSERT(s.substring(1, 3) == "bc");
    ASSERT(s.substring(2, 4) == "cd");
    ASSERT(s.substring(3, 5) == "d");
//	ASSERT(s.substring(0, -1) == s); should be ""
    ASSERT(s.substring(2, 2) == "");
    ASSERT(s.substring(5, 7) == "");
    ASSERT(s.substring(3, 0) == "");
    ASSERT(MyString().substring(0, 1) == "");
    MyString s2 = s.substring(2, 4);
    ASSERT(s2.charAt(0) == 'c');
}

//void test_valueOf(){
//	ASSERT(MyString::valueOf(0) == "0");
//	ASSERT(MyString::valueOf(10) == "10");
//	ASSERT(MyString::valueOf(999) == "999");
//	ASSERT(MyString::valueOf(-0) == "0");
//	ASSERT(MyString::valueOf(-10) == "-10");
//	ASSERT(MyString::valueOf(-999) == "-999");
//}

void test_charAt() {
    MyString s("abc");
    ASSERT_EQUAL(s.charAt(0), 'a');
    ASSERT_EQUAL(s.charAt(1), 'b');
    ASSERT_EQUAL(s.charAt(2), 'c');
    bool catched = false;
    try {
        s.charAt(-1);
    } catch (std::exception &) { catched = true; }
    ASSERT(catched);
    catched = false;
    try {
        MyString("abc").charAt(3);
    } catch (std::exception &) { catched = true; }
    ASSERT(catched);
}

//void test_toInt(){
//	ASSERT(MyString("123").toInt() == 123);
//	ASSERT(MyString("   123").toInt() == 123);
//	ASSERT(MyString("123   ").toInt() == 123);
//	ASSERT(MyString("  123 ").toInt() == 123);
//	ASSERT(MyString("  123 456").toInt() == 123);
//	ASSERT(MyString("  123 abc").toInt() == 123);
//	ASSERT(MyString("-987").toInt() == -987);
//	ASSERT(MyString("  -987").toInt() == -987);
//	ASSERT(MyString("-987  ").toInt() == -987);
//	ASSERT(MyString(" -987 ").toInt() == -987);
//	ASSERT(MyString(" -987 654").toInt() == -987);
//	ASSERT(MyString(" -987 abc").toInt() == -987);
//	bool catched = false;
//	try { MyString("abc123").toInt();
//	} catch(std::exception&) { catched = true; }
//	ASSERT(catched);
//	catched = false;
//	try { MyString("123abc").toInt();
//	} catch(std::exception&) { catched = true; }
//	ASSERT(catched);
//	catched = false;
//	try { MyString("--123").toInt();
//	} catch(std::exception&) { catched = true; }
//	ASSERT(catched);
//	catched = false;
//	try { MyString("123-").toInt();
//	} catch(std::exception&) { catched = true; }
//	ASSERT(catched);
//	catched = false;
//	try { MyString("123-45").toInt();
//	} catch(std::exception&) { catched = true; }
//	ASSERT(catched);
//}

//***** master & test registration**********************************************

void runAllTests(int argc, char const *argv[]) {
    cute::suite s;
    s.push_back(CUTE(test_length));
//	s.push_back(CUTE(test_toCString));
    s.push_back(CUTE(test_equals));
    s.push_back(CUTE(test_compare));
    s.push_back(CUTE(test_concat));
    s.push_back(CUTE(test_substring));
//	s.push_back(CUTE(test_valueOf));
    s.push_back(CUTE(test_charAt));
//	s.push_back(CUTE(test_toInt));
    cute::xml_file_opener xmlfile(argc, argv);
    cute::xml_listener<cute::ide_listener<> > lis(xmlfile.out);
    cute::makeRunner(lis, argc, argv)(s, "AllTests");
}

int main(int argc, char const *argv[]) {
    runAllTests(argc, argv);
    return 0;
}



