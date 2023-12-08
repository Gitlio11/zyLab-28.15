#include "PlaylistNode.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void PrintMenu(const string& playlistTitle) {
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
}

PlaylistNode* ExecuteMenu(char option, const string& playlistTitle, PlaylistNode* headNode) {
    
    PlaylistNode *currentNode, *prevNode;

    switch (option) {
       
        case 'a': {  
            string id, songName, artistName;
            int songLength;
            PlaylistNode* newNode;
            PlaylistNode* lastNode;

            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore(); 
            getline(cin, id);

            cout << "Enter song's name:" << endl;
            getline(cin, songName);

            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            cout << "Enter song's length (in seconds):" << endl;
            cout << endl;
            cin >> songLength;

            newNode = new PlaylistNode(id, songName, artistName, songLength);

            if (headNode == nullptr) {
                headNode = newNode;
            } else {
                lastNode = headNode;
                while (lastNode->GetNext() != nullptr) {
                    lastNode = lastNode->GetNext();
                }
                lastNode->SetNext(newNode);
            }
            break;
        }  
        case 'd': {  
            string id;

            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin.ignore();
            getline(cin, id);

            currentNode = headNode;
            while (currentNode != nullptr && currentNode->GetID() != id) {
                prevNode = currentNode;
                currentNode = currentNode->GetNext();
            }

            if (currentNode == nullptr) {
                cout << "Song with ID " << id << " not found." << endl;
            } else {
                if (prevNode == nullptr) {
                    
                    headNode = currentNode->GetNext();
                } else {
                    
                    prevNode->SetNext(currentNode->GetNext());
                }
                cout << "\"" << currentNode->GetSongName() << "\" removed." << endl;
                cout << endl;
                delete currentNode; 
            }
            break;
        }  
         case 'c': {  
            int currentPos, newPos, i;
            PlaylistNode *newNode, *newPrevNode;

            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> currentPos;
            cout << "Enter new position for song:" << endl;
            cin >> newPos;

            
            if (currentPos < 1 || newPos < 1 || headNode == nullptr) {
                cout << "Invalid position." << endl;
                break;
            }

           
            currentNode = headNode;
            prevNode = nullptr;
            for (i = 1; i < currentPos && currentNode != nullptr; ++i) {
                prevNode = currentNode;
                currentNode = currentNode->GetNext();
            }

            if (currentNode == nullptr) {
                cout << "Invalid current position." << endl;
                break;
            }

           
            if (prevNode == nullptr) {
                headNode = currentNode->GetNext();
            } else {
                prevNode->SetNext(currentNode->GetNext());
            }

          
         
            newPrevNode = nullptr;
            newNode = headNode;
            for (i = 1; i < newPos && newNode != nullptr; ++i) {
                newPrevNode = newNode;
                newNode = newNode->GetNext();
            }

            if (newPrevNode == nullptr) {
                currentNode->SetNext(headNode);
                headNode = currentNode;
            } else {
                currentNode->SetNext(newPrevNode->GetNext());
                newPrevNode->SetNext(currentNode);
            }

            cout << "\"" << currentNode->GetSongName() << "\" moved to position " << newPos << endl;
            cout << endl;
            break;
         }  
         
case 's': {  
    string artistName;
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    cout << endl;
    cin.ignore(); // To consume any leftover newline character
    getline(cin, artistName);

    PlaylistNode* currentNode = headNode;
    int songPosition = 1; 
    while (currentNode != nullptr) {
        if (currentNode->GetArtistName() == artistName) {
            cout << songPosition << "." << endl;
            currentNode->PrintPlaylistNode();
            cout << endl;
        }
        currentNode = currentNode->GetNext();
        songPosition++;  
    }
    break;
}
   
        case 't': {  
            int totalTime = 0;
            currentNode = headNode;
            {
                PlaylistNode* currentNode = headNode;
                while (currentNode != nullptr) {
                    totalTime += currentNode->GetSongLength();
                    currentNode = currentNode->GetNext();
                }

                cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
                cout << "Total time: " << totalTime << " seconds" << endl;
                cout << endl;
            }
            break;
        }  
        case 'o':  
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if (headNode == nullptr) {
                cout << "Playlist is empty" << endl;
                cout << endl;
            } else {
                PlaylistNode* currentNode = headNode;
                int songNumber = 1;
                while (currentNode != nullptr) {
                    cout << songNumber << "." << endl;
                    currentNode->PrintPlaylistNode();
                    cout << endl;
                    currentNode = currentNode->GetNext();
                    songNumber++;
                }
            }
            break;
        case 'q':
            
            break;
        default:
            cout << "Invalid option, please try again." << endl;
    }
    return headNode;
}

int main() {
    string playlistTitle;

    
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, playlistTitle);

    PlaylistNode* headNode = nullptr; 
    char menuOption = ' ';

    while (menuOption != 'q') {
        PrintMenu(playlistTitle);

        cout << "Choose an option:" << endl;
        cin >> menuOption;

        
        while (cin.fail() || (menuOption != 'a' && menuOption != 'd' && menuOption != 'c' && menuOption != 's' && menuOption != 't' && menuOption != 'o' && menuOption != 'q')) {
            cout << "Invalid option, please try again." << endl;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            PrintMenu(playlistTitle);
            cout << "Choose an option:" << endl;
            cin >> menuOption;
        }

        
        if (menuOption != 'q') {
            headNode = ExecuteMenu(menuOption, playlistTitle, headNode);
        }
    }

    

    return 0;
}
