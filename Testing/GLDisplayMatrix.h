
#ifndef _GLDISPLAYMATRIX_H
#define _GLDISPLAYMATRIX_H

#include "DisplayMatrix.h"

class GLDisplayMatrix : public DisplayMatrix
{
private:
	static const int kPixelDepth = 3;

public:
	GLDisplayMatrix(int screenWidth, int screenHeight, int displayWidth, int displayHeight);
	~GLDisplayMatrix();

 	// retrieve screen dimensions
 	virtual int getPixelDepth() const;	//!< bytes per pixel
 	virtual int getStride() const;		//!< width of the screen in bytes
 	virtual int getPixelWidth() const;	//!< width of the screen in pixels
 	virtual int getPixelHeight() const;	//!< height of the screen in pixels

 	// easy modifiers
 	virtual void setPixelColor(uint16_t x, uint16_t y, uint32_t c);

 	// fast direct framebuffer access
 	virtual uint8_t* getRenderBuffer();

 	// for app logic, called after a frame renders
 	virtual void setVSyncCallback(vSyncCallback vsc, void* pUserData);

 	// starts the render loop
 	virtual void start();
 	virtual void stop();

private:
	static uint32_t combineRGB(uint8_t r, uint8_t g, uint8_t b);

	uint8_t* m_aRenderBuffer;
	int m_stride;
	int m_pixelWidth;
	int m_pixelHeight;

	vSyncCallback m_pVSyncCallback;
	void* m_pVSyncUserData;

	bool m_running;
};

inline int GLDisplayMatrix::getPixelDepth() const { return kPixelDepth; }
inline int GLDisplayMatrix::getStride() const { return m_stride; }
inline int GLDisplayMatrix::getPixelWidth() const { return m_pixelWidth; }
inline int GLDisplayMatrix::getPixelHeight() const { return m_pixelHeight; }

inline uint32_t GLDisplayMatrix::combineRGB(uint8_t r, uint8_t g, uint8_t b)
{
	return (uint32_t(r) << 16) | (uint32_t(g) << 8) | uint32_t(b);
}

#endif//_GLDISPLAYMATRIX_H
