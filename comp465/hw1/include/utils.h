#ifndef HW2_UTILS_H
#define HW2_UTILS_H
#include <glad/glad.h>
#include <glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

struct RenderContext {
    GLFWwindow * window;
    int shaderProgram;
    unsigned int * VAO;
    unsigned int * VBO;
    float * vertices;

    int window_width;
    int window_height;

    unsigned int texture1;
    unsigned int texture2;
};


/* GL Required */
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

/* Helpers for code cleanup/organization */
GLFWwindow *myGLCreateWindow(RenderContext *rc, int width, int height, const char *title);
void myGLHandleWindowError();
bool myGLLoadContextAndFuncPointers(GLFWwindow * window);
int myGLLoadCompileAndLinkShaders(const char * vertexShaderPath, const char * fragmentShaderPath);
void myGLBindVertexBufferAndArray(unsigned int * VBO, unsigned int * VAO, float vertices[]);
void myGLDeallocateAndTerminate(RenderContext * rc);

enum UniformType {
    Bool, Int, Float, Vec2, Vec3, Vec4, Mat2, Mat3, Mat4
};
void setUniformBool( int, const char *, bool);
void setUniformInt( int, const char *, int);
void setUniformFloat( int, const char *, float);
void setUniformVec2( int, const char *, float , float);
void setUniformVec3( int, const char *, float , float, float);
void setUniformVec4( int, const char *, float , float, float, float);
void setUniformMat2( int, const char *, glm::mat2&);
void setUniformMat3( int, const char *, glm::mat3&);
void setUniformMat4( int, const char *, glm::mat4&);

#endif //HW2_UTILS_H
