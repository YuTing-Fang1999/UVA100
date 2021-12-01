#include <iostream>

using namespace std;

int main()
{
   int n;
   int arr[100][102];
   int row_arr[100][102];
   while (cin >> n)
   {
      for (int i = 0; i < n; ++i)
      {
         for (int j = 1; j <= n; ++j) //要從1開始輸入，否則第一個col永遠會被減掉
         {
            cin >> arr[i][j];
            row_arr[i][j] = row_arr[i][j - 1] + arr[i][j];
         }
      }

//      for (int i = 0; i < n; ++i)
//      {
//         for (int j = 0; j <= n; ++j)
//         {
//            cout << row_arr[i][j] << "  ";
//         }
//         cout << endl;
//      }

      int maxSum = 0, sum = 0;
      for (int j = 1; j < n; ++j)
      {
         for (int k = 0; k < j; ++k)
         {
            sum = 0;
            for (int i = 0; i < n; ++i)
            {

               sum += row_arr[i][j] - row_arr[i][k];
               if (sum > maxSum)
                  maxSum = sum;
               if (sum < 0)
                  sum = 0; //不然只會越加越小
               // printf("%d %d %d, sum=%d\n", j, k, i, sum);
            }
         }
      }
      cout << maxSum << endl;
   }

   return 0;
}
