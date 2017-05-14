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
    
    font.load("Lato-Thin.ttf", 40);
    
}

void Smile::update() {
    
    if(face->isFaceFound()) {
        classifier.classify(face->tracker);
    }
    
}

void Smile::draw() {
    
    ofSetColor(255);
    if(face->isFaceFound()) {
        text = classifier.getDescription(classifier.getPrimaryExpression());
    }else{
        text = "No Face";
    }
    
    textRec = font.getStringBoundingBox(text, 0, 0);
    font.drawString(text, ofGetWidth()/2 - textRec.width/2, ofGetHeight()/2 - textRec.height/2);
    
}

void Smile::keyPressed(int key) {
    
}
