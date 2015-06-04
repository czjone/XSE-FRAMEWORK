#ifndef XSE_PROJECT_widgets_analysis_h
#define XSE_PROJECT_widgets_analysis_h

#include <widgets.h>

//解析器，把文件解析成界面元素
class widgetsAnalysis{
private:
    widgetsAnalysis();
    
public:
    virtual ~widgetsAnalysis(void);
    virtual widgets* Analysis();
};

#endif
