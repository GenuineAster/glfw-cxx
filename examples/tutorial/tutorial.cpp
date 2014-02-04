#include <glfw-cxx/glfw-cxx.hpp>
#include <cstdlib>
#include <iostream>

void error_callback(int error, const char* description)
{
	std::cerr<<description;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	glfw::Window window;
	glfw::SetErrorCallback(error_callback);

	window.Create(640, 480, "Simple example");

	window.MakeContextCurrent();
	window.SetKeyCallback(key_callback);

	while(!window.ShouldClose())
	{
		glfw::FramebufferSize fb_size = window.GetFramebufferSize();
		
		float ratio = fb_size.x / static_cast<float>(fb_size.y);
		
		glViewport(0, 0, fb_size.x, fb_size.y);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		
		glLoadIdentity();
		glRotatef(glfw::Time::Get() * 50.f, 0.f, 0.f, 1.f);
		
		glBegin(GL_TRIANGLES);
		{
			glColor3f(1.f, 0.f, 0.f);
			glVertex3f(-0.6f, -0.4f, 0.f);
			glColor3f(0.f, 1.f, 0.f);
			glVertex3f(0.6f, -0.4f, 0.f);
			glColor3f(0.f, 0.f, 1.f);
			glVertex3f(0.f, 0.6f, 0.f);
		}
		glEnd();

		window.SwapBuffers();
		window.PollEvents();
	}
	
	return 0;
}
