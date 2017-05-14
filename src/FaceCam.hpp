//
//  FaceTracker.hpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTrackerThreaded.h"

class FaceCam {
    
public:
    void init(int id, int w, int h);
    void update();
    
    bool isFaceFound();
    void reset();
    ofImage getImage();
    vector<ofMeshFace> getMeshFaces();
    
    ofVideoGrabber cam;
    ofFbo camFbo;
    ofPixels camPixels;
    ofImage camImage;
    ofxFaceTrackerThreaded tracker;
    
    ofVec2f facePosition;
    ofVboMesh faceMesh;
    float faceScale;
    ofMatrix4x4 faceMatrix;
    
};
