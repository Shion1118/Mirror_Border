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
    
    font.load("font/Lato-Light.ttf", 40);
    
}

void FaceDetect::update() {
    
    if(face->isFaceFound()) {
        if(face->facePosition.distance(ofVec2f(ofGetWidth()/2, ofGetHeight())/2) < 50) {
            text = "OK";
            
        } else {
            text = "Please adjust your face position";
        }
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
    
    textRec = font.getStringBoundingBox(text, 0, 0);
    font.drawString(text, ofGetWidth()/2 - textRec.width/2, ofGetHeight()/2 - textRec.height/2);
    
}
