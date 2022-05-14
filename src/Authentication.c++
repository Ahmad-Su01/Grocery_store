#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>

// files
#include <fstream>
#include <io.h>
#include <cstdio>

#include "general.h"

using namespace std;

string email, password, verif;
int check = 0;

bool is_email_valid(const string& email);

void login(){

    string check_email, check_password;

    system("CLS");
    
    cout << " Please enter your email "<<endl;
    cin >> email ;
    if(email == "exit")
    {
        return;
    }
    cout<<"Please enter your password"<<endl;
    cin >> password;
    if(password == "exit")
    {
        return;
    }

    if(email == "Admin" && password == "Admin")
    {
        system("CLS");
        cout << "You are an admin"<< endl;
        //inventory();
        return;
    }

    // Ahmad from here!
    ifstream rf;
    rf.open("Auth.txt", ios::in);
    if(!rf)
    {
        system("CLS");
        cout << endl;
        cerr << "*****************************************" << endl;
        cerr << "*        The file doesn't exists!       *" << endl;
        cerr << "*****************************************"<< endl;
        cout << endl;
    }

    while(rf>>check_email>>check_password)
    {
        if(email == check_email && password == check_password)
        {
            // cout << "YES! Email: " << check_email << " Password:" << check_password << endl;
            system("CLS");
            check = 1;
            rf.close();
        }
    }

    if(check == 1)
        {
            system("CLS");
            cout << "\t\t Welcome at the grocery store\n\t\t  Feel free to buy our stuff" << endl;
            //main();
        }
        else{
            system("CLS");
            cout << "Wrong Credentials" << endl;
            rf.close();
        }
}

void reg() 
{
    char ch;
    int in = 1;

    string check_email;

    system("CLS");

    while(in != 0)
    {

        cout <<" Email: "<<endl;
        cin >> email;
        if(!is_email_valid(email))
        {
            system("CLS");
            cout << "Invalid Email address" << endl;
            return;
        }

        ifstream rf;
        rf.open("Auth.txt", ios::in);

        while(rf >> check_email)
        {
            if(check_email == email)
            {
                system("CLS");
                cout << "This email cann't be created because it has been created before!" <<endl;
                cout << "Please add your email address!\n" << endl;
                rf.close();
                return;
            }
        }
        if(email == "exit")
        {
            return;
        }

        cout << "password:"<<endl;
        cin >> password;
        if(password == "exit")
        {
            return;
        }

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
            system("CLS");
            in = 0;

        }
        else{
            ofstream wf("Auth.txt");
            wf << "email" <<  " " << "password" << endl; // Header
            wf <<  email << " " << password << endl; // Bottom
            wf.close();
            cout << "Your file has been created"<< endl;
            system("CLS");
            in = 0;
        }
    }
}

void finding_pass()
{
    string check_email, check_pass;
    int count = 0;
    system("CLS");
    cout << "Enter your email: ";
    cin >> email;
    if(email == "exit")
    {
        return;
    }

    ifstream rf;
    rf.open("Auth.txt", ios::in);

    while(rf >> check_email >> check_pass)
    {
        if(check_email == email)
        {
            count = 1;
            rf.close();
        }
    }
    if(count == 1)
    {
        system("CLS");
        cout << "Your password is: " << check_pass << endl;
        return;
    }
    else
    {
        system("CLS");
        cout << "Your email does not exists" << endl;
        return;
    }
}

bool is_email_valid(const string& email)
{
   // define a regular expression
   const regex pattern ("(\\w+)(\\.|_)*(\\w+)[[:digit:]]*@(\\w+)(\\.(\\w+))+");

   // try to match the string with the regular expression
   return regex_match(email, pattern);
}