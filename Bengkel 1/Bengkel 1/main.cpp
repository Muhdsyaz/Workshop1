#include <iostream>
#include "Student.h"
#include "Lesson.h"
#include "BookClass.h"
#include "ClassHistory.h"
#include "DrivingTest.h"
#include "StudentManager.h"
#include "ClassManager.h"
#include "BookingManager.h"
#include "HistoryManager.h"
#include "TestManager.h"
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;

void loginMenu();
void mainMenu();
void registration();
void studentLogin();
void studentStatus();
void classHistory(string ID);
void studentInfo(string ID);
void classMenu();
void bookClass();
void searchClass();
void displayBookedClass(string ID);
void cancelClass(string ID);
void drivingTestMenu();
void drivingTest(string ID);
void displayBookedTest(string ID);
void exit();
string ID;
int option;
char ans;


void loginMenu()
{
	cout << "\n\n" << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                 Welcome To UDrive System             " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t======================================================" << endl << endl;

	cout << "\t\t     1. CREATE ACCOUNT                                " << endl;
	cout << "\t\t     2. LOGIN                                         " << endl;
	cout << "\t\t     3. EXIT                                          " << endl << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\n\n" << endl;

		cout << "\n\t\t     Please choose option : ";
		cin >> option;

		switch (option)
		{
		case 1:
			registration();
			break;

		case 2:
			studentLogin();
			break;

		case 3:
			exit();
			break;

		default:
			cout << "\n\t\t\tInvalid option!\n\n";
			system("pause");
			system("cls");
			loginMenu();

		}
}

void mainMenu()
{
	system("pause");
	system("cls");
	StudentManager studentManager;
	Student* student = new Student();
	student = studentManager.selectStudent(ID);
	cout << "\n\n" << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                         Main Menu                    " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\t\t           Welcome " << student->name << endl << endl;
	cout << "\t\t     1. STUDENT STATUS                                " << endl;
	cout << "\t\t     2. CLASS                                         " << endl;
	cout << "\t\t     3. DRIVING TEST                                  " << endl;
	cout << "\t\t     4. EXIT                                          " << endl;
	cout << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\n\n" << endl;


	cout << "\t\t     Please choose option : ";
	cin >> option;
	
	if (option == 1) {
		studentStatus();
	}
	else if (option == 2) {
		classMenu();
	}
	else if (option == 3) {
		drivingTestMenu();
	}
	else if (option == 4) {
		exit();
	}
	else {
		cout << "\n\t\t\tInvalid option! Please choose again. " << endl << endl;
		mainMenu();
	}

}

void registration() {
	system("pause");
	system("cls");
	StudentManager studentManager;
	Student* student = new Student();

	cout << "\n\n" << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t             UDrive System User Registration          " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t======================================================" << endl << endl;

	cout << "\n\n\t\tPlease enter 1 to register OR enter other number to return : ";
	cin >> option;
	if (option == 1) {
		cout << "\n\t\tPlease enter the student details" << endl << endl;
		cout << "\t\tStudent ID:\t";
		cin.ignore();
		getline(cin, student->studentID);
		while ((student->studentID).length() != 12) {
			cout << "\t\t\tInvalid student ID range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tStudent ID:\t\t";
			getline(cin, student->studentID);
		}

		cout << "\t\tName:\t\t";
		getline(cin, student->name);
		while ((student->name).length() < 6) {
			cout << "\t\t\tPlease enter full name as in yout IC!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tName:\t\t";
			getline(cin, student->name);
		}

		cout << "\t\tDate of birth (DD/MM/YYYY):\t";
		getline(cin, student->dateOfBirth);
		while ((student->dateOfBirth).length() < 10) {
			cout << "\t\t\tInvalid date range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tDate of birth (DD/MM/YYYY):\t";
			getline(cin, student->dateOfBirth);
		}

		cout << "\t\tGender:\t\t";
		getline(cin, student->gender);

		cout << "\t\tPhone:\t\t";
		getline(cin, student->phone);
		while ((student->phone).length() < 10 || (student->phone).length() > 11) {
			cout << "\t\t\tInvalid phone number range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tPhone:\t\t";
			getline(cin, student->phone);
		}

		cout << "\t\tAddress:\t\t";
		getline(cin, student->address);
		while ((student->address).length() < 12) {
			cout << "\n\t\t\tInvalid address range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tAddress:\t\t";
			getline(cin, student->address);
		}

		cout << "\t\tEmail:\t";
		getline(cin, student->email);
		while ((student->email).length() < 12) {
			cout << "\n\t\t\tInvalid email range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tEmail:\t";
			getline(cin, student->email);
		}

		cout << "\t\tPassword:\t\t";
		getline(cin, student->password);
		while ((student->password).length() < 6) {
			cout << "\n\t\t\tPassword must at least 6 characters!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tPassword:\t\t";
			getline(cin, student->password);
		}

		if (studentManager.checkTableStudent(student)) {

			int status = studentManager.insertStudent(student);

			if (status != 0)
				cout << "\n\t\t\tSuccessfully added a new student." << endl << endl;
			else
				cout << "\t\t\tUnable to add a new student." << endl << endl;

			system("pause");
			system("cls");
			loginMenu();
		}
		else {
			cout << "\t\t\tUnable to add a new student." << endl << endl;
			system("pause");
			system("cls");
			loginMenu();
		}
	}
	else {
		cout << "\n\n";
		system("pause");
		system("cls");
		loginMenu();
	}
}

