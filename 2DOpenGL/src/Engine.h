#pragma once
#include "glad/glad.h"

#include <iostream>
#include <string>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


const int SPEED = 12;

class Engine
{
private:
	unsigned int VAO;
	unsigned int VBO;

	unsigned int image;


public:

	unsigned int boardShader;

	glm::vec3 bgColor = glm::vec3(0.2f, 0.2f, 0.2f);


public:
	Engine();
	~Engine();

	void Clear();
	void Draw();


private:
	void DrawThing(unsigned int texture, glm::mat4 model, float angle = 0.0f, glm::vec3 scale = glm::vec3(1.0f));

public:
	void SetUniform1i(unsigned int shader, const std::string& name, int value);
	void SetUniform2v(unsigned int shader, const std::string& name, glm::vec2& value);
	void SetUniform2v(unsigned int shader, const std::string& name, float x, float y);
	void SetUniform3v(unsigned int shader, const std::string& name, glm::vec3& value);
	void SetUniform3v(unsigned int shader, const std::string& name, float x, float y, float z);
	void SetUniformMat4(unsigned int shader, const std::string& name, const glm::mat4& matrix);

private:
	void CreateVAO();
	void CreateBoardVBO();

	void Texture(const char* path, unsigned int& texture);
	void BindTexture(unsigned int texture, unsigned int slot);


	unsigned int CreateShader(const char* vertexPath, const char* fragmentPath);

	void CheckCompileErrors(unsigned int shader, std::string type);

};