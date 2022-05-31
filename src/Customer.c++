#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <ctype.h>
#include <iomanip>

#include "general.h"

// Class
class Customer
{
    private:
        // Displaying the products
        int id;
        float price;
        string product_name;
        float quantity;
    
    public:
        void cart_checking();
        void purchase_display();
        void backStart();
        void Payment_taken(const char* file);
        void Fruits_taken();
        void Veggies_taken();

        void display_data(){
            cout<<"Id: "<< id<<endl;
            cout<<"Name: "<< product_name <<endl;
            cout<<"Product price: "<< price <<endl;
            cout<<"Quantity: "<< quantity <<endl;
        }

        int get_id(){
            return id;
        };

        float get_price(){
            return price;
        };

        float get_quantity(){
            return quantity;
        };
        
        string get_name(){
            return product_name;
        }
};

Customer co;

string email_taken;
float Total = 0;

void Start(string email)
{
    int n, join = 1;

    email_taken = email;

    while(join != 0)
    {
        cout << "Welcome " << email << "to the store" << endl;
        cout << "1. Cart" <<endl; // see the chosen products
        cout << "2. Display the Grocery products"<<endl; // I want to see the products and adding them in cart
        cout << "3. Log Out" <<endl; // Logs out from the system
        cout << "Choose your option: ";
        cin >> n;

        switch(n){
            case 1: system("CLS"); co.cart_checking(); break;
            case 2: system("CLS"); co.purchase_display(); break;
            case 3: system("CLS"); co.backStart(); break;
            default: system("CLS"); cout << "Not an option!" << endl; cin.get(); cin.get(); system("CLS"); break;
        }
    }
}

void Customer::cart_checking(){
    
    string all;

    system("CLS");

    ifstream f;
    f.open("Customer.txt", ios::in);

    if(f.is_open())
    {
        while(getline(f, all))
        {
            cout << all << endl;
        }
        f.close();
        cout << endl << endl;
        cin.get();
        cin.get();
        system("ClS");
    }
    else{
        f.close();
        cout << "There are no bills!" << endl;
        cout << endl << endl;
        cin.get();
        cin.get();
        system("ClS");
    }
}

void Customer::Fruits_taken(){
    const char* file = "Fruits.txt";

    Payment_taken(file);
}

void Customer::Veggies_taken(){
    const char* file = "Veggies.txt";

    Payment_taken(file);
}

void Customer::purchase_display(){

    Customer m;
    int n, choice = 1;

    while(choice != 0)
    {
        cout << right << setw(30) << "Pick your category" << endl;
        cout << "1. Fruits" << endl;
        cout << "2. Veggies" << endl;
        cout << "3. Back" << endl;
        cout << "Choose your option: ";
        cin >> n;

        switch(n)
        {
            case 1: m.Fruits_taken(); break;
            case 2: m.Veggies_taken(); break;
            case 3: system("CLS"); Start(email_taken); break;
            default: system("CLS"); cout << "Wrong option!" << endl; cin.get(); cin.get(); system("CLS"); break;
        }
    }
}

