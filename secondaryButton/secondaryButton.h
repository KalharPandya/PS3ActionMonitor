#define max_Secondary_objects 10

void secondaryNone(){};
class secondaryButton
{
	public:
	bool pressed=false;
	listener btnPress,btnRelease;
	secondaryButton(listener btnPress,listener btnRelease);
	//button(listener btnPress,listener btnRelease);
	void (*buttonPressed)()=secondaryNone;
	void (*buttonReleased)()=secondaryNone;
	
	void attachPress(void(*f)())
	{
		this->buttonPressed=f;
	}
	void attachRelease(void(*f)())
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
secondaryButton *secbutton[max_Secondary_objects];
int secButtonIndex=0;

secondaryButton::secondaryButton(listener btnPress,listener btnRelease)
{
	this->btnPress=btnPress;
	this->btnRelease=btnRelease;
	secbutton[secButtonIndex]=this; 
	secButtonIndex++;
}

void updateSecondaryButton()
{
	for(int i=0;i<secButtonIndex;i++){
		secbutton[i]->update();
    }
}