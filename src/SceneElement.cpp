//
//  SceneElement.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/13.
//
//
#pragma once

#include "ofMain.h"

class SceneElement {
    public:
        virtual void setup(){};
        virtual void start(){};
        virtual void stop(){};
        virtual void update(){};
        virtual void draw(){};
        virtual void end(){};
    
        virtual void keyPressed(int key){};
        virtual void keyReleased(int key){};
        virtual void mouseMoved(int x, int y ){};
        virtual void mouseDragged(int x, int y, int button){};
        virtual void mousePressed(int x, int y, int button){};
        virtual void mouseReleased(int x, int y, int button){};
        virtual void mouseEntered(int x, int y){};
        virtual void mouseExited(int x, int y){};
        virtual void windowResized(int w, int h){};
        virtual void dragEvent(ofDragInfo dragInfo){};
        virtual void gotMessage(ofMessage msg){};
};
