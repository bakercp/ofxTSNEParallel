#pragma once


#include "ofMain.h"
#include "ofxTSNE.h"


class ofApp: public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();

    struct TestPoint
    {
        int class_;
        ofColor color;
        vector<float> point;
        ofPoint tsnePoint;
    };

    ofxTSNE tsne;
    std::vector<TestPoint> testPoints;
    std::vector<std::vector<double>> tsnePoints;

};
