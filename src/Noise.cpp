//
//  Noise.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/18.
//
//

#include "Noise.hpp"

Noise::Noise(FaceCam *fc) {
    face = fc;
}

void Noise::setup() {
    
    ofSetBackgroundColor(0);
    
    noiseFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    glitch.setup(&noiseFbo);
    
    glitch.setFx(OFXPOSTGLITCH_OUTLINE, true);
    
}

void Noise::update() {
    
    noiseFbo.begin();
    face->camImage.draw(0, 0);
    noiseFbo.end();
    
}

void Noise::draw() {
    
    glitch.generateFx();
    ofSetColor(255);
    noiseFbo.draw(0, 0);
    
}

void Noise::keyPressed(int key) {
    
}


