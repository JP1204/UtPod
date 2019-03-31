// Jimmy Phan
//
#ifndef SONG_H
#define SONG_H
#include <string>
using namespace std;


class Song{
   private:
      string title;
      string artist;
      unsigned int size;   // can only have positive size
   public:
      Song();   // Default Constructor 
      Song(string &titl, string &art, int siz);

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
};

#endif	   
