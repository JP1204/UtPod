// Jimmy Phan
//
#include "UtPod.h"
#include "Song.h"
#include <iostream>
using namespace std;


// Default Constructor
// sets memory size to MAX
UtPod::UtPod(){
   podMemSize = MAX_MEMORY;
   remainingMem = MAX_MEMORY;
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
   if(s.getSize() > podMemSize){
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


int UtPod::removeSong(Song const &s){
   return 1;
}


void UtPod::shuffle(){
   return;
}


void UtPod::sortSongList(){
   return;
}


void UtPod::clearMemory(){
   return;
}

