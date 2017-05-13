#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxFaceTrackerThreaded.h"
#include "ofxDelaunay.h"
#include "ofxDatGui.h"
#include "ofxSyphon.h"

#include "Utils.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
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
    
        ofxDatGui* gui;
        ofxDatGuiLabel* label;
		
    ofxSyphonServer syphon;
};
