#include <iostream>
#include <stack>
using namespace std;

struct Card
{
   char face;
   char suit;
};

void print_pile(stack<Card> pile[52])
{
   for (int i = 0; i < 52; ++i)
   {
      printf("%d ", pile[i].size());
   }
   printf("\n");
}

bool match(Card c1, Card c2)
{
   return (c1.face == c2.face || c1.suit == c2.suit);
}

//���L�Ű�䥪�䶡�jleftNum��index
int find_left_idx(stack<Card> pile[52], int i, int leftNum)
{
   int count = 0;
   int now = i;
   while (--now >= 0)
   {
      if (!pile[now].empty())
      {
         count++;
         if (count == leftNum)
         {
            if (match(pile[now].top(), pile[i].top()))
               return now;
            else
               return -1;
         }
      }
   }
   return -1;
}

int main()
{

   stack<Card> pile[52];
   Card card;

   while (cin >> card.face && card.face != '#')
   {
      //clear stack
      for (int i = 0; i < 52; i++)
         while (!pile[i].empty())
            pile[i].pop();

      //input
      cin >> card.suit;
      pile[0].push(card);
      for (int i = 1; i < 52; ++i)
      {
         cin >> card.face >> card.suit;
         pile[i].push(card);
      }

      //start move
      for (int i = 0; i < 52; i++)
      {
         if (!pile[i].empty())
         {
            //���䥪�T
            int leftIdx = find_left_idx(pile, i, 3);
            //�p�G����A�䥪�@
            if (leftIdx == -1)
               leftIdx = find_left_idx(pile, i, 1);

            //�p�G�i�H��
            if (leftIdx != -1)
            {
               //move
               pile[leftIdx].push(pile[i].top());
               pile[i].pop();

               //������n�q����m�A�~�򩹥���!
               i = leftIdx - 1;

               // print_pile(pile);
            }
         }
      }

      //print ans
      int pileNum = 0;
      for (int i = 0; i < 52; i++)
         if (!pile[i].empty())
            pileNum++;

      printf("%d pile", pileNum);
      if (pileNum > 1)
         printf("s");
      printf(" remaining:");
      for (int i = 0; i < 52; i++)
         if (!pile[i].empty())
            printf(" %d", pile[i].size());
      printf("\n");
   }
   return 0;
}
