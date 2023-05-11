
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define MAX 5

#include "graph.h"
using namespace std;

void visit(int &city);
int convertStringToPosition(string city, string cityArray[]);
int cityRoutes(string cityArray[], Graph<int> graph);

int main()
{
    int bestCityPath[4];
    int totalWeight = 0, bestTotalWeight = 0;
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
    fin.close();
    ofstream zyrafile ("cityPath.txt");
    //referenced https://www.geeksforgeeks.org/stdnext_permutation-prev_permutation-c/#
    int zyra[] = { 1, 2, 3, 4};
    sort(zyra, zyra + 4);
    if (zyrafile.is_open())
    {
        do {
                totalWeight = graph.getEdgeWeight(0,zyra[0]) + graph.getEdgeWeight(zyra[0],zyra[1]) + graph.getEdgeWeight(zyra[1],zyra[2]) + graph.getEdgeWeight(zyra[2],zyra[3]) +graph.getEdgeWeight(zyra[3],0);
                zyrafile << "Reno-> " << listOfCity[zyra[0]] << "-> " << listOfCity[zyra[1]] << "-> " << listOfCity[zyra[2]] << "-> " << listOfCity[zyra[3]] << "Cost: " << totalWeight << "\n";
                if(totalWeight < bestTotalWeight)
                    bestCityPath[0] = zyra[0];
                    bestCityPath[1] = zyra[1];
                    bestCityPath[2] = zyra[2];
                    bestCityPath[3] = zyra[3];
                    bestTotalWeight = totalWeight;
            } 
            while (next_permutation(zyra, zyra + 4));
        zyrafile << "\n" << "\n" << "\n";
        zyrafile << "Best Possible Route: " << "Reno-> " << listOfCity[bestCityPath[0]] << "-> " << listOfCity[bestCityPath[1]] << "-> " << listOfCity[bestCityPath[2]] << "-> " << listOfCity[bestCityPath[3]] << " Cost: " << totalWeight << "\n";
    }
    zyrafile.close();
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

void visit(int &city)
{
    switch (city)
    {
    case 0:
        cout << "Reno" << endl;
        break;
    case 1:
        cout << "SanFrancisco" << endl;
        break;
    case 2:
        cout << "SaltLakeCity" << endl;
        break;
    case 3:
        cout << "LasVegas" << endl;
        break;
    case 4:
        cout << "Seattle" << endl;
    default:
        break;
    }
}
