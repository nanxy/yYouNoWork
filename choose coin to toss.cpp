//============================================================================
// Name        : hw3.cpp
// Author      : Nancy Zhou
// Version     : 1.25- realized that separate Coin classes were not needed.
//               1.2- lines are added between each toss for better user visibility,
//                    grammar is corrected: Uppercase first words, punctuation.
//               1.0- decorative game over screens are added, fixed bug where the score
//                    was not reset after each play-through
//               0.8- NOTE '' single notation is for char,"" for string, actual numbers
//                    for double or int. fixed <$1.00 statements.
//               0.65- fixed if statement for adding coin value to score even when the
//                     result was tails (if statement always ran)
//               0.5- code was written and altered header file to not print anything.
// Copyright   : dfasdfasdfas stealing is bad plz respek
// Description : This is a coin toss game where the player is heads and the
//               bot is tails. The player needs exactly $1.00 to win.
/*INSTRUCTIONS:
For this assignment, you will create a game program using the Coin class from
Programming Challenge 12. The program should have three instances of the Coin
class: one representing a quarter, one representing a dime, and one
representing a nickel. When the game begins, your starting balance is $0.
During each round of the game, the program will toss the simulated coins.
When a coin is tossed, the value of the coin is added to your balance if
it lands heads-up. For example, if the quarter lands heads-up, 25 cents is
added to your balance. Nothing is added to your balance for coins that land
tails-up. The game is over when your balance reaches $1 or more. If your
balance is exactly $1, you win the game. You lose if your balance exceeds $1.*/
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>// for setpresicion
#include "Coin.h"
using namespace std;

