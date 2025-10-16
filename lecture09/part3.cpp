#include <iostream>
#include <vector>

class HitBox {
public:
    double x, y, width, height;
};

class Entity {
protected:
    double x, y, z;
    HitBox hitbox;
public:
    virtual void update() {};
    virtual void render() {};
};

class Player : public Entity {
    double hitpoints = 100;
public:
    void damage(double hp) {
        hitpoints -= hp;
    }
    
    void update() override {
        std::cout << "Updating Player!" << std::endl;
    }

    void render() override {
        std::cout << "Rendering Player!" << std::endl;
    }
};

class Tree : public Entity {
public:
    void update() override {
        std::cout << "Updating Tree!" << std::endl;
    }

    void render() override {
        std::cout << "Rendering Tree!" << std::endl;
    }
};

class Projectile : public Entity {
    double vx, vy, vz;
public:
    void update() override {
        std::cout << "Updating Projectile!" << std::endl;
    }

    void render() override {
        std::cout << "Rendering Projectile!" << std::endl;
    }
};


int main() {
    Player player;
    Tree tree;
    Projectile proj;
    
	std::vector<Entity*> entities { &player, &tree, &proj };
	while (true) {
        std::cout << "Rendering frame..." << std::endl;
		for (auto& entity : entities) {
			entity->update();
			entity->render();
		}
	}
    return 0;    
} 