#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>


Game::Game() : window(sf::VideoMode({ Game::window_width, Game::window_height }), "Pong Game") 
{
	initPaddles();
	initBall();
	player1Score = 0;
	player2Score = 0;
}

void Game::run() {

	while (window.isOpen()) 
	{
		processEvents();
		update();
		render();
		
	}
}

void Game::processEvents() {
	// check all the window's events that were triggered since the last iteration of the loop
	while (const std::optional event = window.pollEvent())
	{
		// "close requested" event: we close the window
		if (event->is <sf::Event::Closed>())
			window.close();
					


	}




}

void Game::update() {


//	std::cout << delta << "\n";

	//Game Logic 	
	sf::Vector2 player1_position = player1.getPosition();
	window.setFramerateLimit(60);
	// dont move past top of window
	movePlayer(player1, sf::Keyboard::Key::W, "up");
	movePlayer(player1, sf::Keyboard::Key::S, "down");
	movePlayer(player2, sf::Keyboard::Key::Up, "up");
	movePlayer(player2, sf::Keyboard::Key::Down, "down");
	ball.move(ball_velocity);
	
	//ball will bounce off top and bottom wall
	if (ball.getPosition().y + ball.getRadius() <= 0 || ball.getPosition().y + ball.getRadius() >= window_height )
	{
		ball_velocity.y = -ball_velocity.y;
	}
	
	if (ball.getPosition().x + ball.getRadius() < -10 - ball.getRadius())
	{
		//player 2 scores
		player2Score++;
		std::cout << player2Score;
		resetBall();

	}
		
	else if (ball.getPosition().x > window_width + ball.getRadius())
	{
		//player 1 scores
		player1Score++;
		resetBall();
	}
	if (ball.getGlobalBounds().findIntersection(player1.getGlobalBounds()) ||
		ball.getGlobalBounds().findIntersection(player2.getGlobalBounds()))
	{
			ball_velocity.x = -ball_velocity.x;
	}
	

}

void Game::render() {

	sf::Font font;
	if (!font.openFromFile("C:\\dev\\Project3\\Pong\\Roboto_Condensed-black.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	int testing = 1;
	// Set font before using sf::Text
	sf::Text player1ScoreText(font);
	sf::Text player2ScoreText(font);
	player1ScoreText;
	// Initialize text properties
	std::string test2 = ("Player 1: " + std::to_string(player1Score));

	player1ScoreText.setString(test2);
	player1ScoreText.setCharacterSize(24);
	player1ScoreText.setFillColor(sf::Color::White);
	player1ScoreText.setPosition({ 100, 20 });

	std::string test1 = ("Player 2: " + std::to_string(player2Score));
	player2ScoreText.setFont(font);
	player2ScoreText.setString(test1);
	player2ScoreText.setCharacterSize(24);
	player2ScoreText.setFillColor(sf::Color::White);
	player2ScoreText.setPosition({ 600, 20 });

//clear window with black color (need to clear before drawing)
	window.clear(sf::Color::Black);
	//Draw stuff
	window.draw(player1);
	window.draw(player2);
	window.draw(ball);
	window.draw(player1ScoreText);
	window.draw(player2ScoreText);
	//end the current frame
	window.display();

}
void Game::initText()
{
	sf::Font font;
	if (!font.openFromFile("C:\dev\Project3\Pong\Roboto_Condensed - Black.ttf")) {
		std::cerr << "Error loading font!" << std::endl;
	}

	int testing = 1;
	// Set font before using sf::Text
	sf::Text player1ScoreText(font);
	sf::Text player2ScoreText(font);
	player1ScoreText;
	// Initialize text properties
	player1ScoreText.setString("20");
	player1ScoreText.setCharacterSize(124);
	player1ScoreText.setFillColor(sf::Color::White);
	player1ScoreText.setPosition({ 300, 20 });

	player2ScoreText.setFont(font);
	player2ScoreText.setString("10");
	player2ScoreText.setCharacterSize(124);
	player2ScoreText.setFillColor(sf::Color::White);
	player2ScoreText.setPosition({ 500, 20 });

}
void Game::initPaddles() {
	float window_height = window.getSize().y;
	float window_width = window.getSize().x;
	player_speed = sf::Vector2f(0.f, 5.f );
	player1.setSize({ 10.f, 100.f });
	player1.setFillColor(sf::Color(100, 250, 50));
	player1.setPosition({ 50, window_height / 2 - 30 });
	player2.setSize({ 10.f, 100.f });
	player2.setFillColor(sf::Color(100, 250, 50));
	player2.setPosition({ window_width - 50, window_height /2 - 30 });

}

void Game::initBall()
{
	float window_height = window.getSize().y - 30 ;
	float window_width = window.getSize().x -  50;
	ball.setRadius(30.f);
	ball.setFillColor(sf::Color(255, 255, 255));
	ball.setPosition({ window_width / 2, window_height / 2 });
	ball_velocity.x = (rand() % 2 == 0) ? 4.0f : -4.0f;
	ball_velocity.y = (rand() % 2 == 0) ? 4.0f : -4.0f;
	

}

void Game::resetBall()
{	
	ball.setPosition({ window_width / 2 - ball.getRadius(), window_height / 2 - ball.getRadius() });
	ball_velocity.x = 0;
	ball_velocity.y = 0;
	sf::sleep(sf::seconds((2)));
	ball_velocity.x = (rand() % 2 == 0) ? 4.0f : -4.0f;
	ball_velocity.y = (rand() % 2 == 0) ? 4.0f : -4.0f;
	
}

void Game::movePlayer(sf::RectangleShape& player, sf::Keyboard::Key key, std::string direction)
{
	
	if (sf::Keyboard::isKeyPressed(key) && player.getPosition().y != 0 && direction == "up")
	{
		player.move({ player_speed.x, -player_speed.y });

	}
	if (sf::Keyboard::isKeyPressed(key) && player.getPosition().y != window_height - player.getSize().y && direction == "down")
	{
		player.move({ player_speed.x, player_speed.y });
	}
	

}



// maybe change this file to game.cpp and put main() in new file main.cpp?************
int main()
{	
	Game game;
	game.run();
}   





