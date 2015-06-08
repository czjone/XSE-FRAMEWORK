#include "Ref.h"

XSE_NS_EXT_USING(CORE_NS_NAME);

Ref::Ref(){
    this->setrefCount(1);
}

Ref::~Ref(){
    
}

void Ref::Release(){
    this->m_property_refCount--;
    if (this->m_property_refCount == 0) {
        this->m_property_refCount = -1;
        delete this;
    }
};

void Ref::Retain(){
    this->m_property_refCount++;
}
