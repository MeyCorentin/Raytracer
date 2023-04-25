/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-arcade-nathan.donat-filliod
** File description:
** sfml
*/

#include "sfml/sfml.hpp"

LibSfml::LibSfml()
{
}

extern "C" std::unique_ptr<LibSfml> allocator()
{
	return std::unique_ptr<LibSfml>(new LibSfml());
}

void LibSfml::createShapes()
{
	fruit = sf::CircleShape(12);
	wall = sf::CircleShape(14, 4);
	player = sf::CircleShape(13, 4);
	floor = sf::CircleShape(13, 4);
	head = sf::CircleShape(12, 7);
}

void LibSfml::setShapes()
{
	fruit.setFillColor(sf::Color::Transparent);
	fruit.setOutlineThickness(1);
	fruit.rotate(45);

	wall.setFillColor(sf::Color(128,128,128));
	wall.setOutlineThickness(1);
	wall.setOutlineColor(sf::Color::Black);
	wall.rotate(45);

	player.setFillColor(sf::Color::Transparent);
	player.setOutlineThickness(1);
	player.rotate(45);

	floor.setFillColor(sf::Color::Transparent);
	floor.rotate(45);

	head.setFillColor(sf::Color::Transparent);
	head.setOutlineThickness(1);
	head.rotate(45);
}



void LibSfml::createWindow(int width, int height)
{
	createShapes();
	setShapes();
	win.create(sf::VideoMode(width, height), "SFML window");
}

void LibSfml::closeWindow()
{
	win.close();
};
void LibSfml::event()
{
	if (ev.type == sf::Event::Closed) {
		closeWindow();
		exit(0);
	}
}

void LibSfml::refreshWindow()
{
	win.clear();
}

int LibSfml::detectInput()
{
	while (win.pollEvent(ev)) {
		event();
		if (ev.type == sf::Event::KeyPressed) {
    		if (ev.key.code == sf::Keyboard::Escape) return 27;
			if (ev.key.code == sf::Keyboard::Return) return 10;
			if (ev.key.code == sf::Keyboard::Space) boost = 30;
			if (ev.key.code == sf::Keyboard::Q || ev.key.code == sf::Keyboard::Left) return 'q';
			if (ev.key.code == sf::Keyboard::Z || ev.key.code == sf::Keyboard::Up) return 'z';
			if (ev.key.code == sf::Keyboard::D || ev.key.code == sf::Keyboard::Right) return 'd';
			if (ev.key.code == sf::Keyboard::S || ev.key.code == sf::Keyboard::Down) return 's';
		}
	}
	return 0;
};

std::tuple<int, int> LibSfml::detectMouse()
{
	std::cout << "LibSfml" << std::endl;
    return std::tuple(0,0);
}

void LibSfml::setScore(int score)
{
	_score.setFont(font);
	_score.setString("Score: " + std::to_string(score));
	_score.setFillColor(sf::Color::White);
}
void LibSfml::setLevel(int level)
{
	_lvl.setFont(font);
	_lvl.setString("Level: " + std::to_string(level));
	_lvl.setFillColor(sf::Color::White);
	_lvl.setPosition(160, 0);
}
void LibSfml::displayGame(std::vector<std::string>map)
{
	win.draw(_score);
	win.draw(_lvl);
	for (size_t i = 0, wally = 40, wallx = 20; i < map.size(); i++, wally += 20, wallx = 20) {
		for (size_t n = 0; n < map[i].size(); n++) {
			switch (map[i][n]) {
				case 'x':
					player.setOutlineColor(sf::Color(rand()%255, rand()%255, rand()%255));
					win.draw(player);
					player.setPosition(wallx, wally);
					wallx += 20;
					break;
				case 'O':
					head.setOutlineColor(sf::Color(rand()%255, rand()%255, rand()%255));
					win.draw(head);
					head.setPosition(wallx, wally);
					wallx += 20;
					break;
				case 'o':
					fruit.setOutlineColor(sf::Color(rand()%255, rand()%255, rand()%255));
					win.draw(fruit);
					fruit.setPosition(wallx, wally);
					wallx += 20;
					break;
				case '#':
					win.draw(wall);
					wall.setPosition(wallx, wally);
					wallx += 20;
					break;
				case ' ':
					win.draw(floor);
					floor.setPosition(wallx, wally);
					wallx += 20;
					break;
			}
		}
	}
}

void LibSfml::displayMenu(std::vector<std::string>map)
{
		_text.setFont(font);
		for (size_t i = 0, y = 50; i < map.size(); i++, y += 30) {
			_text.setString(map[i]);
			_text.setFillColor(sf::Color::White);
			_text.setPosition(0,y);
			win.draw(_text);
		}
}

void LibSfml::displayMap(std::vector<std::string> map, int score, int status, int level)
{
	font.loadFromFile("./src/fonts/Monoid.ttf");
	win.clear();
	if (status == 1) {
		setScore(score);
		setLevel(level);
		displayGame(map);
	}
	if (status == 0)
		displayMenu(map);
	win.display();
};
