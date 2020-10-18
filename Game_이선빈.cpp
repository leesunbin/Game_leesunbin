#include <iostream>
#include <bangtal>

using namespace bangtal;
using namespace std;

class Item : public Object
{
public:
	static ObjectPtr create(const string& image, ScenePtr scene = nullptr,
		int x = 0, int y = 0, bool shown = true) {
		auto object = ObjectPtr(new Item(image, scene, x, y, shown));
		Object::add(object);
		return object;
	}
protected:
	Item(const string& image, ScenePtr scene, int x, int y, bool shown)
		:Object(image, scene, x,y, shown){}

public:
	virtual bool onMouse(int x, int y, MouseAction action) {
		if (!Object::onMouse(x, y, action)) {
			pick();
		}
		return true;
	}
};

void main() { 

	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto scene_start = Scene::create("start page", "Images/시작페이지.png");
	auto scene_main = Scene::create("main page", "Images/빈페이지.png");

	auto human = Object::create("Images/캐릭터.png ", scene_main, 0, 500);

	auto upButton = Object::create("Images/up.png");
	auto downButton = Object::create("Images/down.png");
	auto leftButton = Object::create("Images/left.png");


	startGame(scene_start);
}