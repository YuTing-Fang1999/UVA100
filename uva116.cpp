#include <iostream>
using namespace std;

int main()
{
   int rowNum, colNum;
   while (cin >> rowNum >> colNum)
   {
      int arr[rowNum][colNum] = {0};
      int next[rowNum][colNum] = {0};

      //input array
      for (int i = 0; i < rowNum; ++i)
         for (int j = 0; j < colNum; ++j)
            cin >> arr[i][j];

      //start compute
      //�Ĥ@��col�̤p�~�N��r�嶶�ǳ̤p�A�ҥH�n�ѫ᩹�e��
      for (int j = colNum - 1; j >= 1; --j)
         for (int i = 0; i < rowNum; ++i)
         {
            int upIndex = (i - 1 + rowNum) % rowNum;
            int midIndex = i;
            int downIndex = (i + 1) % rowNum;

            int up = arr[i][j - 1] + arr[upIndex][j];
            int mid = arr[i][j - 1] + arr[midIndex][j];
            int down = arr[i][j - 1] + arr[downIndex][j];

            //�`�N!upIndex���@�w�N����p!�٬O�n�P�_!
            //�]���]�t����A�ҥH�T��if�O�ӧO����
            next[i][j - 1] = 1e8;
            if (up <= mid && up <= down) //�W�̤p
            {
               arr[i][j - 1] = up;
               next[i][j - 1] = min(next[i][j - 1], upIndex);
            }
            if (mid <= up && mid <= down) //���̤p
            {
               arr[i][j - 1] = mid;
               next[i][j - 1] = min(next[i][j - 1], midIndex);
            }

            if (down <= mid && down <= up) //�U�̤p
            {
               arr[i][j - 1] = down;
               next[i][j - 1] = min(next[i][j - 1], downIndex);
            }
         }

      //find minimal cost
      int minCost = 2e9;
      int minCostIndex = 0;
      for (int i = 0; i < rowNum; ++i)
         if (arr[i][0] < minCost)
         {
            minCost = arr[i][0];
            minCostIndex = i;
         }

      printf("%d", minCostIndex + 1);
      for (int j = 0; j < colNum - 1; ++j)
      {
         minCostIndex = next[minCostIndex][j];
         printf(" %d", minCostIndex + 1);
      }
      printf("\n");

      printf("%d\n", minCost);
   }
   return 0;
}
