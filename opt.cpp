#include <vector>
#include <iostream>
#include "opt.h"

Optimizor::Optimizor(int dim)
    :_input_dim(dim), _max_iter(100000), _step_size(0.01) {}

Optimizor::~Optimizor() {}

void Optimizor::set_loss_func(pFunc f) {
    this -> _loss_func = f;
}

void Optimizor::add_restraints(pFunc f) {
    this -> _restraints.push_back(f);
}

double Optimizor::optimize(vector<double> &vec) {
    vector<double> lambda(this->_restraints.size(), 0);
    
    vector<double> vec_grad(vec.size());
    vector<double> lambda_grad(lambda.size());

    for (int i = 0; i < this -> _max_iter; ++i) {
        this->_max_loss(vec, lambda);
        this->_min_loss(vec, lambda);
        
    }
    return this->_calc_loss(vec, lambda);
}

double Optimizor::_calc_loss(const vector<double> &vec, const vector<double>& lambda) {
    double loss = this -> _loss_func(vec);
    for (int i = 0; i < this->_restraints.size(); ++i) {
        loss += lambda[i] * this->_restraints[i](vec);
    }
    return loss;
}

void Optimizor::_min_loss(vector<double> &vec, const vector<double> &lambda) {

}

void Optimizor::_max_loss(const vector<double> &vec, vector<double> &lambda) {

}

void Optimizor::_calc_vec_grad(const vector<double> &vec, const vector<double> &lambda, vector<double> &grad) {

}

void Optimizor::_calc_lambda_grad(const vector<double> &vec, const vector<double> &lambda, vector<double> &grad) {
    
}

void Optimizor::test() {
    vector<double> t;
    t.push_back(2.5);
    std::cout << this->_loss_func(t) << std::endl;
}