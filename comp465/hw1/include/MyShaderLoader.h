#ifndef HW2_MYSHADERLOADER_H
#define HW2_MYSHADERLOADER_H

#include <fstream>
#include <exception>
#include <string>
class MyShaderLoader {
   
public:
    MyShaderLoader(const std::string& shaderPath);
    const char * getShaderSource();
private:
    std::ifstream * shaderStream;
    static bool verify();
};

MyShaderLoader::MyShaderLoader(const std::string& shaderPath) {
    shaderStream = new std::ifstream(shaderPath);
    if (shaderStream->fail()) {
        throw std::runtime_error("Shader path: '" + shaderPath + "'invalid!");
    }
    if (!verify()) {
        throw std::runtime_error("Shader failed to compile!");
    } 
}

bool MyShaderLoader::verify() {
    // Eventually I'd like to put a shader validator/parser here, but for now just
    // return true
    return true;
}

/* Read and return shader source */
const char * MyShaderLoader::getShaderSource() {
    
    std::string line, source;
    while (std::getline(*shaderStream, line)) {
        source = source + line + "\n"; 
    }
    char * out = new char[source.size()+1];
    std::copy(source.begin(), source.end(), out);
    out[source.size()] = '\0';
    return out;
}

#endif
