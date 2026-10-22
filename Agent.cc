// Agent.cc

#include <iostream>
#include <cstdlib> //added for randomization
#include "Agent.h"

using namespace std;

Agent::Agent ()
{

}

Agent::~Agent ()
{

}

void Agent::Initialize ()
{
	x = 1; //first column
    y = 1; //first row
	orientation = RIGHT; //got the orientation from WumpusWorld.cc
    hasArrow = true; //has an arrow
    hasGold = false; //does not have gold
	previousAction = CLIMB; //climb as a placeholder because it doesn't change position or orientation
}

Action Agent::Process (Percept& percept)
{
	if (previousAction == GOFORWARD && !percept.Bump)
	{
		if (orientation == UP) //increments the row
		{
			y++;
		}
		else if (orientation == DOWN) //decrements the row
		{
			y--;
		}
		else if (orientation == RIGHT) //increments the column
		{
			x++;
		}
		else if (orientation == LEFT) //decrements the column
		{
			x--;
		}
	}

	else if (previousAction == TURNLEFT) //turn left orientation states
	{
		if (orientation == RIGHT)
		{
			orientation = UP;
		}
		else if (orientation == UP)
		{
			orientation = LEFT;
		}
		else if (orientation == LEFT)
		{
			orientation = DOWN;
		}
		else if (orientation == DOWN)
		{
			orientation = RIGHT;
		}
	}

	else if (previousAction == TURNRIGHT) //turn right orientation states
	{
		if (orientation == RIGHT)
		{
			orientation = DOWN;
		}
		else if (orientation == DOWN)
		{
			orientation = LEFT;
		}
		else if (orientation == LEFT)
		{
			orientation = UP;
		}
		else if (orientation == UP)
		{
			orientation = RIGHT;
		}
	}

	if (percept.Glitter) //if gold is detected, then grab
    {
        hasGold = true;
		previousAction = GRAB; //sets the previous action to GRAB before returning the action
        return GRAB;
    }

	if (x == 1 && y == 1 && hasGold) //if its at the starting position and has gold, then climb
	{
		previousAction = CLIMB; //sets the previous action to CLIMB before returning the action
    	return CLIMB;
	}
	
	if (hasArrow && y == 4 && orientation == RIGHT) //if it has Arrow, its at the top row and facing right, then shoot
	{
    	hasArrow = false;
		previousAction = SHOOT; //sets the previous action to SHOOT before returning the action
    	return SHOOT;
	}

	if (hasArrow && x == 4 && orientation == UP) //if it has Arrow, its on the right column and facing up, then shoot
	{
    	hasArrow = false;
		previousAction = SHOOT; //sets the previous action to SHOOT before returning the action
    	return SHOOT;
	}

	int choice = rand() % 3; //random number for random turn

	if (choice == 0)
	{
		previousAction = GOFORWARD; //sets the previous action to GOFORWARD before returning the action
		return GOFORWARD; //if the random number is 0, GOFORWARD
	}
	else if (choice == 1)
	{
		previousAction = TURNLEFT; //sets the previous action to TURNLEFT before returning the action
		return TURNLEFT; //if the random number is 1, TURNLEFT
	}
	else
	{
		previousAction = TURNRIGHT; //sets the previous action to TURNRIGHT before returning the action
		return TURNRIGHT; //if the random number is 2, TURNRIGHT
	}

}

void Agent::GameOver (int score)
{

}

