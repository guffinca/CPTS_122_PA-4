
#include "DietPlan.h"
#include "ExercisePlan.h"
#include "FitnessWrapper.h"

void FitnessAppWrapper :: runApp()
{
	//Create list for each Plan

	DietPlan dietList[7] = {};
	ExercisePlan exerciseList[7] = {};
	std::fstream fDiet;
	std::fstream fExercise("exercisePlans.txt");
	displayMenu();

	int choice = 0;
	cin >> choice;

	switch (choice)
	{
		//Load weekly diet plan  from file
		
		if (fDiet.is_open())
		{
			loadWeeklyPlan(fDiet, dietList);
			
		}
		
	break;
	
	//Load weekly exercise plan from file
	case 2:
		if (fExercise.is_open())
		{
			loadWeeklyPlan(fExercise, exerciseList);
			
		}
		break;

	//Store weekly diet plan to file
	case 3: 
		if (fDiet.is_open())
		{
			storeWeeklyPlan(fDiet, dietList);
		
		}
		break;

	//Store Weekly diet plan to file
	case 4:
		if (fExercise.is_open())
		{
			storeWeeklyPlan(fDiet, dietList);
			
		}
		break;
	
		//display weekly diet plan
	case 5:
		displayWeeklyPlan(dietList);
		break;

	//Display weekly exerciseplan

	case 6:
		displayWeeklyPlan(exerciseList);
		break;

	//Edit goals
	case 7:
		/* Kept Giving me error code and i could figure out why
		
		int plan = editPlan(dietList);
		dietList[plan].editcalories();*/

	case 8:
		/* Kept giving me error code and i couldnt figure out why
		int plan = editPlan(exerciseList);
		exerciseList[plan].editSteps();
		break;*/

	//exit
	case 9:
		
		storeWeeklyPlan(fDiet, dietList);
		storeWeeklyPlan(fExercise, exerciseList);
		fExercise.close();
		fDiet.close();
		break;

	}

}

void FitnessAppWrapper::loadDailyPlan(fstream&infile, DietPlan& plan)
{
	
	infile >> plan;
}

void FitnessAppWrapper::loadDailyPlan(fstream& infile, ExercisePlan& plan)
{
	infile >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream &infile, DietPlan weeklyplan[])
{
	int i = 0;

	//does load daily for each day of a week
	for (i = 0; i < 7; i++)
	{
		loadDailyPlan(infile, weeklyplan[i]);
	}

}

void FitnessAppWrapper::loadWeeklyPlan(fstream& infile, ExercisePlan weeklyplan[])
{
	int i = 0;

	//does load daily for each day of a week
	for (i = 0; i < 7; i++)
	{
		loadDailyPlan(infile, weeklyplan[i]);
	}

}

//Displaying daily plan for dietplan class
void FitnessAppWrapper::displayDailyPlan(DietPlan& plan) {
	cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan)
{
	cout << plan << endl;
}

void FitnessAppWrapper :: displayWeeklyPlan(DietPlan weeklyPlan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeDailyPlan(std::fstream& outfile, DietPlan& plan)
{
	outfile << plan;
}

void FitnessAppWrapper::storeDailyPlan(std::fstream& outfile, ExercisePlan& plan)
{
	outfile << plan;
}

void FitnessAppWrapper::storeWeeklyPlan(std::fstream& outfile, DietPlan weeklyPlan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		storeDailyPlan(outfile, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::storeWeeklyPlan(std::fstream& outfile, ExercisePlan weeklyPlan[])
{
	int i = 0;

	for (i = 0; i < 7; i++)
	{
		storeDailyPlan(outfile, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayMenu(void)
{
	cout << "1.    Load weekly diet plan from file." << endl;
	cout << "2.    Load weekly exercise plan from file." << endl;
	cout << "3.    Store weekly diet plan to file. " << endl;
	cout << "4.    Store weekly exercise plan to file." << endl;
	cout << "5.    Display weekly diet plan to screen." << endl;
	cout << "6.    Display weekly exercise plan to screen." << endl;
	cout << "7.    Edit daily diet plan." << endl;
	cout << "8.    Edit daily exercise plan." << endl;
	cout << "9.    Exit. " << endl;








}

int FitnessAppWrapper::editPlan(DietPlan weeklyPlan[])
{
	int i = 0;
	displayWeeklyPlan(weeklyPlan);
	cout << "Which of the Plans do you want to edit ";
	cin >> i;
	return i;
}

int FitnessAppWrapper::editPlan(ExercisePlan weeklyPlan[])
{
	int i = 0;
	displayWeeklyPlan(weeklyPlan);
	cout << "Which of the Plans do you want to edit ";
	cin >> i;
	return i;
}


