#include<iostream>
#include<vector>
#include"MatrixMult.h"


int main(){
    int temp = 5;
    std::vector<std::vector<double>> A(temp, std::vector<double>(temp, 0));
    std::vector<std::vector<double>> B(temp, std::vector<double>(temp, 0));
    std::vector<std::vector<double>> C;

    for(int i = 0;i<temp;i++){
        for(int j = 0;j<temp;j++){
            A[i][j] = i*j+1.0;
            B[i][j] = i*2.0+j+4.0;
        }
    }

    std::cout<<"I am printing A"<<"\n";
    prnt(A);
    std::cout<<"I am printing B"<<"\n";
    prnt(B);
    
    C = matmul(A,B);

    std::cout<<"I am printing C"<<"\n";
    prnt(C);



    return 0;
};