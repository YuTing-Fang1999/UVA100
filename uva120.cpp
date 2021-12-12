#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;

void flip(int pancakes[], int totalPancakes, int index)
{
	for (int i = 0; i <= index / 2; ++i)
	{
		swap(pancakes[i], pancakes[index - i]);
	}
	printf("%d ", totalPancakes - index);
}

int main()
{
	string input_str;
	while (getline(cin, input_str))
	{
		cout << input_str << endl;
		stringstream ss(input_str);

		//init
		int pancakes[35] = {0};
		int totalPancakes = 0;
		while (ss >> pancakes[totalPancakes])
		{
			++totalPancakes;
		}

		//start compute
		int indexOfMax = 0;
		//設定找最大值的範圍
		for (int i = totalPancakes - 1; i > 0; --i)
		{
			indexOfMax = 0;
			//找此範圍內的最大值
			for (int j = 0; j <= i; ++j)
			{
				if (pancakes[indexOfMax] < pancakes[j])
					indexOfMax = j;
			}

			//indexOfMax 不在最右邊
			if (indexOfMax < i)
			{
				//flip indexOfMax to 最左邊
				if (indexOfMax != 0)
				{
					flip(pancakes, totalPancakes, indexOfMax);
				}
				//flip indexOfMax to 最右邊
				flip(pancakes, totalPancakes, i);
			}
		}

		printf("0\n");
	}
}
