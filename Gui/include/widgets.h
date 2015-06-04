//
//  widgets.h
//  XSE-PROJECT
//
//  Created by chenzejun on 6/3/15.
//
//

#ifndef XSE_PROJECT_widgets_h
#define XSE_PROJECT_widgets_h

class widgetsSkin{
    PROPERTY_DEF(WindowBackGround,  ColorRGBA);
    PROPERTY_DEF(MenuBackground,    ColorRGBA);
    PROPERTY_DEF(BottonFront,       ColorRGBA);
    PROPERTY_DEF(BottonBackGround,  ColorRGBA);
    PROPERTY_DEF(BottonText,        ColorRGBA);
    PROPERTY_DEF(TextBox,           ColorRGBA);
    PROPERTY_DEF(TextBackGround,    ColorRGBA);
};

class widgets:public dispather{
public:
    //    widgets();
    //    widgets(const widgets& widgets);
    widgets();
    virtual ~widgets(void);
    PROPERTY_DEF(Position,              vector2);
    PROPERTY_DEF(Rect,                  Rect);
    PROPERTY_DEF(Float,                 FLOAT); //是否为相对位置
    PROPERTY_ONLY_READ_DEF(widgetsSkin, widgetsSkin);
    
protected:
    virtual void onInit();
    virtual void onExit();
    virtual void onLoad();
    virtual void onPain();
    virtual void onUnLoad();
    virtual void onAsyLoad();
};


class window:public widgets{
    
};

class widgetsGroup:public widgets{
    
};

class GLWindow:public widgetsGroup{
    
};

class Botton:public widgets{
    
};

class TextBox:public widgets{
    
};

class DropBox:public widgetsGroup{
    
};

class CheckBox:public Botton{
    
};

class Rido:public CheckBox {
    
};

class Tree:public widgetsGroup{
    
};

class Menu:public Tree{
protected:
    virtual void OnInit();
};


#endif
