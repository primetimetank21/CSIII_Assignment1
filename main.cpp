//
//  main.cpp
//  Prog1.cpp
//
//  Created by Earl Tankard, Jr. on 9/3/19.
//  Copyright © 2019 Earl Tankard, Jr. All rights reserved.
//

#include "doubleLinkedList.hpp"

int main()
{
    
    std::cout << "What would you like your first value to be?\t";
    double x;
    std::cin >> x;
    LinkedList<double> myNumbers = LinkedList<double>(x);
    char option = ' ';
    double input;
    int pos;

    while (option != 'q')
    {
        input = 0;
        pos = 0;
        std::cout << "Add Front\t\t--> f\n";
        std::cout << "Add Back\t\t--> b\n";
        std::cout << "Add to kth postion\t--> a\n";
        std::cout << "View kth element\t--> k\n";
        std::cout << "View Next and Prev\t--> v\n";
        std::cout << "View Head\t\t--> h\n";
        std::cout << "View Tail\t\t--> t\n";
        std::cout << "Print range [a, b]\t--> r\n";
        std::cout << "Print entire list\t--> p\n\n";
        std::cout << "Select an option.\t--> ";

        std::cin >> option;
        std::cout << "\n";
        
        switch (option) {
            case 'F':
            case 'f':
                std::cout << "What value would you like to make the new head?\t";
                std::cin >> input;
                myNumbers.AddFront(input);
                break;
                
            case 'B':
            case 'b':
                std::cout << "What value would you like to make the new tail?\t";
                std::cin >> input;
                myNumbers.AddBack(input);
                break;
                
            case 'A':
            case 'a':
                std::cout << "What value would you like to add?\t";
                std::cin >> input;
                std::cout << "What position would you like to insert " << input << "?\t";
                std::cin >> pos;
                myNumbers.AddObj(input, pos);
                break;
                
            case 'P':
            case 'p':
                myNumbers.Print();
                break;
                
            case 'V':
            case 'v':
                std::cout << "What is the object's position?\t";
                std::cin >> pos;
                myNumbers.NextAndPrev(pos);
                break;
                
            case 'H':
            case 'h':
                myNumbers.CurrFront();
                break;
                
            case 'T':
            case 't':
                myNumbers.CurrBack();
                break;
                
            case 'K':
            case 'k':
                std::cout << "What is the object's position?\t";
                std::cin >> pos;
                myNumbers.Locate(pos);
                break;
                
            case 'R':
            case 'r':
                std::cout << "What is the starting position?\ta=\t";
                std::cin >> pos;
                int pos_2;
                std::cout << "What is the ending position?\tb=\t";
                std::cin >> pos_2;
                myNumbers.Range(pos, pos_2);
                break;
                
            case 'Q':
                option = 'q';
            case 'q':
                std::cout << "Ending program. . .\n";
                break;
                
            default:
                option = ' ';
                std::cout << "Invalid command.\n\n";
                break;
        }
        std::cout << "\n\n";
    }    
    return 0;
}
