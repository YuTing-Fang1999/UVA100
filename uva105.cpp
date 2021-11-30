#include <iostream>

using namespace std;

int main()
{
   int skyline[10001] = {0};
   int L, H, R;
   int maxR = 0;
   bool space = false;
   while (cin >> L >> H >> R)
   {
      for (int i = L; i < R; ++i) //���൥��R
      {
         if (H > skyline[i])
            skyline[i] = H;
         if (R > maxR)
            maxR = R;
      }
   }
   for (int i = 1; i <= maxR; ++i)
   {
      if (skyline[i] != skyline[i - 1])
      {
         if (space) //���ڤ��঳�Ů�!!!���M�|WA
            cout << " ";
         else
            space = true;
         cout << i << " " << skyline[i];
      }
   }
   cout << endl; //���ݭn����!!!!���M�|WA
   return 0;
}
