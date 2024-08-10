#pragma once

#include "OpenGLWindow.h"
#include <ShaderProgram.h>
#include <memory>
#include <AssetManager.h>
#include "Transform.h"

class Scene
{
public:
	Scene(OpenGLWindow* window);
	~Scene();

	bool init();
	void shutdown();
	void render(float dt);
	void update(float dt);
	OpenGLWindow* getWindow();

	void onKey(Key key, Action action, Modifier modifier);
	void onMouseMove(MousePosition mouseposition);
	void onMouseButton(MouseButton button, Action action, Modifier modifier);
	void onMouseScroll(double xscroll, double yscroll);
	void onFrameBufferResize(int width, int height);

private:
	OpenGLWindow* m_window;
	AssetManager m_assets;
    ShaderProgram* m_shader;
    GLuint vaoID, vboID;
    Transform* head;
    Transform* body;
    Transform* right_arm1;
    Transform* left_arm1;
    Transform* t1bodypart;
    Transform* leftLegrotation;
    Transform* leftRightrotation;
    Transform* right_arm2;
    Transform* left_arm2;
    Transform* left_leg;
    Transform* right_leg;
    Transform* rightlegRotate;
    Transform* leftlegRotate;
    Transform* leftArmrotate;
    Transform* rightArmrotate;
    Transform* arm=new Transform();

    Transform* LowerleftArmrotate2;
    Transform* LowerrightArmrotate2;
    Transform* rotateAroundX;
    int i=0;
    int j=0;
    int k=0;
    int flag=0;
    int m=0;
    int l=0;
    glm::vec3 camera=glm::vec3(0,0,1);

    glm::vec3 center=glm::vec3(0,0,0);

    glm::vec3 up=glm::vec3(0,1,0);
    float rotation;
    Transform* LowerleftArmrotate;
    Transform* LowerrightArmrotate;

    glm::vec3 oldPosition;
    glm::vec3 newPosition;

    float legRotationDirection;
    float leftLegRotationDirection;

    glm::vec3 cameraCenter;
    glm::vec3 observationPont;
    glm::vec3 upVector;

    bool done=true;




    float m_time;
    int rotationAngle;
    int rotationSpeed;
    int rotationAxis;

};

