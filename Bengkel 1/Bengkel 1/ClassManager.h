#ifndef CLASSMANAGER_H
#define CLASSMANAGER_H


class ClassManager
{
public:
	Lesson* selectClass(int ID);

	int selectMax();

	bool checkTableClass(Lesson* lesson);

	Lesson* searchClass(string classID);

	Lesson* searchAvailable(string classID);

};

#endif // !PROGRAMMANAGER_H
