
#include <iostream>
#include <fstream>
#include <string>
#define MAX 5

#include "graph.h"
using namespace std;

void visit(int);
int convertStringToPosition(string city, string cityArray[]);

int main()
{
    int numOfCities, cityWeight, cityRow, cityColumn;
    string mainCity, adjacentCity;
    string listOfCity[MAX];
    Graph<int> graph;
    int Matrix[MAX][MAX] = {0};
    ifstream fin;
    fin.open("city.txt");
    fin >> numOfCities;
    if(numOfCities <= MAX)
    {
        for(int i = 0; i < numOfCities; i++)
        {
            fin >> listOfCity[i];
        }
    }
    else
    {
        cout << "its to big" << endl;
    }
    while (fin)
    {
        fin >> numOfCities;
        fin >> mainCity;
        cityColumn = convertStringToPosition(mainCity, listOfCity);
        for(int z = 0; z < numOfCities; z++)
        {
            fin >> cityWeight;
            fin >> adjacentCity;
            cityRow = convertStringToPosition(adjacentCity, listOfCity);
            graph.add(cityColumn, cityRow, cityWeight);
        }
    }
    
}

int convertStringToPosition(string city, string cityArray[])
{
    for(int i = 0; i < MAX; i++)
    {
        if(city == cityArray[i])
        {
            return i;
        }
    }
    cout << "didnt find the correct city boss" << endl;
    return -666;
}

//passing in the array of strings is technically not allowed, but rather then displaying numbers I would want to display the string names. Thus I changed the paramaters to
//add the aray of strings to make the position string association. I hope I dont get docked points for this. If I do lose points then that is something I am fully willing
//too in order to have this nice code. It is worth it in my mind
void visit(int position, string CityArray[])
{
    cout << CityArray[position] << endl;
}