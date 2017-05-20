//
//  Noise.hpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/18.
//
//

#pragma once

#include "ofMain.h"
#include "ofxPostGlitch.h"

#include "FaceCam.hpp"
#include "SceneElement.cpp"

class Noise : public SceneElement{
    
public:
    Noise(FaceCam *fc);
    void setup() override;
    void update() override;
    void draw() override;
    
    void keyPressed(int key) override;
    
    FaceCam *face;
    
    ofFbo noiseFbo;
    ofxPostGlitch glitch;
    
};

