// shader is just a program that runs on the GPU
// GLFW - CROSS PLATFORM
// GLFW - opens a window easily
// GLFW - render context
// GLFW - takes input
// GLFW - allows us to use raw OpenGL code


#include <iostream>
#include <GLFW/glfw3.h>



int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// by default open GL uses -1 to +1 in every dimention x,y,z
		/* RENDER COOL STUFF */

		glBegin(GL_TRIANGLES);

		// triangle top
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(0.5f, 0.0f);

		// triangle bot left
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(-0.5f, 0.0f);
		glVertex2f(0.0f, -1.0f);		

		// triangle bot right
		glVertex2f(0.0f, -1.0f);
		glVertex2f(0.5f, -0.0f);
		glVertex2f(1.0f, -1.0f);

		glEnd();		

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}