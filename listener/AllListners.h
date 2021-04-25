//All Listeners

listener lPress(&Ps3Updater.Ps3_event_button_down_l3);
listener lRelease(&Ps3Updater.Ps3_event_button_up_l3);
listener lx(&Ps3Updater.Ps3_data_analog_stick_lx);
listener ly(&Ps3Updater.Ps3_data_analog_stick_ly);
joystick leftJoystick(lPress,lRelease,lx,ly);

listener rPress(&Ps3Updater.Ps3_event_button_down_r3);
listener rRelease(&Ps3Updater.Ps3_event_button_up_r3);
listener rx(&Ps3Updater.Ps3_data_analog_stick_rx);
listener ry(&Ps3Updater.Ps3_data_analog_stick_ry);
joystick rightJoystick(rPress,rRelease,rx,ry);

listener crossP(&Ps3Updater.Ps3_event_button_down_cross);
listener crossR(&Ps3Updater.Ps3_event_button_up_cross);
listener crossA(&Ps3Updater.Ps3_data_analog_button_cross);
button cross(crossP,crossR,crossA);

listener squareP(&Ps3Updater.Ps3_event_button_down_square);
listener squareR(&Ps3Updater.Ps3_event_button_up_square);
listener squareA(&Ps3Updater.Ps3_data_analog_button_square);
button square(squareP,squareR,squareA);

listener triangleP(&Ps3Updater.Ps3_event_button_down_triangle);
listener triangleR(&Ps3Updater.Ps3_event_button_up_triangle);
listener triangleA(&Ps3Updater.Ps3_data_analog_button_triangle);
button triangle(triangleP,triangleR,triangleA);

listener circleP(&Ps3Updater.Ps3_event_button_down_circle);
listener circleR(&Ps3Updater.Ps3_event_button_up_circle);
listener circleA(&Ps3Updater.Ps3_data_analog_button_circle);
button circle(circleP,circleR,circleA);

listener upP(&Ps3Updater.Ps3_event_button_down_up);
listener upR(&Ps3Updater.Ps3_event_button_up_up);
listener upA(&Ps3Updater.Ps3_data_analog_button_up);
button up(upP,upR,upA);

listener downP(&Ps3Updater.Ps3_event_button_down_down);
listener downR(&Ps3Updater.Ps3_event_button_up_down);
listener downA(&Ps3Updater.Ps3_data_analog_button_down);
button down(downP,downR,downA);

listener rightP(&Ps3Updater.Ps3_event_button_down_right);
listener rightR(&Ps3Updater.Ps3_event_button_up_right);
listener rightA(&Ps3Updater.Ps3_data_analog_button_right);
button right(rightP,rightR,rightA);

listener leftP(&Ps3Updater.Ps3_event_button_down_left);
listener leftR(&Ps3Updater.Ps3_event_button_up_left);
listener leftA(&Ps3Updater.Ps3_data_analog_button_left);
button left(leftP,leftR,leftA);

listener l1P(&Ps3Updater.Ps3_event_button_down_l1);
listener l1R(&Ps3Updater.Ps3_event_button_up_l1);
listener l1A(&Ps3Updater.Ps3_data_analog_button_l1);
button l1(l1P,l1R,l1A);

listener l2P(&Ps3Updater.Ps3_event_button_down_l2);
listener l2R(&Ps3Updater.Ps3_event_button_up_l2);
listener l2A(&Ps3Updater.Ps3_data_analog_button_l2);
button l2(l2P,l2R,l2A);

listener r1P(&Ps3Updater.Ps3_event_button_down_r1);
listener r1R(&Ps3Updater.Ps3_event_button_up_r1);
listener r1A(&Ps3Updater.Ps3_data_analog_button_r1);
button r1(r1P,r1R,r1A);

listener r2P(&Ps3Updater.Ps3_event_button_down_r2);
listener r2R(&Ps3Updater.Ps3_event_button_up_r2);
listener r2A(&Ps3Updater.Ps3_data_analog_button_r2);
button r2(r2P,r2R,r2A);

listener startP(&Ps3Updater.Ps3_event_button_down_start);
listener startR(&Ps3Updater.Ps3_event_button_up_start);
secondaryButton start(startP,startR);

listener psP(&Ps3Updater.Ps3_event_button_down_ps);
listener psR(&Ps3Updater.Ps3_event_button_up_ps);
secondaryButton ps(psP,psR);

listener selectP(&Ps3Updater.Ps3_event_button_down_select);
listener selectR(&Ps3Updater.Ps3_event_button_up_select);
secondaryButton selectButton(selectP,selectR);

movement m(&leftJoystick,&up,&down,&left,&right,&l2,&r2,&l1,&r1);
