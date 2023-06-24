#include "Node.h"

//Used to create new node using Stock object
Node::Node(Stock s) : data(new Stock(s)), next(nullptr) {}

//Used to create new node using Coin object
Node::Node(Coin c) : cdata(new Coin(c)), next(nullptr) {}

//Clears data
Node::~Node(){
    delete data;
    delete cdata;
}

//Gets next node
Node* Node::getNext() {
    return next;
}

//Gets stock data
Stock Node::getData() const {
    return *data;
}

//Sets stock data
void Node::setData(const Stock s) {
    *data = s;
}

//Gets coin data
Coin Node::getCData() const {
    return *cdata;
}

//Sets coin data
void Node::setCData(const Coin c) {
    *cdata = c;
}

//Stock constructor
Stock::Stock(const std::string& id, const std::string& name, const std::string& desc, const Price& price, const unsigned& on_hand) {
    this->id = id;
    this->name = name;
    this->description = desc;
    this->price = price;
    this->on_hand = on_hand;
}