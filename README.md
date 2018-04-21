# Data-Structures-and-Algorithm-PlayList

Assignment 3 - Playlist


Due: March 3

Objective

To be able to use and manipulate linked lists, work with programs consisting of multiple files, and gain experience with menu-driven programs.
Task

You are to write a program for managing a playlist of songs. A playlist is simply a list of songs - for this assignment it will be implemented as a doubly linked list. Each song contains two pieces of information: the title and the artist who performs it; each will be stored as strings.

Your program must support the following features:

Add a song to the playlist.
Remove a song from the playlist.
Print the number of songs in the playlist.
“Play” the playlist. For our purposes, this will mean just printing out the songs from first to last.
Shuffle the list. You can do this any way you want so long as the list changes each time, and doesn’t change the exact same way. The shuffling should not be easily predictable.
Quit.
A sample run of such a program can be seen here.
Details

Start by downloading a copy of the DoubleList class files: doublelist.h and doublelist.cpp.
You should then rename them as playlist.h and playlist.cpp respectively and rename the class as well.
You will need to create a Song class for storing song objects. It will need to store the artist and title, and contain whatever member functions are needed to work with the songs. You should store the title and artist as arrays of 100 characters. This should be done in files called song.h and song.cpp.
Then you will have to modify the Playlist class so that it stores Song objects instead of integers. To do this, you will need to replace the “int data” field inside of the node with a Song object.
Your program should also have a main function inside of a file called main.cpp. You can use this makefile to compile your program.
The main function will create a playlist object and provide a menu for the user to operate on the playlist. You can use any format for the commands you want, but should print out a message at the start of the program describing how to use it.
In order to implement the “count” feature, you will have to add a function to the doubly linked list class that counts the nodes in the list.
In order to implement the “shuffle” feature, you will have to add a function that rearranges the nodes in the list pseudo-randomly. In C++, you can call the function “rand” which returns random integers. Remember that you can call the other member functions (such as addAtStart, addAtEnd, and remove) inside of any other function in a class.
Your program must accept song titles and artists that have spaces in them. You can use cin.getline to accomplish this. All artist and title names will be limited to 100 characters.
Just For Fun

If you want to export your playlists so you can listen to them, you can paste the output of the “play” command into this website: playlist-converter.net which can export them to services including Spotify and YouTube.

General Requirements

No global variables other than constants.
All member data of a class must be private.
Your source code should be readable and reasonably indented.
You must provide comments in your code.
Member functions that don’t change a classes member data should be marked as const.
