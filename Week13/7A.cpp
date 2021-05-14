#include <iostream>
#include <cassert>

using namespace std;

struct DNode
{
    const char* element;
    DNode *next, *prev;

    DNode(const char* e = NULL, DNode* p = NULL, DNode *n = NULL)
    {
        element = e;
        next = n;
        prev = p;
    }
};

struct DList
{
    DNode *header, *trailer;

    DList()
    {
        header = NULL;
        trailer = NULL;
    }

    ~DList(){
        while (header != NULL)
        {
            DNode* tmp = header;
            header = tmp->next;
            delete tmp;
        }
        trailer = NULL;
    }

    void addFirst(const char* s)
    {
        DNode* newNode = new DNode(s);
        if (header == NULL){
            header = newNode;
            trailer = newNode;
            return;
        }

        header->prev = newNode;
        newNode->next = header;
        header = newNode;
    }

    void insertAfter(DNode* p, const char* e){
        assert(p!=NULL);
        bool pIsExist = false;
        DNode* newNode = new DNode(e,NULL,NULL);
        for(DNode* tmp = header; tmp != NULL; tmp = tmp->next)
            if (tmp == p) {
                pIsExist = true;
                newNode->next = p->next;
                newNode->prev = tmp;
                if (p->next != NULL) p->next->prev = newNode;
                p->next = newNode;
                return;
            }
        assert(pIsExist=false);
    }

    void print()
    {
        DNode* tmp = header;
        while(tmp !=  NULL)
        {
            cout << tmp->element << " ";
            tmp = tmp->next;
        }
    }


};

int main()
{
    DList dlist;
    //dlist.addFirst("ChuBeDan");
    //dlist.addFirst("MinhNguNgok");
    //dlist.addFirst("long");
    //dlist.~DList();
    DNode *binh = new DNode("Binh", NULL, NULL);
    dlist.insertAfter(binh, "binh");
    //dlist.insertAfter(dlist.header->next, "binhdz");
    //dlist.insertAfter(dlist.header, "binh");
    dlist.print();

    return 0;
}
