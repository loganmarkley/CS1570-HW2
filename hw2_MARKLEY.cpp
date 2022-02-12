//Programmer: Logan Markley
//Student ID: 12579435
//MST Username: lcmkbc
//Instructor Name: San Yeung
//Section: 109
//Date: 2/5/22
//File: hw2 MARKLEY.cpp
//Purpose: Recreate the game "WORDLE" in C++ (HW 2)


#include <iostream>
#include <string>
#include <ctype.h>
#include <stdio.h>
using namespace std;

int main()
{
    //---------variable declaration----------------------------------------
    
    string player1name;
    string player2name;
    
    string p1word;
    string p2guess;
    
    int friendshipLevel=-1;
    
    int attemptCount=1;
    
    bool rematch = false;     //these variables deal with the replaying and start of the game
    bool newPlayer2 = true;
    
    //------------introduction---------------------------------------------
    
    
    cout << "Welcome to Wordle!" <<endl <<"Player 1's name: ";
    cin >> player1name;
    
    do
    {
        attemptCount=1; //resets the attempt counter after each game
        if(newPlayer2==true) //gets a new player 2 and friendship level if player 1 wants
        {
            cout << "Player 2's name: ";
            cin >> player2name;
            
            friendshipLevel=-1; //resets the friendshipLevel when changing characters
            while(friendshipLevel<0 || friendshipLevel>100)    //this while loop is to make sure that the friendship level is a valid number
            {
                cout << player1name<<", what is your friendship level with "<<player2name<<"? (integer value in [0, 100]): ";
                cin >> friendshipLevel;
                if(friendshipLevel<0 || friendshipLevel>100)
                    cout << "That friendship level is not a valid entry." <<endl;
            }
            cout << "Thanks! Let's begin.";
        }
    
    
    //-----start of the game------------------------------------------------------------------------------------------------------------------------
    
    
        bool fiveLetters = false;  //these two variables must be turned true in order to continue the game
        bool alphabetical = false;
        while(fiveLetters==false || alphabetical==false)
        {
            cout <<endl<< player1name<<", enter your word: ";
            cin >> p1word;
        
            if(p1word.length()==5)  //this if else is to make sure that the word is 5 letters
                fiveLetters=true;
            else
                fiveLetters=false;
        
            alphabetical=true;                  //sets alphabetical to true     
            int len = p1word.length();
            for(int i=0; i<len;i++) //this for loop is to make sure that all characters are alphabetical
            {
                if(isalpha( p1word.at(i) )==0)  //changes alphabetical to false if non-alphabetic characters are detected
                    alphabetical=false;
            }
            if(alphabetical==false)
                cout << "That word contains non-alphabetic characters! ";
            if(fiveLetters==false)
                cout << "That word is not 5 letters long!";
        }
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl; //creates a big break so that player 2 cannot see the word.
    
    
        //-------guessing part of the game-------------------------------------------------------------------------------------------------------
    
    
        bool guessingFinished=false; //this variable would be turned to true if the word is guessed.
        while(attemptCount<7 && guessingFinished==false)   
        {
            fiveLetters = false;  //this segment of code is the same format as before. used to make sure player 2 enters a 5 letter word.
            alphabetical = false;
            while(fiveLetters==false || alphabetical==false)
            {
                cout <<endl<< player2name<<", this is attempt #"<<attemptCount<<". What word will you guess? ";
                cin >> p2guess;
        
                if(p2guess.length()==5)  //this if else is to make sure that the word is 5 letters
                    fiveLetters=true;
                else
                    fiveLetters=false;
        
                alphabetical=true;                  //sets alphabetical to true   
                int len=p2guess.length();
                for(int i=0; i<len; i++) //this for loop is to make sure that all characters are alphabetical
                {
                    if(isalpha( p2guess.at(i) )==0)  //changes alphabetical to false if non-alphabetic characters are detected
                        alphabetical=false;
                }
                if(alphabetical==false)
                    cout << "That word contains non-alphabetic characters! ";
                if(fiveLetters==false)
                    cout << "That word is not 5 letters long!";
            }
        
        
            if(p1word==p2guess)
            {
                cout << "You entered \"" <<p2guess<< "\". Great job! You got it in "<<attemptCount<<" tries!" <<endl;
                guessingFinished=true;
            }
            else if(attemptCount==6)
                cout << "You entered \"" <<p2guess<< "\"." <<endl;
            else
                cout << "You entered \"" <<p2guess<< "\". Nice try, keep going!" <<endl;
            bool skipLetter=false;   //this variable is used to prevent the searching from going more than needed
            int len=p2guess.length();
            int len2=p1word.length();
            for(int i=0; i<len; i++) //this for loop and nested for loop are used to compare the letters of the words.
            {
                skipLetter=false;
                for(int j=0; j<len2; j++)
                {
                
                    if( p1word.at(j)==p2guess.at(i) && i==j && skipLetter==false)
                    {
                        cout << p2guess.at(i) << ": ^o^" <<endl;
                        skipLetter=true;
                    }
                    else if( p1word.at(j)==p2guess.at(i) && skipLetter==false)
                    {
                        cout << p2guess.at(i) << ": ^('-')^" <<endl;
                        skipLetter=true;
                    }
                    else if( p1word.at(j)!=p2guess.at(i) && j==len2-1 && skipLetter==false)  //at the last search, concludes the letter is not correct
                    {
                        cout << p2guess.at(i) << ": @.@" <<endl;
                        skipLetter=true;
                    }
                }
            }
            if(guessingFinished==false)
                attemptCount++;
        
        }
    
    
        //-------end results part of the game-----------------------------------------------------------------------------------------------


        if(guessingFinished==false)
            cout<<"Aww! You didn't get the word! :(";
        if(attemptCount==7)  //these if statements change friendship level depending on how many tries it took player 2.
        {
            cout<<"Friendship Level did not change! It is still " <<friendshipLevel;
        }
        else if(attemptCount==6)
        {
            if(friendshipLevel<95)
            {
                friendshipLevel+=6;
                cout<<"Friendship Level increased by 6! It is now " <<friendshipLevel;
            }
            else
            {
                friendshipLevel=100;
                cout<<"Friendship Level is now 100!";
            }
        }
        else if(attemptCount==5)
        {
            if(friendshipLevel<96)
            {
                friendshipLevel+=5;
                cout<<"Friendship Level increased by 5! It is now " <<friendshipLevel;
            }
            else
            {
                friendshipLevel=100;
                cout<<"Friendship Level is now 100!";
            }
        }
        else if(attemptCount==4)
        {
            if(friendshipLevel<97)
            {
                friendshipLevel+=4;
                cout<<"Friendship Level increased by 4! It is now " <<friendshipLevel;
            }
            else
            {
                friendshipLevel=100;
                cout<<"Friendship Level is now 100!";
            }
        }   
        else if(attemptCount==3)
        {
            if(friendshipLevel<98)
            {
                friendshipLevel+=3;
                cout<<"Friendship Level increased by 3! It is now " <<friendshipLevel;
            }
            else
            {
                friendshipLevel=100;
                cout<<"Friendship Level is now 100!";
            }
        }
        else if(attemptCount==2)
        {
            if(friendshipLevel<99)
            {
                friendshipLevel+=2;
                cout<<"Friendship Level increased by 2! It is now " <<friendshipLevel;
            }
            else
            {
                friendshipLevel=100;
                cout<<"Friendship Level is now 100!";
            }
        }
        else
        {
            if(friendshipLevel<100)
            {
                friendshipLevel+=1;
                cout<<"Friendship Level increased by 1! It is now " <<friendshipLevel;
            }
            else
            {
                friendshipLevel=100;
                cout<<"Friendship Level is now 100!";
            }
        }
        cout<<endl;
        
        //-----------the remaking part of the game------------------------------------------------------------------------------
        
        
        rematch=false;
        newPlayer2=false;
        
        string rematchCheck;        //this block checks if player 1 and player 2 want to start a new round with the same friendship
        bool loopBackOuter=false;
        do
        {
            loopBackOuter=false;
            cout << player1name<<" and "<< player2name<< ", do you want to start a new round? (YES/NO): ";
            cin >> rematchCheck;
            if(rematchCheck=="YES")
                rematch=true;
            else if(rematchCheck=="NO")
                rematch=false;
            else
            {
                loopBackOuter=true;
                cout<<"Invalid entry!"<<endl;
            }
        } while(loopBackOuter==true);
        
        string newPlayer2Check;     //this block asks player1 if they want to start a new game with a different player2
        bool loopBackInner=false;
        if(rematch==false)
        {
            do
            {
                loopBackInner=false;
                cout << player1name<<", so do you want to start a new round with a different Player 2? (YES/NO): ";
                cin >> newPlayer2Check;
                if(newPlayer2Check=="YES")
                    newPlayer2=true;
                else if(newPlayer2Check=="NO")
                {
                    cout<<"OK! Goodbye, "<<player1name<<"! See you soon!"<<endl;
                    newPlayer2=false;
                }
                else
                {
                    loopBackInner=true;
                    cout<<"Invalid entry!"<<endl;
                }
            }
            while(loopBackInner==true);
        }
    } while(rematch==true || newPlayer2==true);
    
return 0;
}
