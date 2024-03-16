//
// CopyRight 2024
//

#ifndef INC_8_15_PLAYLISTNODE_H
#define INC_8_15_PLAYLISTNODE_H
#include "string"

class PlaylistNode {
private:
    std::string uniqueID = "none";
    std::string songName = "none";
    std::string artistName = "none";
    int songLength = 0;
    PlaylistNode* nextNodePtr;

public:
    PlaylistNode();
    PlaylistNode(std::string uniqueID, std::string songName, std::string artistName, int songLength);

    // Accessor functions
    std::string GetID();
    std::string GetSongName();
    std::string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext();

    // Mutator functions
    void InsertAfter(PlaylistNode* nodePtr);
    void SetNext(PlaylistNode* nodePtr);

    // Other functions
    void PrintPlaylistNode();


};


#endif //INC_8_15_PLAYLISTNODE_H
