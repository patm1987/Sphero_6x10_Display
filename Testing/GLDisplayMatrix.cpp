
#include "Testing/GLDisplayMatrix.h"
#include "Math/Vector2.h"

#include <cstring>

GLDisplayMatrix::GLDisplayMatrix(
	int screenWidth,
	int screenHeight,
	int displayWidth,
	int displayHeight) :
	m_pixelWidth(screenWidth),
	m_pixelHeight(screenHeight),
	m_pVSyncCallback(NULL),
	m_pVSyncUserData(NULL),
	m_running(false)
{
	m_stride = screenWidth * kPixelDepth;

	// pad to be 32 bit aligned
	m_stride += m_stride % 4;

	m_aRenderBuffer = new uint8_t[m_stride * screenHeight];
	memset(m_aRenderBuffer, 0, m_stride * screenHeight);
}

GLDisplayMatrix::~GLDisplayMatrix()
{
	if (m_aRenderBuffer != NULL)
	{
		delete[](m_aRenderBuffer);
	}
}

// easy modifiers

void GLDisplayMatrix::setPixelColor(uint16_t x, uint16_t y, uint32_t c)
{
	int startIndex = (x * getPixelDepth()) + (y * getStride());
	memcpy(m_aRenderBuffer + startIndex, &c, 3);
}

// fast direct framebuffer access
uint8_t* GLDisplayMatrix::getRenderBuffer()
{
	return m_aRenderBuffer;
}

// for app logic, called after a frame renders
void GLDisplayMatrix::setVSyncCallback(vSyncCallback vsc, void* pUserData)
{
	if (m_running && vsc) return; // should probably assert at some point
	m_pVSyncCallback = vsc;
	m_pVSyncUserData = pUserData;
}

// starts the render loop
void GLDisplayMatrix::start()
{
	if (m_running || !m_pVSyncCallback) return;

	m_running = true;
	while(m_running)
	{
		m_pVSyncCallback(m_pVSyncUserData);
	}
}

void GLDisplayMatrix::stop()
{
	m_running = false;
}
