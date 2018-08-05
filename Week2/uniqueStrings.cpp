#include <iostream>
#include <string>
#include <set>

using namespace std;

int uniqueStrings()
{
	int commandNum;
	cin >> commandNum;

	set<string> uniqueStrings;

	for (int commandNo = 0; commandNo < commandNum; ++commandNo)
	{
		string str;
		cin >> str;
		uniqueStrings.insert(str);
	}

	cout << uniqueStrings.size();

	return 0;
}