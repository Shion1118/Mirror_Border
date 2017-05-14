//
//  FaceTracker.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#include "FaceCam.hpp"

void FaceCam::init(int id, int w, int h) {
    
    cam.setDeviceID(id);
    cam.initGrabber(1920, 1080);
    
    camFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);
    
    tracker.setup();
    
}

void FaceCam::update() {
    
    cam.update();
    
    if(cam.isFrameNew()) {
        camFbo.begin();
        cam.draw(-((3680 - ofGetWidth())/2), -((2070 - ofGetHeight())/2), 3680, 2070);
        camFbo.end();
        camFbo.readToPixels(camPixels);
        camPixels.mirror(false, true);
        camImage.setFromPixels(camPixels);
        
        tracker.update(ofxCv::toCv(camPixels));
        
        if(tracker.getFound()) {
            
            facePosition = tracker.getPosition();
            faceMesh = tracker.getImageMesh();
            faceScale = tracker.getScale();
            faceMatrix = tracker.getRotationMatrix();
            
        }
    }
    
}

bool FaceCam::isFaceFound() {
    return tracker.getFound();
}

void FaceCam::reset() {
    tracker.reset();
}

vector<ofMeshFace> FaceCam::getMeshFaces() {
    return faceMesh.getUniqueFaces();
}
