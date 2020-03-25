#include <iostream>
#include "opt.h"

using std::cout;
using std::endl;

double func(const vector<double>&);
double restraint1(const vector<double>&);
double restraint2(const vector<double>&);


int main(int argc, char* argv[]) {
    Optimizor optimizor(3);
    optimizor.set_loss_func(func);
    optimizor.add_restraints(restraint1);
    optimizor.add_restraints(restraint2);
    vector<double> t({4, 5});
    std::cout << "loss: " << optimizor.optimize(t) << std::endl;
}

double func(const vector<double> &input) {
    double sum = 0;
    for (auto num = input.begin(); num != input.end(); ++num) {
        sum += (*num) * (*num);
    }
    return sum;
}

double restraint1(const vector<double> &input) {
    return input[1] - input[0] - 1;
}

double restraint2(const vector<double> &input) {
    return input[1] + input[0] - 1;
}
