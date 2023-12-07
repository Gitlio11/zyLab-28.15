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

   cout<<"Choose an option:"<<endl;
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
   
   if(option == 'a'){
         // Get user input... then:
      //string songTitle;
        // PlaylistNode* temp = new playlistNode();
         //temp->setTitle(songTitle);
         // ...
         //return temp;
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
      return nullptr;
   } 
   else{

   return nullptr;
   }
}


int main(){

   string playlistTitle;
   char input;
   PlaylistNode* node = new PlaylistNode();
   bool isValidInput = false;
   
   cout << "Enter playlist's title:" << endl<<endl;
   getline(cin, playlistTitle);
   
   cin >> input;
   
   PrintMenu(playlistTitle);
   if(input!='q'){
   while(isValidInput){

      PlaylistNode* newSong = ExecuteMenu(input, playlistTitle, node);
      if (newSong != nullptr) {
         node->SetNext(newSong);
         node = node->GetNext();
      }
      break;
   } 
   }
   
   else{
    isValidInput = false;
   }
   
   delete node;
   
   return 0;

}
