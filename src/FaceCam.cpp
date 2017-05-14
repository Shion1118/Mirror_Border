//
//  FaceTracker.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#include "FaceCam.hpp"

void FaceCam::init(int id, int w, int h){
    
    cam.setDeviceID(id);
    cam.initGrabber(1920, 1080);
    
    camFbo.allocate(1920, 1080, GL_RGB);
    
    tracker.setup();
    
}

void FaceCam::update(){
    
    cam.update();
    
    if(cam.isFrameNew()) {
        camFbo.begin();
        cam.draw(0, 0);
        camFbo.end();
        camFbo.readToPixels(camPixels);
        camPixels.mirror(false, true);
        camImage.setFromPixels(camPixels);
        
        tracker.update(ofxCv::toCv(camImage));
        
        if(tracker.getFound()) {
            
            facePosition = tracker.getPosition();
            faceMesh = tracker.getObjectMesh();
            faceScale = tracker.getScale();
            faceMatrix = tracker.getRotationMatrix();
            
        }
    }
    
}

bool FaceCam::isFaceFound(){
    return tracker.getFound();
}

vector<ofMeshFace> FaceCam::getMeshFaces(){
    return faceMesh.getUniqueFaces();
}
