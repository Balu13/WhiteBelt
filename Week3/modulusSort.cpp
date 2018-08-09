#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int modulusSort()
{
	int number;
	cin >> number;

	vector<int> numbers;
	for (int i = 0; i < number; ++i)
	{
		int num;
		cin >> num;
		numbers.push_back(num);
	}

	sort(begin(numbers), end(numbers), [](const auto& first, const auto& second)
	{
		return abs(first) < abs(second);
	});

	for (const auto& el : numbers)
	{
		cout << el << " ";
	}
	cout << endl;

	return 0;
}