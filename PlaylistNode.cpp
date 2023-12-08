//
// Created by Emilio Munoz on 12/5/23.
//

#include "PlaylistNode.h"
using namespace std;

PlaylistNode::PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

PlaylistNode::PlaylistNode(std::string id,std::string name,std::string artist,std::int length){}
    

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

string PlaylistNode::GetArtistName() const {
    return artistName;
}

int PlaylistNode::GetSongLength() const {
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* tmpPtr = nextNodePtr;
    nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tmpPtr;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

void PlaylistNode::PrintPlaylistNode() const {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
