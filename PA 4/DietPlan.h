#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cout; // we can now use cout without explicitly writing std::cout
using std::cin;
using std::endl;
using std::fstream;



class DietPlan
{
public:
	//Consturctor
	DietPlan(const int goalCalories = 0, std::string planName = "", std::string newdate = "");
	//Copy Consturctor
	DietPlan(DietPlan& rhs);

	//Deconstructor
	~DietPlan();

	int getCalories() const;
	std::string getPlan();
	std::string getDate();

	void setCalories(const int goalCalories);
	void setplan(std::string planName);
	void setdate(std::string newdate);

	void editcalories();

	





private:
	int calories;
	std::string plan;
	std::string date;
};

std::fstream& operator>> (std::fstream& lhs, DietPlan& rhs);
std::fstream& operator<<(std::fstream& lhs, DietPlan& rhs);
std::ostream& operator<<(std::ostream& lhs, DietPlan& rhs);


