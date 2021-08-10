//19F-0188
//Muhammad Hammad Shahid
//Group member: Hamza Jamil
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"Header.h"
using namespace std;

//student
Student::Student()
{
	key = "\0";
	rollnumbercount = lastdata();
	firstname = "\0";
	lastname = "\0";
	Class = 0;
	rollnumber = "\0";
	emailid = "\0";
	date.day = 0;
	date.month = 0;
	date.year = 0;
	gender = "\0";
	contactno = "\0";
	fathername = "\0";
	fatherprofession = "\0";
	parentscontactno = "\0";
	feesubmitted = "\0";
	bloodgroup = "\0";
	address = "\0";
}
Student::~Student()
{

}
void Student::addStudent()
{
	cout << "Please enter the first name:";
	cin >> firstname;
	cout << "Please enter the last name:";
	cin >> lastname;
	cout << "Please enter the class:";
	cin >> Class;
	cout << "Please enter the registration date\n";
	cout << "Day: ";
wapis:cin >> date.day;
	if (date.day < 1 || date.day>31)
	{
		cout << "Invalid input. TRY AGAIN\n";
		goto wapis;
	}
wapis1:cout << "Month: ";
	cin >> date.month;
	if (date.month < 1 || date.month>12)
	{
		cout << "Invalid input. TRY AGAIN\n";
		goto wapis1;
	}
	cout << "Year:";
	cin >> date.year;
back:cout << "Please enter the gender(MALE/FEMALE):";
	cin >> gender;
	if (!(gender[0] == 'm' || gender[0] == 'f' || gender[0] == 'M' || gender[0] == 'F'))
	{
		cout << "Invalid input Try again\n";
		goto back;
	}
	cout << "Please enter the contact number:";
	cin >> contactno;
	cout << "Please etner the father name:";
	cin >> fathername;
	cout << "Please enter the father profession:";
	cin >> fatherprofession;
	cout << "Please enter the father's contact number:";
	cin >> parentscontactno;
	cout << "Please enter the fee status(Submitted or not)Yes/NO?";
back1:	cin >> feesubmitted;
	if (!(feesubmitted[0] == 'Y' || feesubmitted[0] == 'y' || feesubmitted[0] == 'n' || feesubmitted[0] == 'N'))
	{
		cout << "Invalid input TRY AGAIN.\n";
		goto back1;
	}
	cout << "Please enter the blood group:";
	cin >> bloodgroup;
	cout << "Please enter the address:";
	cin >> address;
	rollno();
	addstudentinfile();
}
void Student::rollno()
{
	emailid = "\0";
	int klass = Class * 1000;
	rollnumbercount++;
	savelastdata(rollnumbercount);
	klass += rollnumbercount;
	rollnumber = to_string(klass);
	emailid += to_string(klass);
	emailid += "@schoolsystem.edu.pk";
	key += rollnumber + "$69";
	ofstream fout;
	fout.open("password.txt",ios::app);
	if (!fout.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fout)
		{
			fout << rollnumber << " " << emailid << " " << key << endl;
			fout.close();
		}
	}
}
void Student::addstudentinfile()
{
	ofstream fout;
	fout.open("student.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fout)
		{
			fout << rollnumber << " " << firstname << " " << lastname << " " << Class
				<< " " << feesubmitted << " " << address << " " << emailid << " " << contactno << " "
				<< fathername << " " << fatherprofession << " " << parentscontactno << " " << gender
				<< " " << date.day << " " << date.month << " " << date.year << endl;
			fout.close();
		}
	}
}
void Student::viewstudent()
{
	ifstream fin;
	string input = "\0";
	cout << "Press 1 to view all students.\n"
		<< "Press 2 to view students of specific class.\n"
		<< "Press 3 to view a specific student.\n"
		<< "Press 4 to return to main menu\n";
invalid:cin >> input;
	if (input.length() > 1)
	{
		cout << "Invalid input try again.\n";
		goto invalid;
	}
	else
	{
		switch (input[0])
		{
		case '1':
			fin.open("student.txt");
			if (!fin.is_open())
			{
				cout << "File not found.\n";
			}
			else
			{
				cout << left << setw(15) << "Roll number" << left << setw(15) << "Name"
					<< right << setw(8) << "class" << right << setw(30) << "email id" << endl;
				while (fin >> rollnumber >> firstname >> lastname >> Class >> feesubmitted
					>> address >> emailid >> contactno >> fathername >> fatherprofession
					>> parentscontactno >> gender >> date.day >> date.month >> date.year)
				{
					cout << left << setw(15) << rollnumber << left << setw(15) << firstname + " " + lastname
						<< right << setw(8) << Class << right << setw(30) << emailid << endl;
				}
			}
			break;
		case '2':
			viewstudentofclass(input[0]);
			break;
		case '3':
			viewstudentofclass(input[0]);
			break;
		case '4':
			return;
			break;
		default:
			cout << "Invalid Input TRY AGAIN.\n";
			goto invalid;
			break;
		}
		cout << "Press any key to continue..... to menu.\n";
		cin >> input;
	}

}
void Student::editstudent()
{
	//rollnumbercount = 1;
	ifstream fin;
	Student* std;
	int j = 0;
	int i = 0;
	string check = "\0";
	string rallnambar;
	std = viewforedit();
backo:		cout << "please enter the roll do you want:";
	cin >> rallnambar;
	for (i = 0; i < rollnumbercount; i++)
	{
		if (std[i].rollnumber == rallnambar)
		{
			j = 1;
			break;
		}
	}
	if (j != 1)
	{
		cout << "Roll number not found TRY AGAIN.\n";
		goto backo;
	}
	else
	{
		cout << "Press 1 to edit first name.\n"
			<< "Press 2 to last name.\n"
			<< "press 3 to edit fee status.\n"
			<< "Press 4 to edit address.\n"
			<< "Press 5 to edit contact number.\n";
	wapsii:cin >> check;
		if (check.length() > 1)
		{
			cout << "Invalid Input TRY AGAIN\n";
			goto wapsii;
		}
		else
		{

			switch (check[0])
			{
			case '1':
				cout << "Enter the new first name:";
				cin >> std[i].firstname;
				break;
			case '2':
				cout << "Enter the new last name:";
				cin >> std[i].lastname;
				break;
			case '3':
				cout << "Enter the Updated fee status:";
				cin >> std[i].feesubmitted;
				break;
			case '4':
				cout << "Please enter the new address:";
				cin >> std[i].address;
				break;
			case '5':
				cout << "Please enter the new contact number:";
				cin >> std[i].contactno;
				break;
			default:
				cout << "Invalid input TRY AGAIN.\n";
				goto wapsii;
				break;
			}
			ofstream fout;
			fout.open("student.txt");
			if (!fout.is_open())
			{
				cout << "File not found.\n";
			}
			else
			{
				while (fout)
				{
					for (int k = 0; k < rollnumbercount; k++)
					{
						fout << std[k].rollnumber << " " << std[k].firstname << " " << std[k].lastname << " " << std[k].Class
							<< " " << std[k].feesubmitted << " " << std[k].address << " " << std[k].emailid << " " << std[k].contactno << " "
							<< std[k].fathername << " " << std[k].fatherprofession << " " << std[k].parentscontactno << " " << std[k].gender
							<< " " << std[k].date.day << " " << std[k].date.month << " " << std[k].date.year << endl;
					}
					fout.close();
				}
			}
			system("cls");
			std = viewforedit();
			cout << "Press 1 to update again and 2 to go to main menu\n";
		hello: cin >> check;
			if (check.length() > 1)
			{
				cout << "Invalid Input TRY AGAIN.\n";
				goto hello;
			}
			else
			{
				if (check[0] == '1')
				{
					system("cls");
					editstudent();
				}
				else if (check[0] == '2')
				{
					return;
				}
				else
				{
					cout << "Invalid Input TRY AGAIN.\n";
					goto hello;
				}
			}
		}
	}
}
Student* Student::viewforedit()
{
	Student* std;
	std = new Student[rollnumbercount];
	int j = 0;
	int i = 0;
	ifstream fin;
	fin.open("student.txt");
	if (!fin.is_open())
	{
		cout << "FIle not found.\n";
	}
	else
	{
		cout << left << setw(15) << "Roll number" << left << setw(15) << "Name"
			<< right << setw(20) << "fee submitted" << right << setw(25) << "address" << right << setw(18) << "contact no." << endl;
		while (fin >> std[i].rollnumber >> std[i].firstname >> std[i].lastname >> std[i].Class >> std[i].feesubmitted
			>> std[i].address >> std[i].emailid >> std[i].contactno >> std[i].fathername >> std[i].fatherprofession
			>> std[i].parentscontactno >> std[i].gender >> std[i].date.day >> std[i].date.month >> std[i].date.year)
		{
			cout << left << setw(15) << std[i].rollnumber << left << setw(15) << std[i].firstname + " " + std[i].lastname
				<< right << setw(20) << std[i].feesubmitted << right << setw(25) << std[i].address << right << setw(18) << std[i].contactno << endl;
			++i;
		}
	}
	return std;
}
void Student::viewstudentofclass(char x)
{
	int check = 0;
	ifstream fin;
	int number = 0;
	string roll = "\0";
	if (x == '2')
	{
		cout << "Please enter class:";
		cin >> number;
	}
	else
	{
		cout << "Please neter the roll number:";
		cin >> roll;
	}
	fin.open("student.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		cout << left << setw(15) << "Roll number" << left << setw(15) << "Name"
			<< right << setw(8) << "class" << right << setw(30) << "email id" << endl;
		while (fin >> rollnumber >> firstname >> lastname >> Class >> feesubmitted
			>> address >> emailid >> contactno >> fathername >> fatherprofession
			>> parentscontactno >> gender >> date.day >> date.month >> date.year)
		{
			if (x == '2')
			{
				if (number == Class)
				{
					cout << left << setw(15) << rollnumber << left << setw(15) << firstname + " " + lastname
						<< right << setw(8) << Class << right << setw(30) << emailid << endl;
					check = 1;
				}
			}
			else
			{
				if (roll == rollnumber)
				{
					cout << left << setw(15) << rollnumber << left << setw(15) << firstname + " " + lastname
						<< right << setw(8) << Class << right << setw(30) << emailid << endl;
					check = 1;
				}
			}
		}
		fin.close();
		if (x == '2')
		{
			if (check != 1)
			{
				cout << "No student of class found\n";
			}
		}
		else
		{
			if (check != 1)
			{
				cout << "No any roll number found.\n";
			}
		}
	}
}
void Student::viewfeestatus()
{
	string input;
	Student* std;
	std = new Student[rollnumbercount];
	ifstream fin;
	int i = 0;
	fin.open("student.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{

		cout << left << setw(15) << "Roll number" << left << setw(15) << "Name"
			<< right << setw(20) << "fee submitted" << endl;
		while (fin >> std[i].rollnumber >> std[i].firstname >> std[i].lastname >> std[i].Class >> std[i].feesubmitted
			>> std[i].address >> std[i].emailid >> std[i].contactno >> std[i].fathername >> std[i].fatherprofession
			>> std[i].parentscontactno >> std[i].gender >> std[i].date.day >> std[i].date.month >> std[i].date.year)
		{
			cout << left << setw(15) << std[i].rollnumber << left << setw(15) << std[i].firstname + " " + std[i].lastname
				<< right << setw(20) << std[i].feesubmitted << endl;
			++i;
		}
		cout << "Press any key to go to main menu......";
		cin >> input;
	}
}
void Student::viewindividualstatus(string p)
{
	string input;
	ifstream fin;
	fin.open("student.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{

		cout << left << setw(15) << "Roll number" << left << setw(15) << "Name"
			<< right << setw(20) << "fee submitted" << endl;
		while (fin >> rollnumber >> firstname >> lastname >> Class >> feesubmitted
			>> address >> emailid >> contactno >> fathername >> fatherprofession
			>> parentscontactno >> gender >> date.day >> date.month >> date.year)
		{
			if (rollnumber == p)
			{

				cout << left << setw(15) << rollnumber << left << setw(15) << firstname + " " + lastname
					<< right << setw(20) << feesubmitted << endl;
			}
		}
		cout << "Press any key to go to main menu......";
		cin >> input;
	}
}

