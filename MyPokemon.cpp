/*********************
 * File: MyPokemon.cpp
 * Author: Arnold Epanda
 * Date: 10/11/2016
 * Email: aepanda1@umbc.edu

 * This c++ file includes MyPokemon header file and a definition 
 * of all functions decalred in the MyPokemon header file. This file 
 * basically defines the 2 constructors prototyped in the MyPokemon header
 * file, all getters and setters and a member function Train(). 
 ******************/

#include "MyPokemon.h"
using namespace std;

MyPokemon::MyPokemon(){
  m_Num = 1;
  m_Name = "Bulbasaur";
  m_CP = 321;
  m_HP = 1072;
  m_Rarity = 2;
}

MyPokemon::MyPokemon(int num, string name, int cp, int hp, int rarity){
  m_Num = num;
  m_Name = name;
  m_CP = cp;
  m_HP = hp;
  m_Rarity = rarity;
}

int MyPokemon::GetCP(){
  return m_CP;
}

int MyPokemon::GetHP(){
  return m_HP;
}

int MyPokemon::GetRarity(){
  return m_Rarity;
}

string MyPokemon::GetName(){
  return m_Name;
}

int MyPokemon::GetNum(){
  return m_Num;
}

void MyPokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

void MyPokemon::SetName(string newName){
  m_Name = newName;
}

void MyPokemon::SetCP(int newCP){
  m_CP = newCP;
}

void MyPokemon::SetHP(int newHP){
  m_HP = newHP;
}

//Addd 10CP to the Pokemon and updates Pokemon that was trained
void MyPokemon::Train(){
  m_CP += 10;
  cout << "Your CP is now " << m_CP << '.' << endl;
}
