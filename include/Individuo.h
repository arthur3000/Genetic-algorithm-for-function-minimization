#ifndef INDIVIDUO_H
#define INDIVIDUO_H


class Individuo
{
    public:
        Individuo(x, y);
        virtual ~Individuo();

        unsigned int Getx() { return x; }
        unsigned int Gety() { return y; }

        unsigned int x;
        unsigned int y;

    protected:

    private:
};

#endif // INDIVIDUO_H
