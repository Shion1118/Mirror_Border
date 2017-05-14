#include "Face.hpp"

using namespace ofxCv;

//--------------------------------------------------------------
void Face::setup(){
    
    ofSetVerticalSync(true);
    
    ofBlendMode(OF_BLENDMODE_ADD);
    
    cam.listDevices();
    cam.setDeviceID(0);
    cam.initGrabber(1920, 1080);
    
    tracker.setup();
}

//--------------------------------------------------------------
void Face::update(){
    
    cam.update();
    
    if(cam.isFrameNew()) {
        camFbo.begin();
        cam.draw(0, 0);
        camFbo.end();
        
        tracker.update(toCv(cam));
        
        if(tracker.getFound()) {
            
            facePosition = tracker.getPosition();
            faceMesh = tracker.getObjectMesh();
            faceScale = tracker.getScale();
            faceMatrix = tracker.getRotationMatrix();
                
            boundingBox = Utils::getMeshBoundingBoxDimension(faceMesh);
            
            if(ofGetFrameNum() % 2 == 0) {
                blackMesh.clear();
                blackFaces = faceMesh.getUniqueFaces();
                if(blackSize > blackFaces.size()) blackSize = blackFaces.size();
                for (int i = 0; i < blackSize; i++) {
                    int r = ofRandom(blackFaces.size() - 1);
                    for (int j = 0; j < 3; j++) {
                        blackMesh.addVertex(blackFaces.at(r).getVertex(j));
                    }
                    blackFaces.erase(blackFaces.begin() + r);
                }
            }
            
        }
    }

}

//--------------------------------------------------------------
void Face::draw(){
    
    ofBackground(0);

    ofSetColor(255);
    cam.draw(0, 0);
    
    if(tracker.getFound()) {
        
        ofPushMatrix();
        
        ofTranslate(facePosition);
        ofScale(faceScale, faceScale);
        
//        ofNoFill();
//        ofDrawRectangle(-boundingBox[0]/2, -boundingBox[1]/2, boundingBox[0], boundingBox[1]);
    
        applyMatrix(faceMatrix);
        
        ofSetLineWidth(1);
        ofSetColor(255);
        faceMesh.drawWireframe();
        
        ofSetColor(ofColor::fromHsb(ofRandom(255), 255, 255));
        blackMesh.drawFaces();
        
        
        ofPopMatrix();
        
    }
    
}

//--------------------------------------------------------------
void Face::keyPressed(int key){
    
    switch (key) {
        case 'r':
            tracker.reset();
            break;
        case 'l':
            blackSize++;
            break;
        case 'k':
            blackSize--;
            if(blackSize < 0) blackSize = 0;
            break;
    }

}
