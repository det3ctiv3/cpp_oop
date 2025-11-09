#include <iostream>
using namespace std;


class Course{
public:
	string title;
	string code;
	int credits;


	Course(){

		this->title = "Unknown";
		this->code ="0000";
		this->credits= 0;


	}
	Course(string title, string code, int credits){
		this->title = title;
		this->code = code;
		this->credits = credits;
	}

	void display(){
		cout<< "Title: " << title << endl;
		cout<< "Code: " << code << endl;
		cout<< "Credits: "<< credits << endl;
	}

};

class Student {
private:
	string name;
	int id;
	double gpa;
	string department;
	// Course enrolledCourse;

public:
	void setName(string name) {
		this->name = name;
	}
	void getName() {
		cout << "Name: " << name << endl;
	}

	Student (){
		this->name = "Dovud";
		this->id = 23002;
		this->gpa = 3.8;
		this->department = "Physics";
		// this->enrolledCourse = Course("Calculus", "MATH101", 4);
	}



	Student(string name, int id, double gpa, string department){
			name = name;
		this->id = id;
		this->gpa = gpa;
		this->department = department;
		//this->enrolledCourse = Course("Calculus", "MATH101", 4);
	}
	void display(){
	cout<< "Name: " << name << endl;
	cout<< "ID: " << id << endl;
	cout<< "GPA: "<< gpa << endl;
	cout<< "Department: " << department<< endl;
	cout<< "Enrolled course:" << endl;
	//cout<< "Course: " << enrolledCourse.title << endl;
   // cout<< "Code: " << enrolledCourse.code << endl;
    //cout<< "Credits: " << enrolledCourse.credits << endl;

	}


};


int main(){

	Student object1;
	Student object2("Dovud", 23002, 3.8, "Physics");
	
	Course favoriteCourse("Object-Oriented Programming", "CS201", 4);
	
	// Student myStudent("Ghost", 24001, 3.9, "Computer Science");
	// myStudent.enrolledCourse = favoriteCourse;
	
	cout << "Student1: " << endl;
	object1.display();
	cout << endl;
	cout << "Student2: " << endl;
	object2.display();
	cout << endl;
	// cout << "My Student with favorite course: " << endl;
	// myStudent.display();

}




