#include <iostream>
#include <string>

using namespace std;

#ifndef _GENERAL_H
#define _GENERAL_H

// Main file
int main();

// Authentication
void login();
void reg();
void finding_pass();

// The store
// Admin
void automation();
void add_item();
void modify_item();
void display_sp();
void display_items();
void update_item();
void delete_item();

// Customer
void Start();
void cart_checking();
void purchase_display();
void backStart();
void fruits_veggies();
void copy_fruits();
void copy_veggies();

#endif