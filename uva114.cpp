#include <iostream>

using namespace std;

// 0 for increasing x
// 1 for increasing y
// 2 for decreasing x
// 3 for decreasing y
int xChange[] = {1, 0, -1, 0};
int yChange[] = {0, 1, 0, -1};

const int MaxGridSize = 55;

// All are indexed [y][x]
bool hasBumper[MaxGridSize][MaxGridSize];
int bumperCost[MaxGridSize][MaxGridSize];
int bumperScore[MaxGridSize][MaxGridSize];

int main()
{
   int XLen, YLen;
   cin >> XLen >> YLen;
   int wallCost, numBumper;
   cin >> wallCost >> numBumper;

   for (int y = 0; y < YLen; ++y)
   {
      for (int x = 0; x < XLen; ++x)
         hasBumper[y][x] = false;
   }

   while (numBumper--)
   {
      int x, y;
      cin >> x >> y;
      hasBumper[y][x] = true; //mark bumper
      cin >> bumperScore[y][x] >> bumperCost[y][x];
   }
   int overallScore = 0;

   int ballX, ballY, dir, lifetime;
   while (cin >> ballX >> ballY >> dir >> lifetime)
   {
      int score = 0;
      while (--lifetime > 0)
      {
         int newX = ballX + xChange[dir], newY = ballY + yChange[dir];

         if (newX == 1 || newX == XLen || newY == 1 || newY == YLen) // Hits wall
         {
            lifetime -= wallCost;
            dir = (dir + 3) % 4; //1->0->3->2 撞到障礙物要改變方向
         }
         else if (hasBumper[newY][newX]) //Hit bumper
         {
            lifetime -= bumperCost[newY][newX];
            score += bumperScore[newY][newX];
            dir = (dir + 3) % 4; //1->0->3->2
         }
         else //update coordinate
         {
            ballX = newX;
            ballY = newY;
         }
      }

      cout << score << endl;
      overallScore += score;
   }

   cout << overallScore << endl;
}