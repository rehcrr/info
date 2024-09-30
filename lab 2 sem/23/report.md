---

# Отчёт по лабораторной работе №23

---

## по курсу "Алгоритмы и структуры данных"

Студент группы М8О-208Б-23 Переверзев Александр

Работа выполнена

Преподаватель: каф.806 Севастьянов Виктор Сергеевич

### Отчёт

1. **Тема**: Проверка уровня листьев в бинарных деревьях на языке Си.

2. **Цель работы**: 
Разработать программу на языке C для создания бинарного дерева, добавления и удаления узлов, проверки, находятся ли все листья дерева на одном уровне, а также визуализации дерева.

3. **Задание**:
Разработать и отладить модуль для работы с бинарным деревом, который включает функции для:
- Создания бинарного дерева.
- Добавления и удаления узлов.
- Проверки уровня всех листьев дерева.
- Визуализации дерева.

4. **Идея, метод, алгоритм решения задачи**:
Для реализации задачи использована структура бинарного дерева, где каждый узел содержит целочисленное значение, а также указатели на левое и правое поддерево. В программе реализованы следующие функции:
- **Создание дерева**: дерево начинается с пустого узла.
- **Добавление узла**: добавление нового значения в дерево.
- **Удаление узла**: удаление существующего узла.
- **Проверка уровня листьев**: рекурсивный обход дерева с целью проверки, находятся ли все листья на одном уровне.
- **Визуализация дерева**: вывод структуры дерева на экран для удобства проверки.

5. **Сценарий выполнения работы**:
- Определена структура узла дерева.
- Реализованы функции для создания, добавления и удаления узлов дерева.
- Разработаны функции для проверки уровня всех листьев и визуализации дерева.
- Написано интерактивное меню для работы с деревом.

6. **Протокол**:

```
Program Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Example of program execution:

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 1

Enter the number to add: 10
Node with value 10 added.

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 1

Enter the number to add: 5
Node with value 5 added.

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 1

Enter the number to add: 15
Node with value 15 added.

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 3

Checking if all leaves are at the same level...
All leaves are at the same level.

Tree structure:
(10)
├──(5)
└──(15)

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 1

Enter the number to add: 7
Node with value 7 added.

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 3

Checking if all leaves are at the same level...
Leaves are at different levels.

Tree structure:
(10)
├──(5)
│   └──(7)
└──(15)

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 2

Enter the number to delete: 5
Node with value 5 deleted.

Menu:
1. Add a node
2. Delete a node
3. Check 
4. Visualize the tree
5. Exit

Enter your choice: 4

Tree structure:
(10)
└──(15)

```

7. **Выводы**:
В ходе работы была создана программа для работы с бинарным деревом, которая включает функции для добавления и удаления узлов, проверки, находятся ли листья на одном уровне, и визуализации дерева. Программа предоставляет гибкий интерфейс для управления деревом, что позволяет пользователю выполнять необходимые действия. Навыки, полученные в ходе выполнения задания, углубили понимание работы с бинарными деревьями и рекурсивными алгоритмами.