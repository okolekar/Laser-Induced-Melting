#include <iostream>
#include <vector>
#include "Mesh.h"
#include "MatrixMult.h"
#include "Material_Subroutine.h"

//#=======================================================================================================================#//
class Elemental_Subroutine{
    private:
        int n;
        std::vector<double> b;
        std::vector<double> F;
        std::vector<std::vector<double>> M;
        std::vector<std::vector<double>> N;
        std::vector<std::vector<double>> dT_dH;
        std::vector<double> He_1; 

    public:
        std::vector<double> Gg;
        std::vector<std::vector<double> > dGg;

    Elemental_Subroutine(int n){
        //Constructor for the Elemental Subroutine//
        this->n = n;
        b.assign(this->n, 0.0);
        F.assign(this->n, 0.0);
        M.assign(this->n,std::vector<double>(this->n,0.0));
        N.assign(this->n,std::vector<double>(this->n,0.0));
        dT_dH.assign(this->n,std::vector<double>(this->n,0.0));
        Gg.assign(this->n,0.0);
        dGg.assign(this->n,std::vector<double>(this->n,0.0));
        He_1 = {0.0,0.0};
    };
//#=======================================================================================================================#//
    void get_gobal_parameter(const std::vector<double>& Hk, const std::vector<double>& Hk_1, const std::vector<double>& Tk_1, const Mesh &Mesh){
        material_subroutine Mat()
        b.assign(n,0.0);
        F.assign(n,0.0);
        M.assign(n,std::vector<double>(n,0.0));
        N.assign(n,std::vector<double>(n,0.0));
        dT_dH.assign(n,std::vector<double>(n,0.0));
        std::vector<double> temp(n,0.0),temp1(n,0.0),diff(n,0.0),temp2(n,0.0);
        std::vector<std::vector<double>> multip;
        for(int i = 0;i<n-1;i++){
            He_1[0] = Hk_1[i];
            He_1[1] = Hk_1[i+1];
            Mat.get_param(&He_1,i,&Mesh);
            diff[i] = Hk_1[i] - Hk[i];
            diff[i+1] = Hk_1[i+1] - Hk[i+1]; 
            assemble(i,&Mat);
        b[b.size()-2] = 0;
        temp = matmul(&N,&Tk_1);
        temp1 = matmul(&N,&Tk_1);
        multip = matmul(&N,&dT_dH);
        temp2 = matmul(&M,diff);
        for(int i = 0; i<n;i++){
            F[i] = delt*D*(b[i]-temp[i]);
            Gg[i] = temp2[i]-F[i];
            for(int j =0;j<n;j++){
                dGg[i][j] = M[i][j] + delt*D*multip[i][j];
            }
        }
        }
    }
}
//#=======================================================================================================================#//

    void Elemental_Subroutine::assemble(int i,const material_subroutine &Mat){
//#-----------------------------------------------------------------------------------------------------------------------#//
        M[i,i] = M[i,i] + Mat.M[0,0];
        M[i,i+1] = M[i,i+1] + Mat.M[0,1];
        M[i+1,i] = M[i+1,i] + Mat.M[1,0];
        M[i+1,i+1] = M[i+1,i+1] + Mat.M[1,1];
//#-----------------------------------------------------------------------------------------------------------------------#//
        N[i,i] = N[i,i] + Mat.N[0,0];
        N[i,i+1] = N[i,i+1] + Mat.N[0,1];
        N[i+1,i] = N[i+1,i] + Mat.N[1,0];
        N[i+1,i+1] = N[i+1,i+1] + Mat.N[1,1];
//#-----------------------------------------------------------------------------------------------------------------------#//
        dT_dH[i,i] = dT_dH[i,i] + Mat.dT_dH[0,0];
        dT_dH[i,i+1] = dT_dH[i,i+1] + Mat.dT_dH[0,1];
        dT_dH[i+1,i] = dT_dH[i+1,i] + Mat.dT_dH[1,0];
        dT_dH[i+1,i+1] = dT_dH[i+1,i+1] + Mat.dT_dH[1,1];
//#-----------------------------------------------------------------------------------------------------------------------#//
        b[i] = b[i] + Mat.b[0];
        b[i+1] = b[i+1] + Mat.b[1];
    }
//#=======================================================================================================================#//