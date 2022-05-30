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
void Bills();

// The store
// Admin
void automation();
void add_item();
void modify_item( const char* );
void display_sp( const char*);
void Sp_choice();
void modify_choice();
void delete_choice();
void display_items();
void update_item();
void delete_item( const char* );

// Customer
void Start(string email);
void cart_checking();
void purchase_display();
void backStart();
// void fruits_veggies();
// void copy_fruits();
// void copy_veggies();

#endif