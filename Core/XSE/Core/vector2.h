#ifndef XSE_CORE_VECTOR2_H
#   define XSE_CORE_VECTOR2_H
#   include <XSE/config.h>

struct vector2{
    DOUBLE X;
    DOUBLE Y;
    
    inline vector2 operator +=(vector2& v2){
        vector2 v;
        v.X = this->X + v2.X;
        v.Y = this->Y + v2.Y;
        return v;
    };
    
    inline vector2 operator -=(vector2& v2){
        vector2 v;
        v.X = this->X - v2.X;
        v.Y = this->Y - v2.Y;
        return v;
    };
    
    inline vector2 operator + (vector2& v2){
        return *this += v2;
    };
    
    inline vector2 operator - (vector2& v2){
        return *this -= v2;
    };
    
    inline Bool operator == (vector2& v2){
        return this->X == v2.X && this->Y == v2.Y;
    }
    
    inline Bool operator!=(vector2& v2){
        return !(*this == v2);
    }
};


#endif
