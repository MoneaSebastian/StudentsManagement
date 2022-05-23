#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

#include "Student.h"

class App {
public:
	vector<Student*> students;

	App() {
		vector <Student*> students;
	}

	void Run() {
		ifstream inFile;
		string line, temp_str;
		inFile.open("Data.txt");

		while (getline(inFile, line))
		{
			string name;
			int year;
			float average;
			vector<string> courses;
			vector<float> grades;


			vector<string> tokens;

			stringstream linestream(line);

			while (getline(linestream, temp_str, '-')) {
				tokens.push_back(temp_str);
			}

			string firstPart = tokens[0];
			string secondPart = tokens[1];
			string thirdPard = tokens[2];

			tokens.clear();

			stringstream firststream(firstPart);

			while (getline(firststream, temp_str, ' ')) {
				tokens.push_back(temp_str);
			}


			name = tokens[0];
			year = stoi(tokens[1]);
			average = stof(tokens[2]);

			stringstream secondstream(secondPart);

			while (getline(secondstream, temp_str, ' ')) {
				courses.push_back(temp_str);
			}

			stringstream thirdstream(thirdPard);

			while (getline(thirdstream, temp_str, ' ')) {
				grades.push_back(stof(temp_str));
			}

			Student* student = new Student(name, year, average, courses, grades);
			students.push_back(student);

			cout << '\n';

		}

		inFile.close();

	}

	void CreateStudentsList() {
		Student* student = new Student("Alex", 3, vector<string> {"Math", "Biology", "Physics"}, vector<float> {6, 5, 3, 9, 1, 7, 2, 5, 7, 7 });
		students.push_back(student);
		Student* student1 = new Student("Irina", 1, vector<string> {"Math", "Biology", "Physics", "Chemistry"}, vector<float> {6, 10, 7, 9, 9, 5, 8, 5, 10, 7 });
		students.push_back(student1);
		Student* student2 = new Student("Marius", 3, vector<string> {"Math", "Biology", "Technology"}, vector<float> {2, 5, 3, 2, 1, 4, 2, 5, 2, 3, 8 });
		students.push_back(student2);
		Student* student3 = new Student("Ovidiu", 3, vector<string> {"Math", "Biology", "Physics"}, vector<float> {10,   6,   2,   5,   3,   9,   1,   4,   7,   8 });
		students.push_back(student3);
		Student* student4 = new Student("Andreea", 2, vector<string> {"Math", "Technology", "Physics"}, vector<float> { 9,   8,   10,   8,   7,   8,  10,   6,   9,   9 });
		students.push_back(student4);
		Student* student5 = new Student("Gabi", 3, vector<string> {"Math", "Biology", "Chemistry"}, vector<float> {4.9,   8.9,   1,   3.9,   6,   2,   5,   9,  10,   7.9 });
		students.push_back(student5);
		Student* student6 = new Student("Mariana", 3, vector<string> {"Math", "Technology", "Physics"}, vector<float> { 9, 8, 10, 8, 7, 8, 10, 6, 9, 9});
		students.push_back(student6);
	}

	void CalculateGeneralAVG() {
		cout << "\tName \t\tAverage\n";
		auto it = students.begin();
		for (; it != students.end(); it++)
		{
			(*it)->calculateAverage();
			cout << "\t" << (*it)->getName() << setw(15)<< (*it)->getAverage();
			cout << '\n';
		}
	}

	void insertStudent() {
		string name, positionEndorBegining, courseString, gradeString, temp_str;
		int year, position;
		float average;
		vector<string> courses;
		vector<float> grades;
		bool positonOutOfIndex = false;

		cout << "Select student position in the list ";
		cin >> position;
		
		if (position > students.size()) {
			cout << "Position out of index, insert at beggining or at the end (B/E): ";
			cin >> positionEndorBegining;
			positonOutOfIndex = true;
		}

		cout << "Name of the student: ";
		cin >> name;
		cout << "Year: ";
		cin >> year;
		cout << "Courses: (insert 0 to stop):\n ";
		do {
			cin >> courseString;
			if(courseString != "0")
				courses.push_back(courseString);
		} while (courseString != "0");
		cout << "Grades: (insert 0 to stop):\n ";
		do {
			cin >> gradeString;
			if(gradeString != "0")
				grades.push_back(stof(gradeString));
		} while (gradeString != "0");

		Student* student = new Student(name, year, courses, grades);

		if (positonOutOfIndex == true) {
			if(positionEndorBegining == "B")
				students.insert(students.begin(), student);
			else {
				students.push_back(student);
			}
		}
		else {
			auto it = students.begin() + position - 1;
			students.insert(it, student);
		}

		
	}

