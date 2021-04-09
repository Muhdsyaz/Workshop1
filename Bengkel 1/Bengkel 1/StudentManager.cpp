#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "Student.h"
#include "Lesson.h"
#include "StudentManager.h"

bool StudentManager::checkTableStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM student WHERE S_ID = ?");

	ps->setString(1, student->studentID);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\n\t\t\tUser ID already registered!" << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int StudentManager::insertStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO student VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

	ps->setString(1, student->studentID);
	ps->setString(2, student->name);
	ps->setString(3, student->dateOfBirth);
	ps->setString(4, student->gender);
	ps->setString(5, student->phone);
	ps->setString(6, student->address);
	ps->setString(7, student->email);
	ps->setString(8, student->password);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

Student* StudentManager::selectStudent(string studentID)
{
	Student* student = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM student WHERE S_ID = ?");

	ps->setString(1, studentID);

	ResultSet* rs = ps->executeQuery();

	if (rs->next())
	{
		student = new Student();

		student->studentID = rs->getString(1);
		student->name = rs->getString(2);
		student->dateOfBirth = rs->getString(3);
		student->gender = rs->getString(4);
		student->phone = rs->getString(5);
		student->address = rs->getString(6);
		student->email = rs->getString(7);
		student->password = rs->getString(8);
	}

	delete rs;
	delete ps;

	return student;
}

bool StudentManager::loginStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM student WHERE S_ID = ?");

	ps->setString(1, student->studentID);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		cout << "\n\t\tWrong id! Please try again" << endl << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		ps = dbConn.prepareStatement("SELECT * FROM student WHERE S_ID = ? AND S_PASSWORD = ?");

		ps->setString(1, student->studentID);
		ps->setString(2, student->password);

		rs = ps->executeQuery();

		if (!(rs->next()))
		{
			cout << "\n\t\t\tWrong password! Please try again " << endl << endl;
			return false;
		}

		delete rs;
		delete ps;
	}

	return true;
}

int StudentManager::updateNameStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE student SET s_name = ? WHERE s_id = ?");

	ps->setString(1, student->name);
	ps->setString(2, student->studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StudentManager::updateDobStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE student SET s_dateOfBirth = ? WHERE s_id = ?");

	ps->setString(1, student->dateOfBirth);
	ps->setString(2, student->studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StudentManager::updatePhoneStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE student SET s_phone = ? WHERE s_id = ?");

	ps->setString(1, student->phone);
	ps->setString(2, student->studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StudentManager::updateAddressStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE student SET s_address = ? WHERE s_id = ?");

	ps->setString(1, student->address);
	ps->setString(2, student->studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

int StudentManager::updateEmailStudent(Student* student)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("UPDATE student SET s_email = ? WHERE s_id = ?");

	ps->setString(1, student->email);
	ps->setString(2, student->studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

