
#include <iostream>
#include <fstream>
#include <string>
#define MAX 5

#include "graph.h"
using namespace std;

void visit(int &city);
int convertStringToPosition(string city, string cityArray[]);
int cityRoutes(string cityArray[], Graph<int> graph);
void bubble(int array[]);

int main()
{
    int totalWeight[8];
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
    cout << endl << endl;
    graph.breadthFirstTraversal(1,visit);
    cout << endl << endl;
    graph.depthFirstTraversal(0,visit);
    //reno -> sf -> s -> slc -> v -> r
    totalWeight[0] = graph.getEdgeWeight(0,1) + graph.getEdgeWeight(1,4) + graph.getEdgeWeight(4,2) + graph.getEdgeWeight(2,3) + graph.getEdgeWeight(3,0);
    //reno -> sf -> v -> slc -> s -> r
    totalWeight[1] = graph.getEdgeWeight(0,1) + graph.getEdgeWeight(1,3) + graph.getEdgeWeight(3,2) + graph.getEdgeWeight(2,4) + graph.getEdgeWeight(4,0);
    //reno -> slc -> v -> sf -> s -> r
    totalWeight[2] = graph.getEdgeWeight(0,2) + graph.getEdgeWeight(2,3) + graph.getEdgeWeight(3,1) + graph.getEdgeWeight(1,4) + graph.getEdgeWeight(4,0);
    //reno -> slc -> s -> sf -> v -> r
    totalWeight[3] = graph.getEdgeWeight(0,2) + graph.getEdgeWeight(2,4) + graph.getEdgeWeight(4,1) + graph.getEdgeWeight(1,3) + graph.getEdgeWeight(3,0);
    //reno -> v -> slc -> s -> sf -> r
    totalWeight[4]= graph.getEdgeWeight(0,3) + graph.getEdgeWeight(3,2) + graph.getEdgeWeight(2,4) + graph.getEdgeWeight(4,1) + graph.getEdgeWeight(1,0);
    //reno -> v -> sf -> s -> slc -> r
    totalWeight[5] = graph.getEdgeWeight(0,3) + graph.getEdgeWeight(3,1) + graph.getEdgeWeight(1,4) + graph.getEdgeWeight(4,2) + graph.getEdgeWeight(2,0);
    //reno -> s -> slc -> v -> sf -> r
    totalWeight[6] = graph.getEdgeWeight(0,4) + graph.getEdgeWeight(4,2) + graph.getEdgeWeight(2,3) + graph.getEdgeWeight(3,1) + graph.getEdgeWeight(1,0);
    //reno -> s -> sf -> v -> slc -> r
    totalWeight[7] = graph.getEdgeWeight(0,4) + graph.getEdgeWeight(4,1) + graph.getEdgeWeight(1,3) + graph.getEdgeWeight(3,2) + graph.getEdgeWeight(2,0);
    bubble(totalWeight);
    for (int i = 0; i < 8; i++)
    {
        cout << totalWeight[i] << endl;
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


void bubble(int array[])
{
    int i, j, zyra;
    for (i = 0; i < MAX - 1; i++)
 
        // Last i elements are already in place
        for (j = 0; j < MAX - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                zyra = array[j];
                array[j] = array[j+1];
                array[j+1] = zyra;
            }
        }
}