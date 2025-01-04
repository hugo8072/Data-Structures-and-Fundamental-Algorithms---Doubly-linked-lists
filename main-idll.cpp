#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>
#include "idll.h" // Includes the header file for the IDll class

/**
 * @brief Main function to execute commands on the doubly linked list (IDll).
 * 
 * This function reads input commands, maps them to specific functions that
 * manipulate the doubly linked list, and executes them accordingly.
 * It also handles error messages when invalid commands or operations are encountered.
 */
int main() {
    IDll list; // Creates an instance of the doubly linked list
    std::string line, cmd; // Declares variables for storing input lines and commands

    // Creates a map of string commands to corresponding lambda functions
    std::unordered_map<std::string, std::function<void(std::istringstream&)>> command_map;

    // Maps the "insert_0" command to the insertion function at the start of the list
    command_map["insert_0"] = [&list](std::istringstream& iss) {
        int item;
        while (iss >> item) {
            list.insertAtStart(item); // Inserts the item at the start
        }
    };

    // Maps the "insert_end" command to the insertion function at the end of the list
    command_map["insert_end"] = [&list](std::istringstream& iss) {
        int item;
        while (iss >> item) {
            list.insertAtEnd(item); // Inserts the item at the end
        }
    };

    // Maps the "print_0" command to print the first element in the list
    command_map["print_0"] = [&list](std::istringstream&) { list.printFirst(); };

    // Maps the "print_end" command to print the last element in the list
    command_map["print_end"] = [&list](std::istringstream&) { list.printLast(); };

    // Maps the "print" command to print all elements in the list
    command_map["print"] = [&list](std::istringstream&) { list.print(); };

    // Maps the "delete_0" command to delete the first element
    command_map["delete_0"] = [&list](std::istringstream&) {
        if (list.getSize() == 0) {
            std::cout << "Command delete_0: List is empty!\n"; // Error if list is empty
        } else {
            list.deleteFromStart(); // Deletes the first element
        }
    };

    // Maps the "delete_end" command to delete the last element
    command_map["delete_end"] = [&list](std::istringstream&) {
        if (list.getSize() == 0) {
            std::cout << "Command delete_end: List is empty!\n"; // Error if list is empty
        } else {
            list.deleteFromEnd(); // Deletes the last element
        }
    };

    // Maps the "dim" command to print the number of items in the list
    command_map["dim"] = [&list](std::istringstream&) {
        std::cout << "The list has " << list.getSize() << " items\n"; // Prints the size of the list
    };

    // Maps the "clear" command to clear all elements in the list
    command_map["clear"] = [&list](std::istringstream&) {
        if (list.getSize() == 0) {
            std::cout << "Command clear: List is empty!\n"; // Error if list is empty
        } else {
            list.clear(); // Clears the entire list
        }
    };

    // Maps the "find" command to find and print the position of an item
    command_map["find"] = [&list](std::istringstream& iss) {
        int item;
        if (iss >> item) {
            list.find(item); // Finds the item and prints its position
        }
    };

    // Maps the "delete_pos" command to delete a node at a specific position
    command_map["delete_pos"] = [&list](std::istringstream& iss) {
        int pos;
        if (iss >> pos) {
            list.deleteAtPos(pos); // Deletes the node at the given position
        }
    };

    // Maps the "invert_range" command to invert a range of elements between two positions
    command_map["invert_range"] = [&list](std::istringstream& iss) {
        int pos1, pos2;
        if (iss >> pos1 >> pos2) {
            list.invertRange(pos1, pos2); // Inverts the elements in the given range
        }
    };

    // Maps the "find_max" command to find the maximum element in the list
    command_map["find_max"] = [&list](std::istringstream&) {
        list.find_max(); // Finds the maximum item in the list
    };

    // Processes each line of input
    while (std::getline(std::cin, line)) {
        if (line.empty() || line[0] == '#') continue; // Skips empty or comment lines
        std::istringstream iss(line); // Creates a stringstream for the current line
        if (!(iss >> cmd)) continue; // Reads the command from the line

        auto it = command_map.find(cmd); // Searches for the command in the map
        if (it != command_map.end()) {
            it->second(iss);  // Executes the associated function with any parameters (if any)
        } else {
            std::cout << "Unknown command: " << cmd << "\n"; // Prints error message for unrecognized commands
        }
    }

    return 0;
}
