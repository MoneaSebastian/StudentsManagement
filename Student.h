#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
private:
	string name;
	int year;
	float average;
	vector<string> courses;
	vector<float> grades;

public:
	Student(string, int, float, vector<string>, vector<float>);
	Student(string, int, vector<string>, vector<float>);

	string getName() const;
	int getYear() const;
	float getAverage() const;
	vector<string> getCourses() const;
	vector<float> getGrades() const;
	string getCoursesDisplayed() const;
	string getGradesDisplayed() const;

	void setName(string);
	void setYear(int);
	void setAverage(float);
	void setCourses(vector <string>);
	void setGrades(vector<float>);

	string displayStudent();
	void calculateAverage();

};



#endif
