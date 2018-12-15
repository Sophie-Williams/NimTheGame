//////////////////////
//Nim game source code
//By Terry and Tom
//Algorithms Project Fall 2018
//////////////////////
#include <iostream>
#include <random>
using namespace std;

template <typename T>
T safeCin(){//Safe Cin function resricts users to only acceptable user inputs
    T n;
    cin >> n;         
    while (cin.fail())//keep asking for good inputs until user does it right
    {
        cin.clear();
        cin.ignore();
        cout << "Bad Input, try again";
        cin >> n;
    }
    cin.clear();
    cin.ignore();
    return n;
}

int computerTurn(int heap, int maxHand){//computer takes turn
    if(maxHand >= heap)return heap;//if computer can take all the items, do it
    if(heap % (maxHand+1) == 0)return rand()%(maxHand-1) + 1;//if computer is put in the state its going to lose, just take a random value
    return (heap % (maxHand+1) );//if computer is in this state its going to win, take proper number of pieces
}

/////////////////////////////////////////////////////////////
///
/// This function is supposed to guess who should have won the game
/// depening on which player goes first, either the computer or the human wins.
///
/////////////////////////////////////////////////////////////

//called in main
void whoShouldHaveWon(int initialHeap, int maxHand, bool userStarted) {
	                    // if userStarted is true then enter in if
	if (userStarted) {

		// it checks on the inital conditions... if the initialHeap is divisible by the (maxHand +1) and it equals 0 or if the initalHeap is less than or equal to the maxhand then
		if (initialHeap % (maxHand + 1) == 0 || initialHeap <= maxHand) {    // check condition and to display
			cout << "Based on initial conditions, human should have won!" << endl;   //display
		}
		else
		{
		   cout << "Based on initial conditions, computer should have won!" << endl;    //display
		}
	}
	else
	{
		// it checks on the inital conditions... if the initialHeap is divisible by the (maxHand +1) and it equals 0 or if the initalHeap is less than to the maxhand then
		if (initialHeap % (maxHand + 1) == 0 && initialHeap < maxHand) {
			cout << "$$Based on initial conditions, computer should have won!" << endl;    //display
		}
		else
		{
			cout << "$$Based on initial conditions, human should have won!" << endl;       //display
		}


	}
}

void play(){//function to play a full game of nim
        int heap,maxHand;
        cout << "Choose a heap size: "; 
        heap = safeCin<int>(); // take input and place in heap
        int initialHeap = heap;
        cout << endl << "Choose a max hand size: ";
        maxHand =safeCin<int>();  //takes input and place in maxhand
        bool userStarted = false;  //declare boolean variable and initialize with false
        char response;
        cout << "Would you like to go first>: ('y' or 'n')" << endl;
        response = safeCin<char>();  // takes input and place in response
        if(response == 'y') userStarted = true;  // checks response, if it is 'y' update userStarted to true
        int userHand,computerHand;

        if(!userStarted){ //userStarted is false then it enter in the if condition
            computerHand = computerTurn(heap,maxHand); //calls the computerTurn Function adn return value stor in computerHand
            heap -= computerHand;
            cout << endl << "Computer took " << computerHand << " from pile." << endl;
            cout << "There are " << heap <<" items left in heap." << endl;
            if(heap <= 0){ // checks if heap is <= 0 then it enters in the if condition
                cout << "THE COMPUTER WON."<< endl;
                whoShouldHaveWon(initialHeap, maxHand, userStarted); //call whoShouldHaveWon function
                return;
            }
        }

        while(true){ //infinite loop it only exist when it reached to return
            cout << endl << "Choose a number between 1 and " << maxHand << " to take from pile: ";
            userHand = safeCin<int>();  //take input from user 
            if(userHand > maxHand || userHand < 1){  // checks if the userHand is greater than maxHand or smaller that 1 
                cout << "CHEATER! You can't take " << userHand << " amount of items."; //displays that the user has made an illegal move
                return;
            }
            heap -= userHand;
            if(heap <= 0){  // checks conidition if heap <= 0
                cout << endl;
                cout << "YOU WON! "<< endl;
                whoShouldHaveWon(initialHeap, maxHand, userStarted); // calls the whoShouldHaveWon Function 
                return;
            }
            cout << "There are now " << heap << " items in heap. " << endl; // displays the amount of items left in the heap
            cout << endl;
            computerHand = computerTurn(heap,maxHand);  // calls the computerTurn Function
            heap -= computerHand;
            cout << "Computer took " << computerHand << " from pile. There are " << heap <<" items left in heap." << endl;
            if(heap <= 0){
                cout << endl << "THE COMPUTER WON."<< endl;
                whoShouldHaveWon(initialHeap, maxHand, userStarted); // calls the whoShouldHaveWon Function 
                return;
            }
        }

}


int main(){
    char response = 'y';
    while (response == 'y'){//loop so that user can choose to try again
        cout <<
    "--------------------------Let's Play----------------------------" << endl <<
    "---OOOOOO-----OOOO-----OOOOOOOOOOOOOOOO------OOOOOOO----OOOOOO---" << endl <<
    "---OOOOOOOO---OOOO-----OOOOOOOOOOOOOOOO------OOOOOOOO--OOOOOOO---" << endl <<
    "---OOOO-OOOO--OOOO------------OOO------------OOO-OOOOO-OOO-OOO---" << endl <<
    "---OOOO--OOOO-OOOO------------OOO------------OOO---OOOOOO--OOO---" << endl <<
    "---OOOO---OOOOOOOO------------OOO------------OOO-----OO----OOO---" << endl <<
    "---OOOO-----OOOOOO-----OOOOOOOOOOOOOOOO------OOO-----------OOO---" << endl <<
    "---OOOO-------OOOO-----OOOOOOOOOOOOOOOO------OOO-----------OOO---" << endl <<
    "-----------------------------------------------------------------" << endl;
        
        play();

        cout << endl << "Try again?('y' or 'n')";
        response =safeCin<char>();//let user choose to try again
    }
    cout << "Goodbye!";
}