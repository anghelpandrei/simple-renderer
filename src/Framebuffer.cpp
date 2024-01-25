#include "Framebuffer.h"

namespace SimpleRenderer {
	Framebuffer::Framebuffer() {
		glGenFramebuffers(1, &m_ID);
	}

	Framebuffer::~Framebuffer() {
		glDeleteFramebuffers(1, &m_ID);
	}

	void Framebuffer::bind() {
		glBindFramebuffer(GL_FRAMEBUFFER, m_ID);
	}

	void Framebuffer::unbind() {
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

}
