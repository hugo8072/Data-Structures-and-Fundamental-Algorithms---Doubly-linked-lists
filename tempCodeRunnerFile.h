#ifndef IDLL_H
#define IDLL_H

#include <iostream>

// Definição do nó da lista
struct INode {
    int item;
    INode* prev;
    INode* next;

    INode(int item, INode* prev = nullptr, INode* next = nullptr)
        : item(item), prev(prev), next(next) {}
};

// Definição da classe da lista duplamente ligada
class IDll {
private:
    INode* head;
    INode* tail;
    int n;

public:
    IDll();
    ~IDll();

    void insertAtStart(int item);
    void insertAtEnd(int item);
    void deleteFromStart();
    void deleteFromEnd();
    void clear();
    void print();
    void printFirst();
    void printLast();
    int size() const;
    void find(int item);
    void deleteAtPos(int pos);
    void invertRange(int pos1, int pos2);
    void find_max();
};

#endif