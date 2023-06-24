#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

using namespace std;

class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void insertCoin(Node* newNode);
    void insertInOrder(Node* newNode);
    void displayItems();
    void displayCoins();
    void resetCoins();
    void resetStock();
    string getHighestId();
    void addItem(string id, string name, string desc, Price price, unsigned on_hand);
    void removeItem(string id);

    // more functions to be added perhaps...

private:
    // the beginning of the list
    Node* head;
  
    // how many nodes are there in the list?
    unsigned count;
};

#endif  // LINKEDLIST_H


