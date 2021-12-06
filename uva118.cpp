#include <iostream>

using namespace std;

int main()
{
   int xLen, yLen;
   cin >> xLen >> yLen;

   //init isDisappear
   bool isDisappear[xLen + 1][yLen + 1];
   for (int i = 0; i <= xLen; ++i)
      for (int j = 0; j <= yLen; ++j)
         isDisappear[i][j] = false;

   int x, y;
   char orientation; //N->E->S->w
   char instruction;
   int changeX[4] = {0, 1, 0, -1};
   int changeY[4] = {1, 0, -1, 0};
   char orientation_char[4] = {'N', 'E', 'S', 'W'};
   while (cin >> x >> y >> orientation)
   {
      int dir, newX = x, newY = y;
      bool lost = false;
      switch (orientation) //將方向以數字代替
      {
      case 'N':
         dir = 0;
         break;

      case 'E':
         dir = 1;
         break;

      case 'S':
         dir = 2;
         break;

      case 'W':
         dir = 3;
         break;

      default:
         break;
      }
      getchar(); //要去掉之前的'\n'

      while ((instruction = getchar()) != '\n') //執行指令
      {

         switch (instruction)
         {
         case 'L':
            dir = (dir + 3) % 4;
            break;

         case 'R':
            dir = (dir + 1) % 4;
            break;

         case 'F':
            newX = x + changeX[dir];
            newY = y + changeY[dir];
            break;

         default:
            break;
         }

         if (instruction == 'F')
         {
            if (newX > xLen || newY > yLen || newX < 0 || newY < 0)
            {
               if (!isDisappear[x][y]) //如果此位置沒被記錄過就掉落
               {
                  printf("%d %d %c LOST\n", x, y, orientation_char[dir]);
                  lost = true;
                  //若過程中有機器人掉出邊界，會紀錄該位置（不管方位），避免有其他機器人也從同樣座標墜落
                  isDisappear[x][y] = true;
                  while ((instruction = getchar()) != '\n') //將後面的字元吃完
                     ;
                  break;
               }
            }
            else //如果沒超出邊界就更新
            {
               x = newX;
               y = newY;
            }

            // cout << instruction << endl;
            // printf("%d %d %c\n", x, y, orientation_char[dir]);
         }
      }
      if (!lost)
         printf("%d %d %c\n", x, y, orientation_char[dir]);
   }
   return 0;
}
