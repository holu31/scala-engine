#include <engine/render/Cube.hpp>

Cube::Cube() : Mesh()
{
    this->m_shader = new Shader("shaders/mesh.vert", "shaders/mesh.frag");
	this->m_texture = nullptr;

	this->m_vertices = {
		 -0.5f, 0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
                        
		0.5f, 0.5f, -0.5f,
		0.5f, 0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, -0.5f,
                        
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,
                        
		0.5f, 0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,
                        
		0.5f, 0.5f, 0.5f,
		0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, -0.5f,
		-0.5f, 0.5f, 0.5f,
                            
		0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
	};
	
    this->m_indices = {
		0, 1, 2,
		2, 3, 0,
                
		4, 5, 6,
		6, 7, 4,
                
		8, 9, 10,
		10, 11, 8,
                
		12, 13, 14,
		14, 15, 12,
                    
		16, 17, 18,
		18, 19, 16,
                    
		20, 21, 22,
		22, 23, 20,
	};

	this->m_normals = {
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
		0, 0, 1,
                
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
		1, 0, 0,
                
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
		-1, 0, 0,
                
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
		0, 0, -1,
                
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
		0, 1, 0,
                
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
		0, -1, 0,
	};

	this->m_uv = {
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f,
                
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
                
		1.0f, 1.0f,
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
                    
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
                
		1.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f,
		0.0f, 0.0f,
                    
		1.0f, 0.0f,
		0.0f, 0.0f,
		0.0f, 1.0f,
		1.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &m_verBuffer);
	glGenBuffers(1, &m_indexBuffer);
	glGenBuffers(1, &m_norBuffer);
	glGenBuffers(1, &m_uvBuffer);

	this->updateBuffers();
}