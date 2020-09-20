#include "CoordR2.h"
#include <iostream>
#include <math.h>


using namespace std;

//Metódos construtores
CoordR2::CoordR2()
{
    this->x = 0;
    this->y = 0;
    this->fitness = 0;   
}

CoordR2::CoordR2(double x, double y){
    this->x = x;
    this->y = y;
    this->fitness = 0;
}

double CoordR2::function(double x)
{
    double y = (2*cos(0.039*x) + 5*sin(0.05*x) + 0.5*cos(0.01*x) + 10*sin(0.07*x) + 5*sin(0.1*x) + 5*sin(0.035*x))*10+500;
    return y;
}

void CoordR2::calcFitness(double target)
{
    this->fitness = (this->y - target)>0?(this->y - target):-(this->y - target);
    this->fitness = 1 - this->fitness/target;
}

void CoordR2::crossover(CoordR2 partner)
{
    double x_child = (this->x + partner.x)/2.0;
    double y_child = function(x_child);
    this->x = x_child;
    this->y = y_child;
}

double CoordR2::getFitness()
{
    return this->fitness;
}

void CoordR2::mutation(double mutation_rate, int max_val)
{
    int acresc = ((double)(rand()%max_val) - max_val/2)*mutation_rate;
    this->x = this->x + acresc;
    if(this->x > max_val)
        this->x -= acresc;
    if(this->x < 0)
        this->x += acresc;
    this->y = function(this->x);
}

ostream& operator<<(ostream& output, const CoordR2& p){
    output << "( " << p.x << ", " << p.y << ")";
    return output;
}

bool operator==(const CoordR2 p1, const CoordR2 p2)
{
    return( p1.x == p2.x && p1.y == p2.y);
}

void CoordR2::operator=(const CoordR2& p)
{
    x = p.x;
    y = p.y;
    fitness = p.fitness;
}