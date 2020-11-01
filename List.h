#ifndef H_LIST
#define H_LIST

/// @brief узел списка
struct Node
{
	/// @brief значение элемента 
	int Data;

	/// @brief указатель на 
	/// следующий элемент
	Node* Next;
	/// @brief указатель на 
	/// предыдущий элемент
	Node* Prev;
};

/// @brief  двусвязный линейный список
struct List
{	
	/// @brief корень списка
	Node* RootNode;
	
	/// @brief последний элемент
	Node* LastNode;
};

/// @brief функция инициализации списка
/// 
/// @param lst указатель на список
/// 
/// @return возвращает инициализированный список
/// 
List* ListInit(List* lst);

void ClearList(List* lst);

/// @brief добавляет элемент в список 
/// 
/// @param value значение нового элемента
/// 
/// @param lst список, к воторый добавляется элемент
///  
void Add(int value, List* lst);

/// @brief метод вставки перед 
///			 корневым элементом
/// 
/// @param value значение элемента 
/// 
/// @param lst список, в котором производится вставка 
/// 
void InsertHead(int value, List* lst);

/// @brief метод вставки элемента
/// 
/// @param index  индекс элемента вставки
/// 
/// @param value значение вставляемого элемента
/// 
/// @param lst список, в котором производится вставка
/// 
void Insert(int index, int value, List* lst);

/// @brief меняет местами узлы списка
/// 
/// @param firstNode первый узел
/// 
/// @param secondNode второй узел
/// 
/// @param lst список, в котором производится действие
/// 
void SwapNode(Node* firstNode, Node* secondNode, List* lst);

/// @brief служебная функция для проверки списка 
///			на налицие элементов идущих не в порядке возрастания
///
/// @retval false	если отсутствуют
/// @retval true	если присутствуют
/// 
/// @return false
bool IsNeedToSwap(List* lst);

/// @brief сортирует список
/// 
/// @param lst список для сортировки
/// 
void SortList(List* lst);

/// @brief линейный поиск элемента
/// 
/// @param element значение элемента 
/// 
/// @param lst список, в котором производится поиск
/// 
/// retval -1 при отсутствии такого элемента
/// retval index индекс подходящего элемента
/// 
/// @return индекс найденного элемента
int SearchNode(int element, List* lst);

/// @brief выводит элементы списка на экран
/// 
/// @param lst список, который нужно показать
void ShowList(List* lst);

/// @brief удаляет последний элемент
/// 
/// @param lst список, в котором нужно удалить 
///				последний элемент
/// 
void RemoveLast(List* lst);

/// @brief удаление элемента по индексу с 0
///
/// @param index индекс удаляемого элемента
/// @param lst список, в котором нужно 
///				удалить элемент по индексу
/// 
void RemoveByIndex(int index, List* lst);

#endif