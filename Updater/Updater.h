class Updater
{
public:
    Ps3Controller *st;
    int Ps3_data_analog_stick_ly = 0;
    int Ps3_data_analog_stick_lx = 0;
    int Ps3_event_button_down_l3 = 0;
    int Ps3_event_button_up_l3 = 0;

    int Ps3_data_analog_stick_ry = 0;
    int Ps3_data_analog_stick_rx = 0;
    int Ps3_event_button_down_r3 = 0;
    int Ps3_event_button_up_r3 = 0;

    int Ps3_event_button_down_cross = 0;
    int Ps3_event_button_up_cross = 0;
    int Ps3_data_analog_button_cross = 0;

    int Ps3_event_button_down_square = 0;
    int Ps3_event_button_up_square = 0;
    int Ps3_data_analog_button_square = 0;

    int Ps3_event_button_down_triangle = 0;
    int Ps3_event_button_up_triangle = 0;
    int Ps3_data_analog_button_triangle = 0;

    int Ps3_event_button_down_circle = 0;
    int Ps3_event_button_up_circle = 0;
    int Ps3_data_analog_button_circle = 0;

    int Ps3_event_button_down_up = 0;
    int Ps3_event_button_up_up = 0;
    int Ps3_data_analog_button_up = 0;

    int Ps3_event_button_down_down = 0;
    int Ps3_event_button_up_down = 0;
    int Ps3_data_analog_button_down = 0;

    int Ps3_event_button_down_right = 0;
    int Ps3_event_button_up_right = 0;
    int Ps3_data_analog_button_right = 0;

    int Ps3_event_button_down_left = 0;
    int Ps3_event_button_up_left = 0;
    int Ps3_data_analog_button_left = 0;

    int Ps3_event_button_down_l1 = 0;
    int Ps3_event_button_up_l1 = 0;
    int Ps3_data_analog_button_l1 = 0;

    int Ps3_event_button_down_l2 = 0;
    int Ps3_event_button_up_l2 = 0;
    int Ps3_data_analog_button_l2 = 0;

    int Ps3_event_button_down_r2 = 0;
    int Ps3_event_button_up_r2 = 0;
    int Ps3_data_analog_button_r2 = 0;

    int Ps3_event_button_down_r1 = 0;
    int Ps3_event_button_up_r1 = 0;
    int Ps3_data_analog_button_r1 = 0;

    int Ps3_event_button_down_select = 0;
    int Ps3_event_button_up_select = 0;
    int Ps3_event_button_down_start = 0;
    int Ps3_event_button_up_start = 0;
    int Ps3_event_button_down_ps = 0;
    int Ps3_event_button_up_ps = 0;
    int battery;
   
    //int Ps3_data_analog_stick_lx = 0;

    Updater(){};
    Updater(Ps3Controller *st);

    void update()
    {
        // Serial.println("Update");
        Ps3_data_analog_stick_ly = st->data.analog.stick.ly;
        Ps3_data_analog_stick_lx = st->data.analog.stick.lx;
        Ps3_event_button_up_l3 = st->event.button_up.l3;
        Ps3_event_button_down_l3 = st->event.button_down.l3;

        Ps3_data_analog_stick_ry = st->data.analog.stick.ry;
        Ps3_data_analog_stick_rx = st->data.analog.stick.rx;
        Ps3_event_button_up_r3 = st->event.button_up.r3;
        Ps3_event_button_down_r3 = st->event.button_down.r3;

        Ps3_event_button_down_cross=st->event.button_down.cross;
        Ps3_event_button_up_cross=st->event.button_up.cross;
        Ps3_data_analog_button_cross=st->data.analog.button.cross;

        Ps3_event_button_down_square=st->event.button_down.square;
        Ps3_event_button_up_square=st->event.button_up.square;
        Ps3_data_analog_button_square=st->data.analog.button.square;

        Ps3_event_button_down_triangle=st->event.button_down.triangle;
        Ps3_event_button_up_triangle=st->event.button_up.triangle;
        Ps3_data_analog_button_triangle=st->data.analog.button.triangle;

        Ps3_event_button_down_circle=st->event.button_down.circle;
        Ps3_event_button_up_circle=st->event.button_up.circle;
         Ps3_data_analog_button_circle=st->data.analog.button.circle;

        Ps3_event_button_down_up=st->event.button_down.up;
        Ps3_event_button_up_up=st->event.button_up.up;
        Ps3_data_analog_button_up=st->data.analog.button.up;

        Ps3_event_button_down_down=st->event.button_down.down;
        Ps3_event_button_up_down=st->event.button_up.down;
         Ps3_data_analog_button_down=st->data.analog.button.down;

        Ps3_event_button_down_right=st->event.button_down.right;
        Ps3_event_button_up_right=st->event.button_up.right;
         Ps3_data_analog_button_right=st->data.analog.button.right;

        Ps3_event_button_down_left=st->event.button_down.left;
        Ps3_event_button_up_left=st->event.button_up.left;
        Ps3_data_analog_button_left=st->data.analog.button.left;


        Ps3_event_button_down_l1=st->event.button_down.l1;
        Ps3_event_button_up_l1=st->event.button_up.l1;
        Ps3_data_analog_button_l1=st->data.analog.button.l1;

        Ps3_event_button_down_l2=st->event.button_down.l2;
        Ps3_event_button_up_l2=st->event.button_up.l2;
         Ps3_data_analog_button_l2=st->data.analog.button.l2;

        Ps3_event_button_down_r2=st->event.button_down.r2;
        Ps3_event_button_up_r2=st->event.button_up.r2;
        Ps3_data_analog_button_r2=st->data.analog.button.r2;

       

        Ps3_event_button_down_r1=st->event.button_down.r1;
        Ps3_event_button_up_r1=st->event.button_up.r1;
        Ps3_data_analog_button_r1=st->data.analog.button.r1;

        Ps3_event_button_down_select=st->event.button_down.select;
        Ps3_event_button_up_select=st->event.button_up.select;
        Ps3_event_button_down_start=st->event.button_down.start;
        Ps3_event_button_up_start=st->event.button_up.start;
        Ps3_event_button_down_ps=st->event.button_down.ps;
        Ps3_event_button_up_ps=st->event.button_up.ps;
        battery=st-> data.status.battery;
        
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