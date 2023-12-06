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
   
   if(option == 'd'){

   }

   if(option == 'c'){

   }
   
   if(option == 's'){

   }
   
   if(option == 't'){

   }

   if(option == 'o'){

   }

   if(option == 'q'){

   }

   return ptr;
   
}

int main(){

  string playlistTitle;

cout << "Enter playlist's title:" << end;
cin >> playlistTitle;

}
