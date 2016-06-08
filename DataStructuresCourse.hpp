#pragma once
#include <string>
#include <stdexcept>
#include <cstdlib> // system definitions
#include <iostream> // I/O definitions

namespace DataStructsCourse {
    class GameEntry { // a game score entry
    
    public:
        GameEntry(const std::string& n = "", int s = 0) // constructor
            : name(n), score(s) { } // accessors

        std::string getName() const { return name; }

        int getScore() const { return score; }
    private:
        std::string name; // player’s name
        int score; // player’s score
    };

    class Scores { // stores game high scores
    public:
        Scores(int maxEnt = 10);                // constructor

        ~Scores();

        void add(const GameEntry& e); // add a game entry
        GameEntry remove(int i)                      // remove the ith entry
            throw(std::out_of_range);
    private:
        int maxEntries; // maximum number of entries
        int numEntries; // actual number of entries
        GameEntry* entries; // array of game entries

    
    };

    void clearBoard();

    void putMark(int i, int j);

    bool isWin(int mark);

    int getWinner();

    void printBoard();

    const int X = 1;
    const int O = -1;
    const int EMPTY = 0; // possible marks
    template<typename T>
    class Node
    {
    public:

        Node() : next(nullptr), prev(nullptr) {}

        ~Node() {};

        T GetElem()
        {
            return elem;
        }

        void SetElem(T & elemData)
        {
            elem = elemData;
        }

        Node * GetNext() const
        {
            return next;
        }

        void SetNext(Node * e)
        {
            next = e;
        }
        Node * GetPrev() const
        {
            return prev;
        }

        void SetPrev(Node * e)
        {
            prev = e;
        }
    private:
        T elem;

        Node * next;

        Node * prev;
    };

    template<typename U, template<typename> class ListNode>
    class LinkedList
    { // a linked list of strings
    public:
        LinkedList() : head(nullptr), tail(nullptr) {} // empty list constructor

        ~LinkedList() 
        {
            while (!empty()) removeFront();
        } // destructor

        bool empty() const
        {
            return (head == nullptr);
        } // is list empty?
        
        bool front(const U & elem) const
        {
            bool bValidData = false;

            if (!empty())
            {
                elem = head->GetElem();

                bValidData = true;
            }

            return bValidData;
        }  // get front element
        void addFront(U & e)
        {
            ListNode<U> * v = new ListNode<U>;  // create new node
            
            v->SetElem(e);  // store data
            
            v->SetNext(head); // head now follows v
            
            head = v;
            
        } // add to front of list
        void removeFront()
        {
            // remove front item
            if (!empty())
            {
                ListNode<U> * old = head; // save current head

                head = old->GetNext(); // skip over old head

                delete old; // delete the old head
            }
        }
        
        void addBack(U & e)
        {
            ListNode<U> * v = new ListNode<U>;  // create new node

            v->SetElem(e);  // store data

            v->SetPrev(tail); // head now follows v

            tail = v;

        } // add to front of list
        void removeBack()
        {
            // remove front item
            if (!empty())
            {
                ListNode<U> * old = tail; // save current head

                head = old->GetPrev(); // skip over old head

                delete old; // delete the old head
            }
        }

    private:
        ListNode<U> * head; // pointer to the head of list

        ListNode<U> * tail; // pointer to the tail of list
    };


}