// Entry point

#include "Application.h"

int main() {
	auto application = std::make_unique<SimpleRenderer::Application>();
	application->run();
	return 0;
}
