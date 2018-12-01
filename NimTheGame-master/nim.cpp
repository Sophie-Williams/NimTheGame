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

void whoShouldHaveWon(int initialHeap,int maxHand, bool userStarted){//TERRY BUILD THIS FUNCTION TO COUT ANSWER
    cout << "Ask Terry. IDK..." << endl;
}

void play(){//function to play a full game of nim
    int heap,maxHand;
        cout << "Choose a heap size:";
        heap = safeCin<int>();
        int initialHeap = heap;
        cout << endl << "Choose a max hand size:";
        maxHand =safeCin<int>();
        bool userStarted = false;
        char response;
        cout << "Would you like to go first>: ('y' or 'n')" << endl;
        response = safeCin<char>();
        if(response == 'y') userStarted = true;
        int userHand,computerHand;

        if(!userStarted){
            computerHand = computerTurn(heap,maxHand);
            heap -= computerHand;
            cout << "Computer took " << computerHand << " from pile. There are " << heap <<" items left in heap." << endl;
            if(heap <= 0){
                cout << "The computer won."<< endl;
                whoShouldHaveWon(initialHeap, maxHand, userStarted);
                return;
            }
        }

        while(true){
            cout << "Choose a number between 1 and " << maxHand << " to take from pile: ";
            userHand = safeCin<int>();
            if(userHand > maxHand || userHand < 1){
                cout << "CHEATER! You cant take " << userHand << " amount of items.";
                return;
            }
            heap -= userHand;
            if(heap <= 0){
                cout << "You won!"<< endl;
                whoShouldHaveWon(initialHeap, maxHand, userStarted);
                return;
            }
            cout << "There are now " << heap << "items in heap." << endl;
            computerHand = computerTurn(heap,maxHand);
            heap -= computerHand;
            cout << "Computer took " << computerHand << " from pile. There are " << heap <<" items left in heap." << endl;
            if(heap <= 0){
                cout << "The computer won."<< endl;
                whoShouldHaveWon(initialHeap, maxHand, userStarted);
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