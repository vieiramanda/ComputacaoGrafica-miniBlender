#include "axis.h"

axis::axis(string name, unsigned int idvao, unsigned int idvbo){
    //vertexLines.push_back(glm::vec3());
    nome = name;
    vao = idvao;
    vbo = idvbo;
    setColorAxis();
    setVertexLines();
    setBuffer();    
}

axis::~axis(){
}

void axis::setColorAxis(){
    colorAxis.push_back(glm::vec3(1.0f, 0.0f, 0.0f)); //red x
    colorAxis.push_back(glm::vec3(0.0f, 1.0f, 0.0f)); //green y
    colorAxis.push_back(glm::vec3(0.0f, 0.0f, 1.0f)); //blue z
}

void axis::setVertexLines(){
    //eixo x
    vertexLines.push_back(glm::vec3(-2.0f, 0.0f, 0.0f));
    vertexLines.push_back(glm::vec3(2.0f, 0.0f, 0.0f));
    //eixo y
    vertexLines.push_back(glm::vec3(0.0f, -2.0f, 0.0f));
    vertexLines.push_back(glm::vec3(0.0f, 2.0f, 0.0f));
    //eixo z
    vertexLines.push_back(glm::vec3(0.0f, 0.0f, -2.0f));
    vertexLines.push_back(glm::vec3(0.0f, 0.0f, 2.0f));
}

void axis::setBuffer(){
    int j = 0;
    for (int i = 0; i < vertexLines.size()*2; i++){
        if(i >= 2 && i <= 3){
            j = 1;
        }
        if (i >= 4 && i <= 5){
            j = 2;
        }
        axisBuffer.push_back(vertexLines[i]);
        axisBuffer.push_back(colorAxis[j]);        
    }    
}