void studentLogin() {
	system("pause");
	system("ClS");
	string pass;
	int i = 0;
	char a;

	cout << "\n\n" << endl;
	cout << "\t\t======================================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t              UDrive System User Login                " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t======================================================" << endl << endl;

    StudentManager studentManager;
	Student* login = new Student();

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\t\tStudent ID:\t";
		getline(cin, ID);
		while (ID.length() != 12) {
			cout << "\n\t\t\tInvalid student ID range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tStudent ID:\t";
			getline(cin, ID);
		}
		login->studentID = ID;

		cout << "\t\tPassword:\t";


		getline(cin, login->password);
		while ((login->password).length() < 6) {
			cout << "\n\t\t\tPassword must at least 6 characters!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tPassword:\t";
			getline(cin, login->password);
		}

		if (studentManager.loginStudent(login)) {
			cout << endl << endl;
			cout << "\t\t\tUser login successfully." << endl << endl;

			mainMenu();
		}
		else {
			system("pause");
			system("ClS");
			loginMenu();
		}
}

void studentStatus() {

	system("pause");
	system("cls");

	cout << "\n\n" << endl;
	cout << "                ======================================" << endl;
	cout << "                                                            " << endl;
	cout << "                             Student Status           " << endl;
	cout << "                                                      " << endl;
	cout << "                ======================================" << endl<<endl;
	cout << "     1. STUDENT INFO                                       " << endl;
	cout << "     2. MILESTONE                                          " << endl;
	cout << "     3. CLASS HISTORY                                      " << endl;
	cout << "     4. LOGOUT                                             " << endl;
	cout << "     5. RETURN                                             " << endl;
	cout << "\n\n" << endl;

	cout << endl << "     Please choose option : ";
	cin >> option;

	if (option == 1) {
		studentInfo(ID);
	}
	else if (option == 2) {
		system("pause");
		system("cls");

		cout << "\n\n" << endl;
		cout << "                \t\t======================================" << endl;
		cout << "                                                          " << endl;
		cout << "                \t\t          Student Milestone           " << endl;
		cout << "                                                          " << endl;
		cout << "                \t\t======================================" << endl << endl;
		cout << " \t------------/   ------------/   ------------/   ------------/   ------------/   ------------/        " << endl;
		cout << " \t  KPP01    /     Computer  /      KPP02    /      KPP03    /    Pre Test   /     JPJ Test  /         " << endl;
		cout << " \t (8 hour) /       test    /      (6 hour) /     (10 hour) /     (2 hour)  /      (2 hour) /          " << endl;
	    cout << " \t---------/      ---------/      ---------/      ---------/      ---------/      ---------/           " << endl << endl;
		cout << "\tStudent will need to progress through all these session in order to complete the course. " << endl << endl;
		studentStatus();
	}
	else if (option == 3) {
		classHistory(ID);
		studentStatus();
	}
	else if (option == 4) {
		system("pause");
		system("cls");
		loginMenu();
	}
	else if (option == 5) {
		mainMenu();
	}
	else {
		cout << "\n\tInvalid option! Please choose again. " << endl << endl;
		studentStatus();
	}
}

