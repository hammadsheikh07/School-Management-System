//19F-0188
//Muhammad Hammad Shahid
//Group Member: Hamza Jamil
#pragma once
#include<string>
using namespace std;
struct date
{
	int day;
	int month;
	int year;
};
class Student
{
public:
	void savelastdata(int);
	Student();
	~Student();
	void addStudent();
	void addstudentinfile();
	void rollno();
	int lastdata();
	void viewstudent();
	void editstudent();
	Student* viewforedit();
	void viewstudentofclass(char);
	void viewindividualstatus(string);
	void viewfeestatus();
protected:
	string key;
	int rollnumbercount;
	string firstname, lastname;
	string emailid;
	int Class;
	string rollnumber;
	date date;
	string gender;
	string contactno;
	string fathername, fatherprofession;
	string parentscontactno;
	string feesubmitted;
	string bloodgroup;
	string address;
};
class Teacher
{
public:
	Teacher();
	int lastdatat();
	void sldt(int);
	void addTeacher();
	void addTeacherToFile();
	void viewAllTeachers();
	void editTeacher();
	Teacher* viewforedit();

protected:
	int teachercount;
	string firstName;
	string lastName;
	string email;
	string pass;
	string confirmpass;
	string cnic;
	string Gender;
	string qualification;
	string contact;
	string Address;
	date dob;
	date joiningdate;
	int salary;
};
class Course : public Teacher,public Student
{
public:
	Course();
	void teachercourse(string);
	void addCourse();
	void addCourseToFile();
	void assigncourses();
	void assignCourseToFile(string,string,int);
	void viewAllCourses();
protected:
	string coursename;
	string coursecode;
	int klass;
	string parentcourse;
	string assigncoursename;
	string assigncoursecode;
};

class Marks : public Course
{
public:
	Marks();
	void updateStudentMarks(bool,string);
	void studentMarks();
	void studentMarks(string);
protected:
	int marks;
	int totalmarks;
};
class Admin : public  Marks
{
public:
	Admin();
	~Admin();
	void mainmenu();
	void admin();
	void studentlogin();
	void teacherlogin();
	void teachermenu(string);
	void studentmenu(string);
protected:
	string id;
	string possword;
};

