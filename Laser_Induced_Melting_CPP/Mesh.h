//Mesh.h
#pragma once
#include <iostream>
#include <vector>
#include<cmath>


class Mesh{
    /* This class stores the variables related to the Mesh like 
    the shape function, derivative of the shape functions and also the Jacobian.
    phi  = shape function
    dphi = derivative of the shape function 
    J    = Jacobian */
public:
    std::vector<double> nodelist;
    std::vector<double> phi;
    std::vector<double> dphi;
    double J;

    Mesh(int);
    void update_Phi(float);
    void update_J(int);
    void update_dPhi();
    void update_element(float, int);
};
