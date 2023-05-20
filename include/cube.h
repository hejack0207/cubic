#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include "shader.h" 

class Cube
{
private:
   std::vector<float> vertices;
   std::vector<uint32_t> indices;
   
   
    uint32_t vaoID;
    uint32_t vboID;
    uint32_t eboID;
public:
   float pos[3];
    


    Cube(float _colors[3][3]);
    ~Cube();

    void setPos(float x, float y, float z);
    void render();
    void clean();
};

Cube::Cube(float colors[3][3]) {
    vertices = {
                // -0.5f, -0.5f, -0.5f, colors[0][0] , colors[0][1], colors[0][2],
                // 0.5f, -0.5f, -0.5f,  colors[0][0] , colors[0][1], colors[0][2],
                // 0.5f,  0.5f, -0.5f,  colors[0][0] , colors[0][1], colors[0][2],
                // 0.5f,  0.5f, -0.5f,  colors[0][0] , colors[0][1], colors[0][2],
                // -0.5f,  0.5f, -0.5f, colors[0][0] , colors[0][1], colors[0][2],
                // -0.5f, -0.5f, -0.5f, colors[0][0] , colors[0][1], colors[0][2],

                -0.5f, -0.5f,  0.5f, colors[0][0] , colors[0][1], colors[0][2],
                0.5f, -0.5f,  0.5f,  colors[0][0] , colors[0][1], colors[0][2],
                0.5f,  0.5f,  0.5f,  colors[0][0] , colors[0][1], colors[0][2],
                0.5f,  0.5f,  0.5f,  colors[0][0] , colors[0][1], colors[0][2],
                -0.5f,  0.5f,  0.5f, colors[0][0] , colors[0][1], colors[0][2],
                -0.5f, -0.5f,  0.5f, colors[0][0] , colors[0][1], colors[0][2],

                -0.5f,  0.5f,  0.5f, colors[1][0] , colors[1][1], colors[1][2],
                -0.5f,  0.5f, -0.5f, colors[1][0] , colors[1][1], colors[1][2],
                -0.5f, -0.5f, -0.5f, colors[1][0] , colors[1][1], colors[1][2],
                -0.5f, -0.5f, -0.5f, colors[1][0] , colors[1][1], colors[1][2],
                -0.5f, -0.5f,  0.5f, colors[1][0] , colors[1][1], colors[1][2],
                -0.5f,  0.5f,  0.5f, colors[1][0] , colors[1][1], colors[1][2],

                // 0.5f,  0.5f,  0.5f, colors[3][0] , colors[3][1], colors[3][2],
                // 0.5f,  0.5f, -0.5f, colors[3][0] , colors[3][1], colors[3][2],
                // 0.5f, -0.5f, -0.5f, colors[3][0] , colors[3][1], colors[3][2],
                // 0.5f, -0.5f, -0.5f, colors[3][0] , colors[3][1], colors[3][2],
                // 0.5f, -0.5f,  0.5f, colors[3][0] , colors[3][1], colors[3][2],
                // 0.5f,  0.5f,  0.5f, colors[3][0] , colors[3][1], colors[3][2],

                // -0.5f, -0.5f, -0.5f,colors[4][0] , colors[4][1], colors[4][2],
                // 0.5f, -0.5f, -0.5f, colors[4][0] , colors[4][1], colors[4][2],
                // 0.5f, -0.5f,  0.5f, colors[4][0] , colors[4][1], colors[4][2],
                // 0.5f, -0.5f,  0.5f, colors[4][0] , colors[4][1], colors[4][2],
                // -0.5f, -0.5f,  0.5f,colors[4][0] , colors[4][1], colors[4][2],
                // -0.5f, -0.5f, -0.5f,colors[4][0] , colors[4][1], colors[4][2],

                -0.5f,  0.5f, -0.5f,colors[2][0] , colors[2][1], colors[2][2],
                0.5f,  0.5f, -0.5f, colors[2][0] , colors[2][1], colors[2][2],
                0.5f,  0.5f,  0.5f, colors[2][0] , colors[2][1], colors[2][2],
                0.5f,  0.5f,  0.5f, colors[2][0] , colors[2][1], colors[2][2],
                -0.5f,  0.5f,  0.5f,colors[2][0] , colors[2][1], colors[2][2],
                -0.5f,  0.5f, -0.5f,colors[2][0] , colors[2][1], colors[2][2],
            };
    indices = {
        0 , 1 , 2 ,
        0 , 2, 3,
    };


    glGenVertexArrays(1,&vaoID);
    glBindVertexArray(vaoID);

    glGenBuffers(1,&vboID);
    glBindBuffer(GL_ARRAY_BUFFER,vboID);
    glBufferData(GL_ARRAY_BUFFER,vertices.size() * sizeof(float),vertices.data(),GL_STATIC_DRAW);

    glGenBuffers(1,&eboID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,eboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indices.size() *  sizeof(uint32_t),indices.data(),GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 * sizeof(float),(void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);


    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
void Cube::setPos(float x, float y, float z) {
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
}


void Cube::render() {
    
    glBindVertexArray(vaoID);
    glDrawArrays(GL_TRIANGLES,0,vertices.size() / 6);
}

void Cube::clean() {
    glBindVertexArray(0);
    glDeleteVertexArrays(1,&vaoID);
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glDeleteBuffers(1,&vboID);
}
Cube::~Cube() {
}


#endif 