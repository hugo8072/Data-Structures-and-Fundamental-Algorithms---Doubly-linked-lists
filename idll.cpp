#include "idll.h" // Includes the header file for the IDll class

/**
 * @brief Helper function to delete a node.
 * 
 * @param node The node to be deleted.
 */
void deleteNode(INode* node) {
    delete node; // Deallocates the memory for the node
}

/**
 * @brief Constructor for the IDll class.
 * Initializes an empty list with head, tail set to nullptr, and size set to 0.
 */
IDll::IDll() : head(nullptr), tail(nullptr), size(0) {}

/**
 * @brief Destructor for the IDll class.
 * Clears the list by deallocating memory used by nodes.
 */
IDll::~IDll() {
    clear(); // Calls the clear() function to free the memory occupied by nodes
}

/**
 * @brief Returns the size of the list.
 * 
 * @return The current size of the list.
 */
int IDll::getSize() const {
    return size;
}

/**
 * @brief Inserts a new node with the given item at the start of the list.
 * 
 * @param item The value to be inserted.
 */
void IDll::insertAtStart(int item) {
    INode* newNode = new INode(item, nullptr, head); // Creates a new node
    if (head != nullptr) {
        head->prev = newNode; // Updates the previous pointer of the head node
    } else {
        tail = newNode; // Updates the tail pointer if the list is empty
    }
    head = newNode; // Updates the head pointer
    size++; // Increments the size of the list
}

/**
 * @brief Inserts a new node with the given item at the end of the list.
 * 
 * @param item The value to be inserted.
 */
void IDll::insertAtEnd(int item) {
    INode* newNode = new INode(item, tail, nullptr); // Creates a new node
    if (tail != nullptr) {
        tail->next = newNode; // Updates the next pointer of the tail node
    } else {
        head = newNode; // Updates the head pointer if the list is empty
    }
    tail = newNode; // Updates the tail pointer
    size++; // Increments the size of the list
}

/**
 * @brief Deletes the node at the start of the list.
 */
void IDll::deleteFromStart() {
    if (head == nullptr) return; // Checks if the list is empty
    INode* temp = head; // Stores the address of the node to be removed
    head = head->next; // Updates the head pointer
    if (head != nullptr) {
        head->prev = nullptr; // Updates the previous pointer of the new head node
    } else {
        tail = nullptr; // Updates the tail pointer if the list becomes empty
    }
    deleteNode(temp); // Deletes the node
    size--; // Decrements the size of the list
}

/**
 * @brief Deletes the node at the end of the list.
 */
void IDll::deleteFromEnd() {
    if (tail == nullptr) return; // Checks if the list is empty
    INode* temp = tail; // Stores the address of the node to be removed
    tail = tail->prev; // Updates the tail pointer
    if (tail != nullptr) {
        tail->next = nullptr; // Updates the next pointer of the new tail node
    } else {
        head = nullptr; // Updates the head pointer if the list becomes empty
    }
    deleteNode(temp); // Deletes the node
    size--; // Decrements the size of the list
}

/**
 * @brief Clears all nodes in the list, resetting the size to 0.
 */
void IDll::clear() {
    while (head != nullptr) {
        INode* temp = head; // Stores the address of the node to be removed
        head = head->next; // Updates the head pointer
        deleteNode(temp); // Deletes the node
    }
    tail = nullptr; // Resets the tail pointer
    size = 0; // Resets the size of the list
}

/**
 * @brief Prints all elements in the list.
 */
void IDll::print() {
    if (head == nullptr) {
        std::cout << "Command print: List is empty!\n"; // If the list is empty, prints a message
        return;
    }

    INode* current = head; // Starts from the head node
    std::cout << "List= "; // Prints the initial message
    while (current != nullptr) { // Iterates through all the nodes
        std::cout << current->item; // Prints the value of the current node
        if (current->next != nullptr) {
            std::cout << " "; // Prints a space between elements
        }
        current = current->next; // Moves to the next node
    }
    std::cout << "\n"; // Prints a newline at the end
}

