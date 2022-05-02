#include <iostream>
#include "general.h"

using namespace std;

int main()
{
    int num;
    int check = 0;

    while(true )
    {
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "Please choose one of the options:" << endl;
        cin >> num;

        //  Click on the button with the rombus if you have something to say.

        switch(num)
        {
            case 1: login(); break;
            case 2: reg(); break;
            case 3: exit(0); break;
            default: cout << "Proivde with a valid option" << endl;
            break;
        }
    }
    
    return 0;
}
