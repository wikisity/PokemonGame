/*********************
 * File: proj2.cpp
 * Author: Arnold Epanda
 * Date: 10/11/2016
 * Email: behlarnold@gmail.com

 * This c++ file includes a header file to enable the use of
 * all libraries needed to design a simple implementation of the 
 * famous Pokemon game. A goal of this game is to let the user act as a 
 * trainer of Pokemon(also called pocket monsters). He/she searches the 
 * world in hope of finding powerful Pokemon. Finally, after a user has found
 * some Pokemon he/she can battle them against other Pokemon.  
 ******************/

#include "proj2.h"
using namespace std;

int main () {
  vector<Pokemon> pokeDex; // A vector of Pokemon objects
  vector<MyPokemon> myCollection; // A vector of a user all Pokemon objects
  getPokeDex(pokeDex);
  getMyCollection(myCollection);
  mainMenu (pokeDex, myCollection);
  return 0;
}

// Name: getPokeDex(vector)
// Pre-condition: When the application loads, loads 
//                the complete pokemon list from file		
// Post-condition: Returns a populated pokeDex vector
void getPokeDex(vector<Pokemon> & pokeDex){
  int num, cp, hp, rarity; // Number, mimimum and maximum combat points and rarity of a Pokemon.
  string name;  // Name of a Pokemon
  fstream inputStream; // File object to manipulate data about Pokemon 
  inputStream.open(POKEDEX);
  while(inputStream >> num){
    inputStream >> name
		>> cp 
		>> hp 
		>> rarity;
    pokeDex.push_back(Pokemon(num, name, cp, hp, rarity));
  }
  inputStream.close();
}

// Name: getMyCollection
// Pre-condition: When the application loads, loads the user's pokemon collection from file
// Post-condition: Returns a populated myCollection vector
void getMyCollection(vector<MyPokemon> & myCollection){
  int num, cp, hp, rarity; // Number, combat and hit points and rarity of a user Pokemon
  string name; // Name of a user Pokemon
  fstream inputStream; // File object to manipulate data about a user's collection of Pokemon
  inputStream.open(MYCOLLECTION);
  while(inputStream >> num){
    inputStream >> name
		>> cp 
		>> hp 
		>> rarity;
    
    myCollection.push_back(MyPokemon(num, name, cp, hp, rarity));
  }
  inputStream.close();
}

// Name: printPokeDex (vector)
// Pre-condition: Takes in populated pokeDex vector
// Post-condition: Prints num and name of each Pokemon in vector
void printPokeDex(vector <Pokemon> & pokeDex){
  for(unsigned int i = 0; i < pokeDex.size(); i++){
    cout << setw(5) << pokeDex[i].GetNum() << setw(15) 
	 << pokeDex[i].GetName() << endl;
  }
}

// Name: printMyCollection (vector)
// Pre-condition: Takes in populated myCollection vector
// Post-condition: Prints num, name, CP, HP, rarity of each pokemon in vector
void printMyCollection(vector <MyPokemon> & myCollection){
  // A user may try to populate an empty collection
  if((int)myCollection.size() == 0){
    cout << "Your Collection is empty. Need to catch some Pokemon" << endl;
  }
  else{
    for(unsigned int i = 0; i < myCollection.size(); i++){
      cout << setw(5) << i << '.' << setw(6)
	   << myCollection[i].GetNum() << setw(16)
	   << myCollection[i].GetName() << setw(8)
	   << myCollection[i].GetCP() << setw(8)
	   << myCollection[i].GetHP() << setw(5)
	   << myCollection[i].GetRarity() << endl;
    }
    
  }
}

