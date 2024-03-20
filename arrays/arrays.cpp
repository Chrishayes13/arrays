// arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

#include <cstring>

#include <fstream>

#include <iomanip>

using namespace std;

//declare the gobal array of type double

double average[5];

//declare the function prototypes

void getData(ifstream& inf, string n[], double runData[][8], int count);

void calculateAverage(double runData[][8], int count);

void print(string n[], double runData[][8], int count);

int main()

{

    string names[5];

    double runningData[5][8];

    ifstream inputfile("input.txt");

    if (inputfile)

    {

        //call the method getData

        getData(inputfile, names, runningData, 5);

    }

    else

    {

        //error message

        cout << "Sorry! Unable to open the file." << endl;

        system("pause");

        return 0;

    }

    //close the file

    inputfile.close();

    //call the method calculateAverage to compute the

    //average miliage of each runner

    calculateAverage(runningData, 5);

    //call display the names and their weekly run rate and their averages

    print(names, runningData, 5);

    system("pause");

    return 0;

}

//definition of method getData that reads the data from the file and

//stores the names into array n and run data into runData array

//simultaneously.

void getData(ifstream& inf, string n[], double runData[][8], int count)

{

    while (!inf.eof())

    {

        for (int i = 0; i < count; i++)

        {

            inf >> n[i];

            for (int j = 0; j < 7; j++)

            {

                inf >> runData[i][j];

            }

        }

    }

}

//definition of method calculateAverage that comptes the total first

//then stores the value of average into the average array

void calculateAverage(double runData[][8], int count)

{

    double total;

    for (int i = 0; i < count; i++)

    {

        total = 0;

        for (int j = 0; j < 7; j++)

        {

            total += runData[i][j];

        }

        average[i] = total / 7;

    }

}

//definition of method print that prints the output

//in a tabular format

void print(string n[], double runData[][8], int count)

{

    cout << setfill('=') << setw(80) << "=";

    cout << setfill(' ');

    cout << endl;

    cout << "Name" << setw(6) << "";

    for (int i = 0; i < 7; i++)

        cout << setw(7) << "Day " << (i + 1);

    cout << setw(12) << "Average" << endl;

    cout << setfill('=') << setw(80) << "=";

    cout << setfill(' ') << endl;

    for (int i = 0; i < count; i++)

    {

        cout << n[i] << setw(8) << fixed << "";

        for (int j = 0; j < 7; j++)

        {

            cout << setprecision(2) << fixed << runData[i][j] << setw(3) << "";

        }

        cout << setw(8) << average[i];

        cout << endl;

    }

    cout << setfill('=') << setw(80) << "=";

    cout << endl;

}

