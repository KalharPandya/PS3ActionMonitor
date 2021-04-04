#include <Ps3Controller.h>
#include "./Updater/Updater.h"
#include "./listener/listener.h"
#include "./joystick/joystick.h"
void noneFunction(){};
void updateAllEntities()
{
    Ps3Updater.update();
    updateJoySticks();
}
void(*user_update_function)();
void ps3_update(){
    updateAllEntities();
    user_update_function();
}
void initPs3(String addr, void(*funA)() = noneFunction)
{
    Ps3.begin(addr.c_str());
    user_update_function = funA;
    Ps3.attach(ps3_update);
    
}
