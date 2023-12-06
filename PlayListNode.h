//
// Created by Emilio Munoz on 12/5/23.
#ifndef ZYLAB_28_15_PLAYLISTNODE_H
#define ZYLAB_28_15_PLAYLISTNODE_H

class PlayListNode {
public:
    PlaylistNode();  
    PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength);  

    std::string GetID() const;
    std::string GetSongName() const;
    std::string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;

    // Mutators
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);

    // Other
    void PrintPlaylistNode() const;

private:
    std::string uniqueID;
    std::string songName;
    std::string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;



};


#endif //ZYLAB_28_15_PLAYLISTNODE_H