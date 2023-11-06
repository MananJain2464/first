#include <iostream>
#include<time.h>
#include <cstring>


using namespace std;


class animal
{
    protected:
    virtual void makesound();
};


class cat:public animal
{
    public:
    void makesound()
    {
        cout<<"Cat's sound"<<"\n";
        cout<<"Meow Meow"<<endl;
    }
};


class dog: public animal
{
    public:
    void makesound()
    {
        cout<<"Dog's sound"<<"\n";
        cout<<"Bark bark"<<endl;
    }
};


int main()
{
    cout<<"BT22CSE117"<<endl;
   cat c;
   dog d;
   c.makesound();
   d.makesound();
}
