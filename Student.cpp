#include "Student.h"
#include <vector>

using namespace std;

Student::Student(string _name, int _year, float _average, vector<string> _courses, vector<float> _grades) : name(_name), year(_year), average(_average), courses(_courses), grades(_grades) {

}

Student::Student(string _name, int _year, vector<string> _courses, vector<float> _grades) : name(_name), year(_year), courses(_courses), grades(_grades) {
	float _average = 0;
	
	for (int i = 0; i < _grades.size(); i++) {
		_average = _average + _grades.at(i);
	}

	average = _average / _grades.size();

}

string Student::getName() const {
	return name;
}

int Student::getYear() const {
	return year;
}

float Student::getAverage() const {
	return average;
}

vector<string> Student::getCourses() const {
	return courses;
}

vector<float> Student::getGrades() const{
	return grades;
}

void Student::setName(string _name) {
	name = _name;
}

void Student::setYear(int _year){
	year = _year;
}

void Student::setAverage(float _average){
	average = _average;
}

void Student::setCourses(vector <string> _courses) {
	courses = _courses;
}

void Student::setGrades(vector <float> _grades) {
	grades = _grades;
}

string Student::getCoursesDisplayed() const{
	string coursesString;
	for (int i = 0; i < courses.size(); i++) {
		coursesString = coursesString + courses.at(i) + " ";
	}

	return coursesString;
}

string Student::getGradesDisplayed() const {
	string gradesString;
	for (int i = 0; i < grades.size(); i++) {
		gradesString = gradesString + to_string(grades.at(i)) + " ";
	}

	return gradesString;
}

string Student::displayStudent(){
	return "Student " + name + " is in year " + to_string(year) + " and has average " + to_string(average) + " courses: " + getCoursesDisplayed() + "grades: " + getGradesDisplayed();
}

void Student::calculateAverage() {
	float _average = 0;

	for (int i = 0; i < grades.size(); i++) {
		_average = _average + grades.at(i);
	}

	average = _average / grades.size();
}