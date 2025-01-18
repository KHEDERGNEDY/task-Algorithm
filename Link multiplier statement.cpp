#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For seeding rand()
using namespace std;


// ����� ���� �������
struct Node {
    int data;
    Node* next; // ������ ��� ������ �������
    Node* prev; // ������ ��� ������ �������
};




// ���� ������ ���� ��� ����� �������
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


// ���� ������ ����� ������� ������ �������
Node* generateRandomList(int numNodes) {
    Node* head = nullptr;
    srand(time(0)); // ����� ���� ������� ���������

    for (int i = 0; i < numNodes; i++) {
        int randomValue = rand() % 100; // ����� ���� ������� ��� 0 �99
        append(head, randomValue);
    }

    return head;
}


// ���� ������ �������
void printList(Node* head) {
    if (head == nullptr) {
        cout << "������� �����." << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != nullptr && temp != head);

    cout << endl;
}


// ���� ������ ��� ��� ���� ������� ������ ������� ������ �� ������
string checkDoublyLinkedList(Node* head) {
    if (head == nullptr) {
        return "Empty List\n";
    }

    Node* start = head; // ��� ������ ������
    Node* temp = head; //������ ��� ����� ���� ����� �� head �������

    // ������ �� ������� ��� ����� ����� ������ ������
    while (temp->next != nullptr && temp->next != start) {
        if (temp->next->prev != temp) {
            return "The list is not properly doubled Linked.";
        }
        temp = temp->next;
    }

    // ��� ���� ������� �����
    if (temp->next == start && start->prev == temp) {
        return "The list is Nodularly interconnected.";
    }

    // ��� ����� ������� �� nullptr ��� ������
    if (temp->next == nullptr) {
        return "The List is conjunctive interconnected";
    }

    // ��� �� ����� �� �� ������� �������
    return "The List is Not Valid";
}


int main() {

    // ����� ����� ������� ���� ���� �� �����
    int numNodes = 5; 
    Node* head = generateRandomList(numNodes);

    // ����� ������� ���������
    cout << "the Random Linked List: ";
    printList(head);

    // ������ �� ��� �������
    cout << checkDoublyLinkedList(head) << endl;


    return 0;

}