//
//  Smile.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#include "Smile.hpp"

Smile::Smile(FaceCam *fc){
    
    face = fc;
    
}

void Smile::setup() {
    
    ofSetBackgroundColor(0);
    
    classifier.load("expressions");
    
    font.load("font/Lato-Light.ttf", 40);
    
}

void Smile::update() {
    
    if(face->isFaceFound()) {
        classifier.classify(face->tracker);
        smileProbability = classifier.getProbability(1);
    }
    
}

void Smile::draw() {
    
    ofSetColor(255);
    if(face->isFaceFound()) {
        text = ofToUpper(classifier.getDescription(classifier.getPrimaryExpression()));
    }else{
        text = "No Face";
    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    textRec = font.getStringBoundingBox(text, 0, 0);
    font.drawString(text,  -textRec.width/2, -textRec.height/2);
    
    if(smileProbability < 0.25) {
        ofSetColor(255, 100, 100);
    } else if(smileProbability < 0.5) {
        ofSetColor(170, 170, 100);
    } else {
        ofSetColor(100, 255, 100);
    }
    ofSetLineWidth(100);
    ofDrawLine(-(smileProbability * 150)/2, textRec.height/2, (smileProbability * 150)/2, textRec.height/2);
    
    ofPopMatrix();
    
}

void Smile::keyPressed(int key) {
    
}
