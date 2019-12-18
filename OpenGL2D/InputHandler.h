#pragma once

class Renderer;

class InputHandler
{
	static InputHandler* m_pInputHandler;
	Renderer& m_renderer;
public:
	bool menu = true;
	bool game = false;
	bool finished = false;
	int level = 0;
	InputHandler(Renderer& renderer);
	~InputHandler();

	void initialize();

	void processKeyboard(unsigned char key, int x, int y);
	void processKeyboard2(unsigned char key, int x, int y);
	static void __processKeyboard(unsigned char key, int x, int y);
	static void __processKeyboard2(unsigned char key, int x, int y);
};