//teacher
Teacher::Teacher()
{
	teachercount = lastdatat();
	firstName = "";
	lastName = "";
	email = "";
	pass = "";
	confirmpass = "";
	cnic = "";
	Gender = "";
	qualification = "";
	contact = "";
	dob.day = 0;
	dob.month = 0;
	dob.year = 0;
	joiningdate.day = 0;
	joiningdate.month = 0;
	joiningdate.year = 0;
	Address = "";
	salary = 0;
}
void Teacher::addTeacher()
{
	teachercount++;
	sldt(teachercount);
	cout << "Input First Name:" << endl;
	cin >> firstName;
	cout << "Input Last Name:" << endl;
	cin >> lastName;
	cout << "Input Email:" << endl;
	cin >> email;
	cout << "Input Joining Date:" << endl;
tareekh:cin >> joiningdate.day;
	if (joiningdate.day < 1 || joiningdate.day>31)
	{
		cout << "Invalid input. TRY AGAIN\n";
		goto tareekh;
	}
mahina:	cout << "Input Joining Month:" << endl;
	cin >> joiningdate.month;
	if (joiningdate.month < 1 || joiningdate.month>12)
	{
		cout << "Invalid input. TRY AGAIN\n";
		goto mahina;
	}
	cout << "Input Joining Year:" << endl;
	cin >> joiningdate.year;
passwarad:cout << "Input Password:" << endl;
	cin >> pass;
	cout << "Input Confirm Password:" << endl;
	cin >> confirmpass;
	if (pass != confirmpass)
	{
		cout << "Password not matched TRY again.\n";
		goto passwarad;
	}
	cout << "Input CNIC:" << endl;
	cin >> cnic;
	cout << "Input Gender:" << endl;
	cin >> Gender;
	cout << "Input Qualification:" << endl;
	cin >> qualification;
	cout << "Input Contact Number:" << endl;
	cin >> contact;
BM:cout << "Input Birth Date:" << endl;
	cin >> dob.day;
	if (dob.day < 1 || dob.day>31)
	{
		cout << "Invalid input TRY AGAIN.\n";
		goto BM;
	}
BC:cout << "Input Birth Month:" << endl;
	cin >> dob.month;
	if (dob.month < 1 || dob.month>12)
	{
		cout << "Invalid input TRY AGAIN.\n";
		goto BC;
	}
	cout << "Input Birth Year:" << endl;
	cin >> dob.year;
	cout << "Input Address:" << endl;
	cin >> Address;
	cout << "Input Salary:" << endl;
	cin >> salary;
	addTeacherToFile();
}
void Teacher::addTeacherToFile()
{
	ofstream fout;
	fout.open("Teacher.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fout)
		{
			fout << firstName << " " << lastName << " " << Gender
				<< " " << qualification << " " << contact << " " << email << " " << Address << " "
				<< cnic << " " << pass << " " << salary
				<< " " << dob.day << " " << dob.month << " " << dob.year
				<< " " << joiningdate.day << " " << joiningdate.month << " " << joiningdate.year << endl;
			fout.close();
		}
	}
}
void Teacher::viewAllTeachers()
{
	string input;
	ifstream fin;
	fin.open("Teacher.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> firstName >> lastName >> Gender
			>> qualification >> contact >> email >> Address
			>> cnic >> pass >> salary
			>> dob.day >> dob.month >> dob.year
			>> joiningdate.day >> joiningdate.month >> joiningdate.year)
		{
			cout << left << setw(8) << firstName + " " + lastName
				<< right << setw(10) << Gender << right << setw(10) << qualification
				<< right << setw(20) << contact << right << setw(30) << email << endl;
		}
		fin.close();
		cout << "Press any key to continue to main menu......";
		cin >> input;
	}
}
void Teacher::editTeacher()
{
	ifstream fin;
	Teacher* std;
	int j = 0;
	int i = 0;
	string check = "\0";
	int random = 0;
	int number;
	std = viewforedit();
backo:		cout << "Input Teacher Number:";
	cin >> number;
	for (i = 0; i < teachercount; i++)
	{
		random = i + 1;
		if (random == number)
		{
			j = 1;
			break;
		}
	}
	if (j != 1)
	{
		cout << "Roll number not found TRY AGAIN.\n";
		goto backo;
	}
	else
	{
		cout << "Press 1 to edit salary.\n"
			<< "Press 2 to qualification.\n"
			<< "Press 3 to edit Address.\n"
			<< "Press 4 to edit contact number.\n";
	wapsii:cin >> check;
		if (check.length() > 1)
		{
			cout << "Invalid Input TRY AGAIN\n";
			goto wapsii;
		}
		else
		{

			switch (check[0])
			{
			case '1':
				cout << "Enter the new salary:";
				cin >> std[i].salary;
				break;
			case '2':
				cout << "Enter the new qualification:";
				cin >> std[i].qualification;
				break;
			case '3':
				cout << "Please enter the new Address:";
				cin >> std[i].Address;
				break;
			case '4':
				cout << "Please enter the new contact number:";
				cin >> std[i].contact;
				break;
			default:
				cout << "Invalid input TRY AGAIN.\n";
				goto wapsii;
				break;
			}
			ofstream fout;
			fout.open("Teacher.txt");
			if (!fout.is_open())
			{
				cout << "File not found.\n";
			}
			else
			{

				while (fout)
				{
					for (int k = 0; k < teachercount; k++)
					{
						fout << std[k].firstName << " " << std[k].lastName << " " << std[k].Gender
							<< " " << std[k].qualification << " " << std[k].contact << " " << std[k].email << " " << std[k].Address << " "
							<< std[k].cnic << " " << std[k].pass << " " << std[k].salary
							<< " " << std[k].dob.day << " " << std[k].dob.month << " " << std[k].dob.year
							<< " " << std[k].joiningdate.day << " " << std[k].joiningdate.month << " " << std[k].joiningdate.year << endl;
					}
					fout.close();
				}
			}
			system("cls");
			std = viewforedit();
			cout << "Press 1 to update again and 2 to go to main menu\n";
		hello: cin >> check;
			if (check.length() > 1)
			{
				cout << "Invalid Input TRY AGAIN.\n";
				goto hello;
			}
			else
			{
				if (check[0] == '1')
				{
					system("cls");
					editTeacher();
				}
				else if (check[0] == '2')
				{
					return;
				}
				else
				{
					cout << "Invalid Input TRY AGAIN.\n";
					goto hello;
				}
			}
		}
	}
}
Teacher* Teacher::viewforedit()
{
	Teacher* std;
	std = new Teacher[teachercount];
	int j = 0;
	int i = 0;
	ifstream fin;
	fin.open("Teacher.txt");
	if (!fin.is_open())
	{
		cout << "FIle not found.\n";
	}
	else
	{
		cout << left << setw(15) << "First Name" << left << setw(15) << "Salary"
			<< right << setw(20) << "Qualification" << right << setw(25) << "Address" << endl;
		while (fin >> std[i].firstName >> std[i].lastName >> std[i].Gender
			>> std[i].qualification >> std[i].contact >> std[i].email >> std[i].Address
			>> std[i].cnic >> std[i].pass >> std[i].salary
			>> std[i].dob.day >> std[i].dob.month >> std[i].dob.year
			>> std[i].joiningdate.day >> std[i].joiningdate.month >> std[i].joiningdate.year)
		{
			cout << i + 1 << " ";
			cout << left << setw(15) << std[i].firstName << right << setw(15) << std[i].salary
				<< right << setw(20) << std[i].qualification << right << setw(25) << std[i].Address << right << setw(18) << std[i].contact << endl;
			++i;
		}
	}
	return std;
}


