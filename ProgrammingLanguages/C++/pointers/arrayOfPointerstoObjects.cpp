#include <iostream>
#include <cstring>

using namespace std;

class city
{
    private:
        char *name;
        int len;
    
    public:
    
        city() {
            cout<<"Constructor"<<endl;
            len = 0;
            name = NULL;
        }

        void getName(void) {
            char *s = new char[30];
            cout<<"Enter city name"<<endl;
            cin>>s;
            len = strlen(s);
            name = new char[len+1];
            strcpy(name, s);
            delete s;
        }

        void printName() {
            cout<<name<<endl;
        }

        ~city() {
            cout<<"destructor"<<endl;
            delete name;
        }
};

int main ()
{
    city *cptr[10];
    int n = 0;
    int option;

    do {
        cptr[n] = new city;
        cptr[n]->getName();
        n++;
        cout<<"Do you wish to enter another city name"<<endl;
        cout<<"Enter 1 to enter city name and 0 to quit"<<endl;
        cin>>option;
    }while(option);

    for(int i = 0; i < n; i++) {
        cptr[i]->printName();
        delete cptr[i];
    }

    return 0;
}
