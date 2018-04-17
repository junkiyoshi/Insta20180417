#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(ofGetFrameNum() * 0.1);
	ofRotateY(ofGetFrameNum() * 0.25);

	float radius = 400 * ofNoise(ofGetFrameNum() * 0.01);
	ofIcoSpherePrimitive ico_sphere = ofIcoSpherePrimitive(radius , 2);
	vector<ofMeshFace> triangles = ico_sphere.getMesh().getUniqueFaces();
	for (int i = 0; i < triangles.size(); i++) {

		ofPoint average = (triangles[i].getVertex(0) + triangles[i].getVertex(1) + triangles[i].getVertex(2)) / 3;
		average = average.normalized() * 240;

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		ofVertex(triangles[i].getVertex(0).x, triangles[i].getVertex(0).y, triangles[i].getVertex(0).z);
		ofVertex(triangles[i].getVertex(1).x, triangles[i].getVertex(1).y, triangles[i].getVertex(1).z);
		ofVertex(triangles[i].getVertex(2).x, triangles[i].getVertex(2).y, triangles[i].getVertex(2).z);
		ofEndShape(true);

		for (int v = 0; v < 3; v++) {

			ofFill();
			ofSetColor(239);
			ofBeginShape();
			ofVertex(average);
			ofVertex(triangles[i].getVertex(v).x, triangles[i].getVertex(v).y, triangles[i].getVertex(v).z);
			ofVertex(triangles[i].getVertex((v + 1) % 3).x, triangles[i].getVertex((v + 1) % 3).y, triangles[i].getVertex((v + 1) % 3).z);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(39, 198);
			ofBeginShape();
			ofVertex(average);
			ofVertex(triangles[i].getVertex(v).x, triangles[i].getVertex(v).y, triangles[i].getVertex(v).z);
			ofVertex(triangles[i].getVertex((v + 1) % 3).x, triangles[i].getVertex((v + 1) % 3).y, triangles[i].getVertex((v + 1) % 3).z);
			ofEndShape(true);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}