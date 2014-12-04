#include "VertexBuffer.h"

RTTI_DEFINITIONS(AKVertexBuffer)

AKVertexBuffer::AKVertexBuffer()
: m_bufVertexId(0),
m_bufIndexId(0),
m_vertexArrayLength(0),
m_indexArrayLength(0)
{
}

AKVertexBuffer::~AKVertexBuffer()
{
	if(m_bufVertexId)
		glDeleteBuffers(1, &m_bufVertexId);
	if(m_bufIndexId)
		glDeleteBuffers(1, &m_bufVertexId);
}

void AKVertexBuffer::init(const GLfloat *vertices, GLuint vertexArrayLength, const GLuint *indices, GLuint indexArrayLength, bool isDynamic)
{
	if(vertices)
		m_bufVertexId = createVertexBufferObj(GL_ARRAY_BUFFER, sizeof(GLfloat)* vertexArrayLength, vertices, isDynamic);
	else
		m_bufVertexId = 0;

	if(indices)
		m_bufIndexId = createVertexBufferObj(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint)* indexArrayLength, indices, isDynamic);
	else
		m_bufIndexId = 0;
}

GLuint AKVertexBuffer::createVertexBufferObj(GLenum type, GLsizeiptr size, const void *data, bool isDynamic)
{
	GLuint bufferId;
	glGenBuffers(1, &bufferId);
	glBindBuffer(type, bufferId);
	glBufferData(type, size, data, isDynamic ? GL_DYNAMIC_DRAW : GL_STATIC_DRAW);

	return bufferId;
}

void AKVertexBuffer::bind()
{
	bindIndexBuffer(m_bufIndexId);
	bindVertexBuffer(m_bufVertexId);
}

void AKVertexBuffer::bindVertices()
{
	bindVertexBuffer(m_bufVertexId);
}

void AKVertexBuffer::bindIndices()
{
	bindIndexBuffer(m_bufIndexId);
}