void Customer::Payment_taken(const char* file)
{
    int id, quantity, taking, j = 0;
    char picking[5];
    string name;
    float price;

    bool exists = false;
    int price_taken = 0, quantity_taken = 0;

    ofstream f2("temp_2.txt");
    ifstream f1;
    f1.open(file, ios::in);
    f1.seekg(0 | ios::beg);

    while(f1 >> id >> name >> price >> quantity)
    {
        cout << "-------------------------------------------------------" << endl;
        cout << id << " - ";
        cout << name << " - ";
        cout << price << " - ";
        cout << quantity << endl;
    }

    f1.close();
    cout << "-------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Pick your product based on the id: " << endl;
    cin >> picking;

    if(picking == "exit")
    {
        return Start(email_taken);
    }

    if(!atoi(picking))
    {
        system("CLS");
        cout << "Choose a valid option" << endl << endl;
        return purchase_display();
    }

    int a = stoi(picking);
    
    f1.open(file, ios::in);
    while(f1 >> id >> name >> price >> quantity)
    {
        if(a == id)
        {
            exists = true;

            cout << endl;
            cout << "Product: " << name << endl;
            cout << "Price: " << price << endl;
            cout << "We have: " << quantity << endl << endl;
            cout << "How many you need: ";

            if(quantity == 0)
            {
                j = 1;
                break;
            }
            
            cin >> taking;
            if(taking > quantity)
            {
                j = 2;
                break;
            }

            quantity -= taking; // example: 3  bananas
            price_taken = price*taking; // 3 * 10
            quantity_taken = taking;
            Total += price_taken;
        }
        f2<< id <<" "<< name <<" "<< price <<" "<< quantity <<endl;
    }
    if(exists == false){
        system("CLS");
        cout << "Product  doesn't exists" << endl;
        cin.get();
        cin.get();
        system("CLS");
        return purchase_display();
    }
    f1.close();
    f2.close();

    if(j == 1){
        cout << "we are sorry. There are no " << name << " left" << endl << endl;
        purchase_display();
    }

    if(j == 2){
        cout << "What you need is beyong!" << endl << endl;
        purchase_display();
    }

    remove(file);
    rename("temp_2.txt", file);
    
    // Try
    ofstream f3("Customer.txt", ios::app);
    f1.open(file, ios::in);

    while(f1 >> id >> name >> price >> quantity){
        if(a == id)
        {
            f3 << name << " " << price_taken << " " << quantity_taken << endl;
        }
    }
    f1.close();
    f3.close();
}

void Customer:: backStart(){
    string name;
    long int price;
    int quantity;

    int n = 0;

    if(Total == 0)
    {
        main();
    }

    if((_access("bill.txt", 0)) != -1){
        cout << "The file exists" << endl;

        ifstream f1;
        f1.open("Customer.txt", ios::in);

        ofstream wf;
        wf.open("bill.txt", ios::app);

        while(f1 >> name >> price >> quantity)
        {
            if(n == 0)
            {
                wf << left << setw(32) << email_taken;
                wf << left << setw(25) << name << left << setw(18) << price << left << setw(15) << quantity <<endl;
                n = 1;
            }
            wf << right << setw(37) << name << left << setw(20) << " " << left << setw(18) << price << left << setw(17) << quantity <<endl;
        }
        wf << right << setw(42) << "Total: " << Total <<endl;
        wf << "---------------------------------------------------------------------------------" << endl;
        wf.close();
        wf.open("Customer.txt", ios::trunc);
        wf.close();

        Total = 0;
        
        system("CLS");
        main();
    }
    else{
        ofstream wf("bill.txt");// Creates the file
        
        ifstream f1;
        f1.open("Customer.txt", ios::in);
        
        wf << "----------------------------------BILL-------------------------------------------" << endl;
        wf << left << setw(32)<< "Email"<< left << setw(25) <<  "Product Name" << setw(32) <<left << setw(18) << "Price" << left << setw(15)<< "Quantity" <<endl;
        while(f1 >> name >> price >> quantity)
        {
            if(n == 0)
            {
                wf << left << setw(32) << email_taken;
                wf << left << setw(25) << name << left << setw(18) << price << left << setw(15) << quantity <<endl;
                n = 1;
            }
            wf << right << setw(37) << name << left << setw(20) << " " << left << setw(18) << price << left << setw(17) << quantity <<endl;
        }
        wf << right << setw(42) << "Total: " << Total <<endl;
        wf << " " << right << setw(50) << "Total: " << Total <<endl;
        wf << "---------------------------------------------------------------------------------" << endl;
        wf.close();

        Total = 0;

        wf.open("Customer.txt", ios::trunc);
        wf.close();
        
        system("CLS");
        main();
    }
}