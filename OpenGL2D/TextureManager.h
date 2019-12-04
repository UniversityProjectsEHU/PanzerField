#pragma once
#include <unordered_map>
using namespace std;

class TextureObject
{
	unsigned int m_type, m_textureId;

public:
	TextureObject();
	TextureObject(int type, unsigned int textureId);
	~TextureObject();

	void set();
	unsigned int getTextureId() { return m_textureId; }
	void setTextureId(unsigned int id) { m_textureId = id; }
	void setType(unsigned int type) { m_type = type; }
};

class TextureManager
{
	static TextureManager* m_pInstance;

	unordered_map<string, TextureObject> m_textureObjects;

	bool m_bVerbose = false;
public:
	TextureManager();
	virtual ~TextureManager();

	void setVerbose(bool verbose) { m_bVerbose = verbose; }
	bool getVerbose() { return m_bVerbose; }

	//Used from any client
	void useTexture(string filename);
	unsigned int create2DTexture(string filename);
	unsigned int create3DTexture(string filename, int numSubImagesX, int numSubImagesY, bool loop);

	static TextureManager* getInstance() { return m_pInstance; }
};
