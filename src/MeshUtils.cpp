//
//  Util.cpp
//  mirror_world
//
//  Created by Fukushima Shion on 2017/05/06.
//
//

#include "MeshUtils.hpp"

    
ofVec3f MeshUtils::getMeshBoundingBoxDimension(ofMesh mesh) {
    
    auto xExtremes = minmax_element(mesh.getVertices().begin(), mesh.getVertices().end(),
                                    [](const ofPoint& lhs, const ofPoint& rhs) {
                                        return lhs.x < rhs.x;
                                    });
    auto yExtremes = minmax_element(mesh.getVertices().begin(), mesh.getVertices().end(),
                                    [](const ofPoint& lhs, const ofPoint& rhs) {
                                        return lhs.y < rhs.y;
                                    });
    auto zExtremes = minmax_element(mesh.getVertices().begin(), mesh.getVertices().end(),
                                    [](const ofPoint& lhs, const ofPoint& rhs) {
                                        return lhs.z < rhs.z;
                                    });
    return ofVec3f(xExtremes.second->x - xExtremes.first->x,
                   yExtremes.second->y - yExtremes.first->y,
                   zExtremes.second->z - zExtremes.first->z);
}
