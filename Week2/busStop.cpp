#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int printVector(const vector<string>& vec, const string exclusion)
{
	int printedCount = 0;
	for (auto elem : vec)
	{
		if (exclusion != elem)
		{
			++printedCount;
			cout << elem << " ";
		}
	}

	return printedCount;
}

int busStop()
{
	int commandNum;
	cin >> commandNum;

	map<string, vector<string>> busStops;
	map<string, vector<string>> stopBuses;

	for (int commandNo = 0; commandNo<commandNum; ++commandNo)
	{
		string command;
		cin >> command;

		if (command == "NEW_BUS")
		{
			string busName;
			int stopNum;
			cin >> busName >> stopNum;

			for (int stopNo = 0; stopNo < stopNum; ++stopNo)
			{
				string stopName;
				cin >> stopName;
				busStops[busName].push_back(stopName);
				stopBuses[stopName].push_back(busName);
			}

		}
		else if (command == "BUSES_FOR_STOP")
		{
			string stopName;
			cin >> stopName;

			if (stopBuses.count(stopName)==0)
			{
				cout << "No stop" << endl;
			}
			else
			{
				printVector(stopBuses[stopName], "");
				cout << endl;
			}
		}
		else if (command == "STOPS_FOR_BUS")
		{
			string busName;
			cin >> busName;

			if (busStops.count(busName) == 0)
			{
				cout << "No bus" << endl;
			}
			else
			{
				for (auto stopName : busStops[busName])
				{
					cout << "Stop " << stopName << ": ";
					int busNum = printVector(stopBuses[stopName], busName);
					if (busNum == 0)
					{
						cout << "no interchange";
					}
					cout << endl;
				}
			}
		}
		else if (command == "ALL_BUSES")
		{
			if (busStops.empty())
			{
				cout << "No buses" << endl;
			}
			else
			{
				for (auto busStop : busStops)
				{
					cout << "Bus " << busStop.first << ": ";
					printVector(busStop.second, "");
					cout << endl;
				}
			}
		}
	}

	return 0;
}