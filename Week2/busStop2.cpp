#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int busStop2()
{
	int commandNum;
	cin >> commandNum;

	map<vector<string>, int> busStops;

	for (int commandNo = 0; commandNo<commandNum; ++commandNo)
	{
		int stopNum;
		cin >> stopNum;

		vector<string> route(stopNum);

		for (int stopNo = 0; stopNo < stopNum; ++stopNo)
		{
			string stopName;
			cin >> stopName;
			route[stopNo] = stopName;
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