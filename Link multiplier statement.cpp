#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding rand()
using namespace std;


// ÊÚÑíİ ÚŞÏÉ ÇáŞÇÆãÉ
struct Node {
    int data;
    Node* next; // ÇáãÄÔÑ Åáì ÇáÚŞÏÉ ÇáÊÇáíÉ
    Node* prev; // ÇáãÄÔÑ Åáì ÇáÚŞÏÉ ÇáÓÇÈŞÉ
};




// ÏÇáÉ áÅÖÇİÉ ÚŞÏÉ Åáì äåÇíÉ ÇáŞÇÆãÉ
void append(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}


// ÏÇáÉ áÊæáíÏ ŞÇÆãÉ ÚÔæÇÆíÉ ãÖÇÚİÉ ÇáÊÑÇÈØ
Node* generateRandomList(int numNodes) {
    Node* head = nullptr;
    srand(time(0)); // ÊåíÆÉ ãæáÏ ÇáÃÑŞÇã ÇáÚÔæÇÆíÉ

    for (int i = 0; i < numNodes; i++) {
        int randomValue = rand() % 100; // ÊæáíÏ ŞíãÉ ÚÔæÇÆíÉ Èíä 0 æ99
        append(head, randomValue);
    }

    return head;
}


// ÏÇáÉ áØÈÇÚÉ ÇáŞÇÆãÉ
void printList(Node* head) {
    if (head == nullptr) {
        cout << "ÇáŞÇÆãÉ İÇÑÛÉ." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != nullptr && temp != head);

    cout << endl;
}


// ÏÇáÉ ááÊÍŞŞ ããÇ ÅĞÇ ßÇäÊ ÇáŞÇÆãÉ ãÖÇÚİÉ ÇáÊÑÇÈØ æÕáíğÇ Ãæ ÚŞÏíğÇ
string checkDoublyLinkedList(Node* head) {
    if (head == nullptr) {
        return "Empty List\n";
    }

    Node* start = head; // ÍİÙ ÇáÚŞÏÉ ÇáÃæáì
    Node* temp = head; //ááãÑæÑ Úáì ÇáÚŞÏ ÈÏæä ÊÍÑíß Çá head ÇáÃÓÇÓí

    // ÇáÊÍŞŞ ãä ÇáÊÑÇÈØ Èíä ÇáÚŞÏ ÃËäÇÁ ÇáÊäŞá ááÃãÇã
    while (temp->next != nullptr && temp->next != start) {
        if (temp->next->prev != temp) {
            return "The list is not properly doubled Linked.";
        }
        temp = temp->next;
    }

    // ÅĞÇ ßÇäÊ ÇáŞÇÆãÉ ÚŞÏíÉ
    if (temp->next == start && start->prev == temp) {
        return "The list is Nodularly interconnected.";
    }

    // ÅĞÇ ÇäÊåÊ ÇáŞÇÆãÉ ÈÜ nullptr İåí æÕáíøÉ
    if (temp->next == nullptr) {
        return "The List is conjunctive interconnected";
    }

    // ÅĞÇ áã íÊÍŞŞ Ãí ãä ÇáÍÇáÇÊ ÇáÓÇÈŞÉ
    return "The List is Not Valid";
}


int main() {

    // ÅäÔÇÁ ŞÇÆãÉ ÚÔæÇÆíÉ ÈÚÏÏ ãÍÏÏ ãä ÇáÚŞÏ
    int numNodes = 5; 
    Node* head = generateRandomList(numNodes);

    // ØÈÇÚÉ ÇáŞÇÆãÉ ÇáÚÔæÇÆíÉ
    cout << "the Random Linked List: ";
    printList(head);

    // ÇáÊÍŞŞ ãä äæÚ ÇáŞÇÆãÉ
    cout << checkDoublyLinkedList(head) << endl;


    return 0;

}