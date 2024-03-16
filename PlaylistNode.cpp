//
// CopyRight 2024
//


#include "PlaylistNode.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

// Default constructor
PlaylistNode::PlaylistNode() {
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = nullptr;
}

// Parameterized constructor
PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength) {
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    this->nextNodePtr = nullptr;
}

// Accessor functions
string PlaylistNode::GetID() {
    return this->uniqueID;
}

string PlaylistNode::GetSongName()  {
    return this->songName;
}

string PlaylistNode::GetArtistName() {
    return this->artistName;
}

int PlaylistNode::GetSongLength() {
    return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext()  {
    return this->nextNodePtr;
}

// Mutator functions
void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    PlaylistNode* tmpNext = nullptr;
    tmpNext = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
    nodePtr->nextNodePtr = tmpNext;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    nextNodePtr = nodePtr;
}

// PrintPlaylistNode function
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
    cout <<endl;
}

