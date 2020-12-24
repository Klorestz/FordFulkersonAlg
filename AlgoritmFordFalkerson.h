#ifndef FUNC_CALC_H
#define FUNC_CALC_H
#include "mainwindow.h"
int n; //Размер матрицы пропускных способностей
int capacity[100][100], // Матрица пропускных способнотей
flow[100][100],  // Матрица потока
status[100],      // Обозначение вершин 2-прочитанная вершина; 1-текущая; 0-непрочитанная
path[100];       // Массив пути, по которому движемся
int head, tail;  // Начало, Конец
int q[102];      // Очередь, хранящая номера вершин входящих в неё
void CopyMatrix(int first_matrix[100][100],int second_matrix[100][100],int size)
{
    for(int i=0;i<size;i++)
      for(int j=0;j<size;j++)
      {
          second_matrix[i][j]=first_matrix[i][j];
      }
}
//Добавление в очередь
void addque(int x)
{
    q[tail] = x;
    tail++;
    status[x] = 1; //Отмечаем, что вершина является текущей
}
//Удаление из очереди
int removeque()
{
    int x = q[head];
    head++;
    status[x] = 2; //Отмечаем, что вершина x пройдена
    return x;
}
//Сравнение двух целых значений
int min(int x, int y)
{
    if (x >= y) x = y;
    return x;
}
//Поиск пути
int finding(int start, int end)
{
    int u, v;
    for (u = 0; u < n; u++) // Сначала отмечаем все вершины не пройденными
        status[u] = 0;

    head = 0;   // Начало очереди
    tail = 0;   // Конец очереди
    addque(start);      // Вступили на первую вершину
    path[start] = -1;

    while (head != tail)  // Пока конец не совпадёт с началом
    {
        u = removeque();       // вершина u пройдена
        for (v = 0; v < n; v++) // Смотрим смежные вершины
        {
            // Если вершина не пройдена и не заполнена (ненасыщенная дуга)
            if (status[v] == 0 && (capacity[u][v] - flow[u][v]) > 0)
            {
                addque(v);  // Вступаем на вершину v
                path[v] = u; // ОБновляем путь
            }
        }
    }
    if (status[end] == 2) // Если конечная вершина, то конец
        return 0;
    else return 1;//Если вершина неконечная
}
//Максимальный поток из истока в сток
int max_flow(int razmer, int matrix[100][100],int source, int stock, int matrixflow[100][100])
{    int i, j, u;
    int maxflow = 0;
    n=razmer;
    CopyMatrix(matrix,capacity,n);
    for (i = 0; i < n; i++)  // Зануляем матрицу потока
    {
        for (j = 0; j < n; j++)
            flow[i][j] = 0;
    }
    while (finding(source, stock) == 0)             // Пока существует путь
    {
        int delta = 10000;
        for (u = n - 1; path[u] >= 0; u = path[u]) // Найти минимальный поток в сети
        {
            delta = min(delta, (capacity[path[u]][u] - flow[path[u]][u]));
        }
        for (u = n - 1; path[u] >= 0; u = path[u]) // По алгоритму Форда-Фалкерсона
        {
            flow[path[u]][u] += delta;
            flow[u][path[u]] -= delta;
        }
    }
    for(i=0;i<n;i++){maxflow += flow[0][i];}
    CopyMatrix(flow,matrixflow,n);
    return maxflow;
}
#endif // FUNC_CALC_H