//COURSE
Course::Course()
{
	coursename = "";
	coursecode = "";
	klass = 0;
	parentcourse = "";
	assigncoursename = "";
	assigncoursecode = "";
}
void Course::addCourse()
{
	cout << "Input Course Name:" << endl;
	cin >> coursename;
	cout << "Input Course Code:" << endl;
	cin >> coursecode;
	cout << "Input Class:" << endl;
	cin >> klass;
	cout << "Input Parent Course:" << endl;
	cin >> parentcourse;
	addCourseToFile();
}
void Course::addCourseToFile()
{
	ofstream fout;
	fout.open("Courses.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fout)
		{
			fout << coursename << " " << coursecode << " " << parentcourse << " " << klass << endl;
			fout.close();
		}
	}
}
void Course::assigncourses()
{
	string arr[10];
	int arr2[10];
	string arr3[100];
	string arr4[100];
	int x = 0, y = 0, z = 0;
	ifstream fin;
	fin.open("Teacher.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		cout << "The list of teachers are.\n";
		while (fin >> firstName >> lastName >> Gender
			>> qualification >> contact >> email >> Address
			>> cnic >> pass >> salary
			>> dob.day >> dob.month >> dob.year
			>> joiningdate.day >> joiningdate.month >> joiningdate.year)
		{
			arr3[y] = pass;
			arr4[y] = firstName + " " + lastName;
			y++;
		}
		fin.close();
	}
	fin.open("Courses.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		cout << "the list of courses are:\n";
		while (fin >> coursename >> coursecode >> parentcourse >> klass)
		{
			arr[x] = coursename;
			arr2[x] = klass;
			x++;
		}
	}
	fin.close();
	int i = 0, v = 0, a = 0, j = 0;
	cout << "courses available are:" << endl;
	for (i = 0; i < x; i++)
	{
		cout << i + 1 << ". " << arr[i] << " in class " << arr2[i] << endl;
	}
	cout << "The list of teachers available are" << endl;
	for (i = 0; i < y; i++)
	{
		cout << i + 1 << ". " << arr4[i] << endl;
	}
ap:	cout << "Enter the number of course you want to assign:";
	cin >> z;
	for (i = 0; i < x; i++)
	{
		v = i + 1;
		if (z == v)
		{
			a = 1;
			break;
		}

	}
	if (a != 1)
	{
		cout << "Course not found try again.\n";
		goto ap;
	}
	else
	{
		cout << "Enter the teacher number:";
		cin >> z;
		for (j = 0; j < y; j++)
		{
			v = j + 1;
			if (z == v)
			{
				a = 1;
				break;
			}
		}
		if (a != 1)
		{
			cout << "Teacher not found try again.\n";
			goto ap;
		}
	}
	assignCourseToFile(arr[i], arr3[j], arr2[i]);
}
void Course::assignCourseToFile(string CN, string P, int C)
{
	ofstream fout;
	fout.open("Assign.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fout)
		{
			fout << P << " " << CN << " " << C << endl;
			fout.close();
		}
	}
}
void Course::viewAllCourses()
{
	string input;
	ifstream fin;
	fin.open("Courses.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> coursename >> coursecode >> parentcourse >> klass)
		{
			cout << left << setw(10) << coursename << right << setw(10) << coursecode << right << setw(25) << parentcourse << right << setw(25) << klass << endl;
		}
	}
	fin.close();
	cout << "Press any key to continue.....";
	cin >> input;
}
void Course::teachercourse(string password)
{
	string x, y;
	string z[100];
	int num = 0, gg = 0, kount = 0;
	ifstream fin;
	fin.open("Assign.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		cout << "The courses are:\n";
		while (fin >> x >> y >> num)
		{
			if (x == password)
			{
				cout << y << " with class " << num << endl;
				gg = 1;
			}
		}
		fin.close();
		if (gg != 1)
		{
			cout << "No course assigned by admin.\n";
		}
		else
		{
			fin.open("student.txt");
			if (!fin.is_open())
			{
				cout << "File not found.\n";
			}
			else
			{
				cout << "The students are: ";
				cout << left << setw(15) << "Roll number" << left << setw(15) << "Name" << endl;
				while (fin >> rollnumber >> firstname >> lastname >> Class >> feesubmitted
					>> address >> emailid >> contactno >> fathername >> fatherprofession
					>> parentscontactno >> gender >> date.day >> date.month >> date.year)
				{
					cout << left << setw(15) << rollnumber << left << setw(15) << firstname + " " + lastname
						<< endl;
				}
			}

		}
	}
	cout << "Press any key to continue.....";
	cin >> x;
}


