// Jimmy Phan
//
#include "UtPod.h"
#include <stdlib.h>
#include <iostream>
using namespace std;


// Default Constructor
// sets memory size to MAX
UtPod::UtPod(){
   podMemSize = MAX_MEMORY;
   songs = NULL;
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
   if(s.getSize() > getRemainingMemory()){
      cout << "Not enough space for song\n";
      return -1;
   }
   // adds the song otherwise
   else{
      SongNode *temp = new SongNode;	// allocates SongNode

      temp->song = s;
      temp->next = songs;   // songs is the head pointer
      songs = temp;

      return 0;		// successful add
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
            songs = temp->next;	// updates head pointer

            // remove the first song in the list
            SongNode *delSong = temp;
	    delete delSong;	// frees up SongNode
	   
	    removeSuccess = 0;
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
   srand(time(NULL));	// seeds the random number generator

   // perform numSongs amount of swaps to shuffle
   for(int i = 0; i < numSongs(); i++){
      int n = rand() % numSongs();
      int k = rand() % numSongs();

      SongNode *p1 = songs;
      SongNode *p2 = songs;
     
      for(int j = 0; j < n; j++){
         // traverse to the nth song
	 p1 = p1->next;
      }
      for(int j = 0; j < k; j++){
	 // traverse to the kth song
	 p2 = p2->next;
      }
 
      swapSongs(p1, p2); 
   }
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
   for(SongNode *p = songs; p != NULL; p = p->next){
      // insertion sort
      SongNode *smallestSong = p;

      for(SongNode *p2 = p->next; p2 != NULL; p2 = p2->next){
         if(p2->song < smallestSong->song){
            smallestSong = p2;	// iterates through and finds the smallest song
	 }
      }
      
      swapSongs(p, smallestSong); 
   }         
}


void UtPod::clearMemory(){
   // free up all the SongNodes
   SongNode *temp = songs;

   while(temp){
      SongNode *delSong = temp;
      temp = temp->next;

      delete delSong;
   }

   songs = NULL;
}


int UtPod::getRemainingMemory(){
   int memoryUsed = 0;
   int memoryRemaining;

   // traverse the nodes and add the sizes of all the songs
   for(SongNode *temp = songs; temp != NULL; temp = temp->next){
      memoryUsed += temp->song.getSize();
   }

   memoryRemaining = podMemSize - memoryUsed; 
}


void UtPod::swapSongs(SongNode *p1, SongNode *p2){
   Song tempSong = p1->song;

   p1->song = p2->song;
   p2->song = tempSong;
}


int UtPod::numSongs(){
   int num = 0;
   SongNode *temp = songs;

   while(temp){
      num++;
      temp = temp->next;
   }

   return num;
}


UtPod::~UtPod(){
   clearMemory();
}

