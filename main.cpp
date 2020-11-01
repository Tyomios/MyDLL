#include <iostream>
#include <Windows.h>

#include "List.h"
#include "MenuList.h"
#include "Common.h"


using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");

	List lst;
	List* list = &lst;
	ListInit(list);


	int choose;

	while (true)
	{
		ShowList(list);
		cout << "\n";

		ShowMenu();

		cin >> choose;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "ОЙ, введеное значение некоректно. Повторите ввод.\n";
		}

		switch (choose)
		{
			case 1:
			{
				Add(GetItem(), list);
				break;
			}
			case 2:
			{	
				RemoveLast(list);
				break;
			}
			case 3:
			{
				RemoveByIndex(GetIndex(list), list);
				cout << "Элемент удален " << endl;
				Sleep(3000);
				break;
			}
			case 4:
			{
				Insert(GetIndex(list) + 1, GetItem(), list);
				cout << "Готово :)" << endl;
				Sleep(1800);
				break;
			}
			case 5:
			{
				Insert(GetIndex(list), GetItem(), list);
				cout << "Готово :)" << endl;
				Sleep(1800);
				break;
			}
			case 6:
			{
				SortList(list);
				cout << " Список отсортирован ! :)" << "\n" << endl;
				Sleep(1800);
				break;
			}
			case 7:
			{
				int index;
				index = SearchNode(GetItem(), list);

				if (index > 0)
				{
					cout << " Элемент на " << index << " месте  " << endl;
				}
				if (index == -1)
				{
					cout << " Не найдено :((" << endl;
				}

				Sleep(2500);
				break;
			}
			default:
			{
				cout << "!! Неизвестная команда." << endl;
				cout << " Напишите CTRL + С для выхода" << endl;
				Sleep(3000);
				break;
			}
		}

		system("cls");
	}

	return 0;
}