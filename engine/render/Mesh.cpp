#include <engine/render/Mesh.h>
#include <engine/Camera.h>

void Mesh::updateBuffers() {
	glBindVertexArray(VAO);

	setArrayBuffer(0, 3, m_verBuffer, m_vertices);
	setElementArrayBuffer(m_indexBuffer, m_indices);
	setArrayBuffer(1, 2, m_uvBuffer, m_uv);
	setArrayBuffer(2, 3, m_norBuffer, m_normals);

	glBindVertexArray(GL_FALSE);
}

void Mesh::setArrayBuffer(
	int pos, int size, unsigned int id, std::vector<float> data)
{
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(pos);
	glVertexAttribPointer(pos, size, GL_FLOAT, false, 0, nullptr);
	glBindBuffer(GL_ARRAY_BUFFER, GL_FALSE);
}

void Mesh::setElementArrayBuffer(
	unsigned int id, std::vector<int> data)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_FALSE);
}

Mesh::Mesh(std::vector<float> vertices, 
	std::vector<int> indices,
	std::vector<float> normals,
	std::vector<float> uv)
{

	this->m_shader = new Shader("shaders/mesh.vert", "shaders/mesh.frag");
	this->m_texture = nullptr;

	this->m_vertices = vertices;
    this->m_indices = indices;
	this->m_normals = normals;
	this->m_uv = uv;

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &m_verBuffer);
	glGenBuffers(1, &m_indexBuffer);
	glGenBuffers(1, &m_norBuffer);
	glGenBuffers(1, &m_uvBuffer);

	this->updateBuffers();
}

void Mesh::setTexture(Texture *texture)
{
	this->m_texture = texture;

	m_shader->Bind();
	this->m_texture->import();
	m_shader->Unbind();
}

void Mesh::start() {}

void Mesh::draw() {
	m_shader->Bind();
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);

	if(m_texture != nullptr) m_texture->bind();

	if(Camera::current != nullptr){
		m_shader->setUniform("projMat", Camera::current->projMatGet());
		m_shader->setUniform("viewMat", Camera::current->viewMatGet());
	}
	glUniform3f(m_shader->getULoc("color"), color.x, color.y, color.z);

	transMat = glm::mat4(1.0f);

	transMat = glm::translate(transMat, pos);
	
	transMat = glm::rotate(transMat, glm::radians(rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
	transMat = glm::rotate(transMat, glm::radians(rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
	transMat = glm::rotate(transMat, glm::radians(rot.z), glm::vec3(0.0f, 0.0f, 1.0f));

	transMat = glm::scale(transMat, scale);

	m_shader->setUniform("transMat", transMat);

	glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, nullptr);

	m_shader->Unbind();
	
	glBindVertexArray(GL_FALSE);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_FALSE);

	if(m_texture != nullptr) m_texture->unbind();
}