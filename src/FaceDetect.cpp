//
//  FaceDetect.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/18.
//
//

#include "FaceDetect.hpp"

FaceDetect::FaceDetect(FaceCam *fc) {
    face = fc;
}

void FaceDetect::setup() {
    
    ofSetBackgroundColor(0);
    
    font.load("font/Lato-Thin.ttf", 40);
    
}

void FaceDetect::update() {
    
    if(face->isFaceFound()) {
        foundTime = ofGetElapsedTimef();
    }
    
}

void FaceDetect::draw() {
    
    ofSetColor(255);
    ofSetLineWidth(2);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofNoFill();
    ofDrawRectangle(-350, -350, 700, 700);
    ofPopMatrix();
    
}
