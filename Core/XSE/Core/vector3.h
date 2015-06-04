#ifndef XSE_CORE_VECTOR3_H
#define XSE_CORE_VECTOR3_H

struct vector3{
    DOUBLE X;
    DOUBLE Y;
    DOUBLE Z;
    
    inline vector3 operator +=(vector3& v2){
        vector3 v;
        v.X = this->X + v2.X;
        v.Y = this->Y + v2.Y;
        v.Z = this->Z + v2.Z;
        return v;
    };
    
    inline vector3 operator -=(vector3& v2){
        vector3 v;
        v.X = this->X - v2.X;
        v.Y = this->Y - v2.Y;
        v.Z = this->Z - v2.Z;
        return v;
    };
    
    inline vector3 operator + (vector3& v2){
        return *this += v2;
    };
    
    inline vector3 operator - (vector3& v2){
        return *this -= v2;
    };
    
    inline Bool operator == (vector3& v2){
        return this->X == v2.X && this->Y == v2.Y&& this->Z == v2.Z;
    }
    
    inline Bool operator!=(vector3& v2){
        return !(*this == v2);
    }
};

#endif
