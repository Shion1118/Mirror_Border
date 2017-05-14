//
//  FaceNoise.hpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/14.
//
//

#pragma once

#include "ofMain.h"

#include "FaceCam.hpp"
#include "MeshUtils.hpp"
#include "SceneElement.cpp"

class FaceNoise : public SceneElement{

	public:
        FaceNoise(FaceCam *fc);
		void setup() override;
		void update() override;
		void draw() override;

        void keyPressed(int key) override;
    
        FaceCam *face;
    
        vector<ofMeshFace> noiseFaces;
        int noiseSize = 0;
        ofVboMesh noiseMesh;
    
};
