// shader is just a program that runs on the GPU
// GLFW - CROSS PLATFORM
// GLFW - opens a window easily
// GLFW - render context
// GLFW - takes input
// GLFW - allows us to use raw OpenGL code


#include <GL/glew.h> // this MUST be included before glfw3.h
#include <GLFW/glfw3.h>

#include <iostream>


//void updateRowPlacement(float arr[], const int arrTotal)
//{
//	std::cout << "arr[i] = " << arr[1] << std::endl;
//
//	for (int i = 1; i < 60; i += 2)
//	{
//		arr[i] = arr[i] + 0.01f;
//	}
//}



int main(void)
{

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit()) {
		return -1;
	}

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "OpenGL Rocks", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// GLEW MUST be INITIALIZED after valid GL context is defeind... aka "glfwMakeContextCurrent(window)"
	if (glewInit() != GLEW_OK) {
		std::cout << "GLEW didn't init properly" << std::endl;
	}
	else {
		std::cout << "GLEW initialized!" << std::endl;
		std::cout << "OpenGL Version = " << glGetString(GL_VERSION) << std::endl;
	}

	float positions[6] = {
		-0.5f, -0.5f,
		 0.0f, 0.5f,
		 0.5f, -0.5f
	};


	// test ////////////////////////////////////
	//const int positions2_total = 120;
	//float positions2[positions2_total];
	//float xStartOffset = -0.95f;
	//float top = 1.0f;
	//for (int i = 0; i < (positions2_total/6); i++)
	//{
	//	int triIndex = (i * 6);
	//	// tri x1,y1
	//	positions2[triIndex] = xStartOffset + (i*0.1f);
	//	positions2[triIndex + 1] = (top);
	//	// tri x2,y2
	//	positions2[triIndex + 2] = xStartOffset + (i*0.1f) + 0.05f;
	//	positions2[triIndex + 3] = (top - 0.1f);
	//	// tri x3,y4
	//	positions2[triIndex + 4] = xStartOffset + (i*0.1f) - 0.05f;
	//	positions2[triIndex + 5] = (top - 0.1f);

	//}



	// OpenGL is a "state" machine
	// many functions return an 'ID', basically and interger ID for the object, buffer, texture, shader, etc
	//   then... you use that ID henceforth with OpenGL when you want to refer to that object
	unsigned int buffer; // buffer is just and 'ID' to 'grab' the OpenGL object
	glGenBuffers(1, &buffer); // void glGenBuffers( GLsizei n, GLuint * buffers ) // n:  specifies the number of buffer object names to be generated. // buffers:  Specifies an array in which the generated buffer object names are stored.
	glBindBuffer(GL_ARRAY_BUFFER, buffer); // just a buffer of memory, thus 'GL_ARRAY_BUFFER'
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
	//glBufferData(GL_ARRAY_BUFFER, positions2_total * sizeof(float), positions2, GL_STATIC_DRAW);

	{
		// buffers contain data and it's up to us to tell openGL what's in that buffer
		// glVertexAttribPointer()  tells openGL what shape the data is in it

		// in this example a 'vertex' = (postion, vector, normal)
		// position vector and normal ar 'attributes' of the vertex in the buffer

		//void glVertexAttribPointer(GLuint index,             // index in buffer to begin at
		//							 GLint size,               // componant count in buffer: number of groupings of discreet items with multiple attribuites
		//	                         GLenum type,              // type of attribute (  )
		//                           GLboolean normalized,     // leave false
		//	                         GLsizei stride,           // stride: # of BYTES occupied by each discrete data group for 1 item --> 1 thing in buffer = sizeof(position) + sizeof(vector) + sizeof(normal) etc
		//	                         const GLvoid * pointer);  // pointer to beginning of attribute, use offsetOf()
    }
	glVertexAttribPointer( /* GLuint index */ 0, 
	                       /* GLint size   */ 2,
		                   /* GLenum type  */ GL_FLOAT,
		                   /* GLboolean normalized*/ GL_FALSE,   
		                   /* GLsizei stride */ (sizeof(float) * 2),
						   /* const GLvoid * pointer) */ 0
	                      );

	//void glEnableVertexAttribArray(GLuint index);
	glEnableVertexAttribArray(0); // in this case, the arg is an index of vertex to enable
	



	///////////////////////////////////////////
	// MAIN GAME LOOP	         
	///////////////////////////////////////////
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		//updateRowPlacement(positions2, positions2_total);
		//std::cout << "positions2[i] = " << positions2[1] << std::endl;


		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// by default open GL uses -1 to +1 in every dimention x,y,z
		/* RENDER COOL STUFF */


		// use this if you don't have an index buffer
		// this knows which buffer to draw because we previously bound a buffer using 'glBindBuffer()'
		glDrawArrays(GL_TRIANGLES, 0, 3); // glDrawArrays(mode, start array index, number of indicies to be rendered)
		//glDrawArrays(GL_TRIANGLES, 0, (positions2_total/2) ); // glDrawArrays(mode, start array index, number of indicies to be rendered)
		
		//glDrawElements();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

	} // while loop

	glfwTerminate();
	return 0;
}



