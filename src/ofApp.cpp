#include "ofApp.h"

using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    ofBlendMode(OF_BLENDMODE_ADD);
    
    cam.setDeviceID(2);
    cam.initGrabber(1280, 720);
    
    tracker.setup();
    
    gui = new ofxDatGui( ofxDatGuiAnchor::TOP_LEFT );
    gui->addFRM();
    label = gui->addLabel("");
    
    syphon.setName("MIRROR");

}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
        
        if(tracker.getFound()) {
            
            facePosition = tracker.getPosition();
            faceMesh = tracker.getObjectMesh();
            faceScale = tracker.getScale();
            faceMatrix = tracker.getRotationMatrix();
                
            boundingBox = Utils::getMeshBoundingBoxDimension(faceMesh);
            
            
            label->setLabel(ofToString(blackSize));
            
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
void ofApp::draw(){
    
    ofBackground(0);

    ofSetColor(255);
//    cam.draw(0, 0);
    
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
    
    syphon.publishScreen();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
