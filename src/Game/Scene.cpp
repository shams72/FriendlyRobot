#include "Scene.h"
#include <AssetManager.h>

Scene::Scene(OpenGLWindow * window) :
        m_window(window)
{
    assert(window != nullptr);

    legRotationDirection=0.75f;
    leftLegRotationDirection=0.75f;
}

Scene::~Scene()
{


   // left_arm2->rotate(glm::vec3 (0.02,0.0,0));

}

bool Scene::init()
{
    try
    {
        //Load shader
        m_assets.addShaderProgram("shader", AssetManager::createShaderProgram("assets/shaders/vertex.glsl", "assets/shaders/fragment.glsl"));
        m_shader = m_assets.getShaderProgram("shader");
        m_shader->use();

        /*float vertices[] = {-0.5, -0.5, 0.0, 0.0, 1.0,
                            0.5, -0.5, 0.0, 0.0, 1.0,
                            0.5, 0.5, 0.0, 1.0, 0.0,
                            0.0, 1.0, 1.0, 0.0, 0.0,
                            -0.5, 0.5, 0.0, 1.0, 0.0};

        int indices[] = {0, 1, 2,
                         0, 2, 4,
                         4, 2, 3};


        float vertices[] = {
                -1, 1, 0.0, 0.0, 1.0,
                -0.5, 1, 0.0, 0.0, 1.0,
                -1, -1, 0.0, 1.0, 0.0,
                -0.5, -1, 1.0, 0.0, 0.0,


                0, 0, 0.0, 1.0, 0.0,
                0.5, 0.5, 0.0, 1.0, 0.0,
                0, 1, 0.0, 1.0, 0.0,

                0, -1, 0.0, 1.0, 0.0,
                0.5, -0.5, 0.0, 1.0, 0.0,


        };

        int indices[] = {0, 2, 1,
                         1, 2,3,

                         4,5,6,
                         4,7,8


        };*/


        static const float cubeVert[] =  {0.5, -0.5, -0.5, 1, 0, 0,
                                          0.5, -0.5, 0.5, 0, 1, 0,
                                          -0.5, -0.5, 0.5, 0, 0, 1,
                                          -0.5, -0.5, -0.5, 1, 1, 0,
                                          0.5, 0.5, -0.5, 1, 0, 1,
                                          0.5, 0.5, 0.5, 0, 1, 1,
                                          -0.5, 0.5, 0.5, 1, 1, 1,
                                          -0.5, 0.5, -0.5, 0.5, 1, 0.5};

        static const int cubeInd[] = {1, 2, 3,
                                      7, 6, 5,
                                      4, 5, 1,
                                      5, 6, 2,
                                      2, 6, 7,
                                      0, 3, 7,
                                      0, 1, 3,
                                      4, 7, 5,
                                      0, 4, 1,
                                      1, 5, 2,
                                      3, 2, 7,
                                      4, 0, 7};

        //t1=Transform();


        //create and fill vbo with vertex data


        glGenBuffers(1, &vboID);
        glBindBuffer(GL_ARRAY_BUFFER, vboID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVert), &cubeVert, GL_STATIC_DRAW);

        glGenVertexArrays(1, &vaoID);
        glBindVertexArray(vaoID);

        //define and activate color and vertrex attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, false, 6 * sizeof(float), (void*)(3*sizeof (float)));
        glEnableVertexAttribArray(1);

        //ibo
        GLuint iboID;
        glGenBuffers(1, &iboID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(cubeInd), &cubeInd, GL_STATIC_DRAW);

        t1bodypart=new Transform();
        t1bodypart->scale(glm::vec3(1,1,0.15));
        t1bodypart->translate(glm::vec3(0,0.00,0));

        rotateAroundX=new Transform();


        head=new Transform();
        head->scale(glm::vec3 (0.22,0.22,0.22));
        head->translate(glm::vec3 (0.0,0.7,0.0));

        body=new Transform();
        body->scale(glm::vec3 (0.55,0.75,1.75));
        body->translate(glm::vec3 (0.0,0.15,0));

        right_arm1= new Transform();
        right_arm1->scale(glm::vec3 (0.15,0.35,0.15));
        right_arm1->translate(glm::vec3(0.37,0.35,0));

        right_arm2=new Transform();
        right_arm2->scale(glm::vec3 (0.15,0.35,0.15));
        right_arm2->translate(glm::vec3(0.37,-0.06,0));


        left_arm1=new Transform();
        left_arm1->scale(glm::vec3 (0.15,0.35,0.15));
        left_arm1->translate(glm::vec3(-0.37,0.35,0));

        left_arm2=new Transform();
        left_arm2->scale(glm::vec3 (0.15,0.35,0.15));
        left_arm2->translate(glm::vec3(-0.37,-0.06,0));

        left_leg = new Transform();
        left_leg->scale(glm::vec3 (0.10,0.55,0.25));
        left_leg->translate(glm::vec3(-0.22,-0.53,0.0));

        right_leg = new Transform();
        right_leg->scale(glm::vec3 (0.10,0.55,0.25));
        right_leg->translate(glm::vec3(0.22,-0.53,0.0));

        rightlegRotate=new Transform();
        rotation=0;

        leftlegRotate=new Transform();

        rightArmrotate=new Transform();
        leftArmrotate=new Transform();

        LowerleftArmrotate=new Transform();
        LowerrightArmrotate=new Transform();


        LowerleftArmrotate2=new Transform();
        LowerrightArmrotate2=new Transform();

        //t1bodypart->rotate(glm::vec3 (0,-90,0));


      //  gluLookAt(0,0,-1,0,0,0,0,0,1);


        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);
        glDepthFunc(GL_LESS);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_GREATER);
        glClearDepth(0.0);


        //unbinding
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);







        std::cout << "Scene initialization done\n";
        return true;
    }
    catch (std::exception& ex)
    {
        throw std::logic_error("Scene initialization failed:\n" + std::string(ex.what()) + "\n");
    }
}
void Scene::render(float dt)
{


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    m_shader->use();
    static Transform transHead ;
    transHead.rotateAroundPoint(head->getPosition(),glm::vec3 (0.05,0.05,0));

    static Transform transCompleteScene ;
    transHead.rotateAroundPoint(body->getPosition(),glm::vec3 (0.0,0.05,0));





    glm::mat4 look_at = glm::lookAt(camera,center,up);
    m_shader->setUniform("view",look_at,false);

    glm::mat4 projection = glm::perspective(glm::radians(90.0f), 1.0f, 1.0f, 20.0f);
    m_shader->setUniform("projection", projection,false);

    //t1bodypart->rotate(glm::vec3(0,0.05,0));




   //t1bodypart->rotateAroundPoint(glm::vec3 (0,1,0),glm::vec3 (0,0.02,0.0));
   // LowerrightArmrotate->rotateAroundPoint(t1bodypart->getPosition(),glm::vec3 (0,0.02,0.0));


    if(leftlegRotate->getRotation().x >= 0.15){
        i++;
        rightlegRotate->rotateAroundPoint(right_leg->getPosition(), glm::vec3 (legRotationDirection,0,0));
        leftlegRotate->rotateAroundPoint(left_leg->getPosition(), glm::vec3 (-leftLegRotationDirection,0,0));

    }else if(leftlegRotate->getRotation().x <= 0.15){
        j++;
        rightlegRotate->rotateAroundPoint(right_leg->getPosition(), glm::vec3 (-legRotationDirection,0,0)*0.02f);
        leftlegRotate->rotateAroundPoint(left_leg->getPosition(), glm::vec3 (leftLegRotationDirection,0,0)*0.02f);
    }

    if(rightArmrotate->getRotation().x > 0.15){
        rightArmrotate->rotateAroundPoint(right_arm1->getPosition(),glm::vec3(-legRotationDirection,0,0));
        leftArmrotate->rotateAroundPoint(left_arm1->getPosition(),glm::vec3(legRotationDirection,0,0));
    }else if(rightArmrotate->getRotation().x < 0.15){
        rightArmrotate->rotateAroundPoint(right_arm1->getPosition(),glm::vec3(legRotationDirection,0,0)*0.02f);
        leftArmrotate->rotateAroundPoint(left_arm1->getPosition(),glm::vec3(-legRotationDirection,0,0)*0.02f);
    }

    if(LowerrightArmrotate2->getRotation().x > 0.15){
        LowerrightArmrotate2->rotateAroundPoint(right_arm2->getPosition(),glm::vec3(-legRotationDirection,0,0));
        LowerleftArmrotate2->rotateAroundPoint(left_arm2->getPosition(),glm::vec3(legRotationDirection,0,0));

    }else if(LowerrightArmrotate2->getRotation().x < 0.15){
        LowerrightArmrotate2->rotateAroundPoint(right_arm2->getPosition(),glm::vec3(legRotationDirection,0,0)*0.02f);
        LowerleftArmrotate2->rotateAroundPoint(left_arm2->getPosition(),glm::vec3(-legRotationDirection,0,0)*0.02f);
    }


    glm::mat4 actual_body = t1bodypart->getMatrix() * body->getMatrix();
    glm::mat4 actual_head = t1bodypart->getMatrix() * head->getMatrix();




    glBindVertexArray(vaoID);

    static Transform headRotate;
    headRotate.rotateAroundPoint(head->getPosition(),glm::vec3(0.05,0.05,0));

  //  t1bodypart->rotateAroundPoint(body->getPosition(),glm::vec3(0.0,0.03,0));





    static int i ;
    int sign=glm::sin(glfwGetTime()*7)>0?-1:1 ;
    //i++;

    m_shader->setUniform("modelMatrix",  head->getMatrix(), false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    m_shader->setUniform("modelMatrix", actual_body,false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    rightArmrotate->getTransformMatrix();



    static Transform rightUppertransform;
    rightUppertransform.rotateAroundPoint(glm::vec3 (right_arm1->getPosition().x,right_arm1->getPosition().y,right_arm1->getPosition().z),glm::vec3 (0.0295*-sign,0,0));

    static Transform rightlowertransform;
    rightlowertransform.rotateAroundPoint(glm::vec3 (right_arm2->getPosition().x,right_arm2->getPosition().y,right_arm2->getPosition().z),glm::vec3 (0.02295*sign,0,0));

    static Transform leftUppertransform;
    leftUppertransform.rotateAroundPoint(glm::vec3 (left_arm1->getPosition().x,left_arm1->getPosition().y,left_arm1->getPosition().z),glm::vec3 (0.0295*sign,0,0));

    static Transform lefttlowertransform;
    lefttlowertransform.rotateAroundPoint(glm::vec3 (left_arm2->getPosition().x,left_arm2->getPosition().y,left_arm2->getPosition().z),glm::vec3 (0.02295*-sign,0,0));



    //t1bodypart->rotate(glm::vec3(0.0f,0.05f,0.0f));


    m_shader->setUniform("modelMatrix",  (t1bodypart->getMatrix()*rightUppertransform.getMatrix()*right_arm1->getMatrix()), false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    m_shader->setUniform("modelMatrix",  (t1bodypart->getMatrix()*rightUppertransform.getMatrix()*rightlowertransform.getInverseMatrix()*right_arm2->getMatrix()), false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    m_shader->setUniform("modelMatrix", ( t1bodypart->getMatrix() * leftUppertransform.getMatrix()*left_arm1->getMatrix()), false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    m_shader->setUniform("modelMatrix", (t1bodypart->getMatrix() *leftUppertransform.getMatrix()*lefttlowertransform.getInverseMatrix()*left_arm2->getMatrix()), false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);


    static Transform legTransform;
    legTransform.rotateAroundPoint(left_leg->getPosition(),glm::vec3 (0.015*sign,0,0));

    static Transform rightlegTransform;
    rightlegTransform.rotateAroundPoint(right_leg->getPosition(),glm::vec3 (0.015*-sign,0,0));


    m_shader->setUniform("modelMatrix", (t1bodypart->getMatrix()*legTransform.getMatrix()*left_leg->getMatrix()), false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    m_shader->setUniform("modelMatrix",( t1bodypart->getMatrix() *rightlegTransform.getMatrix()*right_leg->getMatrix())*0.02f, false);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

    rotation+=0.1;

    float colorX = (cos(rotation ) + 2)* 0.5;
    float colorY = (sin(rotation) + 2)* 0.5;
    float colorZ = (cos(rotation) + 2) *0.5;

    m_shader->setUniform("colorx", colorX);
    m_shader->setUniform("colory", colorY);
    m_shader->setUniform("colorz", colorZ);










    glBindVertexArray(0);




}

void Scene::update(float dt)
{


}

OpenGLWindow * Scene::getWindow()
{
    return m_window;
}

void Scene::onKey(Key key, Action action, Modifier modifier)
{

    switch(key){
        case Key::R:{
            if(flag==0){
                up.x=0;
                up.y=1;
                flag=1;
                break;

            }else if(flag==1){
                up.y=0;
                up.x=1;
                flag=2;
                break;
            }
            else if(flag==2){
                up.x=0;
                up.y=-1;
                flag=3;
                break;
            }
            else if(flag==3){
                up.y=0;
                up.x=-1;
                flag=0;
            }break;


        }

        case Key::F:{
            camera.z+=0.1;
        }
        break;
        case Key::N:{
            camera.z-=0.1;
        }
        break;
        case Key::D:{

            if(done==true){
                camera.x=1;
                camera.z=0;
                done=false;
            }

           // camera.z +=0.1;
            //camera.x+=1;
            center.z+=0.1;


        }break;


        case Key::A:{

            if(done==true) {
                camera.x = -1;
                camera.z = 0;
                done=false;
            }
            //camera.z -=0.1;
            //camera.x-=1;
            center.z-=0.1;
            break;

        }
        case Key::W:{
            camera.z-=0.1;
            //center.y+=0.1;


        }break;
        case Key::S:{
            camera.z+=0.1;
            //center.y-=0.1;
            break;

        }

    }


}

void Scene::onMouseMove(MousePosition mouseposition)
{

}

void Scene::onMouseButton(MouseButton button, Action action, Modifier modifier)
{

}

void Scene::onMouseScroll(double xscroll, double yscroll)
{

}

void Scene::onFrameBufferResize(int width, int height)
{

}
void Scene::shutdown()
{

}
