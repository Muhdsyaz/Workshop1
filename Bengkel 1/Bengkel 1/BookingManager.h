#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H


class BookingManager
{
public:

	int bookClass(BookClass* book, string studentID);

	bool checkTableBookClass(BookClass* book);

	int selectMax();

	BookClass* selectBooked(string ID);

	bool checkToDelete(BookClass* book);

	int deleteBooked(BookClass* book);

};

#endif // !PROGRAMMANAGER_H
