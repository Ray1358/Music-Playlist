#include <iostream>
#include <iostream>
#include "string"
#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string& playlistTitle) {
    /* Type your code here */
    cout << playlistTitle << " PLAYLIST MENU\n"
         << "a - Add song\n"
         << "d - Remove song\n"
         << "c - Change position of song\n"
         << "s - Output songs by specific artist\n"
         << "t - Output total time of playlist (in seconds)\n"
         << "o - Output full playlist\n"
         << "q - Quit\n";
    cout<<endl;
}



PlaylistNode* ExecuteMenu(char option, string& playlistTitle, PlaylistNode* headNode) {
    /* Type your code here */
    switch (option) {
        case 'a': {
            // Implement Add song
            cout << "ADD SONG" << endl;
            string uniqueID, songName, artistName;
            int songLength;
            //cin.ignore();
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);
            cout << "Enter song's name:" << endl;
            getline(cin, songName);
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;
            cout <<endl;



            PlaylistNode* newNode = new PlaylistNode(uniqueID, songName, artistName, songLength);

            if (headNode == nullptr) {
                headNode = newNode;
            } else {
                PlaylistNode* current = headNode;
                while (current->GetNext() != nullptr) {
                    current = current->GetNext();
                }
                current->InsertAfter(newNode);
            }
            break;
        }
        case 'd': {
            // Implement Remove song
            cout << "REMOVE SONG" << endl;
            string targetID;
            cout << "Enter song's unique ID:" << endl;
            //cin.ignore();
            getline(cin, targetID);

            PlaylistNode* current = headNode;
            PlaylistNode* prev = nullptr;

            while (current != nullptr && current->GetID() != targetID) {
                prev = current;
                current = current->GetNext();
            }

            if (current == nullptr) {
                cout << "Song with ID " << targetID << " not found." << endl;
            } else {
                if (prev == nullptr) {
                    headNode = current->GetNext();
                } else {
                    prev->SetNext(current->GetNext());
                }
                delete current;
                cout << "\"" << targetID << "\" removed." << endl;
            }
            break;
        }
        case 'c': {
            // Implement Change position of song
            cout << "CHANGE POSITION OF SONG" << endl;
            int currentPosition, newPosition;
            cout << "Enter song's current position:" << endl;
            cin >> currentPosition;
            cout << "Enter new position for song:" << endl;
            cin >> newPosition;

            if (currentPosition < 1) {
                currentPosition = 1;
            }

            int count = 1;
            PlaylistNode* current = headNode;
            PlaylistNode* previous = nullptr;

            // Traverse to the current position
            while (current != nullptr && count < currentPosition) {
                previous = current;
                current = current->GetNext();
                count++;
            }

            if (current == nullptr) {
                cout << "Invalid position." << endl;
            } else {
                // Remove current node from its current position
                if (previous == nullptr) {
                    headNode = current->GetNext();
                } else {
                    previous->SetNext(current->GetNext());
                }

                // Find the new position
                PlaylistNode* temp = headNode;
                PlaylistNode* prev = nullptr;
                count = 1;
                while (temp != nullptr && count < newPosition) {
                    prev = temp;
                    temp = temp->GetNext();
                    count++;
                }

                // Insert current node at the new position
                if (prev == nullptr) {
                    current->SetNext(headNode);
                    headNode = current;
                } else {
                    prev->InsertAfter(current);
                }

                cout << "\"" << current->GetSongName() << "\" moved to position " << newPosition << endl;
            }
            break;
        }
        case 's': {
            // Implement Output songs by specific artist
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            string artistName;
            cout << "Enter artist's name:" << endl;
            //cin.ignore();
            cout <<endl;
            getline(cin, artistName);

            PlaylistNode* current = headNode;
            int position = 1;
            bool found = false;

            while (current != nullptr) {
                if (current->GetArtistName() == artistName) {
                    cout << position << "." << endl;
                    current->PrintPlaylistNode();
                    found = true;
                }
                current = current->GetNext();
                position++;
            }

            if (!found) {
                cout << "No songs by " << artistName << " found in the playlist." << endl;
            }
            break;
        }
        case 't': {
            // Implement Output total time of playlist
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            int totalTime = 0;
            PlaylistNode* current = headNode;

            while (current != nullptr) {
                totalTime += current->GetSongLength();
                current = current->GetNext();
            }

            cout << "Total time: " << totalTime << " seconds" << endl;
            cout <<endl;
            break;
        }
        case 'o': {
            // Implement Output full playlist
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            PlaylistNode* current = headNode;
            int position = 1;
            if (current == nullptr) {
                cout << "Playlist is empty" << endl;
                cout <<endl;
            } else {
                while (current != nullptr) {
                    cout << position << "." << endl;
                    current->PrintPlaylistNode();
                    current = current->GetNext();
                    position++;
                }
            }
            break;
        }
        case 'q': {
            // Quit
            cout << "Quitting..." << endl;
            break;
        }
        default:
            cout << "Invalid option. Please choose a valid option from the menu." << endl;
    }
    return headNode;


}

int main() {
    /* Type your code here */
    string playlistTitle;
    cout << "Enter playlist's title:\n";
    getline(cin, playlistTitle);
    cout<<endl;
    char choice;
    PlaylistNode* headNode = nullptr;

    while (true) {
        PrintMenu(playlistTitle);
        cout << "Choose an option:";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer
        cout<<endl;
        if (choice == 'q') {
            break; // Exit loop if the user chooses to quit
        }

        headNode = ExecuteMenu(choice, playlistTitle, headNode);
    }

    return 0;
}

