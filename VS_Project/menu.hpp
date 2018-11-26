/*********************************************************************
** Program name: Lab 9 | Buffer Queue & Palindrome Stack
** Author: Ryan DiRezze
** Date: November 25, 2018
** Description: Defines the main menu and other menu-like
   functions, including function prototypes.
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include "inputValidation.hpp"

#include<fstream>
using std::ifstream;
using std::ofstream;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<string>
using std::string;

// function prototype for the program's menu
void introMenu(bool&);
void mainMenuReturn(bool&);
void settings(int&, int&, int&);
int randNum();
void programSelection(int&);
std::string getStringInput();

#endif
