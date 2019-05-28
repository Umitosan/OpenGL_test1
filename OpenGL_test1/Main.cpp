// shader is just a program that runs on the GPU
// GLFW - CROSS PLATFORM
// GLFW - opens a window easily
// GLFW - render context
// GLFW - takes input
// GLFW - allows us to use raw OpenGL code


#include <GL/glew.h> // this MUST be included before glfw3.h
#include <GLFW/glfw3.h>

#include <iostream>


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

	// OpenGL is a "state" machine
	// many functions return an 'ID', basically and interger ID for the object, buffer, texture, shader, etc
	//   then... you use that ID henceforth with OpenGL when you want to refer to that object
	unsigned int buffer; // buffer is just and 'ID' to 'grab' the OpenGL object
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer); // just a buffer of memory, thus 'GL_ARRAY_BUFFER'
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

	///////////////////////////////////////////
	// MAIN GAME LOOP
	///////////////////////////////////////////
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// by default open GL uses -1 to +1 in every dimention x,y,z
		/* RENDER COOL STUFF */

		// use this if you don't have an index buffer
		// this knows which buffer to draw because we previously bound a buffer using 'glBindBuffer()'
		glDrawArrays(GL_TRIANGLES, 0, 3); // glDrawArrays(mode, start array index, number of indicies to be rendered)
		
		//glDrawElements();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

	} // while loop

	glfwTerminate();
	return 0;
}



