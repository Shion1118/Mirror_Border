//
//  Smile.hpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#pragma once

#include "ofMain.h"
#include "ofxFaceTrackerThreaded.h"

#include "FaceCam.hpp"
#include "SceneElement.cpp"

class Smile : public SceneElement{
    
public:
    Smile(FaceCam *fc);
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    
    FaceCam *face;
    ExpressionClassifier classifier;
    float smileProbability;
    
    ofTrueTypeFont font;
    string text = "No Face";
    ofRectangle textRec;
    
};
