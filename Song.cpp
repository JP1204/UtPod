// Jimmy Phan
//

#include "Song.h"
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


// Copy Constructor

Song::Song(const Song &s){
   title = s.title;
   artist = s.artist;
   size = s.size;
}


void Song::setSize(int siz){
   if(siz >= 0){
      size = siz;
   }
   else{
      cout << "Invalid size\n";
      exit(EXIT_FAILURE);
   }
}


// Overloaded operators
void Song::operator = (Song const &rhs){
   title = rhs.title;
   artist = rhs.artist;
   size = rhs.size;
}


bool Song::operator > (Song const &rhs){
   if(title > rhs.title){
      return true;
   }
   else if(title == rhs.title){
      if(artist > rhs.artist){
         return true;
      }
      else if(artist == rhs.artist){
         if(size > rhs.size){
            return true;
	 }
      }
   }

   return false;

}


bool Song::operator < (Song const &rhs){
   if(title < rhs.title){
      return true;
   }
   else if(title == rhs.title){
      if(artist < rhs.artist){
         return true;
      }
      else if(artist == rhs.artist){
         if(size < rhs.size){
            return true;
	 }
      }
   }

   return false;
}

bool Song::operator == (Song const &rhs){
   return(
      (title == rhs.title) &&
      (artist == rhs.artist) &&
      (size == rhs.size)
   );
}


// Default destructor
Song::~Song() = default;
