#pragma once

#include "DietPlan.h"
#include "ExercisePlan.h"

class FitnessAppWrapper
{
public:
	void runApp();

	//created load daily for both diet and exercise
	void loadDailyPlan(fstream& infile, DietPlan &plan);

	void loadDailyPlan(fstream& infile, ExercisePlan& plan);

	//created load weekly for both diet and exercise
	void loadWeeklyPlan(fstream& infile, DietPlan weeklyPlan[]);

	void loadWeeklyPlan(fstream& infile, ExercisePlan weeklyPlan[]);

	void displayDailyPlan(DietPlan &plan);

	void displayDailyPlan(ExercisePlan& plan);

	void displayWeeklyPlan(DietPlan weeklyPlan[]);

	void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

	void storeDailyPlan(std::fstream &outfile, DietPlan &plan);

	void storeDailyPlan(std::fstream& outfile, ExercisePlan& plan);

	void storeWeeklyPlan(std::fstream &outfile, DietPlan weeklyPlan[]);

	void storeWeeklyPlan(std::fstream& outfile, ExercisePlan weeklyPlan[]);

	void displayMenu(void);

	int editPlan(DietPlan weeklyPlan[]);
	int editPlan(ExercisePlan weeklyPlan[]);

private:

};