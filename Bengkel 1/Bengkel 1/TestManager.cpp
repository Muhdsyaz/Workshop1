#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "DrivingTest.h"
#include "TestManager.h"

bool TestManager::checkToBook(DrivingTest* test)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM drivingtest WHERE s_id = ?");

	ps->setString(1, test->s_id);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\t\t\t\t You already booked a driving test!";
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int TestManager::bookTest(DrivingTest* test, string studentID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO drivingtest VALUES (?, ?, ?, ?)");

	ps->setString(1, studentID);
	ps->setString(2, test->testDate);
	ps->setString(3, test->testTime);
	ps->setString(4, test->classcat);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

bool TestManager::checkTableDrivingTest(string studentID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM drivingtest WHERE s_id = ?");

	ps->setString(1, studentID);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\t\t\t Database is empty!";
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}


DrivingTest* TestManager::displayTest(string studentID)
{
	DrivingTest* test = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM drivingtest WHERE S_ID = ?");

	ps->setString(1, studentID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		test = new DrivingTest();

		test->s_id = rs->getString(1);
		test->testDate = rs->getString(2);
		test->testTime = rs->getString(3);
		test->classcat = rs->getString(4);
	}

	delete rs;
	delete ps;

	return test;
}