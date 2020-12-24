#ifndef CSOURCECSTOCK_H
#define CSOURCECSTOCK_H
//Поиск источника в сети
int current_source(int matrix_algoritm[100][100], int size)
{
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
      {
        if (matrix_algoritm[j][i] != 0) break;
        if (j == size-1)
        {
            if (i != 0)            
              for(int s=0;s<size;s++)
              {
                  matrix_algoritm[s][i] = matrix_algoritm[s][0];
                  matrix_algoritm[s][0] = 0;
              }            
            return i;
        }
      }
    }
    return -1;
}
//Поиск стока в сети
int current_stock(int matrix_algoritm[100][100], int size)
{
    for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
      {
        if (matrix_algoritm[i][j] != 0) break;
        if (j == size-1)
        {
         if (i != 0)
           for(int s=0;s<size;s++)
           {
             matrix_algoritm[i][s] = matrix_algoritm[size-1][s];
             matrix_algoritm[size-1][s] = 0;
           }
         return i;

        }
      }
    }
    return -1;
}
#endif // CSOURCECSTOCK_H
