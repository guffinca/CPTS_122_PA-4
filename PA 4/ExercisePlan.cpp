#include "ExercisePlan.h"
#include "DietPlan.h"
#include "ExercisePlan.h"

ExercisePlan::ExercisePlan(const int goalSteps, std::string planName, std::string newdate)
{
	this->steps = goalSteps;
	this->name = planName;
	this->date = newdate;

}

ExercisePlan::ExercisePlan(ExercisePlan& rhs)
{
	steps = rhs.steps;
	date = rhs.date;
	name = rhs.name;
}

ExercisePlan::~ExercisePlan()
{
	cout << "Inside Desructor" << endl;
}

int ExercisePlan::getSteps() const
{
	return steps;
}

std::string ExercisePlan::getPlan()
{
	return name;
}

std::string ExercisePlan::getDate()
{
	return date;
}

void ExercisePlan::setSteps(const int goalsteps)
{
	if (goalsteps >= 0)
	{
		steps = goalsteps;
	}
}

void ExercisePlan::setplan(std::string planName)
{
	name = planName;
}

void ExercisePlan::setdate(std::string newdate)
{
	date = newdate;
}


void ExercisePlan::editSteps()
{
	int Newgoal;
	cout << "Enter new Goal Calories";
	cin >> Newgoal;
	setSteps(Newgoal);
}

std::fstream& operator>> (std::fstream& lhs, ExercisePlan& rhs)
{
	std::string plan;
	std::getline(lhs, plan);
	//create a string of steps so I can use getline, then use stoi to change it back to an int
	std::string Steps;
	std::getline(lhs, Steps);
	int steps = stoi(Steps);
	std::string date;
	std::getline(lhs, date);
	rhs.setplan(plan);
	rhs.setSteps(steps);
	rhs.setdate(date);

	return lhs;
}

std::fstream& operator<<(std::fstream& lhs, ExercisePlan& rhs)
{
	lhs << rhs.getPlan() << endl; 
	lhs << rhs.getSteps() << endl;
	lhs << rhs.getDate() << endl;
	return lhs;
}

std::ostream& operator<<(std::ostream& lhs, ExercisePlan& rhs)
{
	lhs << "Plan " << rhs.getPlan() << " for " << rhs.getDate() << ": Goal: " << rhs.getSteps() << "steps";
	return lhs;
}

