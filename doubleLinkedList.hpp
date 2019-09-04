//
//  CSIII-Assignment1.hpp
//
//
//  Created by Earl Tankard, Jr. on 9/3/19.
//

#ifndef doubleLinkedList_hpp
#define doubleLinkedList_hpp

#include <iostream>     //to output to user
#include <list>         //to utilize linked list functionalities
/*
 Program Requirements
 § What are the first and last objects (the front and the back)?
 § What is the kth object?
 § What are all objects on a given interval [a, b]
 § Given a reference to one object in the container:
    - What are the previous and next objects?
 
 Assumptions
 § User will create a linked list of doubles
 § 
 §
 §
 */

///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

template <typename myType>
class LinkedList
{
private:
    std::list <myType> myList;
public:
    LinkedList(myType val) {                       //constructor
        myList.push_front(val);
        return;
    };
    void AddFront(myType val) {                    //adds object to front of list
        myList.push_front(val);
        return;
    };
    void AddBack(myType val) {                     //adds object to end of list
        myList.push_back(val);
        return;
    };
    void AddObj(myType val, int position) {        //adds object at location position
        if (position < 0 || position >= myList.size())
        {
            std::cout << "Error! Invalid position!\n";
        }
        else
        {
            typename std::list<myType>::iterator iter = myList.begin();
            for (int i = 0; i < position; i++)
            {
                iter++;
            }
            myList.insert(iter, val);
            
        }
        return;
    };
    
    //Accessors
    myType CurrFront() const {                     //returns head
        std::cout << "The current head is " << myList.front() << std::endl;
        return myList.front();
    };
    myType CurrBack() const {                     //returns tail
        std::cout << "The current tail is " << myList.back() << std::endl;
        return myList.back();
    };
    void Locate(int k) {                 //finds the kth object in the list
        if (k < 0 || k >= myList.size())
        {
            std::cout << "Error! Invalid position!\n";
        }
        else
        {
            typename std::list<myType>::iterator iter = myList.begin();
            for (int i = 0; i < k; i++)
            {
                iter++;
            }
            std::cout << "The " << k << "th object is: " << *iter << std::endl;

        }
        return;
    };
    void Range(int a, int b) {             //prints objects in range [a, b] --> a, b refer to positions
        if (a < 0 || b < a || b >= myList.size())
        {
            std::cout << "Error! Invalid position(s)!\n";
        }
        else
        {
            typename std::list<myType>::iterator iter = myList.begin();
            std::cout << "All the object values on the interval [" << a << ", " << b << "] are: ";
            for (int i = 0; i <= b; i++)
            {
                if (i >=a)
                    std::cout << *iter << " ";
                iter++;
            }
            std::cout << std::endl;

        }
        return;
    };
    void NextAndPrev(int position) {         //shows what the previous and next objects are given the position of the object
        if (position < 0 || position >= myList.size())
        {
            std::cout << "Error! Invalid position!\n";
        }
        else
        {
            
            typename std::list<myType>::iterator iter = myList.begin();
            for (int i = 0; i < position; i++)
            {
                iter++;
            }
            std::cout << "The current object is " << *iter << ".\n";
            iter++;
            if (iter == myList.end())
            {
                std::cout << "The next object is undefined. This is the end of the list!\n";
            }
            else
            {
                std::cout << "The next object is " << *iter << ".\n";
            }
            iter--;
            if (iter == myList.begin())
            {
                std::cout << "The previous object is undefined. This is the beginning of the list!\n";
            }
            else
            {
                iter--;
                std::cout << "The previous object is " << *iter << ".\n";
            }
            return;

        }
    };
    void Print() const {
        std::cout << "Number of objects in list: " << myList.size() << std::endl;
        std::cout << "Object values: ";
        for (myType element : myList)
        {
            std::cout << element << ' ';
        }
        std::cout << std::endl;
    };
};
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
#endif /* CSIII_Assignment1_h */
