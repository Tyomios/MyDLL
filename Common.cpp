#include <iostream>
#include <Windows.h>

#include "Common.h"

using namespace std;


void ErrorByRemove(List* lst)
{
    Node* newRoot = new Node;
    newRoot->Next = lst->RootNode->Next;
    newRoot->Prev = lst->RootNode->Prev;

    cout << "Удаляется корневой узел списка" <<
        " введите новое значение" << endl;

    delete lst->RootNode;
    lst->RootNode = newRoot;

    lst->RootNode->Data = GetItem();

    lst->LastNode = lst->RootNode;
}


int GetItem()
{
    int value;
    cout << " Введите целочисленное значение элемента:" << endl;
    cin >> value;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "ОЙ, введеное значение некоректно. Повторите ввод.\n";
        return GetItem();
    }

    return value;
}


int GetIndex(List* lst)
{
    int index;
    Node* temp = new Node;
    temp = lst->RootNode;
    cout << " Введите индекс:" << endl;
    cin >> index;

    for (int i = 0; i < index - 1; ++i)
    {
        if ((!temp->Next) && (i < index - 1))
        {
            cout << "Ошибка, индекс больше количества элеметов." <<
                " Повторите ввод" << endl;

            return GetIndex(lst);
        }

        temp = temp->Next;
    }

    if (index < 0)
    {
        cout << " Ошибка! Индекс не может быть отрицательным" << endl;
        return GetIndex(lst);
    }
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "ОЙ, введеное значение некоректно. Повторите ввод.\n";
        return GetIndex(lst);
    }

    return index;
}