// Jimmy Phan
//
#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>
using namespace std;


class Song{
   private:
      string title;
      string artist;
      int size;   // can only have positive size
   public:
      Song();   // Default Constructor 
      Song(string titl, string art, int siz);
      Song(const Song &s);	// copy constructor

      // setters
      void setTitle(string titl)
         { title = titl; }
      void setArtist(string artis)
         { artist = artis; }
      void setSize(int siz);

      // getters
      string getTitle() const
         { return title; }
      string getArtist() const
         { return artist; }
      int getSize() const
         { return size; }
      
      ~Song();	// Default destructor

      void operator = (Song const &rhs);
      bool operator > (Song const &rhs);
      bool operator < (Song const &rhs);
      bool operator == (Song const &rhs);	      
};

#endif	   