/**==============================================================
                    Main
==============================================================**/
int main()
{
    char choice;
    double score=0.00;
    Coin useMe;
    //Coin dime;
    //Coin quarter;
    cout<< "This is a game where you toss a coin and if it's head side up, you get that amount."<<endl;
    cout<<" If you reach exactly $1.00, you win! But if you go over, then I win. Ready?"<<endl;
    cout<<" You may quit by inputting '#'"<<endl;
    cout<<"-------------------------------------------------------------------------------"<<endl;
    //end of the welcome screen message
    do
    {
        cout<<" Choose your coin:'d','n', or 'q'?"<< endl;
        cin>>choice;// holds the user input
        if (score<1.0)
        {
            switch(choice)//runs only if score is less than 1
            {

            case 'd'://this statement runs when the user wants to flip a dime.
                useMe.GetsideUp();
                if (useMe.toss("val"))
                {
                    score+=.10;
                    cout<< "Heads"<<endl<<" success, your balance is $"<<score<<setprecision (4)<<endl;
                    cout<<"------------------------------------------------------------"<<endl;
                    break;
                }
                else
                    cout<<"Tails."<<endl<< score<<setprecision (4)<<" oops,try again " <<endl;

                break;
            case 'n'://this statement runs when the user wants to flip a nickel.
                useMe.GetsideUp();

                if ( useMe.toss("val"))
                {
                    score+=.05;
                    cout<< "Heads."<<endl<< "nice, you now have $"<<score<<setprecision (4)<<endl;
                    cout<<"------------------------------------------------------------"<<endl;
                    break;
                }
                else
                    cout<<"Tails."<<endl<< score<<setprecision (4)<<" oops, that's not heads "<<endl;
                    cout<<"------------------------------------------------------------"<<endl;
                break;
            case 'q'://this statement runs when the user wants to flip a quarter.
                useMe.GetsideUp();

                if ( useMe.toss("val"))
                {
                    score+=.25;
                    cout<< "Heads."<<endl<< "good job, the current amount is $"<<score<<setprecision (4)<<endl;
                    cout<<"------------------------------------------------------------"<<endl;
                    break;//return
                }
                else
                    cout<<"Tails."<<endl<< score<<setprecision (4)<<" uh oh, no dice."<<endl;
                    cout<<"------------------------------------------------------------"<<endl;
                break;
            default :
                cout<<"I don't have that, try again"<< endl;
                cout<<"------------------------------------------------------------"<<endl;
                break;//this case prints when the user inputs an invalid coin.
            }
        }//this if statement runs when the score is still under $1.00
        if(score==1.0)
        {
            cout<<"========================================================================="<<endl;
            cout<<"___________________________________"<<endl;
            cout<<"|#######====================#######|"<<endl;
            cout<<"|#(1)*UNITED STATES OF AMERICA*(1)#|"<<endl;
            cout<<"|#*****      #/===\#   ********  **#|"<<endl;
            cout<<"|#* {G}      |(._.)|             *#|"<<endl;
            cout<<"|#*  ****** |  /v\  |    O N E   **#|"<<endl;
            cout<<"|#(1)        #\===/#           (1)*#|"<<endl;
            cout<<"|##=========ONE DOLLAR===========##|"<<endl;
            cout<<"------------------------------------"<<endl;
            cout<<"You win!"<<endl<<"Press any key to play again,'#' to quit"<<endl;
            cout<<"========================================================================="<<endl;
            score=0;
            cin>> choice;
        }//this statement prints a cute congrats screen
        if (score>1.0)
        {
            cout<<"========================================================================="<<endl;
            cout<<" Sorry! you lost!"<<endl;
            score-=1;
            cout<< "Your balance went $"<<score<<setprecision (4)<<" over."<<endl;
            cout<<"========================================================================="<<endl;
            score=0;
            cout<< "Would you like to play again? Press any key to play again,'#' to quit"<<endl;
            cin>>choice;

        }//this statement takes the difference of the score and 1 and displays the amount over the player went.

    }
    while (choice!='#');
    cout<< "Thanks for playing";
    return 0;
}
/*================================================================================================
           OUTPUT
/*================================================================================================
            ver 2
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

This is a game where you toss a coin and if it's head side up, you get that amount.
 If you reach exactly $1.00, you win! But if you go over, then I win. Ready?
 You may quit by inputting '#'
-------------------------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
y
I don't have that, try again
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Heads.
nice, you now have $0.05
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Heads.
nice, you now have $0.1
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.2
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.3
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.4
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.5
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.
0.5 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.
0.5 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.75
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.
0.75 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.
0.75 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.
0.75 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $1
------------------------------------------------------------
=========================================================================
___________________________________
|#######====================#######|
|#(1)*UNITED STATES OF AMERICA*(1)#|
|#*****      #/===#   ********  **#|
|#* {G}      |(._.)|             *#|
|#*  ****** |  /v  |    O N E   **#|
|#(1)        #===/#           (1)*#|
|##=========ONE DOLLAR===========##|
------------------------------------
You win!
Press any key to play again,'#' to quit
=========================================================================
y
 Choose your coin:'d','n', or 'q'?
d
Tails.
0 oops,try again
 Choose your coin:'d','n', or 'q'?
n
Heads.
nice, you now have $0.05
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Tails.
0.05 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.15
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Tails.
0.15 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Tails.
0.15 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Tails.
0.15 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.25
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Tails.
0.25 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.35
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.6
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.
0.6 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.85
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $1.1
------------------------------------------------------------
=========================================================================
 Sorry! you lost!
Your balance went $0.1 over.
=========================================================================
Would you like to play again? Press any key to play again,'#' to quit
#
Thanks for playing
Process returned 0 (0x0)   execution time : 46.264 s
Press any key to continue.



+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   ver 1.2
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This is a game where you toss a coin and if it's head side up, you get that amount.
 If you reach exactly $1.00, you win! But if you go over, then I win. Ready?
 You may quit by inputting '#'
-------------------------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.25
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.35
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.35 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.35 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.6
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.85
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $1.1
------------------------------------------------------------
=========================================================================
 Sorry! you lost!
Your balance went $0.1 over.
=========================================================================
Would you like to play again? Press any key to play again,'#' to quit
y
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Tails.0 oops, that's not heads
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
Heads.
nice, you now have $0.05
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.15
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
0.15 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.25
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.25 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.25 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.5
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
r
Tails.I don't have that, try again
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.5 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.5 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.5 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $0.75
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.75 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Tails.0.75 uh oh, no dice.
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads.
good job, the current amount is $1
------------------------------------------------------------
=========================================================================
___________________________________
|#######====================#######|
|#(1)*UNITED STATES OF AMERICA*(1)#|
|#*****      #/===#   ********  **#|
|#* {G}      |(._.)|             *#|
|#*  ****** |  /v  |    O N E   **#|
|#(1)        #===/#           (1)*#|
|##=========ONE DOLLAR===========##|
------------------------------------
You win!
Press any key to play again,'#' to quit=========================================================================
#
Thanks for playing
Process returned 0 (0x0)   execution time : 55.490 s
Press any key to continue.




++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Version 1.2
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
This is a game where you toss a coin and if it's head side up, you get that amount.
 If you reach exactly $1.00, you win! But if you go over, then I win. Ready?
 You may quit by inputting '#'
-------------------------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads
good job, the current amount is $0.25
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
n
0.25 oops, that's not heads
 Choose your coin:'d','n', or 'q'?
n
0.25 oops, that's not heads
 Choose your coin:'d','n', or 'q'?
n
Heads
nice, you now have $0.3
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
0.3 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.4
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
0.4 oops,try again
 Choose your coin:'d','n', or 'q'?
d
0.4 oops,try again
 Choose your coin:'d','n', or 'q'?
d
0.4 oops,try again
 Choose your coin:'d','n', or 'q'?
d
0.4 oops,try again
 Choose your coin:'d','n', or 'q'?
d
0.4 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.5
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads
good job, the current amount is $0.75
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
0.75 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
Heads
good job, the current amount is $1
------------------------------------------------------------
=========================================================================
___________________________________
|#######====================#######|
|#(1)*UNITED STATES OF AMERICA*(1)#|
|#*****      #/===#   ********  **#|
|#* {G}      |(._.)|             *#|
|#*  ****** |  /v  |    O N E   **#|
|#(1)        #===/#           (1)*#|
|##=========ONE DOLLAR===========##|
------------------------------------
You win!
Press any key to play again,'#' to quit=========================================================================
a
 Choose your coin:'d','n', or 'q'?
d
0 oops,try again
 Choose your coin:'d','n', or 'q'?
s
I don't have that, try again
 Choose your coin:'d','n', or 'q'?
n
0 oops, that's not heads
 Choose your coin:'d','n', or 'q'?
n
0 oops, that's not heads
 Choose your coin:'d','n', or 'q'?
n
Heads
nice, you now have $0.05
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.15
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
0.15 oops,try again
 Choose your coin:'d','n', or 'q'?
d
0.15 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.25
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
d
0.25 oops,try again
 Choose your coin:'d','n', or 'q'?
d
0.25 oops,try again
 Choose your coin:'d','n', or 'q'?
d
Heads
 success, your balance is $0.35
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
0.35 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
0.35 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
0.35 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
0.35 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
Heads
good job, the current amount is $0.6
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
0.6 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
0.6 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
0.6 uh oh, no dice.
 Choose your coin:'d','n', or 'q'?
q
Heads
good job, the current amount is $0.85
------------------------------------------------------------
 Choose your coin:'d','n', or 'q'?
q
Heads
good job, the current amount is $1.1
------------------------------------------------------------
=========================================================================
 Sorry! you lost!
Your balance went $0.1 over.
=========================================================================
Would you like to play again? Press any key to play again,'#' to quit
#
Thanks for playing
Process returned 0 (0x0)   execution time : 72.014 s
Press any key to continue.

}*/
