/*********************
 * File: Pokemon.cpp
 * Author: Arnold Epanda
 * Date: 10/11/2016
 * Email: aepanda1@umbc.edu

 * This c++ file includes a Pokemon header file and provides with 
 * a definition of all Constructors, Mutators and Accessors declared
 * in the Pokemon header file.
 ******************/


#include "Pokemon.h"
using namespace std;

Pokemon::Pokemon(){
  m_Num = 1;
  m_Name = "Bulbasaur";
  m_MinCP = 321;
  m_MaxCP = 1072; 
  m_Rarity = 2;
}

Pokemon::Pokemon(int num, string name, int cpMin, int cpMax, int rarity){
  m_Num = num;
  m_Name = name;
  m_MinCP = cpMin;
  m_MaxCP = cpMax;
  m_Rarity = rarity;
}

int Pokemon::GetCPMin(){
  return m_MinCP;
}

int Pokemon::GetCPMax(){
  return m_MaxCP;
}

int Pokemon::GetRarity(){
  return m_Rarity;
}

string Pokemon::GetName(){
  return m_Name;
}

int Pokemon::GetNum(){
  return m_Num;
}

void Pokemon::SetRarity(int newRarity){
  m_Rarity = newRarity;
}

void Pokemon::SetName(string newName){
  m_Name = newName;
}

void Pokemon::SetCP(int newCP){
  m_MinCP = newCP;
}