	void removeNonPromotedStudents() {
		bool found = false;
		int noOfStudents = 0;
		for (auto it = students.begin(); it != students.end(); ++it) {
			if ((*it)->getAverage() < 5) {
				noOfStudents++;
			}
		}
		for(int i =0; i<noOfStudents; i++)
			for (auto it = students.begin(); it != students.end(); ++it) {
				if ((*it)->getAverage() < 5 ) {
					cout << "Student " << (*it)->getName() << " with average " << (*it)->getAverage() << " deleted.\n";
					students.erase(it);
					break;
				}
			}
	}

	void DisplayStudents() {
		vector<float> grades;
		cout << "\tName \t\Year \t\Average \tCourses \t\t\tGrades\n";
		auto it = students.begin();
		for (; it != students.end(); it++)
		{
			cout << (*it)->getName() << setw(15) << (*it)->getYear() << setw(15) << (*it)->getAverage()<<"      " << setw(15) << (*it)->getCoursesDisplayed() << setw(15);

			grades = (*it)->getGrades();
			for (int i = 0; i < grades.size(); i++)
					cout << grades.at(i)<<" ";
			cout << "\n";
		}
	}

	void DisplayStudentsDescOrder() {
		
		sort(students.begin(), students.end(),
			[]( Student* struct1, Student* struct2)
			{
				if((*struct1).getAverage() == (*struct2).getAverage())
					return ((*struct1).getName() > (*struct2).getName());
				else
					return ((*struct1).getAverage() > (*struct2).getAverage());
			}
		);
		cout << "\tName \t\tYear \t\tAverage";
		cout << '\n';
		auto it = students.begin();
		for (; it != students.end(); it++)
		{
			cout << "\t" << (*it)->getName() << setw(15) << (*it)->getYear() << setw(15) << (*it)->getAverage();
			cout << '\n';

		}
	}

	void DisplayStudentsY3AVG8() {
		cout << "\tName \t\tYear \t\tAverage\n";
		auto it = students.begin();
		for (; it != students.end(); it++)
		{
			if((*it)->getAverage() > 8 && (*it)->getYear()==3)
				cout << "\t" << (*it)->getName() << setw(15) << (*it)->getYear() << setw(15) << (*it)->getAverage()<<"\n";
		}
	}

	void onQuit() {
		ofstream FileOut;
		FileOut.open("data.txt");
		auto it = students.begin();
		for (; it != students.end(); it++)
		{
			FileOut << (*it)->getName() << " " << (*it)->getYear() << " " << (*it)->getAverage() << "-" <<(*it)->getCoursesDisplayed() << "-" << (*it)->getGradesDisplayed();
			FileOut << '\n';
		}

		FileOut.close();
	}


};

int main() {
	App a;
	int choice;

	a.Run();
	do {
		cout << "\t\t           Menu Options";
		cout << "\n\n\n\n\t\t --After selecting an option press enter to exit from it--- \n\n\n";
		cout << '\n';
		cout << "\t\t Create list of students				'1'";
		cout << '\n';
		cout << "\t\t Display all students data				'2'";
		cout << '\n';
		cout << "\t\t Calculate general avg					'3'";
		cout << '\n';
		cout << "\t\t Display students in descending order of avg		'4'";
		cout << '\n';
		cout << "\t\t Display students from year 3 with avg over 8 		'5'";
		cout << "\n";
		cout << "\t\t Insert new student					'6'";
		cout << '\n';
		cout << "\t\t Remove non promoted students				'7'";
		cout << '\n';
		cout << "\t\t Quit							'8'";
		cout << '\n';
		cout << "\n\t\t Enter option ";

		cin >> choice;

		switch (choice)
		{
		case 1:
			system("CLS");
			a.CreateStudentsList();
			break;
		case 2:
			system("CLS");
			a.DisplayStudents();
			break;
		case 3:
			system("CLS");
			a.CalculateGeneralAVG();
			break;
		case 4:
			system("CLS");
			a.DisplayStudentsDescOrder();
			break;
		case 5:
			system("CLS");
			a.DisplayStudentsY3AVG8();
			break;
		case 6:
			system("CLS");
			a.insertStudent();
			break;
		case 7:
			system("CLS");
			a.removeNonPromotedStudents();
			break;
		case 8:
			system("CLS");
			a.onQuit();
			break;

		}

		cin.get();
		if (cin.get() == '\n')
			system("CLS");
	} while (choice != 8);


}
