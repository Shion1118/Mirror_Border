//
//  Default.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#include "Default.hpp"

void Default::setup() {
    
    ofSetBackgroundColor(0);
    
    font.load("Lato-Thin.ttf", 40);
    
}

void Default::update() {
    
    textTime = ofGetTimestampString("%Y/%m/%d %H:%M:%S");
    timeRec = font.getStringBoundingBox(textTime, 0, 0);
    nameRec = font.getStringBoundingBox(textName, 0, 0);
    
}

void Default::draw() {
    
    ofSetColor(255);
    font.drawString(textName, ofGetWidth()/2 - nameRec.getWidth()/2, ofGetHeight()/2 - nameRec.getHeight()/2 - 5);
    font.drawString(textTime, ofGetWidth()/2 - timeRec.getWidth()/2, ofGetHeight()/2 + timeRec.getHeight()/2 + 5);
    
}
