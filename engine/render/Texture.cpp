#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

#include <engine/render/Texture.h>

Texture::Texture(std::string texturePath)
{
    int width, height, nrChannels;

    data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 4);

    glGenTextures(1, &id);

    size = glm::ivec2(width, height);
    channels = nrChannels;
}

void Texture::import()
{
    this->bind();
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

    glTexImage2D(GL_TEXTURE_2D,
        0, GL_RGBA,
        size.x, size.y,
        0, GL_RGBA,
        GL_UNSIGNED_BYTE, data);

    this->unbind();

    stbi_image_free(data);
}

void Texture::bind()
{
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, GL_FALSE);
}