#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Lesson.h"
#include "ClassManager.h"
#include "Student.h"


Lesson* ClassManager::selectClass(int ID) //parameter int ID to pass value of class no
{
	Lesson* lesson = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM available_class where class_no = ?");
	
	    ps->setInt(1, ID);
		ResultSet* rs = ps->executeQuery();

		if (rs->next())
		{
			lesson = new Lesson();
			lesson->classID = rs->getString(2);
			lesson->date = rs->getString(3);
			lesson->time = rs->getString(4);
		}
		else
			lesson = 0;

		delete rs;
		delete ps;

	return lesson;
}

int ClassManager::selectMax(){
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT MAX(class_no) FROM available_class");

	ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		return rs->getInt(1);
	}
	else
		return 0;
}

bool ClassManager::checkTableClass(Lesson* lesson)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM class WHERE c_id = ?");

	ps->setString(1, lesson->classID);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\t\t Class ID entered is invalid!";
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

Lesson* ClassManager::searchClass(string classID)
{
	Lesson* lesson = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM class WHERE c_id = ?");

	ps->setString(1, classID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		lesson = new Lesson();

		lesson->classID = rs->getString(1);
		lesson->className = rs->getString(2);
		lesson->classDuration = rs->getString(3);
		lesson->classcat = rs->getString(4);
		
	}

	delete rs;
	delete ps;

	return lesson;
}

Lesson* ClassManager::searchAvailable(string classID)
{
	Lesson* lesson = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM available_class WHERE c_id = ?");

	ps->setString(1, classID);

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	while (rs->next())
	{
		lesson = new Lesson();

		lesson->classID = rs->getString(2);
		lesson->date = rs->getString(3);
		lesson->time = rs->getString(4);

		cout << "\t\t  " << i << "\t\t" << lesson->classID << "\t\t" << lesson->date << "\t\t" << lesson->time << endl;
		i++;
	}

	delete rs;
	delete ps;

	return lesson;
}