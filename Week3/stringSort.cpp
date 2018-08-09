#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> strs(n);

	for (string& str : strs)
	{
		cin >> str;
	}

	sort(begin(strs), end(strs), [](const string& first, const string& second)
	{
		int secondPos = 0;
		for (size_t pos = 0; pos < first.length(); ++pos)
		{
			if (pos >= second.length())
			{
				return false;
			}
			if (tolower(first[pos]) == tolower(second[pos]))
			{
				continue;
			}
			return tolower(first[pos]) < tolower(second[pos]);
		}
		return true;
	});

	for (const auto& s : strs)
	{
		cout << s << " ";
	}
	cout << endl;

	return 0;
}