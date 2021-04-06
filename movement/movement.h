
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
void pressedleftR();
void pressedrightR();
void analogleftR(int v);
void analogrightR(int v);
void releasedleftR();
void releasedrightR();
class movement
{
public:
    joystick *js;
    button *up, *down, *left, *right, *leftR, *rightR;
    int Semaphore = -1;
    double outputX = 0, outputY = 0, outputR = 0;
    movement(joystick *js, button *up, button *down, button *left, button *right, button *leftR, button *rightR)
    {
        this->up = up;
        this->down = down;
        this->left = left;
        this->right = right;
        this->leftR = leftR;
        this->rightR = rightR;
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

        leftR->attachPress(pressedleftR);
        rightR->attachPress(pressedrightR);

        leftR->attachAnalogChange(analogleftR);
        rightR->attachAnalogChange(analogrightR);

        leftR->attachRelease(releasedleftR);
        rightR->attachRelease(releasedrightR);
    }
    void SemaphoreUpdate()
    {
        if (Semaphore < 0)
        {
            js->enable();
        }
        else
        {
            js->disable();
        }
    }
    void m_analogUp(int v)
    {
        outputX = 0;
        outputY = v;
        sendData();
    }
    void m_releasedUp()
    {
        Semaphore--;
        outputY = 0;
        SemaphoreUpdate();
        sendData();
    }
    void m_pressedUp()
    {
        Semaphore++;
        SemaphoreUpdate();
        sendData();
    }
    void m_analogLeft(int v)
    {
        outputX = -1 * v;
        outputY = 0;
        sendData();
    }
    void m_releasedLeft()
    {
        Semaphore--;
        outputX = 0;
        SemaphoreUpdate();
        sendData();
    }
    void m_pressedLeft()
    {
        Semaphore++;
        SemaphoreUpdate();
        sendData();
    }
    void m_analogRight(int v)
    {
        outputX = v;
        outputY = 0;
        sendData();
    }
    void m_releasedRight()
    {
        Semaphore--;
        outputX = 0;
        SemaphoreUpdate();
        sendData();
    }
    void m_pressedRight()
    {
        Semaphore++;
        SemaphoreUpdate();
        sendData();
    }
    void m_analogDown(int v)
    {
        outputX = 0;
        outputY = -1 * v;
        sendData();
    }
    void m_releasedDown()
    {
        Semaphore--;
        outputY = 0;
        SemaphoreUpdate();
        sendData();
    }
    void m_pressedDown()
    {
        Semaphore++;
        SemaphoreUpdate();
        sendData();
    }
    void m_joyStickX(int v)
    {
        if (v != 0)
            outputX = map(v, -128, 127, -255, 255);
        else
            outputX = 0;
        sendData();
    }
    void m_joyStickY(int v)
    {
        if (v != 0)
            outputY = map(v, 127, -128, -255, 255);
        else
            outputY = 0;
        sendData();
    }
    void m_pressedleftR()
    {
        sendData();
    }
    void m_pressedrightR()
    {
        sendData();
    }
    void m_analogleftR(int v)
    {
        outputR = v * -1;
        sendData();
    }
    void m_analogrightR(int v)
    {
        outputR = v;
        sendData();
    }
    void m_releasedleftR()
    {
        outputR = outputR < 0 ? 0 : outputR;
        sendData();
    }
    void m_releasedrightR()
    {
        outputR = outputR > 0 ? 0 : outputR;
        sendData();
    }
    void sendData()
    {
        Serial.println("X: " + String(outputX) + "  \tY: " + String(outputY) + "  \tR: " + String(outputR));
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

void pressedleftR()
{
    movementObject->m_pressedleftR();
}

void pressedrightR()
{
    movementObject->m_pressedrightR();
}

void analogleftR(int v)
{
    movementObject->m_analogleftR(v);
}
void analogrightR(int v)
{
    movementObject->m_analogrightR(v);
}

void releasedleftR()
{
    movementObject->m_releasedleftR();
}

void releasedrightR()
{
    movementObject->m_releasedrightR();
}
