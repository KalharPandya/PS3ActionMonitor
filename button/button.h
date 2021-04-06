#define max_objects 20

void none(){};
void nonechange(int z){};
class button
{
public:
	int analogChangeValue = 0;
	bool pressed = false;
	bool en = true;
	listener btnPress, btnRelease, btnAnalogChange;

	button() {}
	button(listener btnPress, listener btnRelease, listener btnAnalogChange);
	//button(listener btnPress,listener btnRelease);
	void (*buttonPressed)() = none;
	void (*buttonReleased)() = none;
	void (*analogChange)(int v) = nonechange;
	void enable()
	{
		en = true;
	}
	void disable()
	{
		en = false;
	}
	void attachPress(void (*f)())
	{
		this->buttonPressed = f;
	}
	void attachRelease(void (*f)())
	{
		this->buttonReleased = f;
	}
	void attachAnalogChange(void (*f)(int v))
	{
		this->analogChange = f;
	}
	int getAnalogChangeValue()
	{
		return analogChangeValue;
	}
	bool isPressed()
	{
		return pressed;
	}
	void update()
	{
		if (en)
		{
			if (btnPress.check())
			{
				if (btnPress.get().value == 1)
				{
					pressed = true;
					buttonPressed();
				}
			}
			if (btnRelease.check())
			{
				if (btnRelease.get().value == 1)
				{
					pressed = false;
					analogChangeValue = 0;
					analogChange(analogChangeValue);
					buttonReleased();
				}
			}
			if (pressed && btnAnalogChange.check())
			{
				analogChangeValue = btnAnalogChange.get().value;
				analogChange(analogChangeValue);
			}
		}
	}
};
button *allbutton[max_objects];
int buttonIndex = 0;

button::button(listener btnPress, listener btnRelease, listener btnAnalogChange)
{
	this->btnPress = btnPress;
	this->btnRelease = btnRelease;
	this->btnAnalogChange = btnAnalogChange;
	allbutton[buttonIndex] = this;
	buttonIndex++;
}

void updateButton()
{
	for (int i = 0; i < buttonIndex; i++)
		allbutton[i]->update();
}