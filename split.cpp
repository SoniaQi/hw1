/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

// check if the last node is reached
if (in != NULL) {
  // create a copy of current node and call recurse w/o the current node
  Node* temp = in;
  in = temp->next;
  split(in, odds, evens);
  // check if the val of current node is odd or even
  if (temp->value % 2 == 1) {
    // add val to the front of the odd list
    Node* newN = new Node(temp->value, odds);
    odds = newN;
  }
  else {
    // add val to the front of the even list
    Node* newN = new Node(temp->value, evens);
    evens = newN;
}
  // delete the copy after using it
  delete temp;
}
else {
  // delete the entire in once all vals have been added
  delete in;
}
}

/* If you needed a helper function, write it here */