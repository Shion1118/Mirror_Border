//
//  FaceNoise.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#include "FaceNoise.hpp"

using namespace ofxCv;

FaceNoise::FaceNoise(FaceCam *fc){
    
    face = fc;
    
}

//--------------------------------------------------------------
void FaceNoise::setup(){
    
    ofBlendMode(OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void FaceNoise::update(){
    
    if(face->isFaceFound()) {
        if(ofGetFrameNum() % 2 == 0) {
            noiseMesh.clear();
            noiseFaces = face->getMeshFaces();
            if(noiseSize > noiseFaces.size()) noiseSize = noiseFaces.size();
            for (int i = 0; i < noiseSize; i++) {
                int r = ofRandom(noiseFaces.size() - 1);
                for (int j = 0; j < 3; j++) {
                    noiseMesh.addVertex(noiseFaces.at(r).getVertex(j));
                }
                noiseFaces.erase(noiseFaces.begin() + r);
            }
            
        }
    }
    
}

//--------------------------------------------------------------
void FaceNoise::draw(){
    
    ofBackground(0);

    ofSetColor(255);
    
    face->camImage.draw(0, 0);
    
    if(face->isFaceFound()) {
        
        ofPushStyle();
        ofPushMatrix();
        
        ofTranslate(face->facePosition);
        ofScale(face->faceScale, face->faceScale);
        
        applyMatrix(face->faceMatrix);
        
        ofSetLineWidth(1);
        ofSetColor(255);
        face->faceMesh.drawWireframe();
        
        ofSetColor(ofColor::fromHsb(ofRandom(255), 255, 255));
        noiseMesh.drawFaces();
        
        
        ofPopMatrix();
        ofPopStyle();
    }
}

//--------------------------------------------------------------
void FaceNoise::keyPressed(int key){
    
    switch (key) {
        case 'r':
//            tracker.reset();
            break;
        case 'l':
            noiseSize++;
            break;
        case 'k':
            noiseSize--;
            if(noiseSize < 0) noiseSize = 0;
            break;
    }

}
