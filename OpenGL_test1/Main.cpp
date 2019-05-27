// shader is just a program that runs on the GPU
// GLFW - CROSS PLATFORM
// GLFW - opens a window easily
// GLFW - render context
// GLFW - takes input
// GLFW - allows us to use raw OpenGL code


#include <iostream>
#include <GLFW/glfw3.h>
#include <array>
#include <string>
#include <stdio.h> 
#include <stdlib.h> 


int getRandColorInt()
{
	int colInt;
	colInt = rand();
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << colInt << std::endl;
	}
	return colInt;
}

void updateAnimation(float* x, int* bounceDir)
{
	if ( ( *x >= 0.99) || (*x <= -0.99) )
	{
		*bounceDir *= -1;
		*x += ( *bounceDir * 0.005);
	}
	*x += (*bounceDir * 0.005);
	//std::cout << "x = " << *x << std::endl;
}


int main(void)
{
	GLFWwindow* window;
	unsigned int timer = 0;
	float x,y;
	float* xptr = &x;
	x = -0.9;
	y = 0.9;
	int bounceDir = 1;
	int* bounceDirPtr = &bounceDir;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(800, 600, "OpenGL Rocks", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	getRandColorInt();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		// by default open GL uses -1 to +1 in every dimention x,y,z
		/* RENDER COOL STUFF */

	    // triangle top
		glBegin(GL_TRIANGLES);
		{
			//glColor3f(0.0f, 1.0f, 0.0f);
			glColor3ub(255, 0, 0);
			glVertex2f(-0.5f, 0.0f);
			glVertex2f(0.0f, 1.0f);
			glVertex2f(0.5f, 0.0f);
			// small inside
			glColor3ub(0, 255, 0);
			glVertex2f(-0.5f / 2.0f, 0.0f);
			glVertex2f(0.0f, 1.0f / 2.0f);
			glVertex2f(0.5f / 2.0f, 0.0f);

			// triangle bot left
			glColor3ub(0, 255, 0);
			glVertex2f(-1.0f, -1.0f);
			glVertex2f(-0.5f, 0.0f);
			glVertex2f(0.0f, -1.0f);
			// small inside
			glColor3ub(0, 0, 255);
			glVertex2f(-1.0f / 2.0f, -1.0f / 2.0f);
			glVertex2f(-0.5f / 2.0f, 0.0f);
			glVertex2f(0.0f, -1.0f / 2.0f);

			// triangle bot right
			glColor3ub(0, 0, 255);
			glVertex2f(0.0f, -1.0f);
			glVertex2f(0.5f, -0.0f);
			glVertex2f(1.0f, -1.0f);
			// small inside
			glColor3ub(255, 0, 0);
			glVertex2f(0.0f, -1.0f / 2.0f);
			glVertex2f(0.5f / 2.0f, -0.0f);
			glVertex2f(1.0f / 2.0f, -1.0f / 2.0f);			
			
			// anim triangle
			glColor3ub(150, 50, 150);
			glVertex2f(x,y);
			glVertex2f(x+0.05,y-0.05);
			glVertex2f(x-0.05, y-0.05);
			
			//glColor3ub(255, 0, 0);
			//glVertex2f(0.0f, -1.0f / 2.0f);
			//glVertex2f(0.5f / 2.0f, -0.0f);
			//glVertex2f(1.0f / 2.0f, -1.0f / 2.0f);			
			//
			//glColor3ub(255, 0, 0);
			//glVertex2f(0.0f, -1.0f / 2.0f);
			//glVertex2f(0.5f / 2.0f, -0.0f);
			//glVertex2f(1.0f / 2.0f, -1.0f / 2.0f);

			glEnd(); // triangles	
		}

		glBegin(GL_POINTS);
		{
			//glPointSize(1.0f);
			glColor3f(0.0f, 0.5f, 0.5f);
			glVertex2f(x, y);		

			//glColor3f(0.0f, 0.0f, 1.0f);
			//glVertex2f(x-0.005, y-0.005);	

			//glColor3f(0.0f, 0.0f, 1.0f);
			//glVertex2f(x-0.005, y+0.005);
			glEnd();
		}

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		// animation timer
		if (timer >= 1) 
		{
			timer = 0;
			updateAnimation(xptr, bounceDirPtr);
		}
		else 
		{
			timer += 1;
		}

	} // while loop

	glfwTerminate();
	return 0;
}



