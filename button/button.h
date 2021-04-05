class button
{
	public:
	bool pressed=false;
	listener btnPress,btnRelease;
	button(listener btnPress,listener btnRelease);
	void (*buttonPressed)();
	void (*buttonReleased)();
	void attachBtnPress(void(*f)())
	{
		this->buttonPressed=f;
	}
	void attachBtnRelease(void(*f)())
	{
		this->buttonReleased=f;
	}
	bool isPressed()
	{
		return pressed;
	}
	void update()
	{
		if(btnPress.check()){
			if(btnPress.get().value==1){
				pressed=true;
				buttonPressed();
			}

		}
		if(btnRelease.check()){
			if(btnRelease.get().value==1){
				pressed=false;
				buttonReleased();
			}
		}
	}

};
button *allbutton[12];
int buttonIndex=0;

button::button(listener btnPress,listener btnRelease)
{
	this->btnPress=btnPress;
	this->btnRelease=btnRelease;
	allbutton[buttonIndex]=this; 
	buttonIndex++;
}
void updateButton()
{
	for(int i=0;i<buttonIndex;i++)
		allbutton[i]->update();
}