#pragma once
#include <atomic>
#include "sprite.h"
#include "Bullet.h"
#include "Tank.h"

class Server
{
public:
	Server();
	~Server();
};
void server_main(std::atomic_bool* should_run);

