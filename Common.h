#pragma once
#include "List.h"
#ifndef H_COMMON
#define H_COMMON

/// @brief функция для случаев удаления корневого узла списка
///
/// @param lst список, в котором удаляется корень
void ErrorByRemove(List* lst);

/// @brief функция для получения корректного значения
/// 
/// @return возвращает целочисленное значение
/// 
int GetItem();

/// @brief служебная функция ввода индекса
/// 
/// @param lst список, для котрого нужен индекс
/// 
/// @return возвращает значение, если оно корректно
/// 
int GetIndex(List* lst);
#endif