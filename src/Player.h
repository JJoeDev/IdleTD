#ifndef PLAYER_H_
#define PLAYER_H_

class Player{
public:
    Player(){}
    ~Player(){}

    inline double& getMoney() { return _money; }
    inline void addMoney(double amount) { _money += amount; }
    inline void subMoney(double amount) { _money -= amount; }

private:
    double _money{0};
};

#endif