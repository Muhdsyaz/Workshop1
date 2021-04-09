#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "ClassHistory.h"
#include "HistoryManager.h"

ClassHistory* HistoryManager::selectHistory(string studentID)
{
	ClassHistory* history = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM class_history WHERE s_id = ?");

	ps->setString(1, studentID);

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	while (rs->next())
	{
		history = new ClassHistory();
		history->c_ID = rs->getString(2);
		history->attendance = rs->getString(3);
		history->fine = rs->getString(4);

		cout << "\t\t  " << i << "\t\t" << history->c_ID << "\t\t" << history->attendance << "\t\t" << history->fine << endl;
		i++;
	}

	delete rs;
	delete ps;

	return history;
}


int HistoryManager::selectCount() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT COUNT(s_id) FROM class_history");

	ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		return rs->getInt(1);
	}
	else
		return 0;
}

ClassHistory* HistoryManager::displayTotalFine(string studentID)
{
	ClassHistory* history = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT fine FROM class_history WHERE s_id = ?");

	double num, total = 0;

	ps->setString(1, studentID);

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	while (rs->next())
	{
		history = new ClassHistory();
		history->fine = rs->getString(1);

		num = stod(history->fine);
		total += num;

		i++;
	}

	delete rs;
	delete ps;

	cout << "\t\tTotal fine                                      " << setprecision(4) << total << endl;

		return history;
}
