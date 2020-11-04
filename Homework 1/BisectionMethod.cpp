/*******************************************************************************
 * Program:	Bisection Search Method
 * Purpose:	Allows you to find optimal solution with Bisection Heuristic Method.
 * Author:		Ege Demirbas
 * Version: 	0
********************************************************************************/
#include <windows.h>
#include <iostream>

std::string Option1 = "1 - Question 3.2 Solution.";
std::string Option2 = "2 - I want to define my region and precision level (e).";

void BisectionMethod(float RangeX, float RangeY, float PrecisionLevel);
void CreateShinyMenu();
void ClearKeyPressRecord();

void main()
{
	std::string ReLaunchApp;

	CreateShinyMenu();
	system("cls"); // clear console menu 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	std::cout << "This tool was created by Ege Demirbas. v0.0" << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << "	" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cout << "would you like to use Bisection Method again?" << std::endl;
	std::cout << "type y or n" << std::endl;

	//remove console key press history
	ClearKeyPressRecord();

	std::cin >> ReLaunchApp;
	if (ReLaunchApp == "y")
	{
		system("cls");
		CreateShinyMenu();
	}
	else
	{
		//terminate console app
	}
}

void CreateShinyMenu()
{
	int ToolOption = {};

	bool OptionSelected = false;

	//menu system 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		std::cout << "This tool was created by Ege Demirbas. v0.0" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		std::cout << "--------------------------------------------" << std::endl;
		std::cout << "											  " << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "Select an option with your arrow keys then press enter/return key." << std::endl;
		std::cout << "																	" << std::endl;
		std::cout << Option1 << std::endl;
		std::cout << Option2 << std::endl;
	}
	while (OptionSelected == false)
	{
		if ((GetAsyncKeyState(VK_UP) & 1) || (GetAsyncKeyState(0x31)))
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			std::cout << "This tool was created by Ege Demirbas. v0.0" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << "											  " << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "Select an option with your arrow keys then press enter/return key." << std::endl;
			std::cout << "																	" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			std::cout << Option1 << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << Option2 << std::endl;

			ToolOption = 1;
		}
		else if ((GetAsyncKeyState(VK_DOWN) & 1) || (GetAsyncKeyState(0x32)))
		{
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			std::cout << "This tool was created by Ege Demirbas. v0.0" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 23);
			std::cout << "--------------------------------------------" << std::endl;
			std::cout << "											  " << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			std::cout << "Select an option with your arrow keys then press enter/return key." << std::endl;
			std::cout << "																	" << std::endl;
			std::cout << Option1 << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			std::cout << Option2 << std::endl;

			ToolOption = 2;
		}
		if ((GetAsyncKeyState(VK_RETURN) & 1) && (ToolOption > 0))
		{
			OptionSelected = true;
		}
		Sleep(100);
	}

	if (ToolOption == 1)
	{
		BisectionMethod(float(0.1), float(10), float(0.001)); //standard option
	}
	else
	{
		ClearKeyPressRecord();

		float RangeX;
		float RangeY;
		float PrecisionLevel;

		std::cout << "	" << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		std::cout << "Enter Range Value of X." << std::endl;
		std::cin >> RangeX;
		std::cout << "Enter Range Value of Y." << std::endl;
		std::cin >> RangeY;
		std::cout << "Enter Precision Level." << std::endl;
		std::cin >> PrecisionLevel;

		BisectionMethod(RangeX, RangeY, PrecisionLevel);
	}
}

void ClearKeyPressRecord()
{
	PINPUT_RECORD KeyPress = new INPUT_RECORD[256];
	DWORD ClearingVar;
	ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), KeyPress, 256, &ClearingVar);
	delete[] KeyPress;
}

//main function
void BisectionMethod(float RangeX, float RangeY, float PrecisionLevel)
{	
	float x; 
	float fx;
	float fxe;
	float Result;

	while ((RangeY - RangeX) >= PrecisionLevel)
	{
		x = (RangeX + RangeY) / 2;
		fx = x + (1 / x);
		fxe = (x + PrecisionLevel) + (1 / (x + PrecisionLevel));
		if (fx >= fxe)
		{
			RangeX = x;
		}
		else
		{
			RangeY = x;
		}
	}
	
	Result = x;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cout << Result  << ": is a local minimum of f(x) with " << PrecisionLevel << " e- approximation level."<< std::endl;

	system("PAUSE");
}