#pragma once
#include "List.h"
#ifndef H_COMMON
#define H_COMMON

/// @brief ������� ��� ������� �������� ��������� ���� ������
///
/// @param lst ������, � ������� ��������� ������
void ErrorByRemove(List* lst);

/// @brief ������� ��� ��������� ����������� ��������
/// 
/// @return ���������� ������������� ��������
/// 
int GetItem();

/// @brief ��������� ������� ����� �������
/// 
/// @param lst ������, ��� ������� ����� ������
/// 
/// @return ���������� ��������, ���� ��� ���������
/// 
int GetIndex(List* lst);
#endif