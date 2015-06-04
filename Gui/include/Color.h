//
//  Color.h
//  XSE-PROJECT
//
//  Created by chenzejun on 6/3/15.
//
//

#ifndef XSE_PROJECT_Color_h
#define XSE_PROJECT_Color_h

struct ColorRGB{
    BYTE R;
    BYTE G;
    BYTE B;
    
    ColorRGB(BYTE r,BYTE g,BYTE b) :R(r),G(g),B(b){};
};

struct ColorRGBA{
    BYTE R;
    BYTE G;
    BYTE B;
    BYTE A;
    ColorRGBA(BYTE r,BYTE g,BYTE b,BYTE a) :R(r),G(g),B(b),A(a){};
    ColorRGBA(BYTE r,BYTE g,BYTE b) :R(r),G(g),B(b),A(BYTE(255)){};
};


#endif
