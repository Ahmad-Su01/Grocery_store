#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Inventory
{
    private:
        int id;
        float price;
        string product_name ;

    public:
        void get_data(){

            cout<<"Id:"<<endl;
            cin>>id;

            cout<<"Name:"<<endl;
            cin>>product_name;

            cout<<"Price:"<<endl;
            cin>>price;

        };

        void display_data(){

            cout<<"Id: "<< id<<endl;
            cout<<"Name: "<< product_name <<endl;
            cout<<"Product price: "<< price <<endl;

        }

        void remove();

        int get_id(){

            return id;

        };
        float get_price(){

            return price;

        };
        string get_name(){

            return product_name;

        }

};

fstream f;
Inventory item1;

void add_item(){

    f.open("items.txt", ios::out |ios::app );
    item1.get_data();
    f.write( (char*)&item1, sizeof(item1));

    f.close();
    cout<<"Item saved in file"<<endl;

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

    int n;
    cout<<"Enter the product id:"<<endl;
    cin>>n;
    int flag = 0;
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

void update_item(){

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
        cout<<"------Product not found------"<<endl;
    }
}