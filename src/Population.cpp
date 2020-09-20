#include <iostream>
#include "Population.h"
#include "CoordR2.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

Population::Population(int num_population, double mutationRate, CoordR2 target, int max_x)
{
    srand(time(NULL));
    double x, y;
    for (int i = 0; i < num_population; i++)
    {
        CoordR2 point;
        x = (double)(rand()%max_x);
        y = point.function(x);
        point.x = x;
        point.y = y;
        this->population.push_back(point);
    }

    this->mutationRate = mutationRate;

    this->target = target;

    this->averageFitness = 0;

    this->best = CoordR2();   
}

void Population::calcFitness()
{
    for (int i = 0; i < population.size(); i++)
    {
        population[i].calcFitness(target.y);
        averageFitness += population[i].getFitness();
        if(population[i].getFitness() > best.getFitness())
            best = population[i];
    }
    averageFitness = averageFitness/population.size();
}

void Population::elitism()
{
    for (int i = 0; i < population.size(); i++)
    {
        if(population[i] == this->best)//Protege o melhor
            continue;
        else
            population[i].crossover(best); //Crossover com o melhor
    }
    
    generations++;
}

bool Population::evaluate()
{
    if(best == target)
        return true;
    else
        return false;
}

int Population::getGeneration()
{
    return generations;
}

int Population::populationSize()
{
    return this->population.size();
}