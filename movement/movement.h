
////Up
void analogUp(int v);
void releasedUp();
void pressedUp();
////Left
void analogLeft(int v);
void releasedLeft();
void pressedLeft();
////Right
void analogRight(int v);
void releasedRight();
void pressedRight();
////down
void analogDown(int v);
void releasedDown();
void pressedDown();
void usingJoystickX(int v);
void usingJoystickY(int v);
void pressedRot1();
void pressedRot2();
void analogRot1(int v);
void analogRot2(int v);
void releasedRot1();
void releasedRot2();
class movement
{
public:
    joystick *js; //*js(int id)
                  //button u,d,l,r,rot1,rot2;
    button *up, *down, *left, *right, *rot1, *rot2;
    int xCorBtn = 0, yCorBtn = 0, rCorBtn = 0, xCorJoy = 0, yCorJoy = 0;
    int Semaphore = -1;
    movement(joystick *js, button *up, button *down, button *left, button *right, button *rotational1, button *rotational2)
    {
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
        this->rot1 = rotational1;
        this->rot2 = rotational2;
        this->js = js;
        attachAll();
        storeObject();
    }
    void attachAll()
    {
        up->attachAnalogChange(analogUp);
        down->attachAnalogChange(analogDown);
        left->attachAnalogChange(analogLeft);
        right->attachAnalogChange(analogRight);

        up->attachPress(pressedUp);
        down->attachPress(pressedDown);
        left->attachPress(pressedLeft);
        right->attachPress(pressedRight);

        up->attachRelease(releasedUp);
        down->attachRelease(releasedDown);
        left->attachRelease(releasedLeft);
        right->attachRelease(releasedRight);

        js->attachXChange(usingJoystickX);
        js->attachYChange(usingJoystickY);

        rot1->attachPress(pressedRot1);
        rot2->attachPress(pressedRot2);

        rot1->attachAnalogChange(analogRot1);
        rot2->attachAnalogChange(analogRot2);

        rot1->attachRelease(releasedRot1);
        rot2->attachRelease(releasedRot2);
    }
    void SemaphoreUpdate(){
       if(Semaphore<0){
           js->disable();
       }
       else{
           js->enable();
       }
    }
    void m_analogUp(int v)
    {
        
    }
    void m_releasedUp()
    {
        Semaphore--;
        SemaphoreUpdate();
    }
    void m_pressedUp()
    {
        Semaphore++;
        SemaphoreUpdate();
    }
    void m_analogLeft(int v)
    {

    }
    void m_releasedLeft()
    {
        Semaphore--;
        SemaphoreUpdate();
    }
    void m_pressedLeft()
    {
        Semaphore++;
        SemaphoreUpdate();
    }
    void m_analogRight(int v)
    {

    }
    void m_releasedRight()
    {
        Semaphore--;
        SemaphoreUpdate();
    }
    void m_pressedRight()
    {
        Semaphore++;
        SemaphoreUpdate();
    }
    void m_analogDown(int v)
    {

    }
    void m_releasedDown()
    {
        Semaphore--;
        SemaphoreUpdate();
    }
    void m_pressedDown()
    {
        Semaphore++;
        SemaphoreUpdate();
    }
    void m_joyStickX(int v)
    {

    }
    void m_joyStickY(int v)
    {

    }
    void m_pressedRot1()
    {
        
    }
    void m_pressedRot2()
    {
        
    }
    void m_analogRot1(int v)
    {

    }
    void m_analogRot2(int v)
    {

    }
    void m_releasedRot1()
    {
       
    }
    void m_releasedRot2()
    {
       
    }
    void storeObject();
};

movement *movementObject;

void movement::storeObject()
{
    movementObject = this;
}

////Up
void analogUp(int v)
{
    movementObject->m_analogUp(v);
}

void releasedUp()
{
    movementObject->m_releasedUp();
}

void pressedUp()
{
    movementObject->m_pressedUp();
}

////Left
void analogLeft(int v)
{
    movementObject->m_analogLeft(v);
}

void releasedLeft()
{
    movementObject->m_releasedLeft();
}

void pressedLeft()
{
    movementObject->m_pressedLeft();
}

////Right
void analogRight(int v)
{
    movementObject->m_analogRight(v);
}

void releasedRight()
{
    movementObject->m_releasedRight();
}

void pressedRight()
{
    movementObject->m_pressedRight();
}

////down
void analogDown(int v)
{
    movementObject->m_analogDown(v);
}

void releasedDown()
{
    movementObject->m_releasedDown();
}

void pressedDown()
{
    movementObject->m_pressedDown();
}

void usingJoystickX(int v)
{
    movementObject->m_joyStickX(v);
}

void usingJoystickY(int v)
{
    movementObject->m_joyStickY(v);
}

void pressedRot1()
{
    movementObject->m_pressedRot1();
}

void pressedRot2()
{
    movementObject->m_pressedRot2();
}

void analogRot1(int v)
{
    movementObject->m_analogRot1(v);
}
void analogRot2(int v)
{
    movementObject->m_analogRot2(v);
}

void releasedRot1()
{
    movementObject->m_releasedRot1();
}

void releasedRot2()
{
    movementObject->m_releasedRot2();
}
