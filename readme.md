**INSTRUCTIONS TO RUN THE CODE**

1. Open the DSA_assignment_group_60.c file in any editor

2. In the main() function of the code write the name of your input file in the place of <data.txt>  
   which is present under the "// Open the file for reading" comment. 

3. Set the #define NO_OF_NODES and #define THRESHOLD constants according to the user's need and number
   of values to be inserted.

4. Save the code.

5. Now follow the commands on the terminal to run the file
   
   Navigate to the directory where you saved the code and follow the commands:
   
   gcc DSA_assignment_group_60.c -o DSA_assignment_group_60_exe <press enter>

   ./DSA_assignment_group_60_exe <press enter>

Now you can see the Output.




**BRIEF WORKING OF THE CODE**

- The Mound data structure is implemented in the given code. The Mound data structure is a variation on
the binary heap data structure that preserves the heap property using a more intricate tree structure.

- The programme reads integer values from the "data.txt" file, puts them into the Mound data structure, and then repeatedly extracts the Mound's minimum value until all of the values have been extracted.

- Lnode and Mnode are two structures that the programme defines. A node in a linked list is represented by the Lnode structure, and a node in the Mound data structure is represented by the Mnode structure. A pointer to a linked list of Lnode structures is present in the Mnode structure.

- The program then defines a global array tree of Mnode structures, a global variable depth to keep track of the depth of the Mound, and a global variable CountofLeaf to keep track of the number of leaf nodes at the current depth of the Mound.

- The program then defines a set of functions to perform operations on the Mound data structure.

- createListNode() function creates a new Lnode structure and initializes it with the given data value.

- valueOfMound() function returns the value of an Mnode structure. If the list pointer of the Mnode structure is NULL, INT_MAX is returned.

- binarySearch() function performs binary search on the Mound data structure to find the insertion point for a new value. It takes two parameters, leaf, which is the index of the leaf node to start the search from, and data, which is the value to be inserted. The function returns the index of the parent node of the insertion point.

- randleaf() function returns a random leaf node at the current depth of the Mound.

- insertPosition() function returns the insertion point for a new value. It uses binarySearch() and randleaf() functions to find the insertion point. The function also updates the global variables depth as needed.

- insert() function inserts a new value into the Mound data structure. It creates a new Lnode structure with the given data value, finds the insertion point using the insertPosition() function, and inserts the Lnode structure at the beginning of the linked list pointed to by the list pointer of the Mnode structure at the insertion point.

- moundify() function restores the Mound property in a triangle of nodes. It takes an integer pos as input, which is the index of the parent node of the triangle. The function compares the values of the parent node and its two child nodes, and swaps the parent node with the child node with the minimum value if necessary. The function then recursively calls itself on the child node that was swapped with the parent node.

- extractMin() function extracts the minimum value from the Mound data structure. It returns INT_MAX if the Mound is empty. It extracts the minimum value from the linked list pointed to by the list pointer of the root node of the Mound, updates the list pointer to point to the next node in the linked list, and then restores the Mound property using the moundify() function.

- extractAll() function repeatedly calls extractMin() function to extract all the values from the Mound data structure, and prints each extracted value to the console.