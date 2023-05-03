#include "chassis-controler.cpp"
#include "sensors-controler.cpp"
#include "direction.cpp"

class ObstacleAvoider
{
private:
    ChasisControler *chasis;
    SensorsControler *sensors;
    direction current_direction;
public:
    ObstacleAvoider(ChasisControler *chasis, SensorsControler *sensors)
    {
        this->chasis = chasis;
        this->sensors = sensors;
    };

    void ride()
    {
        current_direction = get_current_direction();
        ride_by_direction();
    }

    direction get_current_direction()
    {
        direction current_direction = direction::front;
        if (sensors->check_left_obstacle() == true || sensors->check_right_obstacle() == true || sensors->check_front_obstacle() == true)
        {
            current_direction = direction::left;
        }
        return current_direction;
    }

    void ride_by_direction()
    {
        switch (current_direction)
        {
        case direction::front:
            chasis->speed_control(200);
            chasis->front();
            break;
        case direction::left:
            chasis->speed_control(160);
            delay(100);
            chasis->left();
            break;
        case direction::right:
            chasis->speed_control(160);
            delay(100);
            chasis->right();
            break;
        case direction::back:
            chasis->back();
            break;
        }
    }
};
