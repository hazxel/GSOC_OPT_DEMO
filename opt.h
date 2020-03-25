#ifndef _OPT_H_
#define _OPT_H_

#include <vector>

using std::vector;

typedef double(*pFunc)(const vector<double>&);

class Optimizor {
public:
    Optimizor(int);
    ~Optimizor();
    void set_loss_func(pFunc);
    void add_restraints(pFunc);
    double optimize(vector<double>&);

private:
    int _input_dim;
    int _max_iter;
    double _step_size;
    pFunc _loss_func;
    vector<pFunc> _restraints;

    double _calc_loss(const vector<double>&, const vector<double>&);

    void _min_loss(vector<double>&, const vector<double>&);
    void _max_loss(const vector<double>&, vector<double>&);

    void _calc_vec_grad(const vector<double>&, const vector<double>&, vector<double>&);
    void _calc_lambda_grad(const vector<double>&, const vector<double>&, vector<double>&);
};

#endif