void classHistory(string ID) {
	system("pause");
	system("cls");
	HistoryManager historyManager;
	ClassHistory* history = new ClassHistory();
	
	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                            " << endl;
	cout << "\t\t                             Class History            " << endl;
	cout << "\t\t                                                            " << endl;
	cout << "\t\t                ======================================" << endl << endl;

	cout << "\t\t\tThe table below shows student booked class" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t  No.           Class ID        Attendance      Fine          " << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	
	history = historyManager.selectHistory(ID);
	cout << "\t\t--------------------------------------------------------------" << endl;
	historyManager.displayTotalFine(ID);
	cout << endl;
	studentStatus();
}

void studentInfo(string ID) {
	system("pause");
	system("cls");
	StudentManager studentManager;
	Student* update = new Student();

	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                            " << endl;
	cout << "\t\t                             Student Info             " << endl;
	cout << "\t\t                                                            " << endl;
	cout << "\t\t                ======================================" << endl << endl;

	Student* student = studentManager.selectStudent(ID);

	cout << "\t\t     1.Name : " << student->name << endl;
	cout << "\t\t     2.Date of birth : " << student->dateOfBirth << endl;
	cout << "\t\t     3.Phone : " << student->phone << endl;
	cout << "\t\t     4.Address : " << student->address << endl;
	cout << "\t\t     5.Email : " << student->email << endl<<endl;

	cout << "\t\tPlease choose 1-5 to update information OR choose 6 to return : ";
	update->studentID = ID;
	cin >> option;

	if (option == 1) {
		cout << "\t\tEnter new name : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, update->name);
		while ((update->name).length() < 6) {
			cout << "\t\t\tPlease enter full name as in yout IC!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tEnter new name : ";
			getline(cin, update->name);
		}
		cout << "\n\n\t\tName will be changed. Are you sure? (Y/N) : ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			studentManager.updateNameStudent(update);
			cout << "\t\t\tName changed successfully "<< endl << endl;
		}
		studentInfo(ID);
	}
	else if (option == 2){
		cout << "\t\tEnter new date of birth : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, update->dateOfBirth);
		while ((update->dateOfBirth).length() < 10) {
			cout << "\t\t\tInvalid date format!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tEnter new date of birth : ";
			getline(cin, update->dateOfBirth);
		}
		cout << "\n\n\t\tDate of birth will be changed. Are you sure? (Y/N) : ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			studentManager.updateDobStudent(update);
			cout << "\t\t\tDate of birth changed successfully " << endl << endl;
		}
		studentInfo(ID);
	}
	else if (option == 3) {
		cout << "\t\tEnter new phone number : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, update->phone);
		while ((update->phone).length() < 10 || (update->phone).length() > 11) {
			cout << "\t\t\tInvalid phone number range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tEnter new phone number : ";
			getline(cin, update->phone);
		}
		cout << "\n\n\t\tPhone number will be changed. Are you sure? (Y/N) : ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			studentManager.updatePhoneStudent(update);
			cout << "\t\t\tPhone number changed successfully " << endl << endl;
		}
		studentInfo(ID);
	}
	else if (option == 4) {
		cout << "\t\tEnter new address : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, update->address);
		while ((update->address).length() < 12) {
			cout << "\t\t\tInvalid address range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tEnter new address : ";
			getline(cin, update->address);
		}
		cout << "\n\n\t\tAddress will be changed. Are you sure? (Y/N) : ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			studentManager.updateAddressStudent(update);
			cout << "\t\t\tAddress changed successfully " << endl << endl;
		}
		studentInfo(ID);
	}
	else if (option == 5) {
		cout << "\t\tEnter new email : ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, update->email);
		while ((update->email).length() < 12) {
			cout << "\t\t\tInvalid email range!" << "\n\t\t\tTry again " << endl << endl;
			cout << "\t\tEnter new email : ";
			getline(cin, update->email);
		}
		cout << "\n\n\t\tEmail will be changed. Are you sure? (Y/N) : ";
		cin >> ans;

		if (ans == 'Y' || ans == 'y') {
			studentManager.updateEmailStudent(update);
			cout << "\t\t\tEmail changed successfully " << endl << endl;
		}
		studentInfo(ID);
	}
	else if (option < 1 || option > 6) {
		cout << "\n\t\t\tInvalid option! Please choose again. " << endl << endl;
		studentInfo(ID);
	}
	else {
		studentStatus();
	}
}

