#pragma once


#include <vector>
#include "tsne.h"


class ofxTSNE
{
public:
    std::vector<std::vector<double>> run(std::vector<std::vector<float>>& data,
                                         int dims=2,
                                         double perplexity=30,
                                         double theta=0.5,
                                         bool normalize=true);

    std::vector<std::vector<double>> iterate();

private:
    void finish();
    
    TSNE tsne;
    std::vector<std::vector<double>> tsnePoints;
    std::vector<std::vector<float>> data;
    
    int dims;
    double perplexity;
    double theta;
    bool normalize;
    
    int N, D;
    double *X, *Y;

    int iter, max_iter;
};
