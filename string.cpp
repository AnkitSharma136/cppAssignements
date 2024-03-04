#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char *str;

public:
    MyString(const char *rawString = "") {
        cout<<"Constructor Called"<<endl;
        str = new char[strlen(rawString) + 1];
        strcpy(str, rawString);
    }

    MyString(const MyString& other) {
        cout<<"Copy Constructor Called"<<endl;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    ~MyString() {
        cout<<"Destructor Called"<<endl;
        delete[] str;
    }

    void operator=(const MyString& other) {
        if (this != &other) {
            delete[] str; 
            str = new char[strlen(other.str) + 1]; 
            strcpy(str, other.str);
        }
    }

    void display() const {
        cout << str << endl;
    }
};

int main() {
    MyString str1("Hello");
    MyString str2 = str1;
    MyString str3;
    str3 = str1;

    str1.display();
    str2.display();
    str3.display();
}
