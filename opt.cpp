#include <vector>
#include <iostream>
#include <limits>
#include "opt.h"

Optimizor::Optimizor(int dim)
    :_input_dim(dim), _max_iter(1000), _step_size(0.01) {}

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
        std::cout<< vec[0] << " " << lambda[0] << std::endl;
    }
    return this->_calc_loss(vec, lambda);
}

double Optimizor::_calc_loss(const vector<double> &vec, const vector<double>& lambda) {
    double loss = this -> _loss_func(vec);
    for (int i = 0; i < this->_restraints.size(); ++i) {
        loss -= lambda[i] * this->_restraints[i](vec);
    }
    return loss;
}

void Optimizor::_min_loss(vector<double> &vec, const vector<double> &lambda) {
    vector<double> grad(vec.size());
    for (int i = 0; i < 1; ++i) {
        this->_calc_vec_grad(vec, lambda, grad);
        for (int j = 0; j < vec.size(); ++j) {
            if (grad[j] < 0 && std::numeric_limits<double>::max() + this->_step_size * grad[j] < vec[j]) {
                vec[j] = std::numeric_limits<double>::max();
            } else if (grad[j] > 0 && std::numeric_limits<double>::min() + this->_step_size * grad[j] > vec[j]) {
                vec[j] = std::numeric_limits<double>::min();
            } else {
                vec[j] -= this->_step_size * grad[j];
            }
        }
    }
}

void Optimizor::_max_loss(const vector<double> &vec, vector<double> &lambda) {
    vector<double> grad(lambda.size());
    for (int i = 0; i < this->_max_iter; ++i) {
        this->_calc_lambda_grad(vec, lambda, grad);
        for (int j = 0; j < lambda.size(); ++j) {
            if (grad[j] > 0 && std::numeric_limits<double>::max() - this->_step_size * grad[j] < lambda[j]) {
                lambda[j] = std::numeric_limits<double>::max();
            } else {
                lambda[j] += this->_step_size * grad[j];
                if (lambda[j] < 0) {
                    lambda[j] = 0;
                }
            }            
        }
    }
}

void Optimizor::_calc_vec_grad(const vector<double> &vec, const vector<double> &lambda, vector<double> &grad) {
    vector<double> dup(vec);
    double left_loss, right_loss;
    for (int i = 0; i < vec.size(); ++i) {
        dup[i] -= 0.0001;
        left_loss = this->_calc_loss(dup, lambda);
        dup[i] += 0.0002;
        right_loss = this->_calc_loss(dup, lambda);
        dup[i] -= 0.0001;
        grad[i] = (right_loss - left_loss) / 0.0002;
    }
}

void Optimizor::_calc_lambda_grad(const vector<double> &vec, const vector<double> &lambda, vector<double> &grad) {
    vector<double> dup(lambda);
    double left_loss, right_loss;
    for (int i = 0; i < lambda.size(); ++i) {
        dup[i] -= 0.0001;
        left_loss = this->_calc_loss(vec, dup);
        dup[i] += 0.0002;
        right_loss = this->_calc_loss(vec, dup);
        dup[i] -= 0.0001;
        grad[i] = (right_loss - left_loss) / 0.0002;
    }
}

void Optimizor::test() {
    vector<double> t;
    t.push_back(2.5);
    std::cout << this->_loss_func(t) << std::endl;
    std::cout<< this->optimize(t) << std::endl;
}