#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() {
        head = NULL;
    }
    void Create() {
        head = NULL;
    }
    void Add(int new_element) {
        Node* new_node = new Node();
        new_node->data = new_element;
        new_node->next = NULL;
        if (head == NULL) {
            new_node->prev = NULL;
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = new_node;
        new_node->prev = last;
    }
    void Push(int new_element) {
        Node* new_node = new Node();
        new_node->data = new_element;
        if (head == NULL) {
            head = new_node;
            new_node->next = NULL;
            return;
        }
        head->prev = new_node;
        new_node->next = head;
        head = new_node;
    }
    void AddAt(int new_element, int position) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < position - 1; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return;
        }

        Node* new_node = new Node();
        new_node->data = new_element;

        if (temp->next == NULL) {
            temp->next = new_node;
            new_node->prev = temp;
            return;
        }

        temp->next->prev = new_node;

        new_node->next = temp->next;

        temp->next = new_node;

        new_node->prev = temp;

    }
    int Get() {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }
        Node* last = head;

        while (last->next != NULL)
            last = last->next;

        return last->data;
    }

    int GetAt(int position) {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }

        Node* temp = head;

        for (int i = 0; i < position; i++)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Position out of range" << endl;
            return -1;
        }

        return temp->data;
    }

    int Pop() {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return -1;
        }

        Node* temp = head;

        head = head->next;

        int popped_data = temp->data;

        delete temp;

        return popped_data;
    }

    void RemoveAt(int position) {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < position - 1; i++)
            temp = temp->next;

        if (temp == NULL || temp->next == NULL)
            return;

        Node* node_to_delete = temp->next;

        node_to_delete->prev = temp;

        temp->next = node_to_delete->next;

        delete node_to_delete;
    }

    void Sort() {

        if (head == NULL || head->next == NULL)
            return;

        Node* i, * j, * minNode, * lastNode = head, * temp = NULL;

        while (lastNode->next != NULL)
            lastNode = lastNode->next;

        for (i = head; i != lastNode; i = i->next) {

            minNode = i;

            for (j = i->next; j != NULL; j = j->next) {

                if (j->data < minNode->data)
                    minNode = j;
            }

            if (minNode != i) {

                temp = new Node();

                temp->data = i->data;
                i->data = minNode->data;
                minNode->data = temp->data;

                delete temp;
            }
        }
    }

    void Display() {

        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};


int main() {

    DoublyLinkedList list;

    list.Create();

    list.Add(5);
    list.Add(3);
    list.Add(1);
    list.Add(4);
    list.Add(2);

    cout << "Original List: ";
    list.Display();

    list.Push(6);

    cout << "List after Push(): ";
    list.Display();

    list.AddAt(7, 3);

    cout << "List after AddAt(): ";
    list.Display();

    cout << "Get(): " << list.Get() << endl;

    cout << "GetAt(): " << list.GetAt(2) << endl;

    cout << "Pop(): " << list.Pop() << endl;

    cout << "List after Pop(): ";
    list.Display();

    list.RemoveAt(2);

    cout << "List after RemoveAt(): ";
    list.Display();

    list.Sort();

    cout << "Sorted List: ";
    list.Display();

    return 0;
}
