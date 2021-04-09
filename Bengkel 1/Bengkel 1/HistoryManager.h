#ifndef HISTORYMANAGER_H
#define HISTORYMANAGER_H


class HistoryManager
{
public:
	ClassHistory* selectHistory(string studentID);

	int selectCount();

	ClassHistory* displayTotalFine(string studentID);

	

};

#endif // !PROGRAMMANAGER_H
