#include "DietPlan.h"

DietPlan::DietPlan(const int goalCalories, std::string planName, std::string newdate)
{
	this->calories = goalCalories;
	this->plan = planName;
	this->date = newdate;
}

DietPlan::DietPlan(DietPlan& rhs)
{
	calories = rhs.calories;
	date = rhs.date;
	plan = rhs.plan;
}

DietPlan::~DietPlan()
{
	cout << "Inside Desructor" << endl;
}

int DietPlan::getCalories() const
{
	return calories;
 }

std::string DietPlan::getPlan()
{
	return plan;
}

std::string DietPlan::getDate()
{
	return date;
}

void DietPlan::setCalories(const int goalCalories)
{
	if (goalCalories >= 0)
	{
		calories = goalCalories;
	}
}

void DietPlan::setplan(std::string planName)
{
	plan = planName;
}

void DietPlan::setdate(std::string newdate)
{
	date = newdate;
}

void DietPlan::editcalories()
{
	int Newgoal;
	cout << "Enter new Goal Calories";
	cin >> Newgoal;
	setCalories(Newgoal);
}

std::fstream& operator>> (std::fstream& lhs, DietPlan& rhs)
{
	std::string plan;
	std::getline(lhs, plan);
	//create a string of calories so I can use getline, then use stoi to change it back to an int
	std::string Calories;
	std::getline(lhs, Calories);
	int calories = stoi(Calories);
	std::string date;
	std::getline(lhs, date);
	rhs.setplan(plan);
	rhs.setCalories(calories);
	rhs.setdate(date);

	return lhs;
}

std::fstream& operator<<(std::fstream& lhs, DietPlan& rhs)
{
	lhs << rhs.getPlan() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl;

	return lhs;
}

std::ostream& operator<<(std::ostream& lhs, DietPlan& rhs)
{
	lhs << "Plan " << rhs.getPlan() << " for " << rhs.getDate() << ": Goal: " << rhs.getCalories() << " calories";
	return lhs;
}