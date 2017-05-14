#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTrackerThreaded.h"
#include "ofxDelaunay.h"

#include "Utils.hpp"
#include "SceneElement.cpp"

class Face : public SceneElement{

	public:
		void setup() override;
		void update() override;
		void draw() override;

        void keyPressed(int key) override;
    
        ofVideoGrabber cam;
        ofxFaceTrackerThreaded tracker;
    
        ofVec2f facePosition;
        ofVboMesh faceMesh;
        float faceScale;
        ofMatrix4x4 faceMatrix;
        ofVec3f boundingBox;
    
        vector<ofMeshFace> blackFaces;
        int blackSize = 0;
        ofVboMesh blackMesh;
    
};
