// simple-renderer.cpp : Defines the entry point for the application.
//

#include "Application.h"

int main() {
	auto application = std::make_unique<SimpleRenderer::Application>();
	application->run();
	return 0;
}
