void LinkedList::removeItem(string id) {
  Node* currNode = nullptr;

  //if there is only 1 value in the linked list, and it is the ID
  if(head->data->id == tail->data->id && head->data->id == id){
    //set node to be deleted to head
    currNode = head;
    //Set the tail and head to nullptr
    tail = nullptr;
    head = nullptr;
    //If you want to be safe, you can unlink currNode(not needed imho)
  }
  else if (head->data->id == id) {
    currNode = head;
    head = currNode->next;
    if (head != nullptr)
      head->prev = nullptr;
  }
  else if (tail->data->id == id) {
    currNode = tail;
    tail = currNode->prev;
    if (tail != nullptr)
      tail->next = nullptr;
  }
  else {
    Node* forwardIter = head->next;
    Node* backwardIter = tail->prev;

    while ((forwardIter != nullptr || backwardIter != nullptr) && currNode == nullptr) {
      if (forwardIter != nullptr && forwardIter->data->id == id) {
        currNode = forwardIter;
      }
      else if (backwardIter != nullptr && backwardIter->data->id == id) {
        currNode = backwardIter;
      }
      forwardIter = forwardIter->next;
      backwardIter = backwardIter->prev;
    }

    if (currNode != nullptr) {
      currNode->prev->next = currNode->next;
      if (currNode->next != nullptr)
        currNode->next->prev = currNode->prev;
    }
  }

  if (currNode != nullptr)
    delete currNode;
}
