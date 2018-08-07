#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

int main()
{
	int commandNum;
	cin >> commandNum;

	map<set<string>, int> busStops;

	for (int commandNo = 0; commandNo<commandNum; ++commandNo)
	{
		int stopNum;
		cin >> stopNum;

		set<string> route;

		for (int stopNo = 0; stopNo < stopNum; ++stopNo)
		{
			string stopName;
			cin >> stopName;
			route.insert(stopName);
		}

		if (busStops.count(route) == 0)
		{
			int newRoute = busStops.size();
			busStops[route] = newRoute + 1;
			cout << "New bus " << newRoute + 1 << endl;
		}
		else
		{
			cout << "Already exists for " << busStops[route] << endl;
		}
	}

	return 0;
}