void classMenu() {
	system("pause");
	system("cls");

	cout << "\n\n" << endl;
	cout << "                ======================================" << endl;
	cout << "                                                            " << endl;
	cout << "                               Class Menu             " << endl;
	cout << "                                                            " << endl;
	cout << "                ======================================" << endl << endl;
	cout << "     1. BOOK CLASS             " << endl;
	cout << "     2. DISPLAY BOOKED CLASS   " << endl;
	cout << "     3. SEARCH CLASS           " << endl;
	cout << "     4. CANCEL CLASS           " << endl;
	cout << "     5. RETURN                 " << endl;
	cout << "\n\n" << endl;

	cout << endl << "     Please choose option : ";
	cin >> option;
	if (option == 1) {
		bookClass();
	}
	else if (option == 2) {
		displayBookedClass(ID);
	}
	else if (option == 3) {
		searchClass();
	}
	else if (option == 4) {
		cancelClass(ID);
	}
	else if (option == 5) {
		mainMenu();
	}
	else {
		cout << "\n\tInvalid option! Please choose again. " << endl << endl;
		classMenu();
	}
}

void bookClass() {
	system("pause");
	system("cls");
	ClassManager classManager;
	BookingManager bookingManager;
	BookClass* book = new BookClass();
	Lesson* lesson = new Lesson();
	book->studentID = ID;

	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                              Book Class              " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                ======================================" << endl << endl;

	cout << "\t\t\tThe table below shows available class within this month." << endl;
	cout << "\t\t--------------------------------------------------------------------------" << endl;
	cout << "\t\t       No.              Class ID        Date                      Time       " << endl;
	cout << "\t\t--------------------------------------------------------------------------" << endl;

	for (int i = 1; i <= classManager.selectMax(); i++) 
	{
		lesson = classManager.selectClass(i);
		if (lesson != 0) {
			cout << "\t\t       " << i << "\t\t" << lesson->classID << "\t\t" << lesson->date << "\t\t" << lesson->time << endl;
		}
	}
	cout << "\n\n\t\t\tPlease enter 1 to book a class, enter 2 to return : ";
	cin >> option;
	if (option == 1) {
		cout << "\n\t\t\tEnter class no : ";
		cin >> book->classNo;

		if (book->classNo < 1 || book->classNo > classManager.selectMax()) {
			cout << "\n\t\t\tNumber entered not in range! Please choose again. " << endl << endl;
			bookClass();
		}
		else {
			if (bookingManager.checkTableBookClass(book)) {
				cout << "\n\n\t\t\tAre you sure you want to book this class? (Y/N) : ";
				cin >> ans;

				if (ans == 'Y' || ans == 'y') {
					int status = bookingManager.bookClass(book, ID);
					if (status != 0) {
						cout << "\n\n\t\t\tSuccessfully booked a class." << endl;
						classMenu();
					}
					else {
						cout << "\n\n\t\t\tUnable to book a class." << endl;
						classMenu();
					}
				}
				else if (ans == 'N' || ans == 'n') {
					cout << "\n\t\t\tBooking cancelled." << endl;
					cout << "\n\n\t\t\tDo you want to book again? (Y/N) : ";
					cin >> ans;
					if (ans == 'Y' || ans == 'y') {
						bookClass();
					}
					else {
						classMenu();
					}
				}
				else {
					cout << "\n\t\t\tInvalid request. Please enter again" << endl << endl;
					bookClass();
				}
			}
			else {
				bookClass();
			}
		}
	}
	else if (option == 2) {
		classMenu();
	}
	else {
		cout << "\n\t\t\tInvalid option! Please choose again. " << endl << endl;
		bookClass();
	}
}

void displayBookedClass(string ID) {
	system("pause");
	system("cls");
	BookingManager bookingManager;
	BookClass* book = new BookClass();

	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                             Booked Class             " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                ======================================" << endl;

		cout << "\n\n\t\tList below shows booked class : " << endl;
		cout << "\t\t----------------------------------------------------------------------" << endl;
		cout << "\t\t  Class No.     Class ID          Date                    Time        " << endl;
		cout << "\t\t----------------------------------------------------------------------" << endl;
		
		book = bookingManager.selectBooked(ID);
		
		cout << endl << endl;
		classMenu();
}

