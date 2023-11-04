#include <engine/render/Shaders.h>

#include <fstream>
#include <stdexcept>
#include <iostream>

Shader::Shader(const std::string &vertFilepath,
    const std::string &fragFilepath)
{
    vertCode = this->readFile(vertFilepath);
    fragCode = this->readFile(fragFilepath);

    setSource(vShader, vertCode.data());
    setSource(fShader, fragCode.data());
}

std::vector<char> Shader::readFile(const std::string& filepath)
{
    std::ifstream file(filepath, std::ios::ate | std::ios::binary);

    if (!file.is_open()){
        throw fprintf(stderr, "failed to open file: %s", filepath);
    }

    size_t fileSize = static_cast<size_t>(file.tellg());
    std::vector<char> buffer(fileSize+1);

    file.seekg(0);
    file.read(buffer.data(), fileSize);

    file.close();
    buffer[fileSize] = '\0';
    return buffer;
}

void Shader::setSource(int id, const char *source){
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);

    int success;
    char infoLog[512];

    glGetShaderiv(id, GL_COMPILE_STATUS, &success);	
    if (success == GL_FALSE) {
        glGetShaderInfoLog(id, 512, NULL, infoLog);
        throw fprintf(stderr, "failed to compile shader %s %s", std::to_string(id), infoLog);
    }

    glAttachShader(program, id);
    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success == GL_FALSE){
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        throw fprintf(stderr, "failed to link program %s %s", std::to_string(id), infoLog);
    }

    glDeleteShader(id);
}

void Shader::Bind(){
    glUseProgram(program);
}

void Shader::Unbind(){
    glUseProgram(GL_FALSE);
}

void Shader::setUniform(
    std::string uniform, glm::mat4 value
) {
    int matrixLocation = glGetUniformLocation(program, uniform.c_str());
    glUniformMatrix4fv(matrixLocation, 1, GL_FALSE, glm::value_ptr(value));
}

int Shader::getULoc(std::string uname){
    return glGetUniformLocation(program, uname.c_str());
}

void Shader::setUInt(std::string uname, int value){
    glUniform1i(getULoc(uname), value);
}