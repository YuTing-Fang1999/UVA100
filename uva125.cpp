#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, from, to, max;
    int path[600][600];
    int city = 0;
    while (cin >> n)
    {
        memset(path, 0, sizeof(path));
        max = 0;
        //input path
        for (int i = 0; i < n; ++i)
        {
            cin >> from >> to;
            path[from][to] = 1;
            if (from > max)
                max = from;
            if (to > max)
                max = to;
        }

        //�p��qi��j�঳�X�ب��k
        //using Floyd-Warshall
        for (int k = 0; k <= max; ++k)
            for (int i = 0; i <= max; ++i)
                for (int j = 0; j <= max; ++j)
                    path[i][j] += path[i][k] * path[k][j];

        //�N���]��-1
        for (int i = 0; i <= max; ++i)
            for (int j = 0; j <= max; ++j)
                if (path[i][j] != 0 && path[j][i] != 0)
                {
                    path[i][j] = -1;
                    path[j][i] = -1;
                }

        //�p�Gi��j�|�g�L���N����|�]��-1
        for (int k = 0; k <= max; ++k)
            for (int i = 0; i <= max; ++i)
                for (int j = 0; j <= max; ++j)
                {
                    if (path[i][k] == -1 && path[k][j] > 0)
                        path[i][j] = -1;
                    if (path[i][k] > 0 && path[k][j] == -1)
                        path[i][j] = -1;
                }

        //print
        printf("matrix for city %d\n", city++);
        for (int i = 0; i <= max; ++i)
        {
            //�̫ᤣ�঳�Ů�!
            printf("%d", path[i][0]);
            for (int j = 1; j <= max; ++j)
            {
                printf(" %d", path[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