//admin
Admin::Admin()
{
	id = "admin";
	possword = "ptcl";
}
Admin::~Admin()
{

}
void Admin::mainmenu()
{
	string input;
	do
	{
		system("cls");
		cout << "Press 1 for Admin.\n"
			<< "Press 2 for Teacher.\n"
			<< "Press 3 for Student.\n"
			<< "Press 4 to exit.\n";
	yayy:	cin >> input;
		if (input.length() > 1)
		{
			cout << "Invalid input TRY AGAIN.\n";
			goto yayy;
		}
		else
		{
			switch (input[0])
			{
			case '1':
				system("cls");
				admin();
				break;
			case '2':
				teacherlogin();
				break;
			case '3':
				studentlogin();
				break;
			case '4':
				return;
				break;
			default:
				cout << "Invalid input TRY AGAIN.\n";
				goto yayy;
				break;
			}
		}
	} while (input[0] != 4);
}
void Admin::admin()
{
	int count = 3;
	string aa, bb;
hellog:cout << "Please enter the id:";
	cin >> aa;
	cout << "Please enter the password:";
	cin >> bb;
	if (aa == id && bb == possword)
	{

		string input;
		do
		{
			system("cls");
		razooor:cout << "Press 1 to add student.\n"
			<< "Press 2 to add teacher.\n"
			<< "Press 3 to add new course.\n"
			<< "Press 4 to assign course.\n"
			<< "Press 5 to edit student details.\n"
			<< "Press 6 to edit teacher details.\n"
			<< "Press 7 to view students.\n"
			<< "Press 8 to view all teachers.\n"
			<< "Press 9 to view all courses.\n"
			<< "Press 10 to update student marks.\n"
			<< "Press 11 to view student marks.\n"
			<< "Press 12 to View fee status.\n"
			<< "Press 0 to exit.\n";
	razoor:cin >> input;
		if (input.length() > 2)
		{
			cout << "Invalid input TRY AGAIN.\n";
			goto razoor;
		}
		else
		{
			system("cls");
			if (input.length() < 2)
			{
				if (input[0] == '1')
				{
					addStudent();
				}
				else  if (input[0] == '2')
				{
					addTeacher();
				}
				else  if (input[0] == '3')
				{
					addCourse();
				}
				else  if (input[0] == '4')
				{
					assigncourses();
				}
				else  if (input[0] == '5')
				{
					editstudent();
				}
				else  if (input[0] == '6')
				{
					editTeacher();
				}
				else  if (input[0] == '7')
				{
					viewstudent();
				}
				else  if (input[0] == '8')
				{
					viewAllTeachers();
				}
				else  if (input[0] == '9')
				{
					viewAllCourses();
				}
				else if (input[0] == '0')
				{
					break;
				}
				else
				{
					cout << "Invalid input TRY AGAIN.\n";
					goto razooor;
				}
			}
			else
			{
				if (input == "10")
				{
					updateStudentMarks(true, "\0");
				}
				else if (input == "11")
				{
					studentMarks();
				}
				else if (input == "12")
				{
					viewfeestatus();
				}
				else
				{
					cout << "Invalid input TRY AGAIN.\n";
					goto razooor;
				}
			}
		}
		} while (input[0] != 0);
	}
	else
	{
		if (count == 0)
		{
			return;
		}
		cout << "Invalid email or password! " << count << " tries left.\n";
		count--;
		goto hellog;
	}
}
void Admin::teacherlogin()
{
	int count = 3;
	bool next = true;
	string email, password;
	ifstream fin;
lol:cout << "Input email: ";
	cin >> email;
	cout << "Input password: ";
	cin >> password;
	fin.open("Teacher.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> firstName >> lastName >> Gender
			>> qualification >> contact >> emailid >> Address
			>> cnic >> pass >> salary
			>> dob.day >> dob.month >> dob.year
			>> joiningdate.day >> joiningdate.month >> joiningdate.year)
		{
			if (email == emailid && password == pass)
			{
				next = false;
				break;
			}
		}
		fin.close();
		if (next == true)
		{
			if (count == 0)
			{
				cout << "Login Failed.\n";
				return;
			}
			cout << "Your email or password is wrong! " << count << " tries left.\n";
			count--;
			goto lol;
		}
		else
		{
			teachermenu(password);
		}
	}
}
void Admin::teachermenu(string p)
{
	string login;
	do
	{
		system("cls");
		cout << "Press 1 to view courses.\n"
			<< "Press 2 to update marks.\n"
			<< "Press 3 to exit.\n";
	yoyo:cin >> login;
		if (login.length() > 1)
		{
			cout << "Invalid input try again.\n";
			goto yoyo;
		}
		else
		{
			switch (login[0])
			{
			case '1':
				system("cls");
				teachercourse(p);
				break;
			case '2':
				system("cls");
				updateStudentMarks(false, p);
				break;
			case'3':
				return;
				break;
			default:
				cout << "Invalid input try again.\n";
				goto yoyo;
				break;
			}
		}
	} while (login[0] != 3);
}
void Admin::studentlogin()
{
	int count = 3;
	bool next = true;
	string email, password;
	ifstream fin;
lol:cout << "Input email: ";
	cin >> email;
	cout << "Input password: ";
	cin >> password;
	fin.open("password.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> rollnumber >> emailid >> key)
		{
			if (email == emailid && password == key)
			{
				next = false;
				break;
			}
		}
		fin.close();
		if (next == true)
		{
			if (count == 0)
			{
				cout << "Login Failed.\n";
				return;
			}
			cout << "Your email or password is wrong! " << count << " tries left.\n";
			count--;
			goto lol;
		}
		else
		{
			studentmenu(rollnumber);
		}
	}
}
void Admin::studentmenu(string p)
{
	string login;
	do
	{
		system("cls");
		cout << "Press 1 to view marks.\n"
			<< "Press 2 to view fee status.\n"
			<< "Press 3 to exit.\n";
	molo:cin >> login;
		if (login.length() > 1)
		{
			cout << "Invalid input try again.\n";
			goto molo;
		}
		else
		{
			switch (login[0])
			{
			case '1':
				system("cls");
				studentMarks(p);
				break;
			case '2':
				system("cls");
				viewindividualstatus(p);
				break;
			case '3':
				return;
				break;
			default:
				cout << "Invalid input try again.\n";
				goto molo;
				break;
			}
		}
	} while (login[0] != 3);
}
int Student::lastdata()
{
	ifstream fin;
	fin.open("data.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> rollnumbercount)
		{
		}
		fin.close();
		return rollnumbercount;
	}
}
int Teacher::lastdatat()
{
	ifstream fin;
	fin.open("datat.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> teachercount)
		{
		}
		fin.close();
		return teachercount;
	}
}
void Student::savelastdata(int x)
{
	ofstream fout;
	fout.open("data.txt");
	if (fout.is_open())
	{
		while (fout)
		{
			fout << x << endl;
			fout.close();
		}
	}
}
void Teacher::sldt(int t)
{
	ofstream fout;
	fout.open("datat.txt");
	if (fout.is_open())
	{
		while (fout)
		{
			fout << t<< endl;
			fout.close();
		}
	}
}

