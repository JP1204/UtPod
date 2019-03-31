// Jimmy Phan
//

#include "Song.h"
#include <string.h>
#include <iostream>
using namespace std;

// Default Constructor for Song Class

Song::Song(){
   // creates empty strings by default
   title = new string();
   artist = new string();
   size = 0;
}


/* Constructor for Song Class
 * Input: title(string), artist(string), and size(int) in MB
*/

Song::Song(char const *titl, char const *art, int siz){
   strcpy(title, titl);
   strcpy(artist, art);
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

