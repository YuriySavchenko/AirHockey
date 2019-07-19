//
//  engine.cpp
//  Air Hockey
//
//  Created by YuriySavchenko on 7/13/19.
//  Copyright © 2019 YuriySavchenko. All rights reserved.
//

#include "../headers/engine.h"

/* implementation of explicit constructor */
Engine::Engine(Borders &&borders, std::shared_ptr<Ball> ballPtr, std::shared_ptr<RealPlayer> realPlayerPtr, std::shared_ptr<VirtualPlayer> virtualPlayerPtr)
{
    this->borders = borders;
    this->ball = ballPtr;
    this->realPlayer = realPlayerPtr;
    this->virtualPlayer = virtualPlayerPtr;
    
    moveDirection = 8;
    
    // points which presents quadrate that consists of 8-parts and cover ball
    ballPoints.push_back(Point {ball->getRect()->x+0, ball->getRect()->y+0});
    ballPoints.push_back(Point {ball->getRect()->x+ball->getRect()->w/2, ball->getRect()->y+0});
    ballPoints.push_back(Point {ball->getRect()->x+ball->getRect()->w, ball->getRect()->y+0});
    ballPoints.push_back(Point {ball->getRect()->x+ball->getRect()->w, ball->getRect()->y+ball->getRect()->h/2});
    ballPoints.push_back(Point {ball->getRect()->x+ball->getRect()->w, ball->getRect()->y+ball->getRect()->h});
    ballPoints.push_back(Point {ball->getRect()->x+ball->getRect()->w/2, ball->getRect()->y+0});
    ballPoints.push_back(Point {ball->getRect()->x+0, ball->getRect()->y+ball->getRect()->h});
    ballPoints.push_back(Point {ball->getRect()->x+0, ball->getRect()->y+ball->getRect()->h/2});
}

/* method which allows update points of ball */
void Engine::updatePoints()
{
    ballPoints[0] = (Point {ball->getRect()->x+0, ball->getRect()->y+0});
    ballPoints[1] = (Point {ball->getRect()->x+ball->getRect()->w/2, ball->getRect()->y+0});
    ballPoints[2] = (Point {ball->getRect()->x+ball->getRect()->w, ball->getRect()->y+0});
    ballPoints[3] = (Point {ball->getRect()->x+ball->getRect()->w, ball->getRect()->y+ball->getRect()->h/2});
    ballPoints[4] = (Point {ball->getRect()->x+ball->getRect()->w, ball->getRect()->y+ball->getRect()->h});
    ballPoints[5] = (Point {ball->getRect()->x+ball->getRect()->w/2, ball->getRect()->y+0});
    ballPoints[6] = (Point {ball->getRect()->x+0, ball->getRect()->y+ball->getRect()->h});
    ballPoints[7] = (Point {ball->getRect()->x+0, ball->getRect()->y+ball->getRect()->h/2});
}

