#ifndef POPULATION
#define POPULATION

#include <iostream>
#include "CoordR2.h"
#include <vector>

using namespace std;

class Population
{
    private:
        //Guarda a geraçao atual
        int generations;

    public:
        //Vetor que guarda a polulação de pontos
        vector<CoordR2> population;
        //Ponto que queremos chegar
        CoordR2 target;
        //Melhor ponto da geracao atual
        CoordR2 best;
        //Guarda o fitness médio da geração
        double averageFitness;
        //Taxa de mutação
        double mutationRate;
        //Construtor
        Population(int num_population, double mutationRate, CoordR2 target, int max_x);
        //Calcula fitness para cada ponto da população e salva o melhor
        void calcFitness();
        //O melhor indivíduo(cromossomo) (poderia ser um conjunto dos melhores) sao copiados para
        //proxima geracao de populacao e sao utilizados para fazer crossover com o resto, gerando nova geracao
        void elitism();
        //Checa se ja chegamos no target, retornando true
        bool evaluate();
        //Retorna geracao atual
        int getGeneration();
        //Retorna numero da populacoa
        int populationSize();
};

#endif