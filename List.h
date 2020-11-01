#ifndef H_LIST
#define H_LIST

/// @brief ���� ������
struct Node
{
	/// @brief �������� �������� 
	int Data;

	/// @brief ��������� �� 
	/// ��������� �������
	Node* Next;
	/// @brief ��������� �� 
	/// ���������� �������
	Node* Prev;
};

/// @brief  ���������� �������� ������
struct List
{	
	/// @brief ������ ������
	Node* RootNode;
	
	/// @brief ��������� �������
	Node* LastNode;
};

/// @brief ������� ������������� ������
/// 
/// @param lst ��������� �� ������
/// 
/// @return ���������� ������������������ ������
/// 
List* ListInit(List* lst);

void ClearList(List* lst);

/// @brief ��������� ������� � ������ 
/// 
/// @param value �������� ������ ��������
/// 
/// @param lst ������, � ������� ����������� �������
///  
void Add(int value, List* lst);

/// @brief ����� ������� ����� 
///			 �������� ���������
/// 
/// @param value �������� �������� 
/// 
/// @param lst ������, � ������� ������������ ������� 
/// 
void InsertHead(int value, List* lst);

/// @brief ����� ������� ��������
/// 
/// @param index  ������ �������� �������
/// 
/// @param value �������� ������������ ��������
/// 
/// @param lst ������, � ������� ������������ �������
/// 
void Insert(int index, int value, List* lst);

/// @brief ������ ������� ���� ������
/// 
/// @param firstNode ������ ����
/// 
/// @param secondNode ������ ����
/// 
/// @param lst ������, � ������� ������������ ��������
/// 
void SwapNode(Node* firstNode, Node* secondNode, List* lst);

/// @brief ��������� ������� ��� �������� ������ 
///			�� ������� ��������� ������ �� � ������� �����������
///
/// @retval false	���� �����������
/// @retval true	���� ������������
/// 
/// @return false
bool IsNeedToSwap(List* lst);

/// @brief ��������� ������
/// 
/// @param lst ������ ��� ����������
/// 
void SortList(List* lst);

/// @brief �������� ����� ��������
/// 
/// @param element �������� �������� 
/// 
/// @param lst ������, � ������� ������������ �����
/// 
/// retval -1 ��� ���������� ������ ��������
/// retval index ������ ����������� ��������
/// 
/// @return ������ ���������� ��������
int SearchNode(int element, List* lst);

/// @brief ������� �������� ������ �� �����
/// 
/// @param lst ������, ������� ����� ��������
void ShowList(List* lst);

/// @brief ������� ��������� �������
/// 
/// @param lst ������, � ������� ����� ������� 
///				��������� �������
/// 
void RemoveLast(List* lst);

/// @brief �������� �������� �� ������� � 0
///
/// @param index ������ ���������� ��������
/// @param lst ������, � ������� ����� 
///				������� ������� �� �������
/// 
void RemoveByIndex(int index, List* lst);

#endif