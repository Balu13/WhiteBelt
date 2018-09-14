#include "stdafx.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}

	Date(int year, int month, int day)
	{
		if (month < 1 || month > 12)
		{
			throw logic_error("Month value is invalid: " + to_string(month));
		}
		else if (day < 1 || day > 31)
		{
			throw logic_error("Day value is invalid: " + to_string(day));
		}
	
		this->year = year;
		this->month = month;
		this->day = day;
	}
};

bool operator<(const Date& lhs, const Date& rhs)
{
	return (lhs.GetYear() == rhs.GetYear())
		? (lhs.GetMonth() == rhs.GetMonth())
				? lhs.GetDay() < rhs.GetDay()
				: lhs.GetMonth() < rhs.GetMonth()
		: lhs.GetYear() < rhs.GetYear();
}

ostream& operator<<(ostream& stream, const Date& date)
{
	cout << setw(4) << setfill('0') << date.GetYear()
		<< "-"
		<< setw(2) << setfill('0') << date.GetMonth()
		<< "-"
		<< setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
private:
	map<Date, set<string>> events;
public:
	void AddEvent(const Date& date, const string& event)
	{
		events[date].insert(event);
	}
	
	bool DeleteEvent(const Date& date, const string& event)
	{
		if (events.count(date) > 0 && events.at(date).count(event) > 0)
		{
			events.at(date).erase(event);
			if (events.at(date).size() == 0)
			{
				events.erase(date);
			}
			return true;
		}

		return false;
	}
	
	int DeleteDate(const Date& date)
	{
		int eventsNum { 0 };
		if (events.count(date) > 0)
		{
			eventsNum = events.at(date).size();
			events.erase(date);
		}

		return eventsNum;
	}

	set<string> Find(const Date& date) const
	{
		set<string> empty;
		return events.count(date) > 0
				? events.at(date)
				: empty;
	}
  
	void Print() const
	{
		for (const auto& dateEvents : events)
		{
			for (const auto& event : dateEvents.second)
			{
				cout << dateEvents.first << " " << event << endl;
			}
		}
	}
};

void PrintSet(const set<string> s)
{
	for (const auto& str : s)
	{
		cout << str << endl;
	}
}

int main()
{
	Database db;
    
	string command;
	while (getline(cin, command))
	{
		if (!command.empty())
		{
			stringstream temp;
			temp << command;

			temp >> command;
			if (command == "Print")
			{
				db.Print();
			}
			else
			{
				if (command!="Add" && command!="Find" && command!="Del")
				{
    				cout << "Unknown command: " << command << endl;
    				break;
				}
				int year, month, day;
				char sep1, sep2;
				string inputDate;
				temp >> inputDate;
				stringstream dateStream;
				dateStream << inputDate;
				dateStream >> year >> sep1 >> month >> sep2 >> day;
			//			cout << "Date read: " << year << sep1 << month << sep2 << day << endl;
				string temp2;
				if (dateStream)
				{
					dateStream >> temp2;
			//				cout << "Extra date info: " << temp2 << endl;
				}
				if (sep1 != '-' || sep2 != '-' || !temp2.empty())
				{
					cout << "Wrong date format: "
							<< inputDate << endl;
					break;
				}

				Date date{ 1,1,1 };
				try
				{
					date = { year, month, day };
				}
				catch (const exception& ex)
				{
					cout << ex.what() << endl;
					break;
				}
				
				if (command == "Find")
				{
					set<string> events = db.Find(date);
					PrintSet(events);
				}
				else
				{
					string event;
					temp >> event;

					if (command == "Add")
					{
						db.AddEvent(date, event);
					}
					else if (command == "Del")
					{
						if (!event.empty())
						{
							if (db.DeleteEvent(date, event))
							{
								cout << "Deleted successfully" << endl;
							}
							else
							{
								cout << "Event not found" << endl;
							}
						}
						else
						{
							cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
						}
					}
				}
			}
		}
	}

	return 0;
}
