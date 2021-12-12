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

        //計算從i到j能有幾種走法
        //using Floyd-Warshall
        for (int k = 0; k <= max; ++k)
            for (int i = 0; i <= max; ++i)
                for (int j = 0; j <= max; ++j)
                    path[i][j] += path[i][k] * path[k][j];

        //將環設為-1
        for (int i = 0; i <= max; ++i)
            for (int j = 0; j <= max; ++j)
                if (path[i][j] != 0 && path[j][i] != 0)
                {
                    path[i][j] = -1;
                    path[j][i] = -1;
                }

        //如果i到j會經過環就把路徑設為-1
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
            //最後不能有空格!
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