void searchClass() {
	system("pause");
	system("cls");
	ClassManager classManager;
	Lesson* lesson = new Lesson();

	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                            " << endl;
	cout << "\t\t                             Search Class             " << endl;
	cout << "\t\t                                                            " << endl;
	cout << "\t\t                ======================================" << endl << endl;

	cout << "\t\t\tPlease enter 1 to search a class OR enter other to return : ";
	cin >> option;
	if (option == 1) {
		cout << "\n\t\tEnter class ID you want to search : " << endl;
		cout << "\t\tExample : KPP01B2 " << endl << endl;
		cout << "\t\t";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, lesson->classID);

		if ((lesson->classID).length() < 6 || (lesson->classID).length() > 7) {
			cout << "\n\t\t\tInvalid Class ID range! Please choose again. " << endl << endl;
			searchClass();
		}
		else {

			if (classManager.checkTableClass(lesson)) {

				lesson = classManager.searchClass(lesson->classID);

				cout << "\t\t--------------------------------------------------------------------------" << endl;
				cout << "\t\t  ID               Name                Duration      Category             " << endl;
				cout << "\t\t--------------------------------------------------------------------------" << endl;
				cout << "\t\t " << lesson->classID << "           " << lesson->className << "         " << lesson->classDuration << "          " << lesson->classcat << endl;
				cout << endl;
				cout << "\t\t--------------------------------------------------------------------------" << endl << endl;
				cout << "\t\t                              Available Class                             " << endl;
				cout << "\t\t--------------------------------------------------------------------------" << endl;
				cout << "\t\t  No.           Class ID           Date                    Time       " << endl;
				cout << "\t\t--------------------------------------------------------------------------" << endl;
				classManager.searchAvailable(lesson->classID);
				cout << "\n\n" << endl;

				classMenu();
			}
			else {
				cout << " No data found." << endl << endl;
				classMenu();
			}
		}
	}
	else
		classMenu();
}

void cancelClass(string ID) {
	system("pause");
	system("cls");
	BookingManager bookingManager;
	BookClass* cancel = new BookClass();
	cancel->studentID = ID;

	cout << "\n\n\t" << endl;
	cout << "\t                ======================================" << endl;
	cout << "\t                                                            " << endl;
	cout << "\t                             Cancel Class             " << endl;
	cout << "\t                                                            " << endl;
	cout << "\t                ======================================" << endl << endl;

	cout << "\t\tPlease enter 1 to cancel a class OR enter 2 to return : ";
	cin >> option;
	if (option == 1) {
		cout << "\n\tEnter class number you want to cancel : ";
		cin >> cancel->classNo;

		if (bookingManager.checkToDelete(cancel)) {
			cout << "\n\n\tAre you sure you want to cancel this class? (Y/N) : ";
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {
				bookingManager.deleteBooked(cancel);
				cout << "\t\tBooked class has been cancelled " << endl << endl;
				classMenu();
			}
			else if (ans == 'N' || ans == 'n') {
				cout << "\t\tCancelling request aborted! " << endl << endl;
				classMenu();
			}
			else {
				cout << "\n\t\tInvalid option! Please choose again. " << endl << endl;
				cancelClass(ID);
			}
		}
		else {
			cout << "\n\tYou don't have any booked class on this date" << "\n\tPlease try again" << endl << endl;
			cancelClass(ID);
		}
	}
	else if (option == 2) {
		classMenu();
	}
	else {
		cout << "\n\t\tInvalid option! Please choose again. " << endl << endl;
		cancelClass(ID);
	}
}

void drivingTestMenu() {
	system("pause");
	system("cls");

	cout << "\n\n" << endl;
	cout << "                ======================================" << endl;
	cout << "                                                      " << endl;
	cout << "                          Driving Test Menu           " << endl;
	cout << "                                                      " << endl;
	cout << "                ======================================" << endl << endl;
	cout << "     1. BOOK DRIVING TEST                             " << endl;
	cout << "     2. BOOKED TEST                                   " << endl;
	cout << "     3. RETURN                                        " << endl;
	cout << "\n\n" << endl;

	cout << endl << "     Please choose option : ";
	cin >> option;

	if (option == 1) {
		drivingTest(ID);
	}
	else if (option == 2) {
		displayBookedTest(ID);
	}
	else if (option == 3) {
		mainMenu();
	}
	else {
		cout << "\n\tInvalid option! Please choose again. " << endl << endl;
		drivingTestMenu();
	}
}

