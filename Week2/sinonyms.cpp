#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	int commandNum;
	cin >> commandNum;

	map<string, set<string>> sinonyms;

	for (int commandNo = 0; commandNo < commandNum; ++commandNo)
	{
		string command;
		cin >> command;

		if (command == "ADD")
		{
			string first, second;
			cin >> first >> second;

			set<string> &firstValues = sinonyms[first];
			set<string> &secondValues = sinonyms[second];
			firstValues.insert(second);
			secondValues.insert(first);
		}
		else if (command == "CHECK")
		{
			string first, second;
			cin >> first >> second;

			set<string> values = sinonyms[first];
			if (sinonyms[first].count(second) == 0 && sinonyms[second].count(first) == 0)
			{
				cout << "NO";
			}
			else
			{
				cout << "YES";
			}
			cout << endl;
		}
		else if (command == "COUNT")
		{
			string word;
			cin >> word;

			cout << sinonyms[word].size() << endl;
		}
	}

	return 0;
}