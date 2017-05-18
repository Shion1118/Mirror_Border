//
//  SceneManager.cpp
//  mirror_border
//
//  Created by Fukushima Shion on 2017/05/13.
//
//

#include <stdio.h>

#include "SceneElement.cpp"
#include "ofMain.h"

class SceneManager{
protected:
    int elementIndex = 0;
    vector<SceneElement *> elements;
    
public:
    
    void setup(){
        for(int i = 0; i < elements.size(); i++){
            elements[i]->setup();
        }
    }
    void update(){
        elements.at(elementIndex)->update();
    };
    
    void draw(){
        elements.at(elementIndex)->draw();
    };
    
    void end(){
        for(int i = 0; i < elements.size(); i++){
            elements[i]->end();
        }
    }
    
    void addElement(SceneElement* element) {
        elements.push_back(element);
    }
    
    void changeElement(int index){
        if(index >= elements.size()) elementIndex = 0;
        elements[elementIndex]->stop();
        elementIndex = index;
        elements[elementIndex]->start();
    }
    
    bool nextElement(){
        elements[elementIndex]->stop();
        elementIndex++;
        if(elementIndex >= elements.size()){
            elementIndex = 0;;
        }else{
            elements[elementIndex]->start();
        }
    };
    
    unsigned int getCurrentIndex(){
        return elementIndex;
    }
    
//--------------------------------------------------------------
    
    virtual void keyPressed(int key){
        elements.at(elementIndex)->keyPressed(key);
    };
    
    virtual void keyReleased(int key){
        elements.at(elementIndex)->keyReleased(key);
    };
    
    virtual void mouseMoved(int x, int y ){
        elements.at(elementIndex)->mouseMoved(x, y);
    };
    
    virtual void mouseDragged(int x, int y, int button){
        elements.at(elementIndex)->mouseDragged(x, y, button);
    };
    
    virtual void mousePressed(int x, int y, int button){
        elements.at(elementIndex)->mousePressed(x, y, button);
    };
    
    virtual void mouseReleased(int x, int y, int button){
        elements.at(elementIndex)->mouseReleased(x, y, button);
    };
    
    virtual void mouseEntered(int x, int y){
        elements.at(elementIndex)->mouseEntered(x, y);
    };
    
    virtual void mouseExited(int x, int y){
        elements.at(elementIndex)->mouseExited(x, y);
    };
    
    virtual void windowResized(int w, int h){
        elements.at(elementIndex)->windowResized(w, h);
    };
    
    virtual void dragEvent(ofDragInfo dragInfo){
        elements.at(elementIndex)->dragEvent(dragInfo);
    };
    
    virtual void gotMessage(ofMessage msg){
        elements.at(elementIndex)->gotMessage(msg);
    };
};
