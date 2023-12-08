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
   
   switch(option){
   case'a':
         // Get user input... then:
      //string songTitle;
        // PlaylistNode* temp = new playlistNode();
         //temp->setTitle(songTitle);
         // ...
         //return temp;
         PrintMenu(playlistTitle);
         break;
   
   
   case'd':
   PrintMenu(playlistTitle);
   break;

   case'c':
   PrintMenu(playlistTitle);
   break;
   
   case's':
   PrintMenu(playlistTitle);
   break;
   
   case't':
   PrintMenu(playlistTitle);
   break;

   case'o':
      cout<<"JAMZ - OUTPUT FULL PLAYLIST ";
         if(headNode == nullptr){
            cout<<"Playlist is empty";
         }
   
   break;

   case'q':
      return nullptr;
      break;

   default:
   return nullptr;
   break;
   }
}


int main(){

   string playlistTitle;
   char input;
   PlaylistNode* node = new PlaylistNode();
   bool isValidInput = false;
   
   cout << "Enter playlist's title:" << endl<<endl;
   getline(cin, playlistTitle);
   PrintMenu(playlistTitle);
   
   while(isValidInput){
   cin >> input;
      if(input!='q'){
         PlaylistNode* newSong = ExecuteMenu(input, playlistTitle, node);
         if (newSong != nullptr) {
            node->SetNext(newSong);
            node = node->GetNext();
            
         }
         
         else{
          isValidInput = false;
         }
      } 
   }
   
   
   delete node;
   
   return 0;

}
