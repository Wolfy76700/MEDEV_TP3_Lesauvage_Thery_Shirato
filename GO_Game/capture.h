/* 
 * File:   capture.h
 * Author: user
 *
 * Created on 8 décembre 2016, 09:56
 */

#ifndef CAPTURE_H
#define	CAPTURE_H
#include <vector>
#include <cstdlib>
#include <iostream>

bool test_capture(char tableau[MSIZE][MSIZE],int i, int j, char couleur);
void enlever_pierres(char tableau[MSIZE][MSIZE]);
std::vector<int> unite(char tableau[MSIZE][MSIZE],int i,int j,char couleur);

#endif	/* CAPTURE_H */

