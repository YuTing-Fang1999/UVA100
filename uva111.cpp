#include <iostream>

using namespace std;

int main()
{
   int n;
   cin >> n;

   //輸入答案
   int num;
   int tea_ans[25];
   for (int i = 1; i <= n; ++i)
   {
      cin >> num;
      tea_ans[num] = i;
   }

   //輸入學生的回答
   int stu_ans[25];
   while (cin >> num)
   {
      stu_ans[num] = 1;
      for (int i = 2; i <= n; ++i)
      {
         cin >> num;
         stu_ans[num] = i;
      }

      //用LCS算ans的分數
      int LCS[25][25] = {0};
      int maxScore = 0;
      for (int i = 1; i <= n; ++i)
      {
         for (int j = 1; j <= n; ++j)
         {
            if (stu_ans[i] == tea_ans[j])
            {
               LCS[i][j] = LCS[i-1][j-1]+1;
            }else{
            	LCS[i][j] = max(LCS[i-1][j],LCS[i][j-1]);
			}
         }
      }

      cout << LCS[n][n] << endl;
   }
   return 0;
}
