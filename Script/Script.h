//
//  Script.h
//  XSE-PROJECT
//
//  Created by chenzejun on 6/4/15.
//
//

#ifndef __XSE_PROJECT__Script__
#define __XSE_PROJECT__Script__

class ScriptEngin{
private:
    ScriptEngin();
    virtual ~ScriptEngin(void);

public:
    static ScriptEngin& create();
    
    virtual void Init();
    virtual void UnInit();
};

void Test();

#endif /* defined(__XSE_PROJECT__Script__) */
