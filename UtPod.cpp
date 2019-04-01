// Jimmy Phan
//
#include "UtPod.h"
#include <iostream>
using namespace std;


// Default Constructor
// sets memory size to MAX
UtPod::UtPod(){
   cout << "in constructor" << endl;
   podMemSize = MAX_MEMORY;
   remainingMem = MAX_MEMORY;
   songs = NULL;
   cout << "finished the constructor\n";
}


// Constructor with size parameter
UtPod::UtPod(int size){
   if(size > 512 || size < 0){
      podMemSize = MAX_MEMORY;
   }
   else{
      podMemSize = size;
   }
}


int UtPod::addSong(Song const &s){
   // check if there is enough memory
   if(s.getSize() > remainingMem){
      cout << "Not enough space for song\n";
      return -1;
   }
   // adds the song otherwise
   else{
      SongNode *temp = new SongNode;	// allocates SongNode
      cout << "allocation successful" << endl;

      temp->song = s;
      temp->next = songs;   // songs is the head pointer
      songs = temp;

      cout << "song successfully added\n";
      return 0;
   }
}


int UtPod::removeSong(Song const &s){
   return 1;
}


void UtPod::shuffle(){
   return;
}

void UtPod::showSongList(){
   if(songs == NULL){
      return;
   }
   else{
      SongNode *temp = songs;	// pointer to traverse linked list
      while(temp){
         cout << temp->song.getTitle() << ", ";
	 cout << temp->song.getArtist() << ", ";
	 cout << temp->song.getSize() << endl;
         
	 temp = temp->next;
      }
   }
}

void UtPod::sortSongList(){
   return;
}

void UtPod::clearMemory(){
   return;
}

int UtPod::getRemainingMemory(){
   return 1;
}

UtPod::~UtPod() = default;