/* method which allows check collisions with board and brasses */
void Engine::checkCollisions()
{
    updatePoints();
    
    // picture of ball
    //
    //     0          1          2
    //      . , , , , . , , , , .
    //      , .       .       . ,
    //      ,   .     .     .   ,
    //      ,     .   .   .     ,
    //      ,       . . .       ,
    //      ,         .         ,
    //   7  . . . . . . . . . . .  3
    //      ,       . . .       ,
    //      ,     .   .   .     ,
    //      ,   .     .     .   ,
    //      , .       .       . ,
    //      . , , , , . , , , , .
    //
    //     6          5          4
    
    // points 0 and 6 on the board
    const int leftUpBorderX = static_cast<Point>(borders.getLeftUpPoint()).x();
    const int leftUpBorderY = static_cast<Point>(borders.getLeftUpPoint()).y();
    const int leftDownBorderX = static_cast<Point>(borders.getLeftDownPoint()).x();
    const int leftDownBorderY = static_cast<Point>(borders.getLeftDownPoint()).y();
    
    // points 2 and 4 on the board
    const int rightUpBorderX = static_cast<Point>(borders.getRightUpPoint()).x();
    const int rightUpBorderY = static_cast<Point>(borders.getRightUpPoint()).y();
    const int rightDownBorderX = static_cast<Point>(borders.getRightDownPoint()).x();
    const int rightDownBorderY = static_cast<Point>(borders.getRightDownPoint()).y();
    
    // points of gates on the board for virtual player
    Point gatesPlayer11 = static_cast<Point>(static_cast<Borders>(virtualPlayer->getGates()->getBorders()).getLeftUpPoint());
    Point gatesPlayer12 = static_cast<Point>(static_cast<Borders>(virtualPlayer->getGates()->getBorders()).getRightUpPoint());
    
    // points of gates on the board for real player
    Point gatesPlayer21 = static_cast<Point>(static_cast<Borders>(realPlayer->getGates()->getBorders()).getLeftUpPoint());
    Point gatesPlayer22 = static_cast<Point>(static_cast<Borders>(realPlayer->getGates()->getBorders()).getRightUpPoint());
    
    // points of center for ball
    int ballCenterX = ballPoints[0].x()+ball->R();
    int ballCenterY = ballPoints[0].y()+ball->R();
    
    // points of center for virtual player brassy
    int brassyCenterPlayer1X = virtualPlayer->getBrassy()->getRect()->x+virtualPlayer->getBrassy()->R();
    int brassyCenterPlayer1Y = virtualPlayer->getBrassy()->getRect()->y+virtualPlayer->getBrassy()->R();
    
    // points of center for real player brassy
    int brassyCenterPlayer2X = realPlayer->getBrassy()->getRect()->x+realPlayer->getBrassy()->R();
    int brassyCenterPlayer2Y = realPlayer->getBrassy()->getRect()->y+realPlayer->getBrassy()->R();
    
    // distances between centers for two brasses
    double distanceBrassy1 = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {brassyCenterPlayer1X+0, brassyCenterPlayer1Y+0});
    double distanceBrassy2 = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {brassyCenterPlayer2X+0, brassyCenterPlayer2Y+0});
    
    // check collision with virtual player brassy
    if (distanceBrassy1 - (virtualPlayer->getBrassy()->R()+ball->R()) <= 0) {
        virtualPlayer->getBrassy()->playMusic();
        
        // if centers of ball and virtual player brassy places on the vertical line
        if (ballCenterX == brassyCenterPlayer1X) {
            // if ball places more upper than brassy
            if (ballCenterY < brassyCenterPlayer1Y)
                moveDirection = 1;
            // if ball places more lower than brassy
            else if (ballCenterY > brassyCenterPlayer1Y)
                moveDirection = 5;
        }
        // if centers of ball and virtual player brassy places on the horizontal line
        else if (ballCenterY == brassyCenterPlayer1Y) {
            // if ball places to the left than brassy
            if (ballCenterX < brassyCenterPlayer1X)
                moveDirection = 7;
            // if ball places to the right than brassy
            else if (ballCenterX > brassyCenterPlayer1X)
                moveDirection = 3;
        }
        // if ball places in more upper and to the left than brassy
        else if ((ballCenterX < brassyCenterPlayer1X) && (ballCenterY < brassyCenterPlayer1Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {brassyCenterPlayer1X+0, ballCenterY+0});
            double angle = Operations::angle(against, distanceBrassy1);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 0;
            else if (angle < 15)
                moveDirection = 1;
            else if (angle > 75)
                moveDirection = 7;
        }
        // if ball places in more upper and to the right than brassy
        else if ((ballCenterX > brassyCenterPlayer1X) && (ballCenterY < brassyCenterPlayer1Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {brassyCenterPlayer1X+0, ballCenterY+0});
            double angle = Operations::angle(against, distanceBrassy1);
   
            if ((angle > 15) && (angle < 75))
                moveDirection = 2;
            else if (angle < 15)
                moveDirection = 1;
            else if (angle > 75)
                moveDirection = 3;
        }
        // if ball places in more down and to the left than brassy
        else if ((ballCenterX < brassyCenterPlayer1X) && (ballCenterY > brassyCenterPlayer1Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {ballCenterX+0, brassyCenterPlayer1Y+0});
            double angle = Operations::angle(against, distanceBrassy1);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 6;
            else if (angle < 15)
                moveDirection = 7;
            else if (angle < 75)
                moveDirection = 5;
        }
        // if ball places in more down and to the right than brassy
        else if ((ballCenterX > brassyCenterPlayer1X) && (ballCenterY > brassyCenterPlayer1Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {ballCenterX+0, brassyCenterPlayer1Y+0});
            double angle = Operations::angle(against, distanceBrassy1);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 4;
            else if (angle < 15)
                moveDirection = 3;
            else if (angle < 75)
                moveDirection = 5;
        }
    }
    
    // check collision with real player brassy
    if (distanceBrassy2 - (realPlayer->getBrassy()->R()+ball->R()) <= 0) {
        realPlayer->getBrassy()->playMusic();
        
        // if centers of ball and virtual player brassy places on the vertical line
        if (ballCenterX == brassyCenterPlayer2X) {
            // if ball places more upper than brassy
            if (ballCenterY < brassyCenterPlayer2Y)
                moveDirection = 1;
            // if ball places more lower than brassy
            else if (ballCenterY > brassyCenterPlayer2Y)
                moveDirection = 5;
        }
        // if centers of ball and virtual player brassy places on the horizontal line
        else if (ballCenterY == brassyCenterPlayer2Y) {
            // if ball places to the left than brassy
            if (ballCenterX < brassyCenterPlayer2X)
                moveDirection = 7;
            // if ball places to the right than brassy
            else if (ballCenterX > brassyCenterPlayer2X)
                moveDirection = 3;
        }
        // if ball places in more upper and to the left than brassy
        else if ((ballCenterX < brassyCenterPlayer2X) && (ballCenterY < brassyCenterPlayer2Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {brassyCenterPlayer2X+0, ballCenterY+0});
            double angle = Operations::angle(against, distanceBrassy2);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 0;
            else if (angle < 15)
                moveDirection = 1;
            else if (angle > 75)
                moveDirection = 7;
        }
        // if ball places in more upper and to the right than brassy
        else if ((ballCenterX > brassyCenterPlayer2X) && (ballCenterY < brassyCenterPlayer2Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {brassyCenterPlayer2X+0, ballCenterY+0});
            double angle = Operations::angle(against, distanceBrassy2);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 2;
            else if (angle < 15)
                moveDirection = 1;
            else if (angle > 75)
                moveDirection = 3;
        }
        // if ball places in more down and to the left than brassy
        else if ((ballCenterX < brassyCenterPlayer2X) && (ballCenterY > brassyCenterPlayer2Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {ballCenterX+0, brassyCenterPlayer2Y+0});
            double angle = Operations::angle(against, distanceBrassy2);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 6;
            else if (angle < 15)
                moveDirection = 7;
            else if (angle < 75)
                moveDirection = 5;
        }
        // if ball places in more down and to the right than brassy
        else if ((ballCenterX > brassyCenterPlayer1X) && (ballCenterY > brassyCenterPlayer1Y)) {
            double against = Operations::distance(Point {ballCenterX+0, ballCenterY+0}, Point {ballCenterX+0, brassyCenterPlayer2Y+0});
            double angle = Operations::angle(against, distanceBrassy2);
            
            if ((angle > 15) && (angle < 75))
                moveDirection = 4;
            else if (angle < 15)
                moveDirection = 3;
            else if (angle < 75)
                moveDirection = 5;
        }
    }
    
    // checking of collisions with board
    if (moveDirection == 0) {
        int x = ballPoints[1].x();
        int y = ballPoints[1].y();
        
        if ((y == gatesPlayer11.y()) && ((gatesPlayer11.x() < x) && (x < gatesPlayer12.x()))) {
            virtualPlayer->getGates()->increaseGoals();
            virtualPlayer->getGates()->playMusic();
            ball->moveToBegin();
            moveDirection = 8;
        }
        else if ((ballPoints[0].x() == leftUpBorderX) && (leftUpBorderY < ballPoints[0].y() < leftDownBorderY)) {
            moveDirection = 2;
            ball->playMusic();
        }
        else if ((ballPoints[0].y() == leftUpBorderY) && (leftUpBorderX < ballPoints[0].y() < rightUpBorderY)) {
            moveDirection = 6;
            ball->playMusic();
        }
    }
    
    if (moveDirection == 1) {
        int x = ballPoints[1].x();
        int y = ballPoints[1].y();
        
        if ((y == gatesPlayer11.y()) && ((gatesPlayer11.x() < x) && (x < gatesPlayer12.x()))) {
            virtualPlayer->getGates()->increaseGoals();
            virtualPlayer->getGates()->playMusic();
            ball->moveToBegin();
            moveDirection = 8;
        }
        else if ((ballPoints[1].y() == rightUpBorderY) && (leftUpBorderX < ballPoints[1].x() < rightUpBorderX)) {
            ball->playMusic();
            moveDirection = 5;
        }
    }
    
    if (moveDirection == 2) {
        int x = ballPoints[1].x();
        int y = ballPoints[1].y();
        
        if ((y == gatesPlayer11.y()) && ((gatesPlayer11.x() < x) && (x < gatesPlayer12.x()))) {
            virtualPlayer->getGates()->increaseGoals();
            virtualPlayer->getGates()->playMusic();
            ball->moveToBegin();
            moveDirection = 8;
        }
        else if ((ballPoints[2].x() == rightUpBorderX) && (rightUpBorderY < ballPoints[2].y() < rightDownBorderY)) {
            ball->playMusic();
            moveDirection = 0;
        }
        else if ((ballPoints[2].y() == rightUpBorderY) && (leftUpBorderX < ballPoints[2].x() < rightUpBorderX)) {
            ball->playMusic();
            moveDirection = 4;
        }
    }
    
    if (moveDirection == 3) {
        if ((ballPoints[3].x() == rightDownBorderX) && (rightUpBorderY < ballPoints[3].y() < rightDownBorderY)) {
            ball->playMusic();
            moveDirection = 7;
        }
    }
    
    if (moveDirection == 4) {
        int x = ballPoints[5].x();
        int y = ballPoints[5].y();
        
        if ((y == gatesPlayer21.y()) && ((gatesPlayer21.x() < x) && (x < gatesPlayer22.x()))) {
            realPlayer->getGates()->increaseGoals();
            realPlayer->getGates()->playMusic();
            ball->moveToBegin();
            moveDirection = 8;
        }
        else if ((ballPoints[4].x() == rightDownBorderX) && (rightUpBorderY < ballPoints[4].y() < rightDownBorderY)) {
            ball->playMusic();
            moveDirection = 6;
        }
        else if ((ballPoints[4].y() == rightDownBorderY) && (leftDownBorderX < ballPoints[4].x() < rightDownBorderX)) {
            ball->playMusic();
            moveDirection = 2;
        }
    }
    
    if (moveDirection == 5) {
        int x = ballPoints[5].x();
        int y = ballPoints[5].y();
        
        if ((y == gatesPlayer21.y()) && ((gatesPlayer21.x() < x) && (x < gatesPlayer22.x()))) {
            realPlayer->getGates()->increaseGoals();
            realPlayer->getGates()->playMusic();
            ball->moveToBegin();
            moveDirection = 8;
        }
        else if ((ballPoints[5].y() == leftDownBorderY) && (leftDownBorderX < ballPoints[5].x() < rightDownBorderX)) {
            ball->playMusic();
            moveDirection = 1;
        }
    }
    
    if (moveDirection == 6) {
        int x = ballPoints[5].x();
        int y = ballPoints[5].y();
        
        if ((y == gatesPlayer21.y()) && ((gatesPlayer21.x() < x) && (x < gatesPlayer22.x()))) {
            realPlayer->getGates()->increaseGoals();
            realPlayer->getGates()->playMusic();
            ball->moveToBegin();
            moveDirection = 8;
        }
        else if ((ballPoints[6].x() == leftDownBorderX) && (leftUpBorderY < ballPoints[6].y() < leftDownBorderY)) {
            ball->playMusic();
            moveDirection = 4;
        }
        else if ((ballPoints[6].y() == leftDownBorderY) && (leftDownBorderX < ballPoints[6].x() < rightDownBorderX)) {
            ball->playMusic();
            moveDirection = 0;
        }
    }
    
    if (moveDirection == 7) {
        if ((ballPoints[7].x() == leftUpBorderX) && (leftUpBorderY < ballPoints[7].y() < leftDownBorderY)) {
            ball->playMusic();
            moveDirection = 3;
        }
    }
}

