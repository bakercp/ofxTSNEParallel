#include "ofxTSNE.h"
#include "ofLog.h"


std::vector<std::vector<double>> ofxTSNE::run(std::vector<std::vector<float>>& data,
                                              int dims,
                                              double perplexity,
                                              double theta,
                                              bool normalize)
{
    if (dims != 2)
    {
        ofLogError("ofxTSNE::run") << "Is only comptible with 2 dimensions.  Using 2.";
        dims = 2;
    }

    this->data = data;
    this->dims = dims;
    this->perplexity = perplexity;
    this->theta = theta;
    this->normalize = normalize;

    max_iter = 1000;
    iter = 0;

    N = data.size();
    D = data[0].size();

    if (N - 1 < 3 * perplexity)
    {
        ofLog(OF_LOG_WARNING, "Perplexity too large for number of data points, setting to max");
        perplexity = (float) (N-1) / 3.0 - 1.0;
    }

    X = (double*) std::malloc(D * N * sizeof(double));
    Y = (double*) std::malloc(dims * N * sizeof(double));

    int idx = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<D; j++) {
            X[idx] = data[i][j];
            idx++;
        }
    }

    // t-SNE
    tsne.run(X, N, D, Y, dims, perplexity, theta, 8, max_iter);

    // void run(double* X, int N, int D, double* Y, int no_dims, double perplexity, double theta, int num_threads, int max_iter);

    return iterate();
}

std::vector<std::vector<double> > ofxTSNE::iterate()
{
    if (iter > max_iter)
    {
        return tsnePoints;
    }

    // keep track of min for normalization
    std::vector<double> min_, max_;

    min_.resize(dims);
    max_.resize(dims);

    for (int i = 0; i < dims; i++)
    {
        min_[i] = std::numeric_limits<double>::max();
        max_[i] = std::numeric_limits<double>::min();
    }

    // unpack Y into tsnePoints
    tsnePoints.clear();

    int idxY = 0;

    for (int i=0; i<N; i++) {
        std::vector<double> tsnePoint;
        tsnePoint.resize(dims);
        for (int j=0; j<dims; j++) {
            tsnePoint[j] = Y[idxY];
            if (normalize) {
                if (tsnePoint[j] < min_[j])  min_[j] = tsnePoint[j];
                if (tsnePoint[j] > max_[j])  max_[j] = tsnePoint[j];
            }
            idxY++;
        }
        tsnePoints.push_back(tsnePoint);
    }

    // normalize if requested
    if (normalize) {
        for (int i=0; i<tsnePoints.size(); i++) {
            for (int j=0; j<dims; j++) {
                tsnePoints[i][j] = (tsnePoints[i][j] - min_[j]) / (max_[j] - min_[j]);
            }
        }
    }

    iter++;

    if (iter == max_iter) {
        finish();
    }

    return tsnePoints;
}

void ofxTSNE::finish()
{
    delete(X);
    delete(Y);
}
