#include <iostream>
#include <string>
#include <fstream>
#include <io.h>
#include <ctype.h>

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

        // Customer
        int id_2;
        float bought;
    
    public:
        void cart_checking();
        void purchase_display();
        void backStart();
        void fruits_veggies();
        void copy_fruits();
        void copy_veggies();
        void purchase_display_veggies();
        void purchase_display_fruits();

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

void Start()
{
    int n, join = 1;
    
    while(join != 0)
    {
        cout << "1. Cart" <<endl; // see the chosen products
        cout << "2. Display the Grocery products"<<endl; // I want to see the products and adding them in cart
        cout << "3. Log Out" <<endl; // Logs out from the system
        cin >> n;

        switch(n){
            case 1: system("CLS"); co.cart_checking(); break;
            case 2: system("CLS"); co.fruits_veggies(); break;
            case 3: system("CLS"); co.backStart(); break;
            default: system("CLS"); cout << "Not an option" << endl; break;
        }
    }
}

void Customer::cart_checking(){
    
    string name;
    float price;
    int quantity;
    
    ifstream check_customer;
    check_customer.open("Customer.txt", ios::in);

    cout << "\tProduct Name\tPrice\tQuantity" << endl;
    while(check_customer >> name >> price >> quantity)
    {
        cout <<"\t"<< name << "\t\t" << price << "\t" <<quantity<<endl;
    }
    cout << endl;

    check_customer.close();
}

void Customer::fruits_veggies(){
    
    int n, join = 1;
    
    while(join != 0)
    {
        cout << "1. Fruits" <<endl; 
        cout << "2. Vegetables"<<endl;
        cin>>n;

        switch(n){
            case 1: system("CLS"); co.copy_fruits(); break;
            case 2: system("CLS"); co.copy_veggies(); break;
            case 3: system("CLS"); Start(); break;
            default: system("CLS"); cout << "Not an option" << endl; break;
        }
    }

}

void Customer::copy_fruits(){
    
    int id;
    string name;
    float price;
    int quantity;

    string file = "fruits.txt";

    ifstream f;
    f.open(file, ios::in);

    ofstream f2;
    f2.open("items.txt", ios::out );
    
    while(f>> id >> name >> price>> quantity){

        f2<<id<< " "<< name <<" "<< price<<" " << quantity<<endl;

    }

    f.close();
    f2.close();

    purchase_display_fruits();

    // remove and rename
    // remove("fruits.txt");
    // rename("items.txt", "fruits.txt");
    
    ofstream it;
    it.open("items.txt", ios::out | ios::trunc);
    it.close();

}


void Customer::copy_veggies(){
    
    int id;
    string name;
    float price;
    int quantity;

    ifstream f;
    f.open("veggies", ios::in);
    
    ofstream f2;
    f2.open("item.txt", ios::out );
    
    while(f>> id >> name >> price >> quantity){
        f2<<id<<" "<< name <<" "<< price << " "<<quantity<<endl;
    }

    f.close();
    f2.close();

    purchase_display_veggies();
    // 
    // remove("veggies.txt");
    // rename("items.txt", "veggies.txt");

    ofstream it;
    it.open("items.txt", ios::out | ios::trunc);
    it.close();
}

void Customer::purchase_display_fruits(){
    int id, quantity, taking, j = 0;
    char picking[5];
    string name;
    float price;

    int price_taken = 0, quantity_taken = 0;

    ofstream f2("temp_2.txt");
    ifstream f1;
    f1.open("fruits.txt", ios::in);
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
        return Start();
    }

    if(!atoi(picking))
    {
        system("CLS");
        cout << "Choose a valid option" << endl << endl;
        return purchase_display_fruits();
    }

    int a = stoi(picking);
    
    f1.open("fruits.txt", ios::in);
    while(j == 0 && f1 >> id >> name >> price >> quantity)
    {
        if(a == id)
        {
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
            quantity_taken = quantity;
        }
        f2<< id <<" "<< name <<" "<< price <<" "<< quantity <<endl;
    }
    f1.close();
    f2.close();
    
    remove("fruits.txt");
    rename("temp_2.txt", "fruits.txt");
    
    // Try
    ofstream f3("Customer.txt", ios::app);
    f1.open("fruits.txt", ios::in);

    while(f1 >> id >> name >> price >> quantity){
        if(a == id)
        {
            f3 << name << " " << price_taken << " " << quantity_taken << endl;
        }
    }
    f1.close();
    f3.close();

    if(j == 1){
        cout << "we are sorry. There are no" << name << " left" << endl << endl;
        //purchase_display_fruits();
    }

    if(j == 2){
        cout << "What you need is beyong!" << endl << endl;
        //purchase_display_fruits();
    }

}

void Customer::purchase_display_veggies(){
    int id, quantity, taking, j = 0;
    char picking[5];
    string name;
    float price;

    int price_taken = 0, quantity_taken = 0;

    ofstream f2("temp_2.txt");
    ifstream f1;
    f1.open("veggies.txt", ios::in);
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
        return Start();
    }

    if(!atoi(picking))
    {
        system("CLS");
        cout << "Choose a valid option" << endl << endl;
        return purchase_display_veggies();
    }

    int a = stoi(picking);
    
    f1.open("veggies.txt", ios::in);
    while(j == 0 && f1 >> id >> name >> price >> quantity)
    {
        if(a == id)
        {
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
            quantity_taken = quantity;
        }
        f2<< id <<" "<< name <<" "<< price <<" "<< quantity <<endl;
    }
    f1.close();
    f2.close();
    
    remove("veggies.txt");
    rename("temp_2.txt", "veggies.txt");
    
    // Try
    ofstream f3("Customer.txt", ios::app);
    f1.open("veggies.txt", ios::in);

    while(f1 >> id >> name >> price >> quantity){
        if(a == id)
        {
            f3 << name << " " << price_taken << " " << quantity_taken << endl;
        }
    }
    f1.close();
    f3.close();

    if(j == 1){
        cout << "we are sorry. There are no" << name << " left" << endl << endl;
        purchase_display_veggies();
    }

    if(j == 2){
        cout << "What you need is beyong!" << endl << endl;
        purchase_display_veggies();
    }

}

void Customer:: backStart(){
    string name, email;
    float price;
    int quantity;

    if((_access("bill.txt", 0)) != -1){
        cout << "The file exists" << endl;

        ofstream wf;
        wf.open("bill.txt", ios::app);
        wf.close();
        system("CLS");
    }
    else{
        ofstream wf("bill.txt");// Creates the file
        wf << "Email\t\t"<< "Product Name" << "\t\t" << "Price" << "\t" << "Quantity" <<endl;
        wf << email << "\t"<< name << "\t\t" << price << "\t" <<quantity<<endl; 
        wf.close();
        cout << "Your file has been created"<< endl;
        system("CLS");
    }
}