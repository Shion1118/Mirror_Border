#pragma once

#include "ofMain.h"

#include "SceneManager.cpp"
#include "FaceCam.hpp"
#include "Default.hpp"
#include "FaceDetect.hpp"
#include "FaceNoise.hpp"
#include "Smile.hpp"
#include "Noise.hpp"

class ofApp : public ofBaseApp{
    
    public:
        void setup();
        void update();
        void draw();
    
        void nextScene();
    
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
    
    
        SceneManager manager;
        FaceCam face;
    
        static const int TIMEOUT = 5000;
        float foundTime;
    
};
