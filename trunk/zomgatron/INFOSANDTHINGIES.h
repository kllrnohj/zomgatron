#ifndef __INFOSANDTHINGIES_H__
#define __INFOSANDTHINGIES_H__

#define APP_WINDOWED 1

// #define OPENGL

#include "OpenGL.h"
#include "DirectX.h"

#ifdef OPENGL
#define GRTYPE OpenGL
#else
#define GRTYPE DirectX
#endif

#endif
