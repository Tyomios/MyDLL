#include <iostream>
#include <Windows.h>

#include "Common.h"

using namespace std;


void ErrorByRemove(List* lst)
{
    Node* newRoot = new Node;
    newRoot->Next = lst->RootNode->Next;
    newRoot->Prev = lst->RootNode->Prev;

    cout << "��������� �������� ���� ������" <<
        " ������� ����� ��������" << endl;

    delete lst->RootNode;
    lst->RootNode = newRoot;

    lst->RootNode->Data = GetItem();

    lst->LastNode = lst->RootNode;
}


int GetItem()
{
    int value;
    cout << " ������� ������������� �������� ��������:" << endl;
    cin >> value;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "��, �������� �������� ����������. ��������� ����.\n";
        return GetItem();
    }

    return value;
}


int GetIndex(List* lst)
{
    int index;
    Node* temp = new Node;
    temp = lst->RootNode;
    cout << " ������� ������:" << endl;
    cin >> index;

    for (int i = 0; i < index - 1; ++i)
    {
        if ((!temp->Next) && (i < index - 1))
        {
            cout << "������, ������ ������ ���������� ��������." <<
                " ��������� ����" << endl;

            return GetIndex(lst);
        }

        temp = temp->Next;
    }

    if (index < 0)
    {
        cout << " ������! ������ �� ����� ���� �������������" << endl;
        return GetIndex(lst);
    }
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "��, �������� �������� ����������. ��������� ����.\n";
        return GetIndex(lst);
    }

    return index;
}