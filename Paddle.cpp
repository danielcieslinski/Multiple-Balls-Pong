#include "Paddle.h"
#include "Mechanics.h"


Paddle::Paddle(bool left) {

	sf::Vector2f size_rec(width, height);
	shape.setSize(size_rec);
	shape.setFillColor(sf::Color::Black);

	if (left == 1){
	    position.x = pixels_from_wall;
	    position.y = HEIGHT / 2 - height / 2;
	}
	else {
        position.x = WIDTH - pixels_from_wall- width;
        position.y = HEIGHT / 2 - height / 2;
    }
    shape.setPosition(position.x, position.y);


}
void Paddle::move_down() {

    int counter = 0;

    while ( position.y + 1 < max_down and counter < move_pixels){
        position.y += 1;
        counter++;}

    shape.setPosition(position.x, position.y);


}

void Paddle::move_up() {

    int counter = 0;

    while ( position.y - 1 >= 0 and counter < move_pixels ){
        position.y -= 1;
        counter++;}

    shape.setPosition(position.x, position.y);
}