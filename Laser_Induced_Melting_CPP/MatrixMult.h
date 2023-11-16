#pragma once


#include<iostream>
#include<vector>
#include <stdexcept>
#include <sstream>
#include <type_traits>

//void prnt(std::vector<std::vector<double> > &A);
//std::vector<std::vector<double>> matmul(const std::vector<std::vector<double>> &, const std::vector<std::vector<double>> &);
template<typename Type1>
void matmul(const Type1 &x, const Type1 &y, std::vector<std::vector<double>> &answer);
template<typename Type1>
void prnt(const Type1 &A);