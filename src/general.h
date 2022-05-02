#include <iostream>
#include <string>

#ifndef _GENERAL_H
#define _GENERAL_H

void login();
void reg();

class Inventory
{
    private: 
    int id;
    float price;
    string product_name;

    public:
    void inventory();
    void add();
    void remove();

};

#endif