#include <iostream>
#include <string>

using namespace std;

#ifndef _GENERAL_H
#define _GENERAL_H

// Authentication
void login();
void reg();
void finding_pass();

// The store
void automation();
void add_item();
void modify_item();
void display_sp();
void display_items();
void update_item();
void delete_item();

// class Inventory
// {
//     private:
//         int id;
//         float price;
//         string product_name;
//     public:
//         void get_data();
//         void display_data();
//         void remove();
//         int get_id();
//         float get_price();
//         string get_name();

// };

#endif