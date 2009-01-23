#ifndef __THINGIESTRUCTS_H__
#define __THINGIESTRUCTS_H__

#define ZOMGFVF (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_SPECULAR)

struct ZOMGVERTEX{
	float x, y, z, nx, ny, nz;
	DWORD diffuse, specular;
};

#endif
