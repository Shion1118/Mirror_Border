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

#include "SceneElement.cpp"

class Smile : public SceneElement{
    
public:
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    
    ExpressionClassifier classifier;
    
};
