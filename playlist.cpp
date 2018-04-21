//playlist.cpp
#include <iostream>
#include <stdlib.h>     
#include "playlist.h"
using namespace std;

// make an empty list
playlist::playlist() {
    head = NULL;
    tail = NULL;
}

// delete the list
playlist::~playlist() {
    // remove first one until there is no first one
    while(head != NULL) {
        remove(head->s);
    }
}


// copy constructor
playlist::playlist(const playlist& other) {
    Node* current = other.head;
    head = tail = NULL;
    while(current != NULL) {
        addAtEnd(current->s);
        current = current->next;
    }
}


// assignment operator
playlist& playlist::operator=(const playlist& other) {
    // clear the list
    while(head != NULL) {
        remove(head->s);
	}

    // copy over the other
    Node* current = other.head;
    head = tail = NULL;
    while(current != NULL) {
        addAtEnd(current->s);
        current = current->next;
    }

    return *this;
}

// add an element to the start
void playlist::addAtStart( const song& s) {
    // make the node
    Node* node = new Node;
    node->s = s;
    node->prev = NULL;

    // if head is NULL, it's the ONLY one
    if(head == NULL) {
        head = node;
        tail = node;
        node->next = NULL;
    } else {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

// add an element to the end
void playlist::addAtEnd(const song s) {
    // make the node
    Node* node = new Node;
    node->s = s;
    node->next = NULL;

    // if tail is NULL, it's the ONLY one
    if(tail == NULL) {
        head = node;
        tail = node;
        node->prev = NULL;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
}

// remove an element
void playlist::remove(song& s) {
    // find the node with our number
    Node* current = head;

    while(current != NULL) {
        if(current->s == s) {
            // FOUND IT

            // if the previous is NULL, we are removing head!
            if(current->prev == NULL) {
                head = current->next;
                if(head != NULL) {
                    head->prev = NULL;
                } else {
                    tail = NULL;
                }
            } else {
                // point previous's next pointer at the one after current
                current->prev->next = current->next;

                // also point next's previous pointer to current's prev
                if(current->next != NULL) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }
            }

            // delete node
            delete current;

            // return
            return;
        }

        current = current->next;
    }

    // if we got here we didn't find it!
    cout << s << " was not found in the list!" << endl;
}


// print the list Forward
void playlist::printForward() const {
    // the node we are currently on
    Node* current = head;

    // while we're not at the end
    while(current != NULL) {
        // print the data portion
        cout << current->s << endl;

        // move onto the next one
        current = current->next;
    }

    cout << endl << endl;
}

// print the list Backward
void playlist::printBackward() const {
    // the node we are currently on
    Node* current = tail;

    // while we're not at the start
    while(current != NULL) {
        // print the data portion
        cout << current->s << endl;

        // move back to the previous one
        current = current->prev;
    }

//    cout << endl << endl;
}
//returns the number of songs in a playlist
int playlist::count(){

	Node* current = head;
	int count = 0;
	//while there are songs in the playlist, add one to count
	while(current != NULL){
		current = current->next;
		count = count + 1;
	}
	return count;
}

//shuffles the list
void playlist::shuffle(){
	playlist shuffle;
	int amount;
	amount = this->count();
	
	//if the songs in a plylist are less than 2, shuffle can't be done
	if(amount < 2 ){
		cout << "There are not enough songs in your playlist to shuffle \n"; 
	}

	Node* current = head;

	while(amount > 0) {
		//getting a random number based on the amount of songs
		int r = rand()%amount;

		for(int i=0; i<r; i++){
			current = current->next;
		}
		shuffle.addAtEnd(current->s);

		//songs that have been added to the new playlist, are removed so the won't be added again
		remove(current->s);
		amount--;
		current = head;
	}

		//the new playlist is returned
		*this=shuffle;
		}

