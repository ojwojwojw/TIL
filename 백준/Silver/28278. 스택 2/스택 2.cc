# include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	int top = 0;

	cin >> N;
	int* ST = new int[1000000];
	int result = -1;


	for (int i = 0; i < N; i++)
	{
		int order = 0;
		int X = 0;
		cin >> order;

		switch (order)
		{
		case(1):
		{
			cin >> X;
			ST[top] = X;
			top++;
			break;
		}
		case(2):
		{
			if (top > 0)
			{
				result = ST[top - 1];
				top--;
			}
			else {
				result = -1;
			}
			break;
		}
		case(3):
		{
			result = top;
			break;
		}
		case(4):
		{
			if (top > 0)
			{
				result = 0;
			}
			else
			{
				result = 1;
			}
			break;

		}
		case(5):
		{
			if (top > 0)
			{
				result = ST[top - 1];
			}
			else
			{
				result = -1;
			}
			break;

		}
		}


		if (order != 1)
		{
			cout << result << '\n';
		}

	}

	delete[] ST; // 메모리 반환

	return 0;
}