//#include "gui.h"
//#include <fstream>
//#include <Script.h>
//XSE_NS_EXT_USING(XSE_NS_GUI)
//int main(int,char**args){
//    Engine engine;
//    return engine.Run();
//}
//

#include "gui.h"
#include <fstream>
#include <Script.h>
#include <XSE/Core/Serialization.h>

XSE_NS_EXT_USING(XSE_NS_GUI)
XSE_NS_EXT_USING(CORE_NS_NAME);

class Test1:public XMLSerialization{
    SERIALIZATION_PROPERTY_SUPPER_DEF(public,public,TestValue,UINT);
    SERIALIZATION_PROPERTY_SUPPER_DEF(public,public,TestValue2,INT);
    SERIALIZATION_PROPERTY_SUPPER_DEF(public,public,TestValue3,STRING);
};

int main(int,char**args){
    Test1 test;
    test.setTestValue(10);
    test.setTestValue2(30);
    test.setTestValue3((STRING)"123123\0");
    UINT value = test.getTestValue();
    UINT value2 = test.getTestValue2();
    STRING value3 = test.getTestValue3();
    XSE_LOG("%d",strlen((const char*)value3));
    Serialization::Save("test.yaml");
}



//#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
//#include <FL/Fl_Box.H>
//#include <FL/Fl_Button.H>
//#include <FL/Fl_Radio_Light_Button.H>
//#include <FL/Fl_Slider.H>
//#include <stdlib.h>
//
//#include <FL/Fl_Gl_Window.H>
////#include <FL/gl.h>
//#include <OpenGL/gl.h>
//
//class cube_box : public Fl_Gl_Window {
//    void draw();
//    int handle(int);
//public:
//    double lasttime;
//    int wire;
//    double size;
//    double speed;
//    cube_box(int x,int y,int w,int h,const char *l=0)
//    : Fl_Gl_Window(x,y,w,h,l) {lasttime = 0.0;}
//};
//
///* The cube definition */
//float v0[3] = {0.0, 0.0, 0.0};
//float v1[3] = {1.0, 0.0, 0.0};
//float v2[3] = {1.0, 1.0, 0.0};
//float v3[3] = {0.0, 1.0, 0.0};
//float v4[3] = {0.0, 0.0, 1.0};
//float v5[3] = {1.0, 0.0, 1.0};
//float v6[3] = {1.0, 1.0, 1.0};
//float v7[3] = {0.0, 1.0, 1.0};
//
//#define v3f(x) glVertex3fv(x)
//
//void drawcube(int wire) {
//    /* Draw a colored cube */
//    glBegin(wire ? GL_LINE_LOOP : GL_POLYGON);
//    glColor3ub(0,0,255);
//    v3f(v0); v3f(v1); v3f(v2); v3f(v3);
//    glEnd();
//    glBegin(wire ? GL_LINE_LOOP : GL_POLYGON);
//    glColor3ub(0,255,255); v3f(v4); v3f(v5); v3f(v6); v3f(v7);
//    glEnd();
//    glBegin(wire ? GL_LINE_LOOP : GL_POLYGON);
//    glColor3ub(255,0,255); v3f(v0); v3f(v1); v3f(v5); v3f(v4);
//    glEnd();
//    glBegin(wire ? GL_LINE_LOOP : GL_POLYGON);
//    glColor3ub(255,255,0); v3f(v2); v3f(v3); v3f(v7); v3f(v6);
//    glEnd();
//    glBegin(wire ? GL_LINE_LOOP : GL_POLYGON);
//    glColor3ub(0,255,0); v3f(v0); v3f(v4); v3f(v7); v3f(v3);
//    glEnd();
//    glBegin(wire ? GL_LINE_LOOP : GL_POLYGON);
//    glColor3ub(255,0,0); v3f(v1); v3f(v2); v3f(v6); v3f(v5);
//    glEnd();
//}
//
//void cube_box::draw() {
//    lasttime = lasttime+speed;
//    if (!valid()) {
//        glLoadIdentity();
//        glViewport(0,0,w(),h());
//        glEnable(GL_DEPTH_TEST);
//        glFrustum(-1,1,-1,1,2,10000);
//        glTranslatef(0,0,-10);
//        //        gl_font(FL_HELVETICA_BOLD, 16 );
//    }
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glPushMatrix();
//    glRotatef(float(lasttime*1.6),0,0,1);
//    glRotatef(float(lasttime*4.2),1,0,0);
//    glRotatef(float(lasttime*2.3),0,1,0);
//    glTranslatef(-1.0, 1.2f, -1.5);
//    glScalef(float(size),float(size),float(size));
//    drawcube(wire);
//    glPopMatrix();
//    //    gl_color(FL_GRAY);
//    glDisable(GL_DEPTH_TEST);
//    //    gl_draw(wire ? "Cube: wire" : "Cube: flat", -4.5f, -4.5f );
//    glEnable(GL_DEPTH_TEST);
//}
//
//int cube_box::handle(int e) {
//    switch (e) {
//        case FL_ENTER: cursor(FL_CURSOR_CROSS); break;
//        case FL_LEAVE: cursor(FL_CURSOR_DEFAULT); break;
//    }
//    return Fl_Gl_Window::handle(e);
//}
//
//
//Fl_Window *form;
//Fl_Slider *speed, *size;
//Fl_Button *button, *wire, *flat;
//cube_box *cube, *cube2;
//
//void makeform(const char *name) {
//    form = new Fl_Window(510+390,390,name);
//    new Fl_Box(FL_DOWN_FRAME,20,20,350,350,"");
//    new Fl_Box(FL_DOWN_FRAME,510,20,350,350,"");
//    speed = new Fl_Slider(FL_VERT_SLIDER,390,90,40,220,"Speed");
//    size = new Fl_Slider(FL_VERT_SLIDER,450,90,40,220,"Size");
//    wire = new Fl_Radio_Light_Button(390,20,100,30,"Wire");
//    flat = new Fl_Radio_Light_Button(390,50,100,30,"Flat");
//    button = new Fl_Button(390,340,100,30,"Exit");
//    cube = new cube_box(23,23,344,344, 0);
//    cube2 = new cube_box(513,23,344,344, 0);
//    Fl_Box *b = new Fl_Box(FL_NO_BOX,cube->x(),size->y(),
//                           cube->w(),size->h(),0);
//    form->resizable(b);
//    b->hide();
//    form->end();
//}
//
//// added to demo printing
//#include <FL/Fl_Sys_Menu_Bar.H>
//#include <FL/Fl_Printer.H>
//
//
//int main(int argc, char **argv) {
//    makeform(argv[0]);
//
//    // end of printing demo
//    speed->bounds(4,0);
//    speed->value(cube->speed = cube2->speed = 1.0);
//    size->bounds(4,0.01);
//    size->value(cube->size = cube2->size = 1.0);
//    flat->value(1); cube->wire = 0; cube2->wire = 1;
//    form->label("cube");
//    form->show(argc,argv);
//    cube->show();
//    cube2->show();
//
//    for (;;) {
//        if (!Fl::check()) break;
//        cube->wire = wire->value();
//        cube2->wire = !wire->value();
//        cube->size = cube2->size = size->value();
//        cube->speed = cube2->speed = speed->value();
//        cube->redraw();
//        cube2->redraw();
//        if (Fl::readqueue() == button) break;
//    }
//    return 0;
//}

//
//#endif /* HAVE_GL */

