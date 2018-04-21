#include "playlist.h"
#include "song.h"
#include <iostream>
using namespace std;


int main(){
	playlist playlist1;

	cout << "\n";
	cout << "\n";
	cout << "*************PLAYLIST MANAGER************* \n";
	
	cout << "** ONLY ENTER THE LETTER CORRESPONDING TO THE ACTION YOU WANT ** \n ";

	//print out commands, only chars are used as options
	cout<< "Commands: \n" << "[a]dd \n" << "[r]emove \n" << "[c]ount \n" << "[p]lay \n" << "[s]huffle \n" << "[q]uit \n";

	bool choice = true;
	while(choice){
		choice = true;
		//making empty arrays for song objects
		char t[100];
		char a[100];
		char t2[100];
		char a2[100];
		song s2;

		//asking user for input
		cout << "Enter a command: ";
		char  choose;
		cin >> choose;
		if(choose == 'q'){
			cout << "BYE BYE \n";
			return false;
		}
	   //based on input, an action takes place
		if(choose == 'a'){
			cout << "Enter the song title: ";
			cin.ignore();
			cin.getline(t,100);
			cout << "Enter the name of the artist: ";
			cin.getline(a,100);
			song *s = new song(t,a);
			playlist1.addAtEnd(*s);

		}
		if(choose == 'r'){
			cout << "Enter the song title: ";
			cin >>t2 ;
			cout << "Enter the name of the artist: ";
			cin >>a2;
			s2.setTitle(t2);
			s2.setArtist(a2);
			playlist1.remove(s2);
				
		}
		if(choose == 'c'){
			cout << playlist1.count() << "\n";
		}
		if(choose == 'p'){
			playlist1.printBackward();
		
		}
	   
		if(choose == 's'){
			playlist1.shuffle();
		}

	}

}
