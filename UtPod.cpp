// Jimmy Phan
//
#include "UtPod.h"
#include "Song.h"
#include <iostream>
using namespace std;


// Default Constructor
// sets memory size to MAX
UtPod(){
   popMemSize = MAX_MEMORY;
   songs = NULL;
}


// Constructor with size parameter
UtPod(int size){
   if(size > 512 || size < 0){
      popMemSize = MAX_MEMORY;
   }
   else{
      popMemSize = size;
   }
}


int addSong(Song const &s){
   // check if there is enough memory
   if(s.getSize() > popMemSize){
      cout << "Not enough space for song\n";
      return -1;
   }
   // adds the song otherwise
   else{
      SongNode *temp;
      temp->sg = s;
      temp->next = songs;   // songs is the head pointer
      songs = temp;

      return 0;
   }
}


int removeSong(Song const &s){
   return 1;
}


void shuffle(){
   return;
}


void sortSongList(){
   return;
}


void clearMemory(){
   return;
}


int getTotalMemory{
   return 1;
}


int getRemainingMemory(){
   return 1;
}


