#include "raylib.h"
#include "raymath.h"
#include "Flee.h"
#include <iostream>
#include <memory>
#include <vector>
#include <set>

using namespace std;


struct CollisionEvent
{
    weak_ptr<Flee> _LowerIndexFlee;
    weak_ptr<Flee> _HigherIndexFlee;
    Vector2 _Position;
    float _TimeOfImpact;

    CollisionEvent(weak_ptr<Flee> InLowerIndexFlee, weak_ptr<Flee> InHigherIndexFlee, float InTimeOfImpact)
        : _LowerIndexFlee(InLowerIndexFlee)
        , _HigherIndexFlee(InHigherIndexFlee)
        , _TimeOfImpact(InTimeOfImpact)
    {
        //Constructeur ici
    }
};

int main(void)
{
    constexpr int screenWidth = 1000;
    constexpr int screenHeight = 1000;
    constexpr int borderMargin = 50;
    constexpr int nbFlee = 25;

    constexpr Vector2 borderMin = Vector2{ borderMargin ,borderMargin };
    constexpr Vector2 borderMax = Vector2{ screenWidth - borderMargin , screenHeight - borderMargin };
    InitWindow(screenWidth, screenHeight, "Flee bonanza!");

    //1) Cr�er une structure de donn�e pour contenir des smart pointeur de puce sans la remplir


    //2) Dans une boucle, cr�ez des puces et placez-les au hasard � l'int�rieur de border min et border max
    //Indice: regardez la fonction raylib  GetRandomValue
    //Soyez explicite si des donn�es changes de type.


    //3) Allez voir plus haut ce que fait la structure et prenez le temps de la comprendre. Initializ� toutes les valeurs de la struct.
    //Pour l'attribut _Position, prenez la position de la puce avec le plus petit index (InLowerIndexFlee)
    //?SAVIEZ_VOUS? En c++, struct et classe sont tr�s similaires et on peut mettre des m�thodes (incluant des constructeurs/destructeurs)
    //aux struct


    //4) Cr�er une structure de donn�es pour contenir des smart pointer d'�v�nement de collision.


    SetTargetFPS(60);
    while (!WindowShouldClose())
    {

        const float deltaTime = GetFrameTime();
        const float totalTime = GetTime();
        BeginDrawing();
        ClearBackground(BLUE);
        DrawLine(borderMin.x, borderMin.y, borderMin.x, borderMax.y, PURPLE);
        DrawLine(borderMin.x, borderMin.y, borderMax.x, borderMin.y, PURPLE);
        DrawLine(borderMax.x, borderMin.y, borderMax.x, borderMax.y, PURPLE);
        DrawLine(borderMin.x, borderMax.y, borderMax.x, borderMax.y, PURPLE);
        //5) Dans raylib, trouvez uen mani�re de dessiner le nombre d'images par secondes en haut � gauche, commun�ment abr�vi� FPS en anglais

        //6) En haut dans le milieu, �crivez le nombre total de puces en noir

        //7) En haut � droite, �crivez le nombre total de collisions

        //8)Pour chaque puce, faites-la avancer (m�thode Move) et dessinez-la (m�thode Draw).

        //9) � l'int�rieur de la boucle pr�c�dente, trouvez une solution pour tester la collision (m�thode CollideWith) entre toutes les paires de puces possible
        //Chaque paire devrait �tre test�e une seule fois! Si une collision est d�tect�e, cr�ez et ajoutez un �v�nement de collision.

        //11) Dans une nouvelle boucle, pour chaque �v�nement de collision...
        //11.1) Dessinez un carr� blanc transparent de 5 par 5 � chaque position qu'il y a eu une collision
        //11.2) Dessinez une ligne noire transparente entre chaque puce qui a subit une collision
        //Suggestion de couleur: Color{ 25, 25, 25, 25 } et Color{ 255, 255, 255, 25 }


        //12) � chaque dois qu'on p�se sur espace, une puce doit �tre supprimez. Votre programme ne devrait pas crasher si vous l'avez fait correctement!

        EndDrawing();
    }

    CloseWindow();
    return 0;
}