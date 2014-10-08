#version 330 core

// Input vertex data, different for all executions of this shader.
layout(location = 2) in vec3 vertexPosition_modelspace;
//layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
//out vec2 UV;

// Values that stay constant for the whole mesh.
uniform mat4 MVP;

uniform float posYoffset;

//#define Scale 0.09
//uniform sampler2D myTextureSampler;

//float GetHeight(vec 2 coords)
//{
  //vec4 t = texture(myTextureSampler,coords);
  //float i = 0.0f;//t.a + t.r + t.g + t.b;
  //return 0.0;
//}

void main(){

	// Output position of the vertex, in clip space : MVP * position
	
	//vec4 t = texture(myTextureSampler,vertexUV);
	//t.x = vertexPosition_modelspace.x;
	//t.z = vertexPosition_modelspace.z;
	//t.w = 1.0;
	
	vec3 pos = vertexPosition_modelspace;
	pos.y = pos.y + posYoffset;
	gl_Position =  MVP * vec4(pos,1);
	
	// UV of the vertex. No special space for this one.
	//UV = vertexUV;
}