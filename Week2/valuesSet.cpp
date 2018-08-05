#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> values;
	std::for_each(m.begin(), m.end(), [&](const auto &entry){
		values.insert(entry.second);
	});

	return values;
}
/*
int main()
{
	map<int, string> str = { {1, "first"}, {2, "first"}, {3, "second"} };

	for (string s : BuildMapValuesSet(str))
	{
		cout << s << endl;
	}

	return 0;
}*/