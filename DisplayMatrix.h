
#ifndef _DISPLAYMATRIX_H
#define _DISPLAYMATRIX_H

#include <cstdint>

/*!
 * An abstraction for rendering, default implementation should be the ws2801
 */
 class DisplayMatrix
 {
 public:
 	// callback on vsync - takes the user data passed in on setVSyncCallback
 	typedef void(*vSyncCallback)(void*);

 	// retrieve screen dimensions
 	virtual int getPixelDepth() const = 0;
 	virtual int getStride() const = 0;
 	virtual int getPixelWidth() const = 0;
 	virtual int getPixelHeight() const = 0;

 	virtual void setPixelColor(uint16_t x, uint16_t y, uint32_t c) = 0;

 	// fast direct framebuffer access
 	virtual uint8_t* getRenderBuffer() = 0;

 	// for app logic, called after a frame renders
 	virtual void setVSyncCallback(vSyncCallback vsc, void* pUserData) = 0;

 	// starts the render loop
 	virtual void start() = 0;
 	virtual void stop() = 0;
 };

#endif//_DISPLAYMATRIX_H