void drivingTest(string ID) {
	system("pause");
	system("cls");
	TestManager testManager;
	DrivingTest* test = new DrivingTest();
	test->s_id = ID;

	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                          Book Driving Test           " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                ======================================" << endl << endl;

	if (testManager.checkToBook(test)) {
		cout << "\t\tEnter 1 to book driving test, enter 2 to return : ";
		cin >> option;

		if (option == 1) {
			cout << "\n\t\tInsert test date (DD/MM/YYYY) : " << endl;
			cout << "\t\tExample : 22/06/2020 " << endl;
			cout << "\t\t";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, test->testDate);
			while ((test->testDate).length() < 10) {
				cout << "\n\t\t\tInvalid date format!" << "\n\t\t\tTry again " << endl << endl;
				cout << "\n\t\tInsert test date (DD/MM/YYYY) : " << endl;
				cout << "\t\tExample : 22/06/2020 " << endl;
				cout << "\t\t";
				getline(cin, test->testDate);
			}

			cout << "\n\t\tInsert test time : " << endl;
			cout << "\t\tExample : 08:00-10:00 OR 08:00 " << endl;
			cout << "\t\t";
			getline(cin, test->testTime);
			while ((test->testTime).length() < 5 || (test->testTime).length() > 11) {
				cout << "\n\t\t\tInvalid time format!" << "\n\t\t\tTry again " << endl << endl;
				cout << "\n\t\tInsert test time : " << endl;
				cout << "\t\tExample : 08:00-10:00 OR 08:00 " << endl;
				cout << "\t\t";
				getline(cin, test->testTime);
			}

			cout << "\n\t\tInsert classcategory : " << endl;
			cout << "\t\tExample : D " << endl;
			cout << "\t\t";
			getline(cin, test->classcat);
			while ((test->classcat).length() < 1 || (test->classcat).length() > 2) {
				cout << "\n\t\t\tInvalid category format!" << "\n\t\t\tTry again " << endl << endl;
				cout << "\n\t\tInsert classcategory : " << endl;
				cout << "\t\tExample : D " << endl;
				cout << "\t\t";
				getline(cin, test->classcat);
			}

			cout << "\n\n\t\tAre you sure you want to book this class? (Y/N) : ";
			cin >> ans;

			if (ans == 'Y' || ans == 'y') {
				int status = testManager.bookTest(test, ID);
				if (status != 0) {
					cout << "\n\n\t\t\tSuccessfully booked a driving test." << endl;
					displayBookedTest(ID);
				}
				else {
					cout << "\n\n\t\t\tUnable to book a driving test." << endl;
					drivingTestMenu();
				}
			}
			else if (ans == 'N' || ans == 'n') {
				cout << "\n\t\t\tBooking cancelled." << endl;
				cout << "\n\n\t\tDo you want to book again? (Y/N) : ";
				cin >> ans;
				if (ans == 'Y' || ans == 'y') {
					drivingTest(ID);
				}
				else {
					drivingTestMenu();
				}
			}
			else {
				cout << "\n\t\tInvalid request! Please enter again" << endl << endl;
				drivingTest(ID);
			}
		}
		else if (option == 2) {
			drivingTestMenu();
		}
		else {
			cout << "\n\t\tInvalid option! Please enter again" << endl << endl;
			drivingTest(ID);
		}
	}
	else {
		cout << "\n\t\t\t\t\tProceed to main menu." << endl << endl;
		mainMenu();
	}
}

void displayBookedTest(string ID) {
	system("pause");
	system("cls");
	TestManager testManager;

	cout << "\n\n" << endl;
	cout << "\t\t                ======================================" << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                         Booked Driving Test          " << endl;
	cout << "\t\t                                                      " << endl;
	cout << "\t\t                ======================================" << endl << endl;

	if (testManager.checkTableDrivingTest(ID)) {
	DrivingTest* test = testManager.displayTest(ID);

		cout << "\n\t\tBooked driving test : " << endl << endl;
		cout << "\t\t1. Student ID : " << test->s_id << endl;
		cout << "\t\t2. Date : " << test->testDate << endl;
		cout << "\t\t3. Time : " << test->testTime << endl;
		cout << "\t\t4. Category : " << test->classcat << endl << endl;

		drivingTestMenu();
	}
	else {
		cout << " No data found." << endl << endl;
		drivingTestMenu();
	}
}

void exit()
{
	system("pause");
	system("cls");

	cout << "\n\n\n\n\n\t\t\t\t======================================" << endl;
	cout << "                                                            " << endl;
	cout << "\t\t\t\t   Thank you for using this system" << endl;
	cout << "                                                            " << endl;
	cout << "\t\t\t\t======================================\n\n\n\n" << endl;

	exit(1);


}


int main() {

	loginMenu();
	return 0;
}