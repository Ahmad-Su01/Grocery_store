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
        void balance();
        void fruits_veggies();

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
        cout << "3. Check Balance"<<endl; // Check Balance
        cout << "4. Log Out" <<endl; // Logs out from the system
        cin >> n;

        switch(n){
            case 1: system("CLS"); co.cart_checking(); break;
            case 2: system("CLS"); co.purchase_display(); break;
            case 3: system("CLS"); co.balance(); break;
            case 4: system("CLS"); join = 0; break;
            default: system("CLS"); cout << "Not an option" << endl; break;
        }
    }
}

void Customer::cart_checking(){
    return;
}

void fruits_veggies(){
    
    int n, join = 1;
    
    while(join != 0)
    {
        cout << "1. Fruits" <<endl; // see the chosen products
        cout << "2. Vegetables"<<endl; // I want to see the products and adding them in cart
        
        switch(n){
            case 1: system("CLS"); co.cart_checking(); break;
            case 2: system("CLS"); co.purchase_display(); break;
            case 4: system("CLS"); join = 0; break;
            default: system("CLS"); cout << "Not an option" << endl; break;
        }
    }


    
}


void Customer::purchase_display(){
    int id, quantity, taking, j = 0;
    char picking[5];
    string name;
    float price;

    int price_taken = 0, quantity_taken = 0;

    ofstream f2("temp_2.txt");
    ifstream f1;
    f1.open("items.txt", ios::in);
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
        return purchase_display();
    }

    int a = stoi(picking);
    
    f1.open("items.txt", ios::in);
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
    
    remove("items.txt");
    rename("temp_2.txt", "items.txt");
    
    // Try
    ofstream f3("Customer.txt", ios::app);
    f1.open("items.txt", ios::in);

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
        return purchase_display();
    }

    if(j == 2){
        cout << "What you need is beyong!" << endl << endl;
        return purchase_display();
    }
}

void Customer::balance(){
    return;
}