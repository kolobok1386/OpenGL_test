#ifndef _VERTEX_BUFFER
#define _VERTEX_BUFFER

#include "CommonInc.h"

class AKVertexBuffer
{
public:
	AKVertexBuffer();
	~AKVertexBuffer();

	void bind();
	void bindVertices();
	void bindIndices();
	void init(const GLfloat *vertices, GLuint vertexArrayLength,
		const GLuint *indices, GLuint indexArrayLength, bool isDynamic);
	//void connectProgram();

protected:

	GLuint createVertexBufferObj(GLenum type, GLsizeiptr size, const void *data, bool isDynamic);
	

	inline void bindVertexBuffer(GLuint buffer)
	{
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
	};
	inline void bindIndexBuffer(GLuint buffer)
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
	};
	inline void drawElements(GLenum type, GLsizei count, const void *indices)
	{
		glDrawElements(type, count, GL_UNSIGNED_INT, indices);
	};


protected:
	GLuint m_bufVertexId;
	GLuint m_bufIndexId;
	GLuint m_vertexArrayLength;
	GLuint m_indexArrayLength;

};

#endif