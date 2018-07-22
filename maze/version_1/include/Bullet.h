#ifndef BULLET_H
#define BULLET_H


class Bullet
{
    public:
        Bullet(float start_x, float start_y, float start_dir, float start_speed);
        virtual ~Bullet();

        float getX(){return this->x;}
        float getY(){return this->y;}
        float getDir(){return this->dir;}
        float getSpeed(){return this->speed;}

        void setX(float value){this->x = value;}
        void setY(float value) {this->y = value;}
        void setDir(float value) {this->dir = value;}
        void setSpeed(float value) {this->speed = value;}

    protected:

    private:
        float x;
        float y;
        float dir;
        float speed;
};

#endif // BULLET_H
