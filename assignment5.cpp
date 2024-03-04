#include<iostream>
using namespace std;

class singleton{
    protected:
    singleton () = default;

    singleton (const singleton&) = delete;
    singleton& operator= (const singleton&) = delete;

    public:

    int data;

    static singleton& get(){
        static singleton instance;
        return instance;
    }
};

int main(){
    singleton::get();
    singleton::get().data = 5;
    cout<< singleton::get().data <<endl;

    singleton &single = singleton::get();

    cout<< single.data<<endl;
}