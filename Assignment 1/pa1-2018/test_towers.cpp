//*****************************************************************************
//
// This part requires all the work to be done in this file only.
// You will be modifying this function only ->
//
//
//
//*****************************************************************************



#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include "stack.cpp"

using namespace std;

void towers(Stack<int>& a, Stack<int>& b, Stack<int>& c);
void helper_fucntion(int plates, Stack<int>& a, Stack<int>& c, Stack<int>& b);
bool testing();

int main()
{
	if (testing())
	{
		cout << "Test cases passed." << endl;
	} else {
		cout << "Test cases failed." << endl;
	}
}

void towers(Stack<int>& a, Stack<int>& b, Stack<int>& c)
{
	helper_fucntion(a.length(),a,c,b);
}
void helper_fucntion(int plates, Stack<int>& a, Stack<int>& c, Stack<int>& b)
{
	if(plates>0)
	{
		helper_fucntion(plates-1, a, b, c);
		c.push(a.pop());
		helper_fucntion(plates-1, b, c ,a);
		}
}

bool testing()
{
	srand(time(NULL));
	int maxValue = 500;
	
	for (int i = 1; i < 200; ++i)
	{
		Stack<int> a;
		Stack<int> b;
		Stack<int> c;
		vector<int> temp;

		for (int j = 0; j < i; ++j)
			temp.push_back((rand()+1) % maxValue);
		sort(temp.begin(), temp.end());

		for (int j = 0; j < i; ++j)
			a.push(temp[i - j - 1]);

		towers(a, b, c);

		for (int j = 0; j < i; ++j)
		{
			if (temp[j] != c.pop())
				return false;
		}
	}

	return true;
}

