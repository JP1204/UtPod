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

      temp->song = s;
      temp->next = songs;   // songs is the head pointer
      songs = temp;

      return 0;
   }
}


int UtPod::removeSong(Song const &s){
   SongNode *temp = songs;
   SongNode *prev = NULL;
   int removeSuccess = -1;

   while(temp){
      if(temp->song == s){
         // remove song if there is a match
         if(prev == NULL){
            // remove the first song in the list
            SongNode *delSong = temp;
	    delete delSong;	// frees up SongNode
	   
	    removeSuccess = 0;
	    songs = temp->next;	// updates head pointer
	    temp = NULL; // breaks out of loop once song is found  
	 }
	 else{
            prev->next = temp->next;
	    SongNode *delSong = temp;
	    delete delSong;

	    removeSuccess = 0;
	    temp = NULL; 
	 }
      }
      else{
	 // increment pointers
         prev = temp;
	 temp = temp->next;
      }
   }

   return removeSuccess;
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