/* method which allows check direction for moving */
void Engine::checkDirection()
{
    if (moveDirection == 0)
        moveToLeftUpperSide();
    if (moveDirection == 1)
        moveToUpperSide();
    if (moveDirection == 2)
        moveToRightUpperSide();
    if (moveDirection == 3)
        moveToRightSide();
    if (moveDirection == 4)
        moveToRightDownSide();
    if (moveDirection == 5)
        moveToDownSide();
    if (moveDirection == 6)
        moveToLeftDownSide();
    if (moveDirection == 7)
        moveToLeftSide();
    if (moveDirection == 8)
        return;
}

/* method which allows move ball to left upper side */
void Engine::moveToLeftUpperSide()
{
    ball->moveBall(ball->getRect()->x-1, ball->getRect()->y-1);
}

/* method which allows move ball to left down side */
void Engine::moveToLeftDownSide()
{
    ball->moveBall(ball->getRect()->x-1, ball->getRect()->y+1);
}

/* method which allows move ball to right upper side */
void Engine::moveToRightUpperSide()
{
    ball->moveBall(ball->getRect()->x+1, ball->getRect()->y-1);
}

/* method which allows move ball to right down side */
void Engine::moveToRightDownSide()
{
    ball->moveBall(ball->getRect()->x+1, ball->getRect()->y+1);
}

/* method which allows move ball to left side */
void Engine::moveToLeftSide()
{
    ball->moveBall(ball->getRect()->x-1, ball->getRect()->y);
}

/* method which allows move ball to right side */
void Engine::moveToRightSide()
{
    ball->moveBall(ball->getRect()->x+1, ball->getRect()->y);
}

/* method which allows move ball to upper side */
void Engine::moveToUpperSide()
{
    ball->moveBall(ball->getRect()->x, ball->getRect()->y-1);
}

/* method which allows move ball to down side */
void Engine::moveToDownSide()
{
        ball->moveBall(ball->getRect()->x, ball->getRect()->y+1);
}

/* implementation of function which allows reset scores of game */
void Engine::resetScores()
{
    ball->moveToBegin();
    realPlayer->getGates()->resetGoals();
    virtualPlayer->getGates()->resetGoals();
    moveDirection = 8;
}

/* method which allows calculate all states of ball and brasses and their collisions between board and between itself */
void Engine::handling()
{
    checkCollisions();
    checkDirection();
    updatePoints();
}
