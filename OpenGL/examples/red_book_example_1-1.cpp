#include <iostream>
using namespace std;

//#include "vgl.h"

//#include "glad.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut_ext.h>

#include "LoadShaders.h"

#define BUFFER_OFFSET(a) ((void *)(a)) 

enum VAO_IDs { Triangles, NumVAOs };
enum Buffer_IDs { ArrayBuffer, NumBuffers };

enum Attrib_IDs { vPosition = 0 };

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

void init(void)
{
    printf("NumVAOs = %d\n", NumVAOs);
    glGenVertexArrays(NumVAOs, VAOs);
    glBindVertexArray(VAOs[Triangles]);

    GLfloat vertices[NumVertices][2] = {
        { -0.90, -0.90 },   // Triangle 1
        {  0.85, -0.90 },
        { -0.90,  0.85 },
        {  0.90, -0.85 },   // Triangle 2
        {  0.90,  0.90 },
        { -0.85,  0.90 }
    };


    glGenBuffers(NumBuffers, Buffers);
    glBindBuffer(GL_ARRAY_BUFFER, Buffers[ArrayBuffer]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    ShaderInfo shaders [] = {
        { GL_VERTEX_SHADER, "../shaders/triangles/triangles.vert" },
        { GL_FRAGMENT_SHADER, "../shaders/triangles/triangles.frag" },
        { GL_NONE, NULL }
    };

    GLuint program = LoadShaders(shaders);
    glUseProgram(program);

    glVertexAttribPointer(vPosition, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
    glEnableVertexAttribArray(vPosition);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(VAOs[Triangles]);
    glDrawArrays(GL_TRIANGLES, 0, NumVertices);

    glFlush();
}

int main(int argc, char* argv[])
{
    //gladLoadGL();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutInitWindowSize(512, 512);
    glutInitContextVersion(3, 3);
    glutInitContextProfile(GLUT_CORE_PROFILE);
    glutCreateWindow(argv[0]);

    glewExperimental = GL_TRUE;
    if (glewInit())
    {
        cerr << "Unable to initialze GLEW ... exiting" << endl;
        exit(EXIT_FAILURE);
    }
    
    init();
    
    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

