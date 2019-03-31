// Jimmy Phan
//

#include "Song.h"
#include <string>
#include <iostream>
using namespace std;


// Default Constructor for Song Class

Song::Song(){
   // creates empty strings by default
   title = "";
   artist = "";
   size = 0;
}


/* Constructor for Song Class
 * Input: title(string), artist(string), and size(int) in MB
*/
Song::Song(string titl, string art, int siz){
   title = titl;
   artist = art;
   size = siz;
}


Song::setSize(int siz){
   if(siz >= 0){
      size = siz;
   }
   else{
      cout << "Invalid size\n";
      exit(EXIT_FAILURE);
   }
}

