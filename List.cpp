#include <iostream>


#include "List.h"
#include "Common.h"


using namespace std;


List* ListInit(List* lst)
{   
    lst->RootNode = nullptr;
    lst->LastNode = nullptr;
        
    return lst;
}

void Add(int value, List* lst)
{
    Node* newNode = new Node;
    newNode->Data = value;
    newNode->Next = nullptr;

    if (!lst->RootNode)
    {
        newNode->Prev = nullptr;
        lst->RootNode = lst->LastNode = newNode;
        return;
    }

    newNode->Prev = lst->LastNode;
    lst->LastNode->Next = newNode;
    lst->LastNode = newNode;
}


void InsertHead(int value, List* lst)
{
    Node* newNode = new Node;
    newNode->Data = value;

    newNode->Next = lst->RootNode;
    lst->RootNode->Prev = newNode;
    lst->RootNode = newNode;
}


void Insert(int index, int value, List* lst)
{
    Node* newNode = new Node;
    Node* temp = new Node;
    temp = lst->RootNode;
    newNode->Data = value;

    for (int i = 1; i < index; ++i)
    {
        temp = temp->Next;
    }
    if (temp == lst->RootNode)
    {
        InsertHead(value, lst);
        return;
    }
    if (!temp)
    {
        Add(value, lst);
        return;
    }

    newNode->Next = temp;
    newNode->Prev = temp->Prev;
    temp = temp->Prev;
    temp->Next = newNode;
    temp = temp->Next->Next;
    temp->Prev = newNode;
}


void SwapNode(Node* firstNode, Node* secondNode, List* lst)
{
    Node* fprev = new Node;
    Node* sprev = new Node;
    Node* fnext = new Node;
    Node* snext = new Node;

    fprev = firstNode->Prev;
    fnext = firstNode->Next;

    sprev = secondNode->Prev;
    snext = secondNode->Next;

    if ((secondNode == fnext) || (firstNode == sprev))
    {
        if ((firstNode == lst->RootNode) && (secondNode == lst->LastNode))
        {
            secondNode->Next = firstNode;
            secondNode->Prev = nullptr;
            firstNode->Prev = secondNode;
            firstNode->Next = nullptr;
            lst->RootNode = secondNode;
            lst->LastNode = firstNode;
            return;
        }
        if (firstNode == lst->RootNode)
        {
            secondNode->Next = firstNode;
            firstNode->Prev = secondNode;
            firstNode->Next = snext;
            snext->Prev = firstNode;
            secondNode->Prev = nullptr;
            lst->RootNode = secondNode;
            return;
        }
        if (secondNode == lst->LastNode)
        {
            firstNode->Prev = secondNode;
            secondNode->Next = firstNode;
            secondNode->Prev = fprev;
            fprev->Next = secondNode;
            firstNode->Next = nullptr;
            lst->LastNode = firstNode;
            return;
        }

        firstNode->Prev = secondNode;
        secondNode->Next = firstNode;
        secondNode->Prev = fprev;
        firstNode->Next = snext;
        fprev->Next = secondNode;
        snext->Prev = firstNode;
        return;
    }
    else
    {
        if ((firstNode == lst->RootNode) && (secondNode == lst->LastNode))
        {
            secondNode->Next = fnext;
            fnext->Prev = secondNode;
            secondNode->Prev = nullptr;
            firstNode->Prev = sprev;
            sprev->Next = firstNode;
            firstNode->Next = nullptr;
            lst->RootNode = secondNode;
            lst->LastNode = firstNode;
            return;
        }
        if (firstNode == lst->RootNode)
        {
            secondNode->Next = fnext;
            fnext->Prev = secondNode;
            firstNode->Prev = sprev;
            sprev->Next = firstNode;
            firstNode->Next = snext;
            snext->Prev = firstNode;
            secondNode->Prev = nullptr;
            lst->RootNode = secondNode;
            return;
        }
        if (secondNode == lst->LastNode)
        {
            firstNode->Prev = sprev;
            sprev->Next = firstNode;
            secondNode->Next = fnext;
            fnext->Prev = secondNode;
            secondNode->Prev = fprev;
            fprev->Next = secondNode;
            firstNode->Next = nullptr;
            lst->LastNode = firstNode;
            return;
        }

        secondNode->Prev = fprev;
        secondNode->Next = fnext;
        fnext->Prev = secondNode;
        firstNode->Next = snext;
        sprev->Next = firstNode;
        firstNode->Prev = sprev;
        fprev->Next = secondNode;
        snext->Prev = firstNode;

        return;
    }
}


bool IsNeedToSwap(List* lst)
{
    Node* container = lst->RootNode;
    Node* cursor = lst->RootNode->Next;

    while (cursor)
    {
        if (container->Data > cursor->Data)
        {
            return true;
        }

        container = container->Next;
        cursor = cursor->Next;
    }

    return false;
}


void SortList(List* lst)
{
    Node* container = lst->RootNode;
    Node* cursor = lst->RootNode->Next;

    while (cursor)
    {
        if (container->Data > cursor->Data)
        {
            SwapNode(container, cursor, lst);
            cursor = container;
        }

        container = container->Next;
        cursor = cursor->Next;
    }

    if (IsNeedToSwap(lst))
    {
        SortList(lst);
    }
}


int SearchNode(int element, List* lst)
{
    Node* temp = lst->RootNode;
    int index = 1;

    while (temp)
    {

        if (temp->Data == element)
        {
            return index;
        }
        if ((!temp->Next) && (temp->Data != element))
        {
            return -1;
        }

        temp = temp->Next;
        index++;
    }
}


void ShowList(List* lst)
{
    Node* temp = lst->RootNode;
    cout << "Список:" << " ";

    while (temp)
    {
        cout << temp->Data << '\t';
        temp = temp->Next;
    }
    cout << "\n" << endl;
}


void RemoveLast(List* lst)
{
    Node* temp = new Node;

    if (lst->RootNode == lst->LastNode)
    {
        return ErrorByRemove(lst);
    }
    else
    {
        temp = lst->LastNode->Prev;
        temp->Next = nullptr;

        delete lst->LastNode;
        lst->LastNode = temp;
    }
}


void RemoveByIndex(int index, List* lst)
{
    Node* temp = new Node;
    Node* nextNode = new Node;
    Node* prevNode = new Node;

    temp = lst->RootNode;

    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->Next;

    }

    if ((temp == lst->RootNode) && (!temp->Next))
    {
        return ErrorByRemove(lst);
    }


    nextNode = temp->Next;
    prevNode = temp->Prev;

    if (temp == lst->RootNode)
    {
        delete lst->RootNode;
        lst->RootNode = nextNode;
        return;
    }
    if (temp == lst->LastNode)
    {
        delete lst->LastNode;
        prevNode->Next = nullptr;
        lst->LastNode = prevNode;
        return;
    }

    nextNode->Prev = prevNode;
    prevNode->Next = nextNode;

    delete temp;
}


List::~List() 
{
    while (RootNode)
    {
        LastNode = RootNode->Next;         
        delete RootNode;
        RootNode = LastNode;
    }
}



