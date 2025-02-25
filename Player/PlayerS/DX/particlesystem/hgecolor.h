﻿/*
	注释时间:2014-4-25
	author: glp
	颜色类
*/
#ifndef HGECOLOR_H
#define HGECOLOR_H


#include "../staff/image/ImgsetMgr.h"


#define hgeColor hgeColorRGB

inline void ColorClamp(float &x) { if(x<0.0f) x=0.0f; if(x>1.0f) x=1.0f; }


class hgeColorRGB
{
public:
	float		r,g,b,a;

	hgeColorRGB(int _r,int _g,int _b,int _a){r=(_r&0xff)/255.0f;g=(_g&0xff)/255.0f;b=(_b&0xff)/255.0f;a=(_a&0xff)/255.0f;}
	hgeColorRGB(float _r, float _g, float _b, float _a) { r=_r; g=_g; b=_b; a=_a; }
	hgeColorRGB(DWORD col) { SetHWColor(col); }
	hgeColorRGB() { r=g=b=a=0; }

	hgeColorRGB		operator-  (const hgeColorRGB &c) const { return hgeColorRGB(r-c.r, g-c.g, b-c.b, a-c.a); }
	hgeColorRGB		operator+  (const hgeColorRGB &c) const { return hgeColorRGB(r+c.r, g+c.g, b+c.b, a+c.a); }
	hgeColorRGB		operator*  (const hgeColorRGB &c) const { return hgeColorRGB(r*c.r, g*c.g, b*c.b, a*c.a); }
	hgeColorRGB&  operator= (const hgeColorRGB& c){r=c.r;g=c.g;b=c.b;a=c.a;return *this;}
	hgeColorRGB&	operator-= (const hgeColorRGB &c)		{ r-=c.r; g-=c.g; b-=c.b; a-=c.a; return *this;   }
	hgeColorRGB&	operator+= (const hgeColorRGB &c)		{ r+=c.r; g+=c.g; b+=c.b; a+=c.a; return *this;   }
	bool			operator== (const hgeColorRGB &c) const { return (r==c.r && g==c.g && b==c.b && a==c.a);  }
	bool			operator!= (const hgeColorRGB &c) const { return (r!=c.r || g!=c.g || b!=c.b || a!=c.a);  }

	hgeColorRGB		operator/  (const float scalar) const { return hgeColorRGB(r/scalar, g/scalar, b/scalar, a/scalar); }
	hgeColorRGB		operator*  (const float scalar) const { return hgeColorRGB(r*scalar, g*scalar, b*scalar, a*scalar); }
	hgeColorRGB&	operator*= (const float scalar)		  { r*=scalar; g*=scalar; b*=scalar; a*=scalar; return *this;   }

	void			Clamp() { ColorClamp(r); ColorClamp(g); ColorClamp(b); ColorClamp(a); }
	void			SetHWColor(DWORD col) {	a = (col>>24)/255.0f; r = ((col>>16) & 0xFF)/255.0f; g = ((col>>8) & 0xFF)/255.0f; b = (col & 0xFF)/255.0f;	}
	DWORD			GetHWColor() const {return (((DWORD(a*255.0f))&0xff)<<24) | (((DWORD(r*255.0f))&0xff)<<16) | (((DWORD(g*255.0f))&0xff)<<8) | ((DWORD(b*255.0f))&0xff);}
};

inline hgeColorRGB operator* (const float sc, const hgeColorRGB &c) { return c*sc; }


class hgeColorHSV
{
public:
	float		h,s,v,a;

	hgeColorHSV(float _h, float _s, float _v, float _a) { h=_h; s=_s; v=_v; a=_a; }
	hgeColorHSV(DWORD col) { SetHWColor(col); }
	hgeColorHSV() { h=s=v=a=0; }

	hgeColorHSV		operator-  (const hgeColorHSV &c) const { return hgeColorHSV(h-c.h, s-c.s, v-c.v, a-c.a); }
	hgeColorHSV		operator+  (const hgeColorHSV &c) const { return hgeColorHSV(h+c.h, s+c.s, v+c.v, a+c.a); }
	hgeColorHSV		operator*  (const hgeColorHSV &c) const { return hgeColorHSV(h*c.h, s*c.s, v*c.v, a*c.a); }
	hgeColorHSV&	operator-= (const hgeColorHSV &c)		{ h-=c.h; s-=c.s; v-=c.v; a-=c.a; return *this;   }
	hgeColorHSV&	operator+= (const hgeColorHSV &c)		{ h+=c.h; s+=c.s; v+=c.v; a+=c.a; return *this;   }
	bool			operator== (const hgeColorHSV &c) const { return (h==c.h && s==c.s && v==c.v && a==c.a);  }
	bool			operator!= (const hgeColorHSV &c) const { return (h!=c.h || s!=c.s || v!=c.v || a!=c.a);  }

	hgeColorHSV		operator/  (const float scalar) const { return hgeColorHSV(h/scalar, s/scalar, v/scalar, a/scalar); }
	hgeColorHSV		operator*  (const float scalar) const { return hgeColorHSV(h*scalar, s*scalar, v*scalar, a*scalar); }
	hgeColorHSV&	operator*= (const float scalar)		  { h*=scalar; s*=scalar; v*=scalar; a*=scalar; return *this;   }

	void			Clamp() { ColorClamp(h); ColorClamp(s); ColorClamp(v); ColorClamp(a); }
	void			SetHWColor(DWORD col);
	DWORD			GetHWColor() const;
};

inline hgeColorHSV operator* (const float sc, const hgeColorHSV &c) { return c*sc; }


#endif
