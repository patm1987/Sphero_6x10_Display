
#ifndef _GLDISPLAYMATRIX_H
#define _GLDISPLAYMATRIX_H

#include "DisplayMatrix.h"

class GLDisplayMatrix : public DisplayMatrix
{
public:
	GLDisplayMatrix(int screenWidth, int screenHeight, int displayWidth, int displayHeight);
	~GLDisplayMatrix();

 	// retrieve screen dimensions
 	virtual int getPixelDepth();
 	virtual int getStride();
 	virtual int getPixelWidth();
 	virtual int getPixelHeight();

 	// easy modifiers
 	virtual void setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b);
 	virtual void setPixelColor(uint16_t n, uint32_t c);
 	virtual void setPixelColor(uint16_t x, uint16_t y, uint32_t c);

 	// fast direct framebuffer access
 	virtual uint8_t* getRenderBuffer();

 	// for app logic, called after a frame renders
 	virtual void setVSyncCallback(vSyncCallback vsc, void* pUserData);

 	// starts the render loop
 	virtual void start();
 	virtual void stop();

private:
	uint8_t* m_aRenderBuffer;
};

#endif//_GLDISPLAYMATRIX_H
