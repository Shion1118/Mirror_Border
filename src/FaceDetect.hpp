//
//  FaceDetect.hpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/18.
//
//

#pragma once

#include "ofMain.h"

#include "FaceCam.hpp"
#include "SceneElement.cpp"

class FaceDetect : public SceneElement {
    
public:
    FaceDetect(FaceCam *fc);
    void setup() override;
    void update() override;
    void draw() override;
    
    FaceCam *face;
    ofTrueTypeFont font;
    
    string text = "No Face";
    ofRectangle textRec;
    
};