// Name: catchPokemon
// Pre-condition: Takes in the current user's collection and the pokeDex vector
// Post-condition: Prompts user for rarity (1-5) user would like to capture
//                 Based on rarity (1=65%, 2=45%, 3=25%, 4=10%, 5=1%) tries to find a random
//                 Pokemon based on that rarity.
//                 If a Pokemon is found, calls foundPokemon
void catchPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0; // Save the user choice
  bool isExit = 0; // Specifies that user has not attempted to catch Pokemon yet
  int range; // save the random number generated
  const int MAX = 100; // Maximum random number that can be generated
  do {
    do {
      cout << endl;
      cout << "What type of Pokemon would you like to try and catch?:" << endl;
      cout << "1. Very Common (Very High Probability)" << endl;
      cout << "2. Common (High Probability)" << endl;
      cout << "3. Uncommon (Normal Probability)" << endl;
      cout << "4. Rare (Law Probability)" << endl;
      cout << "5. Ultra Rare (Extremely Low Probabiliy)" << endl;
      cout << endl;
      cin >> option;
    }while(option < 1 || option > 5);

    switch(option){
    case 1:
      srand((unsigned int)time(NULL));
      range = (rand() % MAX) + 1;
      // Case of 65% of cacthing a Pokemon
      if(range >= 1 and range <= 65){
	cout << endl;
	cout << "You start to search." << endl;
	foundPokemon(1, pokeDex, myCollection);
      }
      else{
	cout << "Pokemon not found" << endl;
      }
      // Should exit whether user has caught or not caught a Pomon. It is one try
      isExit = 1;
      break;

    case 2:
      srand((unsigned int)time(NULL));
      range = (rand() % MAX) + 1;
      // Case of 45% of catching a Pokemon
      if(range >= 1 and range <= 45){
	cout << endl;
	cout << "You start to search." << endl;
	foundPokemon(2, pokeDex, myCollection);
      }
      else{
        cout << "Pokemon not found" << endl;
      }
      isExit = 1;
      break;

    case 3:
      srand((unsigned int)time(NULL));
      range = (rand() % MAX) + 1;
      if(range >= 1 and range <= 25){
	cout << endl;
	cout << "You start to search." << endl;
	foundPokemon(3, pokeDex, myCollection);
      }
      else{
        cout << "Pokemon not found" << endl;
      }
      isExit = 1;
      break;

    case 4:
      srand((unsigned int)time(NULL));
      range = (rand() % MAX) + 1;
      if(range >= 1 and range <= 10){
	cout << endl;
	cout << "You start to search." << endl;
	foundPokemon(4, pokeDex, myCollection);
      }
      else{
        cout << "Pokemon not found" << endl;
      }
      isExit = 1;
      break;

    case 5:
      srand((unsigned int)time(NULL));
      range = (rand() % MAX) + 1;
      //Cae of 1% of catching a Pokemon
      if(range == 1){
	cout << endl;
	cout << "You start to search." << endl;
	foundPokemon(5, pokeDex, myCollection);
      }
      else{
        cout << "Pokemon not found" << endl;
      }
      isExit = 1;
      break;

    }
  }while(isExit == 0);
}

// Name: foundPokemon (rarity, vector pokeDex, vector myCollection)
// Pre-condition: After a Pokemon is found, rarity is passed to this function
// Post-condition: Using rarity, the pokeDex is randomly searched for a matching rarity
//                 After an appropriate Pokemon is found
//                 Adds new Pokemon to user's collection
void foundPokemon(int rarity, vector <Pokemon> & pokeDex, 
		 vector<MyPokemon> & myCollection ){
  int range; // Save the random number generated
  int num, cp, hp; // Number, combat and hit points of a Pokemon
  string name; // Name of the Pokemon
  bool isFound = 0; // Boolean value to False specifies that Pokemon is not found yet 
  const int POKECOUNT = 151; // Total number of existing Pokemon

  // Assure that random number generated are different each time
  srand((unsigned int)time(NULL));

  while(!(isFound)){
    range = (rand() % POKECOUNT) + 1;
    //Randomly searching for a matching rarity
    if(pokeDex.at(range - 1).GetRarity() == rarity){
      num = pokeDex.at(range - 1).GetNum();
      name = pokeDex.at(range - 1).GetName();

      // Keep generating user's Pokemon CP randomly till number is between minCP and maxCP
      do{
	cp = (rand() % pokeDex.at(range - 1).GetCPMax()) + pokeDex.at(range - 1).GetCPMin();
      }while((cp < pokeDex.at(range - 1).GetCPMin()) or (cp > pokeDex.at(range - 1).GetCPMax()));
      
      // Calculating a Pokemon hit point
      hp = (int)(cp * 0.1);
      myCollection.push_back(MyPokemon(num, name, cp, hp, rarity));
      isFound = 1;
    }
  }
  cout << "Congrats! You found a " << name << endl;
}

