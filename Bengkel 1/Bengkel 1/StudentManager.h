#ifndef STUDENTMANAGER_H
#define STUDENTMANAGER_H


class StudentManager
{
public:
	bool checkTableStudent(Student* student);
	int insertStudent(Student* student);
	int updateNameStudent(Student* student);
	int updateDobStudent(Student* student);
	int updatePhoneStudent(Student* student);
	int updateAddressStudent(Student* student);
	int updateEmailStudent(Student* student);
	Student* selectStudent(string studentID);
	bool loginStudent(Student* student);
};

#endif 
