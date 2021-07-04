void nonej(){};
void nonechangej(int z){};
class joystick
{
public:
    int value = 0;
    listener press, release, x, y;
    bool pressed = false;
    bool jpressed = true;
    bool xyPressed = true;
    bool en = true;
    int xValue = 0;
    int yValue = 0;
    joystick() {}
    joystick(listener press, listener release, listener x, listener y);
    void (*pressedJ)() = nonej;
    void (*releasedJ)() = nonej;
    void (*xChange)(int v) = nonechangej;
    void (*yChange)(int v) = nonechangej;
    void enable()
    {
        en = true;
    }
    void disable()
    {
        en = false;
    }
    bool isPressed()
    {
        return pressed;
    }
    int getX()
    {
        return xValue;
    }
    int getY()
    {
        return yValue;
    }
    void attachXChange(void (*f)(int v))
    {
        this->xChange = f;
    }
    void attachYChange(void (*f)(int v))
    {
        this->yChange = f;
    }
    bool attachPress(void (*f)())
    {
        this->pressedJ = f;
        return jpressed;
    }
    void attachRelease(void (*f)())
    {
        this->releasedJ = f;
    }
    void update()
    {
        if (en)
        {
            if (press.check())
            {
                if (press.get().value == 1)
                {
                    pressed = true;
                    pressedJ();
                }
            }

            if (release.check())
            {
                if (release.get().value == 1)
                {
                    pressed = false;
                    xChange(0);
                    yChange(0);
                    releasedJ();
                }
            }

            if (x.check())
            {
                value = x.get().getProcessedValue();
                if ( (!xyPressed || pressed))
                {
                    if(abs(value)<10){
                        value = 0;
                    }
                    xValue = value;
                    xChange(xValue);
                }
            }

            if (y.check())
            {
                value = y.get().getProcessedValue();
                if ( (!xyPressed || pressed))
                {
                    if(abs(value)<10){
                        value = 0;
                    }
                    yValue = value;
                    yChange(yValue);
                }
            }
        }
    }
};

joystick *allSticks[10];
int joyStickIndex = 0;

joystick::joystick(listener press, listener release, listener x, listener y)
{
    this->press = press;
    this->release = release;
    this->x = x;
    this->y = y;
    allSticks[joyStickIndex] = this;
    joyStickIndex++;
}

void updateJoySticks()
{
    for (int i = 0; i < joyStickIndex; i++)
    {
        allSticks[i]->update();
    }
}