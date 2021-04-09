#include <iostream>
#include <string>
using namespace std;

#include <mysql/jdbc.h>
using namespace sql;

#include "DatabaseConnection.h"
#include "BookClass.h"
#include "BookingManager.h"

int BookingManager::bookClass(BookClass* book, string studentID)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("INSERT INTO book_class VALUES (?, ?)");

	ps->setInt(1, book->classNo);
	ps->setString(2, studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}

bool BookingManager::checkTableBookClass(BookClass* book)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM book_class WHERE class_no = ? AND s_id = ?");

	ps->setInt(1, book->classNo);
	ps->setString(2, book->studentID);

	ResultSet* rs = ps->executeQuery();

	if ((rs->next()))
	{
		cout << "\n\t\t\tYou already booked a class on this date! Please book another date" << endl << endl;
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int BookingManager::selectMax() {
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT MAX(class_no) FROM book_class");

	ResultSet* rs = ps->executeQuery();
	if (rs->next())
	{
		return rs->getInt(1);
	}
	else
		return 0;
}


BookClass* BookingManager::selectBooked(string studentID)
{
	BookClass* book = NULL;
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT b.class_no, a.c_id, a.class_date, a.class_time FROM available_class a, book_class b WHERE b.class_no = a.class_no AND s_id = ?");

	ps->setString(1, studentID);

	ResultSet* rs = ps->executeQuery();

	int i = 1;
	while (rs->next())
	{
		book = new BookClass();
        book->classNo = rs->getInt(1);
		book->c_id = rs->getString(2);
		book->date = rs->getString(3);
		book->time = rs->getString(4);

		cout << "\t\t  " << book->classNo << "\t\t" << book->c_id << "\t\t" << book->date << "\t\t" << book->time << endl;
		i++;
	}

	delete rs;
	delete ps;

	return book;
}

bool BookingManager::checkToDelete(BookClass* book)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("SELECT * FROM book_class WHERE class_no = ? AND s_id = ?");

	ps->setInt(1, book->classNo);
	ps->setString(2, book->studentID);

	ResultSet* rs = ps->executeQuery();

	if (!(rs->next()))
	{
		return false;
	}
	else
	{
		delete rs;
		delete ps;

		return true;
	}
}

int BookingManager::deleteBooked(BookClass* book)
{
	DatabaseConnection dbConn;
	PreparedStatement* ps = dbConn.prepareStatement("DELETE FROM book_class WHERE class_no = ? AND s_id = ?");

	ps->setInt(1, book->classNo);
	ps->setString(2, book->studentID);

	int status = ps->executeUpdate();

	delete ps;

	return status;
}