#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *first;
    Node *last;
    int size;
};

void addFirst(List &list, int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = list.first;
    list.first = node;
    if (list.size == 0)
        list.last = node;
    list.size++;
}

void addLast(List &list, int data)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    if (list.size == 0)
        list.first = node;
    else
        list.last->next = node;
    list.last = node;
    list.size++;
}

void addBefore(List &list, int data, int value)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    if (list.size == 0)
        list.first = node;
    else
    {
        Node *current = list.first;
        while (current->next->data != value)
            current = current->next;
        node->next = current->next;
        current->next = node;
    }
    list.size++;
}

void addAfter(List &list, int data, int value)
{
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    if (list.size == 0)
        list.first = node;
    else
    {
        Node *current = list.first;
        while (current->data != value)
            current = current->next;
        node->next = current->next;
        current->next = node;
    }
    list.size++;
}

int sumOfDigits(int number)
{
    int sum = 0;
    while (number != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void insertBeforeEvenElement(List &list)
{
    Node *curr = list.first;

    if (curr->data % 2 == 0)
    {
        addFirst(list, sumOfDigits(curr->data) * 2);
        curr = curr->next;
    }

    while (curr->next != NULL)
    {
        if (curr->next->data % 2 == 0)
        {
            Node *next = curr->next;
            Node *newNode = new Node;
            curr->next = newNode;
            newNode->next = next;
            newNode->data = sumOfDigits(next->data) * 2;
            curr = next;
        }
        else
        {
            curr = curr->next;
        }
    }
}

void readList(List &list)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        addLast(list, data);
    }
}

void printList(List &list)
{
    Node *current = list.first;
    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

List list;

int main()
{
    readList(list);

    insertBeforeEvenElement(list);

    printList(list);

    return 0;
}
