//
// Created by Emilio Munoz on 12/5/23.
//

#include "PlayListNode.h"
using namespace std;

PlaylistNode::PlaylistNode(){

  uniqueID = "none";
  songName= "none";
  artistName = "none";
  songLength= 0;
  nextNodePt=nullptr;
}

PlaylistNode::PlaylistNode(string id,string name, string artist, int length){
uniqueID = id;
  songName= name;
  artistName = artist;
  songLength= length;
  nextNodePt=nullptr;
}
    

string PlaylistNode::GetID() const {
    return uniqueID;
}

string PlaylistNode::GetSongName() const {
    return songName;
}

std::string PlaylistNode::GetArtistName() const {
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
    std::cout << "Unique ID: " << uniqueID << endl;
    std::cout << "Song Name: " << songName << endl;
    std::cout << "Artist Name: " << artistName << endl;
    std::cout << "Song Length (in seconds): " << songLength << endl;
