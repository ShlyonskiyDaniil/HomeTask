#ifndef FAST_LIST
#ifndef UNTITLED_NODE_SAFETY_H
#define UNTITLED_NODE_SAFETY_H

#include "Node_non_exe.h"
#include <stdio.h>
#include "mm_malloc.h"


/*
 * Check_sum подсчитывает значение для поля check_sum, хранящегося в узле.
 * Возвращает подсчитанное значение.
 * В качестве аргумента принимает указатель на узел, для которого необходимо подсчитать значение
 */
int Check_sum (Node*);

/*
 * Is_ok выполняет проверку корректности использующихся данных.
 * Возвращает notOK в случае ошибки или isOK в случае успеха.
 * В качестве аргумента принимает указатель, который необходимо проверить.
 */
int Is_ok (Node* node);

#include "Node_safety.cpp"
#endif
#endif