class Updater{
    public:
    Ps3Controller * st;
    int Ps3_data_analog_stick_ly = 0;
    int Ps3_data_analog_stick_lx = 0;
    Updater(){};
    Updater(Ps3Controller * st){
        this->st = st;
    }

    void update(){
        Ps3_data_analog_stick_ly = st->data.analog.stick.ly;
        Ps3_data_analog_stick_lx = st->data.analog.stick.lx;
    }
};