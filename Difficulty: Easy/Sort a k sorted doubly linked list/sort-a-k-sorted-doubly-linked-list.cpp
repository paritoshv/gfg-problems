//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
         if (!head) return head;

        // Min-heap to store the nodes
        priority_queue<DLLNode*, vector<DLLNode*>, function<bool(DLLNode*, DLLNode*)>> minHeap(
            [](DLLNode* a, DLLNode* b) { return a->data > b->data; }
        );

        DLLNode* newHead = nullptr;
        DLLNode* lastSorted = nullptr;

        // Insert the first k+1 elements into the heap
        DLLNode* current = head;
        for (int i = 0; current != nullptr && i <= k; ++i) {
            minHeap.push(current);
            current = current->next;
        }

        // While there are elements in the heap, keep extracting the minimum
        while (!minHeap.empty()) {
            // Get the smallest element from the heap
            DLLNode* minNode = minHeap.top();
            minHeap.pop();

            // If this is the first node, set it as the new head
            if (!newHead) {
                newHead = minNode;
                lastSorted = newHead;
            } else {
                // Link the sorted list with the new node
                lastSorted->next = minNode;
                minNode->prev = lastSorted;
                lastSorted = minNode;
            }

            // Add the next element from the original list to the heap
            if (current) {
                minHeap.push(current);
                current = current->next;
            }
        }

        // Mark the end of the sorted list
        lastSorted->next = nullptr;

        return newHead;
        
    }
};

//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// Driver
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends