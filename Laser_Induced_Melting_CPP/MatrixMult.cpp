#include "MatrixMult.h"

template<typename Type1>

void matmul(const Type1 &x, const Type1 &y, std::vector<std::vector<double>> &answer){

     int rowsx = x.size();
    int colsx = x[0].size();
    int rowsy = y.size();
    int colsy = y[0].size();

    std::ostringstream error_message;
    double sum = 0.0;

    if(colsx != rowsy){
        error_message << "Inappropriate matrix dimensions"<< colsx <<  "columns of x not equal to" << rowsy <<  "rows of y";
        throw std::runtime_error(error_message.str());
    }

    for(int i = 0;i<rowsx;i++){
        for(int j = 0;j<colsy;j++){
            for(int k = 0;k<colsx;k++){
                sum = sum+x[i][k]*y[k][j];
            }
            answer[i][j] = sum;
            sum = 0.0;
        }
    }
    //return answer;
}

void prnt(std::vector<std::vector<double> > &A){

    for(int i=0;i<A.size();i++){
        for (int j=0;j<A[0].size();j++){
            std::cout<< A[i][j]<< " ";
        }
        std::cout<<"\n";

    }
}




