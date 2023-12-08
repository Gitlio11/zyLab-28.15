
// Created by Emilio Munoz on 12/5/23.
#ifndef PLAYLISTNODE_H
#define PLAYLISTNODE_H

#include <iostream>
#include <string>
using namespace std;

class PlaylistNode {
public:
    PlaylistNode();  
    PlaylistNode(string uniqueID, string songName, string artistName, int songLength);  

    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;

    // Mutators
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);

    // Other
    void PrintPlaylistNode() const;

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;



};


#endif