// Name: mainMenu
// Pre-condition: Takes in vector pokeDex and vector myCollection
// Post-condition: Calls a variety of functions based on user
void mainMenu(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
  int option = 0; // User choice
  bool isExit = 0; // User has not decided to exit yet

  // Allow a good display while program is running
  cout << endl;

  do {
    do {
      cout << endl;
      cout << "What would you like to do?: " << endl;
      cout << "1. See the PokeDex" << endl;
      cout << "2. See your collection" << endl;
      cout << "3. Search for a new Pokemon" << endl;
      cout << "4. Battle Your Pokemon" << endl;
      cout << "5. Train your Pokemon" << endl;
      cout << "6. Exit" << endl;
      cout << endl;
      cin >> option;
    }while((option < 1) or (option > 6));
  
    switch(option){
    case 1:
      printPokeDex(pokeDex);
      break;
    case 2:
      printMyCollection(myCollection);
      break;
    case 3:
      catchPokemon(pokeDex,  myCollection);
      break;
    case 4:
      battlePokemon(pokeDex, myCollection);    
      break;
    case 5:
      trainPokemon(pokeDex, myCollection);
      break;
    case 6:
      exitPokemon(myCollection);
      isExit = 1;
    }
  }while(isExit == 0);
}

// Name: battlePokemon(vector pokeDex, vector myCollection)
// Pre-condition: Takes in both pokeDex and myCollection. Randomly chooses an enemy
//                Sets enemy CP as random number between minCP and maxCP
// Post-condition: Says if battle is won or lost - returns to mainMenu
 void battlePokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int usr_option; // User choice
   // User should catch some Pokemon first
   if((int)myCollection.size() != 0){
     int range, cp; // Save a random enemy and a random enemy CP 
     const int POKECOUNT = 151; // Maximum random number that can be generated
     cout << endl;
     for(unsigned int i = 0; i < myCollection.size(); i++){
       cout << setw(5) << i << '.' << setw(6)
	    << myCollection[i].GetNum() << setw(16) 
	    << myCollection[i].GetName() << setw(8)  
	    << myCollection[i].GetCP() << setw(8) 
	    << myCollection[i].GetHP() << setw(5)
	    << myCollection[i].GetRarity() << endl;
     }
     srand((unsigned int)time(NULL));
     range = (rand() % POKECOUNT) + 1;
     cout << endl;
     // Randomly chooss an enemy to battle with
     cout << "You are going to fight a " << pokeDex.at(range - 1).GetName() << endl;
     
     // Keep generating enemy CP randomly till number is between minCP and maxCP 
     do{
       cp = (rand() % pokeDex.at(range - 1).GetCPMax()) + pokeDex.at(range - 1).GetCPMin();
     }while((cp < pokeDex.at(range - 1).GetCPMin()) or (cp > pokeDex.at(range - 1).GetCPMax()));
     cout << "The enemy has a CP of " << cp << endl;

     // Keep Prompting user to enter a valid choice
     do{
       cout << "Which of your Pokemon would you like to use?:" << endl;
       cin >> usr_option;
     }while((usr_option < 0) or (usr_option > (((int)myCollection.size()) - 1)));

     // User winning decision
     if(cp < myCollection[usr_option].GetCP())
       cout << "You Won!!" << endl;
     else if(cp > myCollection[usr_option].GetCP())
       cout << "You lost the battle!" << endl;
     else
       cout << "The fight ended in a Draw!" << endl;
   }
   // User attempt to battle with an empty collection
   else{
     cout << endl;
     cout << "Cannot battle Pokemons. Your Collection is Empty." << endl;
   }
    
 }

