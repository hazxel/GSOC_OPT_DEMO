#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
#include "opt.h"

using std::cout;
using std::endl;

double func(const vector<double>&);

int main(int argc, char* argv[]) {
    Optimizor optimizor(3);
    optimizor.set_loss_func(func);
    optimizor.add_restraints(func);
    optimizor.test();
}

double func(const vector<double> &input) {
    double sum = 0;
    for (auto num = input.begin(); num != input.end(); ++num) {
        sum += *num;
    }
    return sum;
}