#include "DataStructuresCourse.hpp"

namespace DataStructsCourse
{
    Scores::Scores(int maxEnt) {                   // constructor
        maxEntries = maxEnt;                       // save the max size

        entries    = new GameEntry[maxEntries];  // allocate array storage

        numEntries = 0;                            // initially no elements
    }
    Scores::~Scores() { // destructor
        delete[] entries;
    }

    void Scores::add(const GameEntry& e) 
    {   
        // add a game entry
        int newScore           = e.getScore(); // score to add
        if (numEntries == maxEntries) 
        { 
            // the array is full
            if (newScore <= entries[maxEntries - 1].getScore()) return;
        }
        else ++numEntries;
        
        int i = numEntries - 2;

        while (    (i >= 0) 
                && (newScore > entries[i].getScore())
              )
        {
            entries[i + 1] = entries[i];  // shift right if smaller
            --i;
        }
        entries[i + 1] = e; // put e in the empty spot
    }
    GameEntry Scores::remove(int i) throw(std::out_of_range)
    {
        if (
                (i < 0) 
             || (i >= numEntries)
           ) // invalid index
            throw std::out_of_range("Invalid index");

        GameEntry e = entries[i]; // save the removed object

        for (int j = i + 1; j < numEntries; j++)
            entries[j - 1] = entries[j];
        
        --numEntries;

        return e; // return the removed object
    }

    void insertionSort(char* A, int n) 
    {                                           // sort an array of n characters
        for (int i = 1; i < n; i++) 
        {                                       // insertion loop
            char cur = A[i];                    // current character to insert

            int j = i - 1;                      // start at previous character

            while ((j >= 0) && (A[j] > cur)) 
            {                                   // while A[j] is out of order
                A[j + 1] = A[j];                // move A[j] right

                j--;                            // decrement j
            }
            
            A[j + 1] = cur;                     // this is the proper place for cur
        }
    }
    using namespace std;                // make std:: accessible

    int board[3][3];                    // playing board

    int currentPlayer;                  // current player (X or O)
    void clearBoard() 
    {                                   // clear the board
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = EMPTY;    // every cell is empty
        
        currentPlayer = X;              // player X starts
    }
    void putMark(int i, int j) 
    { // mark row i column j
        board[i][j] = currentPlayer;    // mark with current player
        currentPlayer = -currentPlayer; // switch players
    }
    bool isWin(int mark)
    { // is mark the winner?
        int win = 3 * mark;             // +3 for X and -3 for O
        return (
            (   board[0][0] + board[0][1] + board[0][2] == win) // row 0
            || (board[1][0] + board[1][1] + board[1][2] == win) // row 1
            || (board[2][0] + board[2][1] + board[2][2] == win) // row 2
            || (board[0][0] + board[1][0] + board[2][0] == win) // column 0
            || (board[0][1] + board[1][1] + board[2][1] == win) // column 1
            || (board[0][2] + board[1][2] + board[2][2] == win) // column 2
            || (board[0][0] + board[1][1] + board[2][2] == win) // diagonal
            || (board[2][0] + board[1][1] + board[0][2] == win)
            );
    }
    
    int getWinner() 
    {                                    // who wins? (EMPTY means tie)
        if (isWin(X)) return X;
        else if (isWin(O)) return O;
        else return EMPTY;
    }
    void printBoard() 
    { // print the board
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                 switch (board[i][j]) 
                {
                    case X: 
                        cout << "X"; 
                        
                        break;
         
                    case O:
                        cout << "O"; 
                        
                        break;
                    case EMPTY: 
                        cout << " "; 
                        
                        break;
                } 
                if ( j<2) cout << "|"; // column boundary
            } 
            
            if (i<2) cout << "\n-+-+-\n"; // row boundary
        }
    }
};