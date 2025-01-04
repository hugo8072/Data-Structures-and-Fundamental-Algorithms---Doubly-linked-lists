#ifndef IDLL_H
#define IDLL_H

#include <iostream>

/**
 * @brief Structure that defines a node in a doubly linked list.
 */
struct INode {
    int item;       ///< Value stored in the node
    INode* prev;    ///< Pointer to the previous node
    INode* next;    ///< Pointer to the next node

    /**
     * @brief Constructor to initialize a node with default values.
     * 
     * @param item Value to be stored in the node.
     * @param prev Pointer to the previous node.
     * @param next Pointer to the next node.
     */
    INode(int item, INode* prev = nullptr, INode* next = nullptr)
        : item(item), prev(prev), next(next) {}
};

/**
 * @brief Class representing a doubly linked list (DLL).
 * 
 * This class provides functionalities to insert, delete, and manipulate elements in the list.
 */
class IDll {
private:
    INode* head;    ///< Pointer to the first node in the list
    INode* tail;    ///< Pointer to the last node in the list
    int size;       ///< Current size of the list

public:
    /**
     * @brief Constructor of the IDll class.
     * Initializes an empty list with head, tail set to nullptr, and size set to 0.
     */
    IDll();

    /**
     * @brief Destructor of the IDll class.
     * Clears the list by deallocating memory used by nodes.
     */
    ~IDll();

    /**
     * @brief Returns the size of the list.
     * 
     * @return The current size of the list.
     */
    int getSize() const;

    /**
     * @brief Inserts a new node with the given item at the start of the list.
     * 
     * @param item The value to be inserted.
     */
    void insertAtStart(int item);

    /**
     * @brief Inserts a new node with the given item at the end of the list.
     * 
     * @param item The value to be inserted.
     */
    void insertAtEnd(int item);

    /**
     * @brief Deletes the node at the start of the list.
     */
    void deleteFromStart();

    /**
     * @brief Deletes the node at the end of the list.
     */
    void deleteFromEnd();

    /**
     * @brief Clears all nodes in the list, resetting the size to 0.
     */
    void clear();

    /**
     * @brief Prints all the elements in the list.
     */
    void print();

    /**
     * @brief Prints the first element in the list.
     */
    void printFirst();

    /**
     * @brief Prints the last element in the list.
     */
    void printLast();

    /**
     * @brief Finds a specific item in the list and prints its position.
     * 
     * @param item The item to be searched for.
     */
    void find(int item);

    /**
     * @brief Deletes the node at the specified position.
     * 
     * @param pos The position of the node to be deleted.
     */
    void deleteAtPos(int pos);

    /**
     * @brief Reverses the order of elements between positions pos1 and pos2.
     * 
     * @param pos1 The starting position.
     * @param pos2 The ending position.
     */
    void invertRange(int pos1, int pos2);

    /**
     * @brief Finds the maximum element in the list and prints its position.
     */
    void find_max();
};

#endif
