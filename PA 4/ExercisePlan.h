#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;
using std::fstream;

class ExercisePlan
{
public:
	ExercisePlan(const int goalSteps = 0, std::string planName = "", std::string newdate = "");
	ExercisePlan(ExercisePlan& rhs);
	~ExercisePlan();
	int getSteps() const;
	std::string getPlan();
	std::string getDate();

	void setSteps(const int goalsteps);
	void setplan(std::string planName);
	void setdate(std::string newdate);

	void editSteps();
private:
	int steps;
	std::string name;
	std::string date;
};

//read file function
std::fstream& operator>> (std::fstream& lhs, ExercisePlan& rhs);

std::fstream& operator<<(std::fstream& lhs, ExercisePlan& rhs);

std::ostream& operator<<(std::ostream& lhs, ExercisePlan& rhs);
