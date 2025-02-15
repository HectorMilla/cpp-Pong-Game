#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>


class Game {
public:
	Game(); //constructor	
	void run(); // Main Game loop

private:
	int player1Score;
	int player2Score;
	unsigned int window_height = 600;
	unsigned int window_width = 800;
	sf::Vector2f player_speed;
	sf::Vector2f ball_velocity;
	sf::RenderWindow window;
	sf::RectangleShape player1;
	sf::RectangleShape player2;
	sf::CircleShape ball;
	void initText();
	void initPaddles();
	void initBall();
	void processEvents();
	void update();
	void render();
	void movePlayer(sf::RectangleShape& player, sf::Keyboard::Key key, std::string direction);
	void resetBall();

};

#endif

