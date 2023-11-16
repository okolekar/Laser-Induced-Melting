#include"Mesh.h"


    Mesh::Mesh(int n){
        //Constructor of the Mesh Class.//
        phi  = std::vector<double>(2,0.0);
        dphi = std::vector<double>(2,0.0);
        J = 1.0;

        if(n<2){
            throw std::runtime_error("Invalid number of nodes");
        }
        for (int i=0;i<n;i++){
            nodelist.push_back(i/static_cast<double>(n-1));
        }
        if(nodelist.back() != 1 || nodelist.back() == 0){
            throw std::runtime_error("Node list not generated correctly");
        }
    }

    void Mesh::update_Phi(float xi){
        //The method to modify the shape functions//

        if(xi<-1||xi>1){
            throw std::runtime_error("Incorrect xi value detected terminated the program");
        }
        phi[0] = 0.5*(1-xi);
        phi[1] = 0.5*(1+xi);
        if(static_cast<int>(phi[0] + phi[1]) != 1){
            std::cout << "The sum of shape function is " << phi[0] + phi[1] << std::endl;  
            throw std::runtime_error("The shape function does not follow the partition of unity");
        }
    }

    void Mesh::update_J(int i){
        // Method to update the Jacobian//
        double x1 = nodelist[i];
        double x2 = nodelist[i+1];
        J = 0.5*(x2-x1);
        if(J <= 0){
            std::cout<<"The Jacobian is found to be " << J << std::endl; 
            throw std::runtime_error("The jacobian is wrong");
        }
    }

    void Mesh::update_dPhi(){
        // The method to modify the derivative of shape functions //
        dphi[0] = -0.5;
        dphi[1] = 0.5;
        if(round((phi[0] + phi[1])) != 0){
            std::cout << "The sum of the derivative is" << (phi[0] + phi[1]);
            throw std::runtime_error("The derivative of shape function does not follow the partition of unity");
        }
        for(int i=0;i<2;i++){
            phi[i] = pow(J,-1)*phi[i];
        }
        
    }

    void Mesh::update_element(float xi, int i){
        //Updates all the mesh related parameters//
        update_J(i);
        update_dPhi();
        update_Phi(xi);
    }
