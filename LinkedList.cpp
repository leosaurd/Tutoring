#include "LinkedList.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//LinkedList constructor
LinkedList::LinkedList() {
   head = nullptr;
}

//LinkedList de-constructor
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Add item into linkedlist (uses insertInOrder() to maintain alphabetical order)
void LinkedList::addItem(string id, string name, string desc, Price price, unsigned on_hand){
    Node* newNode = new Node(Stock(id, name, desc, price, on_hand));
    insertInOrder(newNode);
    cout << "This item \"" << name << " - " << desc << "\" has now been added to the menu." << endl;
}


//Get highest ID in linkedlist, used for addItem
string LinkedList::getHighestId(){
    string highestId = "I0000";
    Node* currNode = head;
    while (currNode != nullptr) {
        Stock stockCurr = currNode->getData();
        if(highestId < stockCurr.id){
            highestId = stockCurr.id;
        }
        currNode = currNode->getNext();
    }
    return highestId;
}

//Inserts coin from lowest to highest (For loading coins.dat)
void LinkedList::insertCoin(Node* newNode){
    if (head == nullptr || newNode->cdata->denom < head->cdata->denom) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->cdata->denom < newNode->cdata->denom) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

//Removes item from linkedlist
void LinkedList::removeItem(string id){
    Node* currNode = head;
    Node* temp;
    temp = currNode->next;

    //If id is found at the head
    if(head->data->id == id){
        head = temp;
        cout << "\""<< currNode->data->id 
        << " - " <<  currNode->data->name 
        << " - " << currNode->data->description 
        << "\" has been removed from the system."<< endl;
        delete currNode;
    }
    else{
        while(temp->next != nullptr){
            if (temp->data->id == id){
                currNode->next = temp->next;
                cout << "\""<< temp->data->id 
                << " - " <<  temp->data->name 
                << " - " << temp->data->description 
                << "\" has been removed from the system."<< endl;
                delete temp;
                return;
            }
            currNode = temp;
            temp = currNode->next;
        }
        //If id is found at the tail
        if(temp->data->id == id){
            currNode->next = nullptr;
            cout << "\""<< temp->data->id 
            << " - " <<  temp->data->name 
            << " - " << temp->data->description 
            << "\" has been removed from the system."<< endl;
            delete temp;
        }
    }
}

//This inserts items in alphabetical order (Used in loading stock.dat and addItem())
void LinkedList::insertInOrder(Node* newNode) {
    if (head == nullptr || newNode->data->name < head->data->name) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data->name < newNode->data->name) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

//Displays Items
void LinkedList::displayItems() {
    cout << "Items Menu" << endl;
    cout << "----------" << endl;
    cout << "ID\t| "
    << setw(40) << setfill(' ') << left <<"Name \t" 
    << setw(9) << setfill(' ') << left << " | Available | Price" << endl;
    string line(70, '-');
    cout << line << endl;

    Node* currNode = head;
    while (currNode != nullptr) {
        Stock currStock = currNode->getData();
        cout << currStock.id << " \t| " 
        << setw(40) << setfill(' ') << left << currStock.name << " | " 
        << setw(9) << setfill(' ') << left << currStock.on_hand << " | $" 
        << currStock.price.dollars << "." << setw(2) << setfill('0') << currStock.price.cents << endl;
        currNode = currNode->getNext();
    }
}

//Displays Coins
void LinkedList::displayCoins() {
    cout << "Coins Summary" << endl;
    cout << "-------------" << endl;
    cout << "Denomination\t| "
    << setw(5) << setfill(' ') << right << "Count " << endl;
    string line(25, '-');
    cout << line << endl;

    Node* currNode = head;
    while (currNode != nullptr) {
        Coin currCoin = currNode->getCData();
        if(currCoin.denom == FIVE_CENTS){
            cout << "5 Cents";
        }

        else if(currCoin.denom == TEN_CENTS){
            cout << "10 Cents";
        }

        else if(currCoin.denom == TWENTY_CENTS){
            cout << "20 Cents";
        }

        else if(currCoin.denom == FIFTY_CENTS){
            cout << "50 Cents";
        }

        else if(currCoin.denom == ONE_DOLLAR){
            cout << "1 Dollar";
        }

        else if(currCoin.denom == TWO_DOLLARS){
            cout << "2 Dollars";
        }

        else if(currCoin.denom == FIVE_DOLLARS){
            cout << "5 Dollars";
        }
        
        else if(currCoin.denom == TEN_DOLLARS){
            cout << "10 Dollars";
        }
        cout << " \t| " << setw(5) << setfill(' ') << right << currCoin.count << endl;
        currNode = currNode->getNext();
    }
}

//Resets coins based on DEFAULT_COIN_COUNT
void LinkedList::resetCoins(){
    Node* currNode = head;
    while (currNode != nullptr) {
        Coin currCoin = currNode->getCData();
        currCoin.count = DEFAULT_COIN_COUNT;
        currNode->setCData(currCoin);
        currNode = currNode->getNext();
    }

    cout << "All coins have been reset to the default level of " << DEFAULT_COIN_COUNT << endl;
}

//Resets stock based on DEFAULT_STOCK_LEVEL
void LinkedList::resetStock(){
    Node* currNode = head;
    while (currNode != nullptr) {
        Stock currStock = currNode->getData();
        currStock.on_hand = DEFAULT_STOCK_LEVEL;
        currNode->setData(currStock);
        currNode = currNode->getNext();
    }

    cout << "All stock has been reset to the default level of " << DEFAULT_STOCK_LEVEL << endl;
}

