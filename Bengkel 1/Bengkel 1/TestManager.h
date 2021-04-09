#ifndef TESTMANAGER_H
#define TESTMANAGER_H


class TestManager
{
public:
	
	bool checkToBook(DrivingTest* test);

	int bookTest(DrivingTest* test, string no);

	bool checkTableDrivingTest(string studentID);

	DrivingTest* displayTest(string studentID);

};

#endif 
