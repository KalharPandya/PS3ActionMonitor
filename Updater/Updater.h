class Updater
{
public:
    Ps3Controller *st;
    int Ps3_data_analog_stick_ly = 0;
    int Ps3_data_analog_stick_lx = 0;
    int Ps3_event_button_down_l3 = 0;
    int Ps3_event_button_up_l3 = 0;
    Updater(){};
    Updater(Ps3Controller *st);

    void update()
    {
        // Serial.println("Update");
        Ps3_data_analog_stick_ly = st->data.analog.stick.ly;
        Ps3_data_analog_stick_lx = st->data.analog.stick.lx;
        Ps3_event_button_up_l3 = st->event.button_up.l3;
        Ps3_event_button_down_l3 = st->event.button_down.l3;
    }
} Ps3Updater(&Ps3);

void g_update()
{
    Ps3Updater.update();
}

Updater::Updater(Ps3Controller *st)
{
    Updater::st = st;
}