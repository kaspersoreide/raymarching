#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "player.h"
#include "rng.h"
#include <chrono>
#include "raycaster.h"

GLFWwindow* window;
Player* player;
bool closed = false;
vec2 mouse(0.0f);

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_E) {
		if (action == GLFW_PRESS) player->rot[0] = true;
		if (action == GLFW_RELEASE) player->rot[0] = false;
	}
	if (key == GLFW_KEY_Q) {
		if (action == GLFW_PRESS) player->rot[1] = true;
		if (action == GLFW_RELEASE) player->rot[1] = false;
	}
	if (key == GLFW_KEY_LEFT) {
		if (action == GLFW_PRESS) player->rot[2] = true;
		if (action == GLFW_RELEASE) player->rot[2] = false;
	}
	if (key == GLFW_KEY_RIGHT) {
		if (action == GLFW_PRESS) player->rot[3] = true;
		if (action == GLFW_RELEASE) player->rot[3] = false;
	}
	if (key == GLFW_KEY_UP) {
		if (action == GLFW_PRESS) player->rot[4] = true;
		if (action == GLFW_RELEASE) player->rot[4] = false;
	}
	if (key == GLFW_KEY_DOWN) {
		if (action == GLFW_PRESS) player->rot[5] = true;
		if (action == GLFW_RELEASE) player->rot[5] = false;
	}

	if (key == GLFW_KEY_W) {
		if (action == GLFW_PRESS) player->mov[0] = true;
		if (action == GLFW_RELEASE) player->mov[0] = false;
	}
	if (key == GLFW_KEY_S) {
		if (action == GLFW_PRESS) player->mov[1] = true;
		if (action == GLFW_RELEASE) player->mov[1] = false;
	}
	if (key == GLFW_KEY_A) {
		if (action == GLFW_PRESS) player->mov[2] = true;
		if (action == GLFW_RELEASE) player->mov[2] = false;
	}
	if (key == GLFW_KEY_D) {
		if (action == GLFW_PRESS) player->mov[3] = true;
		if (action == GLFW_RELEASE) player->mov[3] = false;
	}
	if (key == GLFW_KEY_LEFT_SHIFT) {
		if (action == GLFW_PRESS) player->mov[4] = true;
		if (action == GLFW_RELEASE) player->mov[4] = false;
	}
	if (key == GLFW_KEY_LEFT_CONTROL) {
		if (action == GLFW_PRESS) player->mov[5] = true;
		if (action == GLFW_RELEASE) player->mov[5] = false;
	}
	if (key == GLFW_KEY_ESCAPE) {
		closed = true;
	}
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		player->jump();
	}
}

void cursorCallback(GLFWwindow* window, double xpos, double ypos) {
	//vec2 diff(xpos - mouse.x, ypos - mouse.y);
	//player->rotate(diff);
	mouse = vec2(xpos, ypos);
	player->rotate(mouse);
	//std::cout << "mouse x: " << xpos << ", y: " << ypos << "\n";
}

int main() {
	rng::srand(425);
    glfwInit();
	window = glfwCreateWindow(1280, 720, "application", NULL, NULL);
	glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glewInit();
    glfwSetKeyCallback(window, keyCallback);
	glDisable(GL_DEPTH_TEST);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE);
	glfwSetCursorPosCallback(window, cursorCallback);

	player = new Player();
	Raycaster raycaster;
	raycaster.setResolution(1280, 720);
	typedef std::chrono::high_resolution_clock Time;
	typedef std::chrono::duration<float> fsec;
	auto t0 = Time::now();
    while (!glfwWindowShouldClose(window) && !closed) {
		//main loop
        glClear(GL_COLOR_BUFFER_BIT);
		auto t1 = Time::now();
		fsec t = t1 - t0;
		raycaster.setTime(t.count());
        player->move();
        raycaster.render(player->getModel());
        glfwSwapBuffers(window);
		glfwPollEvents();
    }

    return 0;
}