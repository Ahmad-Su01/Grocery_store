#include <iostream>
#include <string>
#include <stdlib.h>

// files
#include <fstream>
#include <io.h>
#include <cstdio>

#include "general.h"

#define BUFF 100

using namespace std;

string email, password, verif;
char rwwf;
int check = 0;

void login(){

    string check_email, check_password;
    
    cout << " Please enter your email "<<endl;
    cin >> email ;
    cout<<"Please enter your password"<<endl;
    cin >> password;

    if(email == "Admin" && password == "Admin")
    {
        cout << "You are an admin"<< endl;
        //inventory();
        return;
    }

    // Ahmad from here!
    ifstream rf;
    rf.open("Auth.txt", ios::in);
    if(!rf)
    {
        cout << endl;
        cerr << "*****************************************" << endl;
        cerr << "*        The file doesn't exists!       *" << endl;
        cerr << "*****************************************"<< endl;
        cout << endl;
    }

    rwwf = rf.get();

    while(rf.good()){
        // cout << rwwf << endl;*/
        rwwf = rf.get();
        if(rwwf.)
        {
            cout << " YES" << endl;
        }
    }
}

void reg() 
{
    cout <<" Email: "<<endl;
    cin >> email;
    cout << "password:"<<endl;
    cin >> password;

    if(password.length() < 8)
    {
        cout << endl;
        cerr << "*****************************************" << endl;
        cerr << "*  Please input more than 8 characters  *" << endl;
        cerr << "*****************************************"<< endl;
        cout << endl;
        return;
    }
    cout <<"Password again"<<endl;
    cin >> verif;

    if(password.compare(verif) != 0 ){

        cout << endl;
        cerr << "********************************" << endl;
        cerr << "*  The passwords didn't match! *" << endl;
        cerr << "********************************"<< endl;
        cout << endl;
        return;
    }

    cout<<"Succesfully registerd"<<endl;

    if((_access("Auth.txt", 0)) != -1){
        cout << "The file exists" << endl;
 
        ofstream wf;
        wf.open("Auth.txt", ios::app);
        wf << email << " " << password << endl;
        wf.close();

    }
    else{
        ofstream wf("Auth.txt");
        wf << "email" <<  " " << "password" << endl; // Header
        wf <<  email << " " << password << endl; // Bottom
        wf.close();
        cout << "Your file has been created"<< endl;
    }
    check = 1;

}
