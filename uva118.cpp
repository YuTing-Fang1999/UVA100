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
      switch (orientation) //�N��V�H�Ʀr�N��
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
      getchar(); //�n�h�����e��'\n'

      while ((instruction = getchar()) != '\n') //������O
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
               if (!isDisappear[x][y]) //�p�G����m�S�Q�O���L�N����
               {
                  printf("%d %d %c LOST\n", x, y, orientation_char[dir]);
                  lost = true;
                  //�Y�L�{���������H���X��ɡA�|�����Ӧ�m�]���ޤ��^�A�קK����L�����H�]�q�P�ˮy�мY��
                  isDisappear[x][y] = true;
                  while ((instruction = getchar()) != '\n') //�N�᭱���r���Y��
                     ;
                  break;
               }
            }
            else //�p�G�S�W�X��ɴN��s
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
