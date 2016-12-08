#include "constantes.h"
#include "capture.h"
#include <cstdlib>
#include <iostream>
#include <vector>

//on créé une fonction qui va prendre en argument le tableau et la pièce qu'on
//veut mettre et renvoie true ou false sans changer le tableau, on peut ainsi
//utiliser cette fonction pour voir si on est dans un cas de suicide ou pas

bool test_capture(char tableau[MSIZE][MSIZE],int i, int j, char couleur){
    bool capture = false;
    
    
    
    
    
    return capture;
}


//fonction pour voir si un pion touche un ou plusieurs autres pions
//renvoie un vect<int> avec, pour chaque pion adj de couleur diff i puis j
//prend en arg le tableau 
std::vector<int> touche_diff(char tableau[MSIZE][MSIZE],int i,int j,char couleur){
    std::vector<int> touches;
    if(i != 0 && i != MSIZE-1 && j != 0 && j != MSIZE-1){
        //on fait d'abord en dehors des bords
        //on vérifie pour les quatre directions
        if(tableau[i-1][j] != couleur && tableau[i-1][j] != '+'){
            touches.push_back(i-1,j);
        }
        if(tableau[i][j-1] != couleur && tableau[i][j-1] != '+'){
            touches.push_back(i,j-1);
        }
        if(tableau[i+1][j] != couleur && tableau[i+1][j] != '+'){
            touches.push_back(i+1,j);
        }
        if(tableau[i][j+1] != couleur && tableau[i][j+1] != '+'){
            touches.push_back(i,j+1);
        }
    }
    
    return touches;
}
