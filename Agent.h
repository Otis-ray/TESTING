// Agent.h

#ifndef AGENT_H
#define AGENT_H

#include "Action.h"
#include "Percept.h"

class Agent
{
public:
	Agent ();
	~Agent ();
	void Initialize ();
	Action Process (Percept& percept);
	void GameOver (int score);

private:
	enum Direction { //each direcation of a grid
        UP,
        RIGHT,
        DOWN,
        LEFT
    };

    int x; //stores our column location
    int y; //stores our row location
	Direction orientation; //stores where we're facing
	Action previousAction; //stores our previous action (such as moving forward)
	bool hasArrow; //true or false for the arrow
    bool hasGold; //true or false for having gold
};

#endif // AGENT_H
