#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif
#include <iostream>
#include "CoordR2.h"
#include "Population.h"
#include <vector>

//Tamanho em pixels da janela
#define windowWidth 600
#define windowHeight 600
//Máximo valor no eixo x
#define x_max_val 1000

using namespace std;

//Função para desenhar gráfico e menu
void draw();

//Função para receber comandos do teclado
void keyboard(unsigned char key, int x, int y);

const int num_population = 100;
const double mutation_rate = 0.6;

CoordR2 best_point(21,738.10);

Population pop(num_population, mutation_rate, best_point, x_max_val);

int main(int argc, char *argv[])
{
    //Criando janela na OpenGL
    glutInit(&argc, argv);
    //Definindo tamanho da janela
    glutInitWindowSize(windowWidth, windowHeight);
    //Posicao inicial da janela na tela
    glutInitWindowPosition(0, 0);
    //Nome da janela
    glutCreateWindow("Max Value Finder - GA");
    //Limpa a tela deixando com a cor definida (red, green, blue, alpha)
    glClearColor(0, 0, 0, 0);
    //Determinando intervalo do eixo cartesiano
    gluOrtho2D(0, 1000, 0, 1000);
    // Define qual função irá desenhar
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutDisplayFunc(draw);
    //Função que irá cpatar comandos do teclado
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    

    
    /*while (!pop.evaluate())
    {
        pop.calcFitness();
        pop.elitism();
        for (int i = 0; i < pop.populationSize(); i++)
        {
            cout << pop.population[i] << " - " << pop.population[i].getFitness() <<endl;
        }
        cout << "Best: " << pop.best << endl;
        cout << "Generation: " << pop.getGeneration() << endl;
        cout << "Target: " << pop.target << endl;
        cout << "-----------------------------------------------" << endl;
        getchar();
    }*/
    
    return 0;
}

void draw()
{
    //Limpa o buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Define que será desenhar um objeto azul
    glColor3f(0,1,0);
    // Fala para o OpenGL que os próximos pontos serão para desenhar linhas
    glBegin(GL_LINE_STRIP);

    //Gera o vetor de pontos a ser plotado  
    vector<CoordR2> points;
    for (int i = 0; i < x_max_val; i++)
    {
        CoordR2 p(i,p.function(i));
        points.push_back(p);
        glVertex2d((float)points[i].x,(float)points[i].y);
        if(points[i].y >= best_point.y)
        {
            best_point = points[i];
        }
    }
    // Fala para o OpenGL que terminou de enviar os pontos
    glEnd();

    //Escrevendo informações agora

    char best_point_s[30] = {'\0'};
    sprintf(best_point_s, "Target Point: (%.2f,%.2f)",best_point.x,best_point.y);
    glColor3f(0,1,0);
    glRasterPos2i(5,950);
    for (int i = 0; i < 30; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,best_point_s[i]);
    }

    char generation_s[30] = {'\0'};
    sprintf(generation_s, "Generation: %d",pop.getGeneration());
    glColor3f(0,1,0);
    glRasterPos2i(5,920);
    for (int i = 0; i < 30; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,generation_s[i]);
    }

    char best_gen_s[30] = {'\0'};
    sprintf(best_gen_s, "Best Point: (%.2f,%.2f)",pop.best.x,pop.best.y);
    glColor3f(0,1,0);
    glRasterPos2i(5,890);
    for (int i = 0; i < 30; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,best_gen_s[i]);
    }

    char avg_fit_s[30] = {'\0'};
    sprintf(avg_fit_s, "Average Fitness: %.2f",pop.averageFitness);
    glColor3f(0,1,0);
    glRasterPos2i(5,860);
    for (int i = 0; i < 30; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,avg_fit_s[i]);
    }

    char pop_size_s[30] = {'\0'};
    sprintf(pop_size_s, "Population Size: %d",pop.populationSize());
    glColor3f(0,1,0);
    glRasterPos2i(600,950);
    for (int i = 0; i < 30; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,pop_size_s[i]);
    }

    char mut_rate_s[30] = {'\0'};
    sprintf(mut_rate_s, "Mutation Rate: %.3f",mutation_rate);
    glColor3f(0,1,0);
    glRasterPos2i(600,920);
    for (int i = 0; i < 30; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13,mut_rate_s[i]);
    }

    glEnd();

    //Plotando pontos do individuo
    glBegin(GL_LINES);
    
    glColor4f(1.0,1.0,1.0,0.5);
    for (int i = 0; i < pop.populationSize(); i++)
    {
        glVertex2f(pop.population[i].x,pop.population[i].y);
        glVertex2f(pop.population[i].x,0);
    }
    //Plotando target
    glColor4f(1.0,0,0,0.5);
    glVertex2f(best_point.x,best_point.y);
    glVertex2f(best_point.x,0);

    if(pop.getGeneration() > 0)
    {
        //Plota melhor atual
        glColor4f(0,0,1.0,0.5);
        glVertex2f(pop.best.x,pop.best.y);
        glVertex2f(pop.best.x,0);
    }
    
    glEnd();
    //Faz o swap entre buffer de desenho e que será mostrado
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    if(key == 'q')
    {
        pop.calcFitness();
        pop.elitism();
        glutPostRedisplay();
    }
}