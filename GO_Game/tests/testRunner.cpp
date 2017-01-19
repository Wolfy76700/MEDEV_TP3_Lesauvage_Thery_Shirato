#include "gtest/gtest.h"
#include "constantes.h"
#include "capture.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
 

TEST(Equality,AddIntegers_GetSum){
	EXPECT_EQ(23,11+12);
}




TEST(unite,unite){
    char board[MSIZE][MSIZE];
    for (int i = 0; i<MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            board[i][j] = '+';
        }
    }
    board[0][2] = 'N';
    board[1][1] = 'N';
    board[1][3] = 'N';
    board[3][2] = 'N';
    board[1][2] = 'B';
    board[2][2] = 'B';
    board[2][3] = 'B';
    vector<int> resultat;
    resultat.push_back(2);
    resultat.push_back(1);
    resultat.push_back(2);
    resultat.push_back(2);
    resultat.push_back(3);
    resultat.push_back(2);
    EXPECT_EQ(resultat[0],unite(board,1,2,'B')[0]);
    EXPECT_EQ(resultat[1],unite(board,1,2,'B')[1]);
    EXPECT_EQ(resultat[2],unite(board,1,2,'B')[2]);
    EXPECT_EQ(resultat[3],unite(board,1,2,'B')[3]);
    EXPECT_EQ(resultat[4],unite(board,1,2,'B')[4]);
    EXPECT_EQ(resultat[5],unite(board,1,2,'B')[5]);
    

}





TEST(testcapture,test_capture){
    char board[MSIZE][MSIZE];
    for (int i = 0; i<MSIZE; i++){
        for (int j = 0; j < MSIZE; j++){
            board[i][j] = '+';
        }
    }
    board[0][2] = 'N';
    board[1][1] = 'N';
    board[1][3] = 'N';
    board[3][2] = 'N';
    board[1][2] = 'B';
    board[2][2] = 'B';
    board[2][3] = 'B';
    
    
    EXPECT_FALSE(test_capture(board,1,2,'B'));
    
    board[2][1] = 'N';
    board[3][3] = 'N';
    board[2][4] = 'N';
    EXPECT_TRUE(test_capture(board,1,2,'B'));
    
}





int main (int argc, char** argv)
{
  cout << "hello" << endl;
  ::testing::InitGoogleTest (&argc, argv);
  return RUN_ALL_TESTS();
}

