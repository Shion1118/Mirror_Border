//
//  Default.hpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#pragma once

#include "ofMain.h"

#include "SceneElement.cpp"

class Default : public SceneElement {
    
    public:
        void setup() override;
        void update() override;
        void draw() override;
    
    ofTrueTypeFont font;
    string textName = "Shion Fukushima";
    string textTime;
    ofRectangle nameRec, timeRec;
};
