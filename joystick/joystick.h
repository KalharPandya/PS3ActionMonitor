void nonej(){};
void nonechangej(int z){};
class joystick
{
public:
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
        en = true;//enabling joystick
    }
    void disable()
    {
        en = false;//disabling joystick
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
                    releasedJ();
                }
            }

            if (x.check())
            {
                if (!xyPressed || pressed)
                {
                    xValue = x.get().value;
                    xChange(xValue);
                }
            }

            if (y.check())
            {
                if (!xyPressed || pressed)
                {
                    yValue = y.get().value;
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