//MARKS
void Marks::updateStudentMarks(bool check, string lolo)
{
	int temp = 0;
	string arr[10];
	int count = 0;
	int rand = 0;
	string ran = "\0";
	string ptanai[100];
	ifstream fin;
	int kont = 0;
	if (check == true)
	{

		cout << "Input The Class You Wanna Update:" << endl;
		cin >> temp;
		fin.open("Courses.txt", ios::app);
		if (!fin.is_open())
		{
			cout << "File not found.\n";
		}
		else
		{
			while (fin >> coursename >> coursecode >> parentcourse >> klass)
			{
				if (temp == klass)
				{
					arr[count] = coursename;
					count++;
				}
			}
			fin.close();
			cout << "Available Courses Of This Class:" << endl;
			for (int i = 0; i < count; i++)
			{
				cout << i + 1 << ". ";
				cout << arr[i] << endl;
			}
			cout << "Input The Number Of Course You Want To Update Marks:" << endl;
			cin >> rand;
		}

		fin.open("student.txt");
		if (!fin.is_open())
		{
			cout << "File not found.\n";
		}
		else
		{
			cout << left << setw(15) << "Roll Number" << setw(15) << left << "Course Name" << endl;
			while (fin >> rollnumber >> firstname >> lastname >> Class >> feesubmitted
				>> address >> emailid >> contactno >> fathername >> fatherprofession
				>> parentscontactno >> gender >> date.day >> date.month >> date.year)
			{
				if (temp == Class)
				{
					cout << left << setw(15) << rollnumber << setw(15) << left << arr[rand - 1] << endl;
					ptanai[kont] = rollnumber;
					kont++;
				}
			}
			fin.close();
		}
	}
	else
	{
		string xd = "\0", bd = "\0";
		int why = 0;
		fin.open("Assign.txt");
		if (!fin.is_open())
		{
			cout << "File not found.\n";
		}
		else
		{
			while (fin >> xd >> bd >> why)
			{
				if (xd == lolo)
				{
					arr[rand] = bd;
					rand++;
					temp = why;
				}
			}
			fin.close();
		}
		fin.open("student.txt");
		if (!fin.is_open())
		{
			cout << "File not found.\n";
		}
		else
		{
			cout << left << setw(15) << "Roll Number" << setw(15) << left << "Course Name" << endl;
			while (fin >> rollnumber >> firstname >> lastname >> Class >> feesubmitted
				>> address >> emailid >> contactno >> fathername >> fatherprofession
				>> parentscontactno >> gender >> date.day >> date.month >> date.year)
			{
				if (temp == Class)
				{
					//cout << left << setw(15) << rollnumber << setw(15) << left << arr[rand - 1] << endl;
					ptanai[kont] = rollnumber;
					kont++;
				}
			}
			fin.close();
		}
	}
	int i = 0;
	int j = 0;
	string nambar;
	Marks* number;
	int x = 0;
	string input;
	number = new Marks[kont];
	fin.open("Marks.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> rollnumber >> coursename >> klass >> marks >> totalmarks)
		{
			if (temp == klass && arr[rand - 1] == coursename)
			{
				number[j].marks = marks;
				number[j].totalmarks = totalmarks;
				j++;
			}
		}
		fin.close();
	}
	studentMarks();
	cout << "Input the roll number you want to edit:";
xoxo: cin >> nambar;
	for (i = 0; i < kont; i++)
	{
		if (ptanai[i] == nambar)
		{
			x = 1;
			break;
		}
	}
	if (x != 1)
	{
		cout << "INVALID INPUT TRY AGAIN\n";
		goto xoxo;
	}
	else
	{
		cout << "Input The New Marks:" << endl;
		cin >> number[i].marks;

		number[i].totalmarks += number[i].marks;

		ofstream fout;
		fout.open("Marks.txt");
		if (!fout.is_open())
		{
			cout << "File not found.\n";
		}
		else
		{
			while (fout)
			{
				for (int i = 0; i < kont; i++)
				{
					fout << ptanai[i] << " " << arr[rand - 1] << " " << temp << " " << number[i].marks << " "
						<< number[i].totalmarks << endl;
				}
				fout.close();
			}
		}
		system("cls");
		studentMarks();
		cout << "Press 1 to Update Marks" << endl;
		cout << "Press 2 to go to main menu" << endl;
	pc: cin >> input;
		if (input[0] == '1')
		{
			system("cls");
			updateStudentMarks(check, lolo);
		}
		else if (input[0] == '2')
		{
			return;
		}
		else
		{
			cout << "INVALID INPUT TRY AGAIN\n";
			goto pc;
		}
	}

}
void Marks::studentMarks()
{
	ifstream fin;
	fin.open("Marks.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> rollnumber >> coursename >> klass >> marks >> totalmarks)
		{
			cout << rollnumber << " " << coursename << " " << marks << " " << totalmarks << endl;
		}
		fin.close();
	}
	cout << "Press any key to go to main menu......";
	string wahy;
	cin >> wahy;
}
void Marks::studentMarks(string p)
{
	string input;
	ifstream fin;
	fin.open("Marks.txt");
	if (!fin.is_open())
	{
		cout << "File not found.\n";
	}
	else
	{
		while (fin >> rollnumber >> coursename >> klass >> marks >> totalmarks)
		{
			cout << rollnumber << " " << coursename << " " << marks << " " << totalmarks << endl;
		}
		fin.close();
	}
	cout << "press any key to continue....";
	cin >> input;
}
Marks::Marks()
{
	marks = 0;
	totalmarks = 0;
}