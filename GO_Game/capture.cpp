#include "constantes.h"
#include "capture.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "switchcolor.h"

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
    std::vector<int> touches = ();
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
    
    //test des cas particuliers
    //ici, on est sur le bord gauche sans être dans les coins
    if(i == 0 && j != 0 && j != MSIZE-1){
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
    
    //ici, on est sur le bord droit sans être dans les coins
    if(i == MSIZE-1 && j != 0 && j != MSIZE-1){
        if(tableau[i-1][j] != couleur && tableau[i-1][j] != '+'){
            touches.push_back(i-1,j);
        }
        if(tableau[i][j-1] != couleur && tableau[i][j-1] != '+'){
            touches.push_back(i,j-1);
        }
        if(tableau[i][j+1] != couleur && tableau[i][j+1] != '+'){
            touches.push_back(i,j+1);
        }
    }
    
    //en haut != coins
    if(j == 0 && i != 0 && i != MSIZE-1){
        if(tableau[i-1][j] != couleur && tableau[i-1][j] != '+'){
            touches.push_back(i-1,j);
        }
        if(tableau[i+1][j] != couleur && tableau[i+1][j] != '+'){
            touches.push_back(i+1,j);
        }
        if(tableau[i][j+1] != couleur && tableau[i][j+1] != '+'){
            touches.push_back(i,j+1);
        }
    }
    
    //en bas
    if(i != 0 && i != MSIZE-1 && j == MSIZE-1){
        if(tableau[i-1][j] != couleur && tableau[i-1][j] != '+'){
            touches.push_back(i-1,j);
        }
        if(tableau[i][j-1] != couleur && tableau[i][j-1] != '+'){
            touches.push_back(i,j-1);
        }
        if(tableau[i+1][j] != couleur && tableau[i+1][j] != '+'){
            touches.push_back(i+1,j);
        }
    }
    
    //en haut à gauche
    if(i == 0 && j == 0){
        if(tableau[i+1][j] != couleur && tableau[i+1][j] != '+'){
            touches.push_back(i+1,j);
        }
        if(tableau[i][j+1] != couleur && tableau[i][j+1] != '+'){
            touches.push_back(i,j+1);
        }
    }
    
    //haut droite
    if(i == 0 && j == MSIZE-1){
        if(tableau[i][j-1] != couleur && tableau[i][j-1] != '+'){
            touches.push_back(i,j-1);
        }
        if(tableau[i+1][j] != couleur && tableau[i+1][j] != '+'){
            touches.push_back(i+1,j);
        }
    }
    
    //bas gauche
    if(i == MSIZE-1 && j = 0){
        if(tableau[i-1][j] != couleur && tableau[i-1][j] != '+'){
            touches.push_back(i-1,j);
        }
        if(tableau[i][j+1] != couleur && tableau[i][j+1] != '+'){
            touches.push_back(i,j+1);
        }
    }
    
    //bas droite
    if(i == MSIZE-1 && j == MSIZE-1){
        if(tableau[i-1][j] != couleur && tableau[i-1][j] != '+'){
            touches.push_back(i-1,j);
        }
        if(tableau[i][j-1] != couleur && tableau[i][j-1] != '+'){
            touches.push_back(i,j-1);
        }
    }
    
    return touches;
}

//retourne true si le pion est capturé, false sinon
bool pion_capture(char tableau[MSIZE][MSIZE],int i,int j,char couleur){
    bool capture = true;//on l'initialise à true et on regarde si on ne peit pas le mettre false
    
    //cas hors bords
    if (i != 0 && j != 0 && i != MSIZE-1 && j != MSIZE-1){
        if (tableau[i-1][j] == '+' || tableau[i][j-] == '+' || tableau[i+1][j] == '+' || tableau[i][j+1] == '+'){
            capture = false;
        }
        
        //test sur toutes les directions pour savoir si on a des pions de même couleur
        //puis récursivité en changeant la couleur du pion originel pour éviter qu'ils ne se lancent la balle l'un l'autre
        //on stocke également les coord des pions de même couleur dans un vect<int>
        //ici, cependant, on stocke sous forme j,i pour utiliser les popbacks
        std::vector<int> memecouleur;
        memecouleur.push_back(0);//on stocke le nbre de pions blancs qu'on trouve
        if (tableau[i][j] == tableau[i-1][j]){
            memecouleur.push_back(j);
            memecouleur.push_back(i-1);
            memecouleur[0] += 1;
        }
        if (tableau[i][j] == tableau[i][j-1]){
            memecouleur.push_back(j-1);
            memecouleur.push_back(i);
            memecouleur[0] += 1;
        }
        if (tableau[i][j] == tableau[i+1][j]){
            memecouleur.push_back(j);
            memecouleur.push_back(i+1);
            memecouleur[0] += 1;
        }
        if (tableau[i][j] == tableau[i][j+1]){
            memecouleur.push_back(j+1);
            memecouleur.push_back(i);
            memecouleur[0] += 1;
        }
        
        //on teste sur les autres et on retourne false si c'est false pour l'un d'entre eux
        //mais au préalable, on change la couleur du pion courant (que l'on rechangera ensuite) pour éviter le ping-pong
        couleur = switchcolor(couleur);
        for (int k = 0; k < memecouleur[0]; k++){//on utilise la récursivité pour tous les pions adjacents de la meme couleur
            if (pion_capture(tableau[MSIZE][MSIZE],memecouleur.pop_back(),memecouleur.pop_back(),switchcolor(couleur)) == false){
                capture = false;
            }
        }
    }//ici se termine le cas général
    
    return capture;
}