#include<iostream>
#include "Mesh.h"
#include "MatrixMult.h"

class material_subroutine{
    public:
        std::vector<double> b;
        std::vector<std::vector<double>> M;
        std::vector<std::vector<double>> N;

        material_subroutine();
        void resetatt();
        void get_param(std::vector<double> &He_1,int ele,Mesh &Mesh);
    };
    material_subroutine::material_subroutine(){
        b= {0.0, 0.0};
        M = {{{0.0,0.0},{0.0,0.0}}};
        N = {{{0.0,0.0},{0.0,0.0}}};
    }

    void material_subroutine::resetatt(){
        b = {0.0, 0.0};
        M = {{{0.0,0.0},{0.0,0.0}}};
        N = {{{0.0,0.0},{0.0,0.0}}};
    }
    void material_subroutine::get_param(std::vector<double> &He_1,int ele,Mesh &Mesh){
        switch (ele)
        {
        case 0:
            b[0] = 1;//ratioI; TO BE CHANGED LATER
            break;
        case 5-2://TO BE CHANGED LATER
            b[0] = Mesh.dphi[1]*Mesh.phi[0]*Mesh.J;
            b[1] = Mesh.dphi[1]*Mesh.phi[1]*Mesh.J;
            break;
        default:
            b[0] = 0.0;
            b[1] = 0.0;
            break;
        }
        matmul(Mesh.phi,Mesh.phi,M);

    }

int main(){

    std::vector<double> He_1(2,0.0);
    Mesh mes(11);
    material_subroutine al;
    al.get_param(He_1,2,mes);
}