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
        cout << "3. Forgot password" << endl;
        cout << "4. Exit" << endl;
        cout << "Please choose one of the options:" << endl;
        cin >> num;

        //  Click on the button with the rombus if you have something to say.

        switch(num)
        {
            case 1: system("CLS");login(); break;
            case 2: 
            system("CLS");
            cout << "\t\t Welcome at the Register" <<endl;
            cout << "\t\tInput the required credentails!" << endl;
            reg(); break;
            case 3: system("CLS");finding_pass(); break;
            case 4: exit(0); break;
            default: cout << "Proivde with a valid option" << endl;
            break;
        }
    }
    
    return 0;
}
