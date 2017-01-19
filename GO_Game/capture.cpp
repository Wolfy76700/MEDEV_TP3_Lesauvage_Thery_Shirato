#include "constantes.h"
#include "capture.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include "switchcolor.h"

//on créé une fonction qui va prendre en argument le tableau et la pièce qu'on
//veut mettre et renvoie true ou false sans changer le tableau, on peut ainsi
//utiliser cette fonction pour voir si on est dans un cas de suicide ou pas

void enlever_pierres(char tableau[MSIZE][MSIZE]){
    std::vector<int> morts;
    morts.push_back(0);//compteur
    for (int i = 0; i < MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            //TODO
        }
    }
    for (int k = 0; k < morts[0]; k++){
        tableau[morts[morts.size()-1]][morts[morts.size()-2]] = '+';
        morts.pop_back();
        morts.pop_back();
    }
}


bool test_capture(char tableau[MSIZE][MSIZE],int i, int j, char couleur){ //TODO: Adapter a unite
    using namespace std;
    //ici, on récupère l'unite du pion avec unite et on teste dessus
    //puis, on renvoie true si l'unite est capturée
    bool capture = true;
    //TODO
    
    vector<int> atester = unite(tableau, i, j, couleur);
    unsigned int g = atester.size()/2;
    for(int h = 0; h<g;h++){
            int a = 2*h+1;//on récupère i puis j
            int b = 2*h;
            if (a>0){
                if (tableau[a-1][b] == '+'){
                    capture = false;
                }
            }
            if(b>0){
                if (tableau[a][b-1] == '+'){
                    capture = false;
                }
            }
            if(a<MSIZE-1){
                if (tableau[a+1][b] == '+'){
                    capture = false;
                }
            }
            if(b<MSIZE-1){
                if (tableau[a][b+1] == '+'){
                    capture = false;
                }
            }
            
        }
    return capture;
}




//on fait une fonction unite qui sort l'ensemble des pions en contact les uns avec les autres et avec le pion de départ, j avant i
std::vector<int> unite(char tableau[MSIZE][MSIZE],int i,int j,char couleur){
    using namespace std;
    vector<int> retour;
    int k = 1;//compteur du nombre de pions pris en compte, à l'itération où il ne bouge plus, on sort du programme
    int previousk = 0;
    retour.push_back(j);//on met toujours j avant i
    retour.push_back(i);
    
    while(k != previousk){
        previousk = k;
        for(int h=0;h<previousk;h++){
            int a = 2*h+1;//on récupère i puis j
            int b = 2*h;
            if (a!=0){
                if (tableau[a][b] == tableau[a-1][b]){
                    retour.push_back(b);
                    retour.push_back(a-1);
                    k += 1;
                }
            }
            if(b!=0){
                if (tableau[a][b] == tableau[a][b-1]){
                retour.push_back(b-1);
                retour.push_back(a);
                k += 1;
                }
            }
            if(a!=MSIZE-1){
                if (tableau[a][b] == tableau[a+1][b]){
                    retour.push_back(b);
                    retour.push_back(a+1);
                    k += 1;
                }
            }
            if(b!=MSIZE-1){
                if (tableau[a][b] == tableau[a][b+1]){
                    retour.push_back(b+1);
                    retour.push_back(a);
                    k += 1;
                }
            }
            
        }
    
    }
    return retour;
    
}