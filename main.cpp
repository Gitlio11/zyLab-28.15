#include <iostream>
#include "PlaylistNode.h"
using namespace std;
#include<string>


void PrintMenu(const string playlistTitle) {
   cout<< playlistTitle << " PLAYLIST MENU"<<endl;
   cout<<"a - Add song"<<endl;
   cout<<"d - Remove song"<<endl;
   cout<<"c - Change position of song"<<endl;
   cout<<"s - Output songs by specific artist"<<endl;
   cout<<"t - Output total time of playlist (in seconds)"<<endl;
   cout<<"o - Output full playlist"<<endl;
   cout<<"q - Quit"<<endl<<endl;

   cout<<"Choose an option:"<<endl
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   
   if(option == 'a'){

   }
   
   else if(option == 'd'){

   }

   else if(option == 'c'){

   }
   
   else if(option == 's'){

   }
   
   else if(option == 't'){

   }

   else if(option == 'o'){

   }

   else if(option == 'q'){

   } else{

   return ptr;
   
}


int main(){

  string playlistTitle;
   char option;
   vector<char> options = {'a', 'd', 'c', 's', 't', 'o', 'q'};
   cout << "Enter playlist's title:" << end;
   cin >> playlistTitle;

   PrintMenu();
   cin >> option;

   for (option : options) {
            if (userInput.size() == 1 && userInput[0] == option) {
                bool isValidInput = true;
                break;
            }
        }
   
   if(isValidInput){
   ExecuteMenu(option, playlistTitle, POINTER)
   }
   


   

}
