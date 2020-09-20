#ifndef COORDR2_H
#define COORDR2_H

#include <iostream>

using namespace std;

class CoordR2
{
    private:

        //Pontuação (Score) do ponto
        double fitness;

    public:
        //Coordenada x
        double x;
        //Coordenada y
        double y;

        //Metódos construtores
        CoordR2();
        //Cria ponto com valores x e y passado como parâmetro
        CoordR2(double x, double y);

        //Calcula o fitness para o ponto
        void calcFitness(double target);

        //Faz o cruzamento do ponto com um parceiro, retornando o ponto do filho
        void crossover(CoordR2 partner);

        //Calcula valor y aplicando o x como entrada da função que rege o sistema
        double function(double x);

        //Retorna o fitness do ponto
        double getFitness();

        //Gera mutação para o ponto adicionando valor rândomico ao x e assim gerando um novo y
        void mutation(double mutation_rate, int max_val);

        //Sobrecrevendo operações nativas 
        friend ostream& operator<<(ostream& output, const CoordR2& p);

        friend bool operator==(const CoordR2 p1, const CoordR2 p2);

        void operator=(const CoordR2& p);
};


#endif