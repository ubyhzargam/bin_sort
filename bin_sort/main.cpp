#include <iostream>
#include <limits>

using namespace std;

// Node structure for the linked list
struct Node {
  int data;
  Node* next;
};

// Function to insert a new element into the linked list
void Insert(Node* &head, int x) {
  Node* newNode = new Node;
  newNode->data = x;
  newNode->next = nullptr;

  if (head == nullptr) {
    head = newNode;
  } else {
    Node* temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Function to delete a node from the linked list
int Delete(Node* &head) {
  if (head == nullptr) return -1;

  int data = head->data;
  Node* temp = head;
  head = head->next;
  delete temp;

  return data;
}

// Function to find the maximum element in the array
int FindMax(const int A[], int n) {
  int max = A[0];
  for (int i = 1; i < n; ++i) {
    max = std::max(max, A[i]);
  }
  return max;
}

// Bin Sort implementation
void BinSort(int A[], int n) {
  // Find the maximum element
  int max = FindMax(A, n);

  // Create an array of linked lists to store elements in respective bins
  Node** p = new Node*[max + 1];
  
  // Initialize all bins to nullptr
  for (int i = 0; i <= max; ++i) {
    p[i] = nullptr;
  }

  // Insert each element into its corresponding bin
  for (int i = 0; i < n; ++i) {
    Insert(p[A[i]], A[i]);
  }

  // Traverse the bins and collect sorted elements
  int j = 0;
  for (int i = 0; i <= max; ++i) {
    while (p[i]) {
      A[j++] = Delete(p[i]);
    }
  }

  // Free the allocated memory
  delete[] p;
}

// Function to display the sorted array
void Display(const int A[], int n) {
  cout << "The elements of the array in the sorted order are:" << endl;
  for (int i = 0; i < n; ++i) {
    cout << A[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  if (n <= 0) {
    cout << "Invalid input. Please enter a positive number." << endl;
    return 1;
  }

  int A[n];
  cout << "Enter the elements: ";
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  BinSort(A, n);
  Display(A, n);

  return 0;
}
