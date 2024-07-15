Double Linked List Command Operated Program
This project is a C++11 program designed to manage a doubly linked list of integers through a series of commands read from an input file. Each command can insert, delete, find, and manipulate elements in the list, making it a versatile tool for practicing data structure operations.
Features
- Insert items at the beginning or end of the list.
- Delete items from the beginning, end, or a specific position in the list.
- Print the entire list or specific elements.
- Find specific items or the maximum item in the list.
- Invert the order of a range of items.
- Clear the entire list.
- Dimension of the list.
Commands
Insert Commands
insert_0 item ... - Insert items at the beginning of the list.
insert_end item ... - Insert items at the end of the list.
Print Commands
print_0 - Print the first item in the list.
print_end - Print the last item in the list.
print - Print the entire list.
Delete Commands
delete_0 - Remove the first item in the list.
delete_end - Remove the last item in the list.
delete_pos pos - Remove the item at the specified position.
Utility Commands
dim - Print the total number of items in the list.
clear - Remove all items from the list.
find item - Find the first occurrence of an item and print its position.
find_max - Find the maximum item and print its position.
invert_range pos1 pos2 - Invert the order of items between two positions.
