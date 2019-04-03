/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"
using namespace std;


int main(int argc, char *argv[])
{
    UtPod t;
    
    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;
    
    t.showSongList();
    // testing copy constructor
    Song copySong = s1;
    result = t.addSong(copySong);
    cout << "result = " << result << endl;

    if(copySong == s1){
	cout << "the copy constructor worked\n";
    }


    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;
    
    t.showSongList();
       
    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;
       
    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;
       
    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "After the sort: " << endl;
cout << "After sorting" << endl;
    t.sortSongList();
    t.showSongList();

// shuffling
cout << "shuffle 1 " << endl;
    t.shuffle();
    t.showSongList();
cout << "shuffle 2 " << endl;
    t.shuffle();
    t.showSongList();
cout << "shuffle 3 " << endl;


    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;
  
    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();
    
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;
 
    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;
    
    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;
    
    
    t.showSongList();
    
    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
 cout << "clearing memory" << endl;  
    t.clearMemory();
    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    t.shuffle();
    t.shuffle();

    t.~UtPod();	// destroying UtPod

    UtPod t2(400);
    UtPod t3(550);	// should initialize at 512 MB

    cout << "size of UtPod t2 = " << t2.getTotalMemory() << endl;
    cout << "size of UtPod t3 = " << t3.getTotalMemory() << endl << endl;

    Song s6("Love Story", "Taylor Swift", 45);
    cout << "got here" << endl;
    result = t2.addSong(s6);
    cout << "add result = " << result << endl;

    cout << s6.getTitle() << ", " << s6.getArtist() << ", " << s6.getSize() << endl;
    
    Song s7("Right Above It", "Lil Wayne", 64);
    Song s8("Cooler Than me", "Mike Posner", 423);	// this should fail to add
    Song s9("Headlines", "Drake", 81);
    Song s10("Just a Dream", "Nelly", 56);

    t2.addSong(s7);
    result = t2.addSong(s8);
    cout << "This song is too large - result = " << result << endl << endl;

    t2.addSong(s9);
    t2.addSong(s10);
    
    t2.showSongList();
    cout << endl;
    
    cout << "Song List after shuffling\n\n";
    t2.shuffle();
    t2.showSongList();

    cout << endl;

    cout << "Song List after sorting\n\n";
    t2.sortSongList();
    if(s6 > s7)
	    cout << "The operator works\n";
    t2.showSongList();
    cout << endl;

    cout << "remaining Memory = " << t2.getRemainingMemory();
    
    t2.removeSong(s6);
    t2.removeSong(s7);
    t2.removeSong(s8);
    t2.removeSong(s9);
    t2.removeSong(s10);

    return 1;
}