/**
 * @brief Prints the first element in the list.
 */
void IDll::printFirst() {
    if (head != nullptr) {
        std::cout << "List(0)= " << head->item << "\n"; // If the list is not empty, prints the first element
    }
}

/**
 * @brief Prints the last element in the list.
 */
void IDll::printLast() {
    if (tail != nullptr) {
        std::cout << "List(end)= " << tail->item << "\n"; // If the list is not empty, prints the last element
    }
}

/**
 * @brief Finds a specific item in the list and prints its position.
 * 
 * @param item The item to be searched for.
 */
void IDll::find(int item) {
    int index = 0; // Starts the index from zero
    for (INode* current = head; current != nullptr; current = current->next) { // Iterates through all the nodes
        if (current->item == item) {
            std::cout << "Item " << item << " at position " << index << "\n"; // If found, prints its position
            return;
        }
        index++; // Increments the index
    }
    std::cout << "Item " << item << " not found!\n"; // If the item is not found, prints a message
}

/**
 * @brief Deletes the node at the specified position.
 * 
 * @param pos The position of the node to be deleted.
 */
void IDll::deleteAtPos(int pos) {
    if (pos < 0 || pos >= size) {
        std::cout << "Command delete_pos: Invalid position!\n"; // If the position is invalid, prints an error message
        return;
    }
    if (pos == 0) {
        deleteFromStart(); // If the position is zero, deletes the first node
        return;
    }
    if (pos == size - 1) {
        deleteFromEnd(); // If the position is the last one, deletes the last node
        return;
    }

    INode* current = head; // Starts from the head node
    for (int i = 0; i < pos; i++) {
        current = current->next; // Moves to the node at the specified position
    }

    current->prev->next = current->next; // Updates the pointers to remove the node
    current->next->prev = current->prev;
    deleteNode(current); // Deletes the node
    size--; // Decrements the size of the list
}

/**
 * @brief Reverses the order of elements between positions pos1 and pos2.
 * 
 * @param pos1 The starting position.
 * @param pos2 The ending position.
 */
void IDll::invertRange(int pos1, int pos2) {
    if (pos1 < 0 || pos2 >= size || pos1 > pos2) {
        std::cout << "Command invert_range: Invalid position!\n"; // If the positions are invalid, prints an error message
        return;
    }

    INode *current1 = head, *current2 = tail; // Starts from the head and tail nodes
    for (int i = 0; i < pos1; i++) current1 = current1->next; // Moves to the node at position pos1
    for (int i = size - 1; i > pos2; i--) current2 = current2->prev; // Moves to the node at position pos2

    while (current1 != current2 && current1->prev != current2) { // While the nodes are not at the same position
        std::swap(current1->item, current2->item); // Swaps the values of the nodes
        current1 = current1->next; // Moves to the next node
        current2 = current2->prev; // Moves to the previous node
    }
}

/**
 * @brief Finds the maximum element in the list and prints its position.
 */
void IDll::find_max() {
    if (head == nullptr) {
        std::cout << "Command find_max: List is empty!\n"; // If the list is empty, prints an error message
        return;
    }

    int maxItem = head->item; // Starts with the value of the first node
    int maxPosition = 0; // Initializes the maximum position to zero
    int currentPosition = 0; // Initializes the current position to zero
    INode* current = head; // Starts from the head node

    while (current != nullptr) { // Iterates through all the nodes
        if (current->item > maxItem) { // If a larger value is found
            maxItem = current->item; // Updates the maximum value
            maxPosition = currentPosition; // Updates the maximum position
        }
        current = current->next; // Moves to the next node
        currentPosition++; // Increments the current position
    }

    std::cout << "Max Item " << maxItem << " at position " << maxPosition << "\n"; // Prints the maximum value and its position
}
