#define GLM_ENABLE_EXPERIMENTAL
#include "main.h"
#include "timer.h"
#include "ball.h"
#include "enemy1.h"
#include "platform.h"
#include "wall.h"
#include "wallout.h"
#include "wallout1.h"
#include "coins.h"
#include "jetpack.h"
#include "flying.h"
#include "walldec.h"
#include "ring.h"
#include "wallin.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <GL/glut.h>
#include "line.h"
#include "line1.h"
#include "mag1.h"
#include "mag2.h"
#include "mag3.h"
#include "mag5.h"
#include "mag6.h"
#include "enemy2.h"
#include "rec.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;


/**************************
* Customizable functions *
**************************/
int count=0,score=0,num=0,quo,rem;
float pos=-3,pos1=3;
float good1=0,good2=3,good3=26,good4=0,good5=0,good6=32;
int x=0;
float good=0;
float z=-100;
int tut;
float teju=0.000001;
Ball ball1;
Platform plat;
Wall wal;
Jetpack jet;
Ring rin;
Coins coin[1000];
Flying fly;
Walldec walld[1000];
Wallin in[1000];
Wallout out[1000];
Wallout1 out1[1000];
Enemy1 enemy[100];
Enemy2 enemy1[100];
Line lin[100];
Line1 lin1[100];
Rec rec1[1000];
Rec rec2[1000];
Rec rec3[1000];
Rec rec4[1000];
//Rec rec5[1000];
int life=10,num1=0,num2=0,num3=0;
void fly1();
void fly2();
Mag1 mag1;
Mag2 mag2;
Mag3 mag3;
Mag5 mag5;
Mag6 mag6;
int flag;
bool detect_collision1(Ball ball,Coins coin[]);
bool detect_collision2(Ball ball,Enemy1 enemy2[]);
void enemymov();
void enemymov1();
void movballoon();
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
Timer t60(1.0 / 60);
float arr[1000];
float arr1[1000];
float arr2[1000];
float arr3[1000];
float arr4[1000];
float arr5[1000];
float arr6[1000];
int arr23[1000];
int arr34[1000];
/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    //int teju=0.05;
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    glm::vec3 eye (x, 0, 5);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (x, 0, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane
    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;
    //printf("%f %f",ball1.position.x,ball1.position.y);
    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    //ball1.draw(VP);
    //plat.draw(VP);
    wal.draw(VP);
    for(int i=0;i<100;i++)
    {
        walld[i].draw(VP);
        in[i].draw(VP); 
        out[i].draw(VP);
        out1[i].draw(VP);
    }
    ball1.draw(VP);
    plat.draw(VP);
    jet.draw(VP);
    for(int i=0;i<200;i++)
        coin[i].draw(VP);
    for(int i=0;i<6;i++)
        enemy[i].draw(VP);
    for(int i=0;i<10;i++)
        lin[i].draw(VP);
    for(int i=0;i<5;i++)
        lin1[i].draw(VP);
    mag1.draw(VP);
    mag2.draw(VP);
    mag3.draw(VP);
    mag5.draw(VP);
    mag6.draw(VP);
    if(flag==2)
    {
        enemy[6].draw(VP);
    }
    enemy[7].draw(VP);
    enemy[8].draw(VP);
    enemy[9].draw(VP);
    enemy1[10].draw(VP);
    enemy1[11].draw(VP);
    enemy1[12].draw(VP);
    rec1[0]=Rec(-10+x+8,0+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec1[1]=Rec(-10+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec1[2]=Rec(-10+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec1[3]=Rec(-10+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec1[4]=Rec(-9.2+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec1[5]=Rec(-10+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec1[6]=Rec(-9.2+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec2[0]=Rec(-10+1.5+x+8,0+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec2[1]=Rec(-10+1.5+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec2[2]=Rec(-10+1.5+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec2[3]=Rec(-10+1.5+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec2[4]=Rec(-9.2+1.5+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec2[5]=Rec(-10+1.5+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec2[6]=Rec(-9.2+1.5+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec3[0]=Rec(-10+3+x+8,0+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec3[1]=Rec(-10+3+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec3[2]=Rec(-10+3+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec3[3]=Rec(-10+3+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec3[4]=Rec(-9.2+3+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec3[5]=Rec(-10+3+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec3[6]=Rec(-9.2+3+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec4[0]=Rec(-10+5.5+x+8,0+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec4[1]=Rec(-10+5.5+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec4[2]=Rec(-10+5.5+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,0);
    rec4[3]=Rec(-10+5.5+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec4[4]=Rec(-9.2+5.5+x+8,-0.75+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec4[5]=Rec(-10+5.5+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec4[6]=Rec(-9.2+5.5+x+8,-1.5+3.75,COLOR_DARKRED,0.8,0.2,1.57);
    rec4[3].draw(VP);
    rec4[5].draw(VP);
    int lap = 100;
    tut = score;
    while(lap>=1)
    {
        quo=tut/lap;
        if(lap==100)
        {
          switch(quo)
          {
            case 1:
                rec1[4].draw(VP);
                rec1[6].draw(VP);
                break;
            case 2:
                rec1[0].draw(VP);
                rec1[4].draw(VP);
                rec1[1].draw(VP);
                rec1[5].draw(VP);
                rec1[2].draw(VP);
                break;
            case 3:
                rec1[0].draw(VP);
                rec1[4].draw(VP);
                rec1[1].draw(VP);
                rec1[6].draw(VP);
                rec1[2].draw(VP);
                break;
            case 4:
                rec1[3].draw(VP);
                rec1[4].draw(VP);
                rec1[1].draw(VP);
                rec1[6].draw(VP);
                break;
            case 5:
                rec1[0].draw(VP);
                rec1[3].draw(VP);
                rec1[1].draw(VP);
                rec1[6].draw(VP);
                rec1[2].draw(VP);
                break;
            case 6:
                rec1[0].draw(VP);
                rec1[3].draw(VP);
                rec1[1].draw(VP);
                rec1[5].draw(VP);
                rec1[6].draw(VP);
                rec1[2].draw(VP);
                break;
            case 7:
                rec1[0].draw(VP);
                rec1[4].draw(VP);
                rec1[6].draw(VP);
                break;
            case 8:
                rec1[0].draw(VP);
                rec1[1].draw(VP);
                rec1[2].draw(VP);
                rec1[3].draw(VP);
                rec1[4].draw(VP);
                rec1[5].draw(VP);
                rec1[6].draw(VP);
                break;
            case 9:
                rec1[0].draw(VP);
                rec1[1].draw(VP);
                rec1[2].draw(VP);
                rec1[3].draw(VP);
                rec1[4].draw(VP);
                rec1[6].draw(VP);
                break;
            case 0:
                rec1[0].draw(VP);
                rec1[2].draw(VP);
                rec1[3].draw(VP);
                rec1[4].draw(VP);
                rec1[5].draw(VP);
                rec1[6].draw(VP);
                break;
            default:
                break;      
        }
    }
    if(lap==10)
    {
       switch(quo)
          {
            case 1:
                rec2[4].draw(VP);
                rec2[6].draw(VP);
                break;
            case 2:
                rec2[0].draw(VP);
                rec2[4].draw(VP);
                rec2[1].draw(VP);
                rec2[5].draw(VP);
                rec2[2].draw(VP);
                break;
            case 3:
                rec2[0].draw(VP);
                rec2[4].draw(VP);
                rec2[1].draw(VP);
                rec2[6].draw(VP);
                rec2[2].draw(VP);
                break;
            case 4:
                rec2[3].draw(VP);
                rec2[4].draw(VP);
                rec2[1].draw(VP);
                rec2[6].draw(VP);
                break;
            case 5:
                rec2[0].draw(VP);
                rec2[3].draw(VP);
                rec2[1].draw(VP);
                rec2[6].draw(VP);
                rec2[2].draw(VP);
                break;
            case 6:
                rec2[0].draw(VP);
                rec2[3].draw(VP);
                rec2[1].draw(VP);
                rec2[5].draw(VP);
                rec2[6].draw(VP);
                rec2[2].draw(VP);
                break;
            case 7:
                rec2[0].draw(VP);
                rec2[4].draw(VP);
                rec2[6].draw(VP);
                break;
            case 8:
                rec2[0].draw(VP);
                rec2[1].draw(VP);
                rec2[2].draw(VP);
                rec2[3].draw(VP);
                rec2[4].draw(VP);
                rec2[5].draw(VP);
                rec2[6].draw(VP);
                break;
            case 9:
                rec2[0].draw(VP);
                rec2[1].draw(VP);
                rec2[2].draw(VP);
                rec2[3].draw(VP);
                rec2[4].draw(VP);
                rec2[6].draw(VP);
                break;
            case 0:
                rec2[0].draw(VP);
                rec2[2].draw(VP);
                rec2[3].draw(VP);
                rec2[4].draw(VP);
                rec2[5].draw(VP);
                rec2[6].draw(VP);
                break;
            default:
                break;      
        } 
    }
    if(lap==1)
    {
        switch(quo)
          {
            case 1:
                rec3[4].draw(VP);
                rec3[6].draw(VP);
                break;
            case 2:
                rec3[0].draw(VP);
                rec3[4].draw(VP);
                rec3[1].draw(VP);
                rec3[5].draw(VP);
                rec3[2].draw(VP);
                break;
            case 3:
                rec3[0].draw(VP);
                rec3[4].draw(VP);
                rec3[1].draw(VP);
                rec3[6].draw(VP);
                rec3[2].draw(VP);
                break;
            case 4:
                rec3[3].draw(VP);
                rec3[4].draw(VP);
                rec3[1].draw(VP);
                rec3[6].draw(VP);
                break;
            case 5:
                rec3[0].draw(VP);
                rec3[3].draw(VP);
                rec3[1].draw(VP);
                rec3[6].draw(VP);
                rec3[2].draw(VP);
                break;
            case 6:
                rec3[0].draw(VP);
                rec3[3].draw(VP);
                rec3[1].draw(VP);
                rec3[5].draw(VP);
                rec3[6].draw(VP);
                rec3[2].draw(VP);
                break;
            case 7:
                rec3[0].draw(VP);
                rec3[4].draw(VP);
                rec3[6].draw(VP);
                break;
            case 8:
                rec3[0].draw(VP);
                rec3[1].draw(VP);
                rec3[2].draw(VP);
                rec3[3].draw(VP);
                rec3[4].draw(VP);
                rec3[5].draw(VP);
                rec3[6].draw(VP);
                break;
            case 9:
                rec3[0].draw(VP);
                rec3[1].draw(VP);
                rec3[2].draw(VP);
                rec3[3].draw(VP);
                rec3[4].draw(VP);
                rec3[6].draw(VP);
                break;
            case 0:
                rec3[0].draw(VP);
                rec3[2].draw(VP);
                rec3[3].draw(VP);
                rec3[4].draw(VP);
                rec3[5].draw(VP);
                rec3[6].draw(VP);
                break;
            default:
                break;      
        }
    }
        tut = tut%lap;
        lap = lap/10;
    }   
}

void tick_input(GLFWwindow *window) {
    //int teju=0.05;
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up    = glfwGetKey(window,GLFW_KEY_SPACE);
    int down  = glfwGetKey(window,GLFW_KEY_A);
   if (left==GLFW_PRESS) {
       ball1.position.x=(ball1.position.x)-0.02; 
       jet.position.x=(jet.position.x)-0.02;
    }
    if(right==GLFW_PRESS) {
        ball1.position.x=(ball1.position.x)+0.02;
        jet.position.x=(jet.position.x)+0.02;
    }
    else if (up==GLFW_PRESS) {
       if(ball1.position.y<3.59)
       {
          ball1.position.y=(ball1.position.y)+0.02;
          jet.position.y=(jet.position.y)+0.02;
       }
       if(ball1.position.y==3.59)
       {
          ball1.position.y=3.59;
          jet.position.y=3.59;      
       }
    }
    if(down==GLFW_PRESS)
    {
        flag=2;
        enemy[6]=Enemy1(ball1.position.x,ball1.position.y-0.02,COLOR_PINK);
        //enemy[6].position.y=(enemy[6].position.y)-0.02;
    }
    if(up!=GLFW_PRESS)
    {
        if((ball1.position.y)>-3.0125)
        {
          ball1.position.y=(ball1.position.y)-0.05;
          jet.position.y=(jet.position.y)-0.05;
        }
        if(ball1.position.y==-3.0125)
        {
          ball1.position.y=-3.0125;
          jet.position.y=-3.0125;
        }
        if(ball1.position.x>=12.75 && ball1.position.x<=16.75 && ball1.position.y >=-0.75 && ball1.position.y <=0.75)
        {
            ball1.position.x=(ball1.position.x)-teju;
            jet.position.x=(jet.position.x)-teju;
            teju=teju+0.0002;
        }
    }
    if(ball1.position.x>=12.75 && ball1.position.x<=16.75 && ball1.position.y >=-0.75 && ball1.position.y <=0.75)
    {
            ball1.position.x=(ball1.position.x)-teju;
            jet.position.x=(jet.position.x)-teju;
            teju=teju+0.0002;
    }
    if(down!=GLFW_PRESS)
    {
        enemy[6].position.y=enemy[6].position.y-0.03;
        if(enemy[6].position.x>=4 && enemy[6].position.x<=6 && enemy[6].position.y>=0 && enemy[6].position.y<=0.75)
        {
            for(int sus=0;sus<5;sus++)
            {
                lin[sus].position.x=-500;
                lin[sus].position.y=-500;
            }
        }
        if(enemy[6].position.x>=15 && enemy[6].position.x<=17 && enemy[6].position.y>=0 && enemy[6].position.y<=0.85)
        {
            for(int sus=5;sus<10;sus++)
            {
                lin[sus].position.x=-500;
                lin[sus].position.y=-500;
            }
        }
        if(enemy[6].position.x>=enemy[4].position.x && enemy[6].position.x<=enemy[5].position.x && enemy[6].position.y<=lin1[1].position.y && enemy[6].position.y>=lin1[2].position.y)
        {
            for(int sus=0;sus<5;sus++)
            {
                lin1[sus].position.x=-500;
                lin1[sus].position.y=-500;
            }
        }
    }
}

void tick_elements() {
   	 //ball1.tick();
     x=ball1.position.x;
     camera_rotation_angle += 1;
}
/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    ball1       = Ball(-3, -3, COLOR_RED);
    plat        = Platform(0,0,COLOR_GREEN);
    wal         = Wall(0,0,COLOR_BLACK);
    jet         = Jetpack(-3,-3,COLOR_BROWN);
    for(int t=0;t<100;t++)
    {
        walld[t]       =Walldec(z,0,COLOR_DARKWHITE);
        in[t]          =Wallin(z,0,COLOR_DARKGREEN);
        out[t]         =Wallout(z+4.5,0,COLOR_DARKWHITE);
        out1[t]        =Wallout1(z+4.5,0,COLOR_DARKGREEN);
        z=z+9.0;
    }
    int max=100;
    int min=-100;
    int max1=2;
    int min1=0;
    int j,i;
    for(i=0;i<300;i++)
    {
        int randNumx = rand()%(max-min + 1) + min;
        int randNumy = rand()%(max1-min1+1)+min1;
        if(i<25)
            coin[i]=Coins(randNumx,randNumy,COLOR_PINK);
        if(i>=25 && i<50)
        {
            coin[i]=Coins(randNumx,randNumy,COLOR_DARKBLUE);
        }
        if(i>=50 && i<75)
        {
            coin[i]=Coins(randNumx,randNumy,COLOR_BROWN);
        }
        if(i>=75 && i<200)
        {
            coin[i]=Coins(randNumx,randNumy,COLOR_RED);
        }
        if(i>=1)
        {
            for(j=i-1;j>=0;j--)
            {
                if((coin[j].position.x==coin[i].position.x)&&(coin[j].position.y==coin[j].position.y))
                {
                    coin[i].position.x=-500;
                    coin[i].position.y=-500;
                    break;
                }
            }
        }  
    }
    enemy[0]=Enemy1(4,0,COLOR_DARKRED);
    enemy[1]=Enemy1(6,2,COLOR_DARKRED);
    enemy[2]=Enemy1(15,0,COLOR_DARKRED);
    enemy[3]=Enemy1(17,2,COLOR_DARKRED);
    enemy[4]=Enemy1(20,0,COLOR_DARKRED);
    enemy[5]=Enemy1(22,0,COLOR_DARKRED);
    enemy[7]=Enemy1(3,0,COLOR_VIOLET);
    enemy[8]=Enemy1(26,0,COLOR_VIOLET);
    enemy[9]=Enemy1(32,0,COLOR_VIOLET);
    enemy1[10]=Enemy2(3,0,COLOR_BACKGROUND);
    enemy1[11]=Enemy2(26,0,COLOR_BACKGROUND);
    enemy1[12]=Enemy2(32,0,COLOR_BACKGROUND);
    lin[0]=Line(0,0,COLOR_DARKRED);
    lin[5]=Line(11,0,COLOR_DARKRED);
    lin[1]=Line(0,0.2,COLOR_DARKRED);
    lin[2]=Line(0,-0.2,COLOR_DARKRED);
    lin[6]=Line(11,0.2,COLOR_DARKRED);
    lin[7]=Line(11,-0.2,COLOR_DARKRED);
    lin[3]=Line(0,0.1,COLOR_DARKRED);
    lin[4]=Line(0,-0.1,COLOR_DARKRED);
    lin[8]=Line(11,0.1,COLOR_DARKRED);
    lin[9]=Line(11,-0.1,COLOR_DARKRED);
    lin1[0]=Line1(16,0,COLOR_DARKRED);
    lin1[1]=Line1(16,0.2,COLOR_DARKRED);
    lin1[2]=Line1(16,-0.2,COLOR_DARKRED);
    lin1[3]=Line1(16,0.1,COLOR_DARKRED);
    lin1[4]=Line1(16,-0.1,COLOR_DARKRED);
    mag1=Mag1(10,0,COLOR_DARKRED);
    mag2=Mag2(10,0,COLOR_DARKRED);
    mag3=Mag3(10,0,COLOR_DARKRED);
    mag5=Mag5(10,0,COLOR_GREY);
    mag6=Mag6(10,0,COLOR_GREY);
    
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a hint randNumx = rand()%(max-min + 1) + min;
       //int randNumy = rand()%(max-min+1)+min;//andle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");

    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) 
{
    srand(time(0));
    int width  = 1000;
    int height = 1000;
    int set=0;
    int set1=0;

    window = initGLFW(width, height);

    initGL (window, width, height);
    for(set=0;set<150;set++)
    {
        arr[set]=good;
        good+=0.02;
    }
    for(set=0;set<300;set++)
    {
        arr1[set]=good1;
        if(set<150)
            good1=good1+0.02;
        if(set>150)
            good1=good1-0.02;
    }
    for(set=0;set<300;set++)
    {
        arr2[set]=good2;
        good2=good2+0.01;
    }
    for(set=0;set<300;set++)
    {
        arr3[set]=good4;
        if(set<150)
            good4=good4+0.02;
        if(set>150)
            good4=good4-0.02;
    }
    for(set=0;set<300;set++)
    {
        arr4[set]=good3;
        good3=good3+0.01;
    }
    for(set=0;set<300;set++)
    {
        arr5[set]=good5;
        if(set<150)
            good5=good5+0.02;
        if(set>150)
            good5=good5-0.02;
    }
    for(set=0;set<300;set++)
    {
        arr6[set]=good6;
        good6=good6+0.01;
    }
    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) 
    {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            //detect_collision1(ball1,coin);
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);
            tick_elements();
            tick_input(window);
            fly1();
            enemymov();
            detect_collision1(ball1,coin);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }
    quit(window);
}
bool detect_collision(bounding_box_t a, bounding_box_t b) 
{
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}
bool detect_collision1(Ball ball,Coins coin[])
{
     for(int i=0;i<200;i++)
     {
        if((abs(ball.position.x-coin[i].position.x)*2<0.9)&&(abs(ball.position.y-coin[i].position.y)*2)<0.9 )
        {
           coin[i].position.x=-500;
           coin[i].position.y=-500;
           score=score+10;
           printf("%d\n",score);
           for(int wet=0;wet<4;wet++)
              arr23[wet]=score+40;
           arr34[0]=score-5;
        }
    }
    for(int i=7;i<10;i++)
    {
        if((abs(ball.position.x-enemy[i].position.x)*2<1)&&(abs(ball.position.y-enemy[i].position.y)*2)<1)
        {
            score=arr23[i-7];
        }
    }
    if(ball1.position.x>=4 && ball1.position.x <=6 && ball1.position.y>=0 && ball1.position.y<=0.75 && lin[0].position.x!=-500)
    {
        if(score<=0)
            score=0;
        else
            score=arr34[0];
    }
    if(ball1.position.x>=15 && ball1.position.x<=17 && ball1.position.y>=0 && ball1.position.y<=0.85 && lin[5].position.x!=-500)
    {
        if(score<=0)
            score=0;
        else
            score=arr34[0];
    }
    if(ball1.position.x>=enemy[4].position.x && ball1.position.x<=enemy[5].position.x && ball1.position.y>=lin1[1].position.y&& ball1.position.y<=lin1[2].position.y&&lin1[0].position.x!=-500)
    {
        if(score<=0)
            score=0;
        else
            score=arr34[0];
    }
}
void reset_screen() 
{
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
void enemymov()
{
    num++;
    if(num>150)
        num=0;
    enemy[4].position.y=arr[num];
    enemy[5].position.y=arr[num];
    lin1[0].position.y=arr[num];
    lin1[1].position.y=arr[num]+0.2;
    lin1[2].position.y=arr[num]-0.2;
    lin1[3].position.y=arr[num]+0.1;
    lin1[4].position.y=arr[num]-0.1;
}
void fly1()
{
    num1++;
    num2++;
    if(num1>300)
        num1=0;
    enemy[7].position.y=arr1[num1];
    if(num2>300)
        num2=0;
    enemy[7].position.x=arr2[num2];
    enemy[8].position.y=arr3[num1];
    enemy[8].position.x=arr4[num1];
    enemy[9].position.y=arr5[num1];
    enemy[9].position.x=arr6[num1];
    enemy1[10].position.x=arr2[num1];
    enemy1[10].position.y=arr1[num1];
    enemy1[11].position.x=arr4[num1];
    enemy1[11].position.y=arr3[num1];
    enemy1[12].position.x=arr6[num1];
    enemy1[12].position.y=arr5[num1];
}
