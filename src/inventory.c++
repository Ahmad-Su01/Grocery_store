#include <iostream>
#include <string>
#include <fstream>
#include "general.h"

#include <io.h>

using namespace std;

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// I don't get it. Why you created a class Inventory here if
// we have one made in general.h ??
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// In general.h is only the prototype. You have to declare it there to work. And here is the implementation. OK!
// 
class Inventory
{
    private:
        int id;
        float price;
        string product_name ;
        float quantity;

    public:
        void add_item();
        void display_items();
        void display_sp();
        void modify_item();
        void delete_item();

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

Inventory item1;

// My implementation
void automation()
{
    Inventory m;
    int n, choice = 1;

    while(choice)
    {
        cout << "Choose a valid option" << endl;
        cout << "1. Add item" << endl;
        cout << "2. Display items" << endl;
        cout << "3. Display supplements" << endl;
        cout << "4. Update the item" << endl;
        cout << "5. Remove an item" << endl;
        cin >> n;

        switch(n){
            case 1: system("CLS"); m.add_item(); break;
            case 2: system("CLS"); m.display_items(); break;
            case 3: system("CLS"); m.display_sp(); break;
            case 4: system("CLS"); m.modify_item(); break;
            case 5: system("CLS"); m.delete_item(); break;
            case 6: system("CLS"); choice = 0; main();break; 
            default: cout << "The option is not valid!" << endl; break;
        }
    }
}

// Your implementation
void Inventory::add_item(){
    int n;
    int id;
    string name;
    float price;
    int quantity;

    ofstream wf;
    ifstream rf;

    rf.open("items.txt", ios::in);

    cout<<"How many items would you like to add?"<<endl;
    cin>>n;
    // Ahmad Method
    if((_access("items.txt", 0)) != -1){
        // The file exists and appends
        cout << "The file exists" << endl;

        wf.open("items.txt", ios::app);
        while(n != 0)
        {
            item1.get_data();
            bool found = false;

            while(!found && rf >>id>>name>>price>>quantity){

                if(id == item1.get_id())
                    found = 1;
                    cout<<"Product ID already exists";
                    cout<<endl;
                    cout<<"Id: "<<id<<" - ";
                    cout<<"Name: "<< name <<" - ";
                    cout<<"Price: "<<price<<" - ";
                    cout<<"Quantity: "<<quantity<<endl;
                        
            }

            if(!found)
            {
                wf<<item1.get_id() <<" "<< item1.get_name()<<" "<<item1.get_price()<<" "<<item1.get_quantity()<<endl;
                n--;
                cout<<"---------Item added successfully---------"<<endl;
                cout<<endl;
                cout<<endl;
                system("Cls");
            }

        }
        rf.close();
        wf.close();
        system("CLS");
    }
    // Creatres the if not exists
    else{
        ofstream wf("items.txt");
        ifstream rf;

        rf.open("items.txt", ios::in);

        while(n != 0)
        {
            item1.get_data();
            bool found = false;

            while(!found && rf >>id>>name>>price>>quantity){

                if(id == item1.get_id())
                    found = 1;
                    
            }

            if(!found)
            {
                wf<<item1.get_id() <<" "<< item1.get_name()<<" "<<item1.get_price()<<" "<<item1.get_quantity()<<endl;
                n--;
                cout<<"---------Item added successfully---------"<<endl;
                cout<<endl;
                cout<<endl;
                system("Cls");
            }else{

                cout<<"Product ID already exists";
                cout<<endl;
                cout<<"Id: "<<item1.get_id()<<" - ";
                cout<<"Name: "<< item1.get_name()<<" - ";
                cout<<"Price: "<<item1.get_price()<<" - ";
                cout<<"Quantity: "<<item1.get_quantity()<<endl;

            }
        }
        rf.close();
        wf.close();
        cout << "Your file has been created"<< endl;
        system("CLS");
    }
}

void Inventory::display_items(){
    int id;
    string name;
    float price;
    int quantity;
    
    cout<<"----------- All items -----------"<<endl;
    
    ifstream f;
    f.open("items.txt", ios::in);
    f.seekg(0);

    while(f>>id>>name>>price>>quantity){
        cout<<"Id: "<<id<<" - ";
        cout<<"Name: "<< name<<" - ";
        cout<<"Price: "<<price<<" - ";
        cout<<"Quantity: "<<quantity<<endl;
        
        //item1.display_data();
        cout<<"-------------------"<<endl;
    }
    f.close();
}

void Inventory::display_sp(){

    ifstream f;

    int id;
    string name;
    float price;
    int quantity;

    int n, flag = 0;
    cout<<"Enter the product id:"<<endl;
    cin>>n;

    f.open("items.txt", ios::in);
    
    while(f >> id >> name >> price >> quantity){
        if(n == id){
            cout << id << " - " << name << " - " << price << " - " << quantity << endl;
            f.close();
            flag = 1;
        }
    }

    if(flag == 1){
        cout<<"-----Product found!-----"<<endl;
    }else{
        cout<<"-----Product not found!-----"<<endl;
    }

}

void Inventory::modify_item(){

    int id;
    string name;
    float price;
    int quantity;
    bool idf = false;
    int in_id, found = 0;

    ifstream f;
    ofstream f2("temp.txt");
    ifstream f3;

    f3.open("temp.txt", ios::in);
    f.open("items.txt", ios::in );

    cout<<"Enter product id to modify: ";
    cin>>in_id;

    while(f >> id >> name >> price >> quantity){

        if(id != in_id){
            f2<< id <<" "<< name <<" "<< price <<" "<< quantity<< endl;
        }else{
            cout<< id << " - "<<name<< " - "<< price << " - "<<quantity<<endl;
            found = 1;
            cout<<"Please enter new data:\n" << endl;
            item1.get_data(); // Inputing Data

            while(!idf && f3 >> id >> name >> price >> quantity){

                if(id == item1.get_id())
                    idf = 1;
                    cout<<"Product ID already exists";
                    cout<<endl;
                    cout<<"Id: "<<id <<" - ";
                    cout<<"Name: "<< name <<" - ";
                    cout<<"Price: "<<price<<" - ";
                    cout<<"Quantity: "<<quantity<<endl;

            }

            if(!idf)
            {
                f2<<item1.get_id() << " "<<item1.get_name()<<" "<<item1.get_price()<<" "<<item1.get_quantity()<<endl;
                cout<<"Item " << item1.get_name() << " updated" << endl;
                cout<<"---------Item added successfully---------"<<endl;
                cout<<endl;
                cout<<endl;
                system("Cls");

            }
        }
    }
    f.close();
    f2.close();
    f3.close();
    
    remove("items.txt");
    rename("temp.txt", "items.txt");

    if(found == 0){
        cout<<"------Product not found"<<endl;
    }

}

void Inventory::delete_item(){

    int id;
    int in_id;
    int found = 0;
    string name;
    float price;
    int quantity;

    cout<<"Enter product id to remove: ";
    cin>>in_id;

    ifstream fin;
    ofstream f2("temp.txt");

    fin.open("items.txt", ios::in);

    fin.seekg(0, ios::beg);
    
    while(fin >> id >> name >> price >> quantity){
        if(id != in_id){
            f2<< id <<" "<< name <<" "<< price <<" "<< quantity<<endl;
        }
        if(id == item1.get_id()){
            found = 1;
        }
    } 

    fin.close();
    f2.close();

    remove("items.txt");
    rename("temp.txt", "items.txt");
  
    if(found == 1){
        system("CLS");
        cout<<"------Product removed-------"<<endl;
    }else{
        cout<<"-------Product not found-------"<<endl;
    }

}
