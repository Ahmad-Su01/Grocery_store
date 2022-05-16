#include <iostream>
#include <string>
#include <fstream>
#include "general.h"

using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// I don't get it. Why you created a class Inventory here if
// we have one made in general.h ??
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

class Inventory
{
    private:
        int id;
        float price;
        string product_name ;
        float quantity;

    public:
        void get_data(){

            cout<<"Id: ";
            cin>>id;
            cout<<endl;

            cout<<"Name: ";
            cin>>product_name;
            cout<<endl;

            cout<<"Price: ";
            cin>>price;
            cout<<endl;

            cout<<"Quantity: ";
            cin>>quantity;
            cout<<endl;
        };

        void display_data(){
            cout<<"Id: "<< id<<endl;
            cout<<"Name: "<< product_name <<endl;
            cout<<"Product price: "<< price <<endl;
            cout<<"Quantity: "<< quantity <<endl;
        }

        void remove();

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

fstream f;
Inventory item1;

// My implementation
void automation()
{
    int n;

    while(true)
    {
        cout << "Choose a valid option" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Display items" << endl;
        cout << "3. Display supplements" << endl;
        cout << "4. Update the item" << endl;
        cout << "5. Remove an item" << endl;
        cin >> n;

        switch(n){
            case 1: system("CLS"); add_item(); break;
            case 2: system("CLS"); display_items(); break;
            case 3: system("CLS"); display_sp(); break;
            case 4: system("CLS"); modify_item(); break;
            case 5: system("CLS"); delete_item(); break;
            default: cout << "The option is not valid!" << endl; break;
        }
    }
}

// Your implementation
void add_item(){
    int n;

    cout<<"How many items would you like to add?"<<endl;
    cin>>n;

    f.open("items.txt", ios::out |ios::app );

    for(int i = 0; i < n; i++)
    {
        item1.get_data();
        f.write( (char*)&item1, sizeof(item1));
        cout<<"---------Item added successfully---------"<<endl;
        cout<<endl;
        cout<<endl;
    }
    f.close();
    //cout<<"--------Item/Items saved in file--------"<<endl;
}

void display_items(){
    cout<<"----------- All items -----------"<<endl;

    f.open("items.txt", ios::in);
    f.seekg(0);

    while(f.read((char*)&item1, sizeof(item1)) ){
        item1.display_data();
        cout<<"-------------------"<<endl;
    }
    f.close();
}

void display_sp(){

    int n, flag = 0;
    cout<<"Enter the product id:"<<endl;
    cin>>n;

    f.open("items.txt", ios::in);
    
    while(f.read((char*)&item1, sizeof(item1))){
        if(item1.get_id() == n){
            item1.display_data();
            flag = 1;
        }
    }
    f.close();

    if(flag == 0){
        cout<<"-----Product not found!-----"<<endl;
    }

}

void modify_item(){

    int id, found = 0;

    cout<<"enter product id to modify: ";
    cin>>id;

    f.open("items.txt", ios::in | ios::out);

    while(f.read((char*)&item1, sizeof(item1))){
        if(item1.get_id() == id){
            item1.display_data();
            cout<<"Please enter new data"<<endl;
            item1.get_data();

            int pos = -1*((int)sizeof(item1));
            f.seekp(pos, ios::cur);
            f.write((char*)&item1, sizeof(item1));

            found = 1;
            cout<<"Item updated";

        }
    }
    f.close();
    if(found == 0){
        cout<<"------Product not found"<<endl;
    }
}

void delete_item(){

    int id;
    int found = 0;

    cout<<"Enter product id to remove: ";
    cin>>id;

    f.open("items.txt", ios::out | ios::in);
    fstream f2;

    f2.open("temp.txt", ios::out);
    f.seekg(0, ios::beg);
    
    while(f.read((char*)&item1, sizeof(item1))){

        if(item1.get_id() != id){
            f2.write((char*)&item1, sizeof(item1));
        }

        if(item1.get_id() == id){
            found = 1;
        }
    }
    f2.close();
    f.close();

    remove("items.txt");
    rename("temp.txt", "items.txt");

    if(found){
        cout<<"------Product removed-------"<<endl;
    }else{
        cout<<"-------Product not found-------"<<endl;
    }

}