// Name: trainPokemon(vector pokeDex, vector myCollection)
// Pre-condition: Takes in both pokeDex and myCollection
// Post-condition: Calls Train member function that increases CP by 10. Updates myCollection
 void trainPokemon(vector <Pokemon> & pokeDex, vector<MyPokemon> & myCollection){
   int usr_option; // User choice
   // User train Pokemon only if he/she has a collection
   if((int)myCollection.size() != 0){
     do{
       cout << endl;
       cout << "Which of your Pokemon would you like to use?:" << endl;
       for(unsigned int i = 0; i < myCollection.size(); i++){
	 cout << setw(5) << i << '.' << setw(6) 
	      << myCollection[i].GetNum() << setw(16)
	      << myCollection[i].GetName() << setw(8)
	      << myCollection[i].GetCP() << setw(8) 
	      << myCollection[i].GetHP() << setw(5)
	      << myCollection[i].GetRarity() << endl;
       }
       cin >> usr_option;
     }while((usr_option < 0) or (usr_option > (((int)myCollection.size()) - 1)));
     
     // Making sure that we only train Pokemon that have their CP no more than CPMax
     unsigned int i = 0;
     while(i < pokeDex.size()){
       if(myCollection[usr_option].GetNum() == pokeDex[i].GetNum()){
	 if(myCollection[usr_option].GetCP() == pokeDex[i].GetCPMax()){
	   cout << endl;
	   cout << myCollection[usr_option].GetName() << " has reached MAX CP." << endl 
		<< "Cannot be trained" << endl;
	   i = pokeDex.size();
	 }
	 else if((myCollection[usr_option].GetCP() + 10) > pokeDex[i].GetCPMax()){
	   cout << endl;
	   cout << myCollection[usr_option].GetName() << " CP cannot be more than "  
		<< pokeDex[i].GetCPMax() << " So cannot be trained." << endl;
	   i = pokeDex.size();
	 }
	 else{
	   cout << endl;
	   cout << "Your " << myCollection[usr_option].GetName() << " is trained." << endl;
	   myCollection[usr_option].Train();
	   i = pokeDex.size();
	 }
       }
       else
	 i++;
     }
   }
   // User attempt to train an empty collection of Pokemon
   else{
     cout << endl;
     cout << "Cannot train Pokemons. Your Collection is Empty." << endl;
   }
   
 }

// Name: exitPokemon
// Pre-condition: From main menu, user selects 6
// Post-condition: Calls saveMyCollection and exits application
 void exitPokemon(vector<MyPokemon> & myCollection){
   saveMyCollection(myCollection);
 }

// Name: saveMyCollection(vector)
// Pre-condition: Takes in vector of user collection of Pokemon
// Post-condition: Saves a file with each Pokemon with number, name, CP, HP, rarity
void saveMyCollection(vector<MyPokemon> & myCollection){
  fstream outputStream; // File object to manipulate user's collection of Pokemon
  outputStream.open(MYCOLLECTION);
  // User can only open file taht exits
  if(outputStream){
    for(unsigned int i = 0; i < myCollection.size(); i++){
      outputStream << myCollection[i].GetNum()  
		   << setw(16)
		   << myCollection[i].GetName() << right 
		   << setw(8) 
		   << myCollection[i].GetCP() 
		   << setw(8) 
		   << myCollection[i].GetHP() 
		   << setw(9) 
		   << myCollection[i].GetRarity()
		   << endl;
    }
    outputStream.close();
    cout << endl;
    cout << "File Saved" << endl;
    cout << "Thank you for playing Pokemon UMBC" << endl;
  }
  // If file does not exit prompt user that is not an apropriate action.
  else{
    cout << endl;
    cout << "Cannot do this action yet." << endl
	 << " Need to create a myCollection.txt file. " << endl
	 << "Thank you." << endl;
  }
}
