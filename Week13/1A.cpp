#include <iostream>
using namespace std;

struct Node
{
    const char* element;
    Node* next;

    Node(const char* e = NULL, Node* n = NULL)
    {
        element = e;
        next = n;
    }
};

struct SLinkedList
{
    Node* head;
    long size;

    SLinkedList()
    {
        head = NULL;
        //size = 0;
    }

    ~SLinkedList()
    {
        while(head != NULL)
        {
            Node* tmp = head;
            head = tmp->next;
            delete tmp;
        }
    }

    void addFirst(const char* element)
    {
        Node* newNode = new Node(element, head);
        head = newNode;
    }

    void addLast(const char *element)
    {
        Node* newNode = new Node(element, NULL);
        if (head == NULL)
            head = newNode;
        else
        {
            for (Node* tail = head; tail != NULL; tail = tail->next)
            {
                if (tail->next == NULL)
                {
                    tail->next = newNode;
                    break;
                }
            }
        }
    }

    void removeFirst()
    {
        Node* tmp = head;
        head = tmp->next;
        delete tmp;
    }

    void print()
    {
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next)
        {
            cout << tmp->element << endl;
        }
    }

    void removeLast()
    {
        Node* tmp = head;
        while(tmp->next->next != NULL)
        {
            tmp = tmp->next;
        }
        Node *tmp1 = tmp;
        tmp1 = tmp->next;
        tmp->next = NULL;
        delete tmp1;
    }

    void inserAfter(Node* p, const char* s){
        Node* tmp1 = new Node(s,NULL);
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next)
            if (tmp == p) {
                tmp1->next = p->next;
                tmp->next = tmp1;
                return;
            }
    }

    void removeNode(Node *p){
        Node* tmp1 = new Node;
        for(Node* tmp = head; tmp != NULL; tmp = tmp->next)
        {
            if (tmp == p) {
                if (p == head) head = p->next;
                else tmp1->next = p->next;
                delete p;
                return;
            }
            tmp1=tmp;
        }
    }
};

int main()
{
    SLinkedList list;
    list.addFirst("Binh");
    list.addFirst("Manh");
    list.addFirst("Minh");
    list.addLast("binh");
    list.addLast("long");
    //list.inserAfter(list.head, "php");
    //list.removeNode(list.head->next->next);
    //list.removeLast();
    //list.removeFirst();
    //list.~SLinkedList();
    list.print();

    return 0;
}
