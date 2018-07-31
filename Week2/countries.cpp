#include <iostream>
#include <string>
#include <map>

using namespace std;

int countries()
{
	int commandNum;
	cin >> commandNum;

	map<string, string> countries;

	for (int commandNo=0; commandNo<commandNum; ++commandNo)
	{
		string command;
		cin >> command;

		if (command == "CHANGE_CAPITAL")
		{
			string country;
			cin >> country;

			string newCapital;
			cin >> newCapital;

			string capital = countries[country];
			if (capital == "")
			{
				cout << "Introduce new country " << country << " with capital " << newCapital << endl;
			}
			else
			{
				if (capital == newCapital)
				{
					cout << "Country " << country << " hasn't changed its capital" << endl;
				}
				else
				{
					cout << "Country " << country << " has changed its capital from " << capital << " to " << newCapital << endl;
				}
			}
			countries[country] = newCapital;
		}
		else if (command == "RENAME")
		{
			string country;
			cin >> country;

			string capital = countries[country];

			string newCountry;
			cin >> newCountry;

			if (capital == "" || countries[newCountry] != "" || country == newCountry)
			{
				cout << "Incorrect rename, skip" << endl;
			}
			else
			{
				cout << "Country " << country << " with capital " << capital << " has been renamed to " << newCountry << endl;
				countries[newCountry] = capital;
				countries.erase(country);
			}
		}
		else if (command == "ABOUT")
		{
			string country;
			cin >> country;

			string capital = countries[country];

			if (capital == "")
			{
				cout << "Country " << country << " doesn't exist" << endl;
			}
			else
			{
				cout << "Country " << country << " has capital " << capital << endl;
			}
		}
		else if (command =="DUMP")
		{
			bool isEmpty = true;
			for (auto country : countries)
			{
				if (country.second != "")
				{
					isEmpty = false;
					cout << country.first << '/' << country.second << " ";
				}
			}
			if (isEmpty)
			{
				cout << "There are no countries in the world";
			}
			cout << endl;
		}
	}

	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}
