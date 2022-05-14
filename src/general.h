#include <iostream>
#include <string>

#ifndef _GENERAL_H
#define _GENERAL_H

void login();
void reg();
void finding_pass();
void add_item();
void display_items();
void update_item()

class Inventory
{
    private:
        int id;
        float price;
        string product_name ;

    public:
        void get_data();
        void display_data();
        void remove();
        int get_id();
        float get_price();
        string get_name();

};

#endif