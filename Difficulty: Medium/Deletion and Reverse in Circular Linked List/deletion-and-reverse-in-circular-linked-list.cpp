//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Structure for the linked list node
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to print nodes in a given circular linked list
void printList(struct Node *head) {
    if (head != NULL) {
        struct Node *temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    } else {
        cout << "empty" << endl;
    }
    cout << endl;
}


// } Driver Code Ends

class Solution {
public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (head == nullptr || head->next == head) return head;

        Node* prev = nullptr;
        Node* curr = head;
        Node* frw = head->next;

        while (frw != head) {
            curr->next = prev;
            prev = curr;
            curr = frw;
            frw = frw->next;
        }

        // Last node should point to the previous node (head)
        curr->next = prev;
        head->next = curr;

        return curr; // New head after reversal
    }

    // Function to delete a node by key in a circular linked list
    Node* deleteNode(Node* head, int key) {
        if (head == nullptr) return head;  // If the list is empty

        Node* temp = head;

        // Case 1: The head node is the one to be deleted
        if (head->data == key) {
            if (head->next == head) {  // Only one node in the list
                delete head;
                return nullptr;  // The list is now empty
            }
            // Traverse to the last node to update the 'next' pointer
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;  // Last node points to the second node
            Node* toDelete = head;
            head = head->next;  // Move the head to the next node
            delete toDelete;
            return head;
        }

        // Case 2: The node to delete is not the head node
        while (temp->next != head && temp->next->data != key) {
            temp = temp->next;
        }

        // If the node is found, delete it
        if (temp->next->data == key) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }

        return head;  // Return the potentially updated head
    }
};

//{ Driver Code Starts.

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

        // Reading input into a vector
        while (ss >> number) {
            arr.push_back(number);
        }

        int key;
        cin >> key;
        cin.ignore();

        // Creating the circular linked list
        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make the list circular

        Solution ob;

        // Delete the node with the given key
        head = ob.deleteNode(head, key);

        // Reverse the circular linked list
        head = ob.reverse(head);

        // Print the modified list
        printList(head);
    }
    return 0;
}

// } Driver Code Ends