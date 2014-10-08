#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

//#define Scale 0.09
uniform sampler2D myTextureSampler;

//float GetHeight(vec 2 coords)
//{
  //vec4 t = texture(myTextureSampler,coords);
  //float i = 0.0f;//t.a + t.r + t.g + t.b;
  //return 0.0;
//}

void main(){

	// Output position of the vertex, in clip space : MVP * position
	
	vec4 t = texture(myTextureSampler,vertexUV);
	t.x = vertexPosition_modelspace.x;
	t.z = vertexPosition_modelspace.z;
	//t.y = -t.y + 0.5f;
	t.w = 1.0;
	
	gl_Position =  MVP * t;//vec4(vertexPosition_modelspace,1);
	
	// UV of the vertex. No special space for this one.
	UV = vertexUV;
}