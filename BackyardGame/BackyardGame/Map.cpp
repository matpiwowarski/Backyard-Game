#include "Map.h"

void Map::LoadBackyardMap()
{
	const int map[] =
	{
		0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,
		0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,
		30,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	30,	0,	0,	30,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,
		0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	1,	0,	0,	1,	0,	0,	0,	0,	0,	30,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,
		2,	4,	2,	4,	2,	4,	8,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		9,	10, 11, 12, 9, 19,	15, 0,	0,	0, 0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	30,	0,	0,	30,
		0,	0,	0,	0,	0,	6,	15,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	0,	0,	30,	0,	6,	14,	0,	0,	0, 0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	30,	0,
		0,	30,	0,	0,	0,	6,	15,	0,	30,	0,	0,	0,	6,	15,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	0,	0,	0,	0,	6,	15,	0,	0,	1,	0,	30,	6,	15,	0,	0,	1,	0,	0,	0,	0,	0,	1,	0,	0,
		0,	0,	30,	0,	0,	6,	25,	4,	2,	4,	2,	4,	25,	25,	4,	2,	4,	4,	2,	2,	2,	2,	4,	4,	2,
		0,	0,	0,	0,	0,	18,	9,	10,	11,	12,	12,	11,	12,	10,	12,	11,	12,	11,	12,	10,	25,	25,	11,	12,	10,
		0,	30,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	6,	15,	0,	0,	30,
		0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	30,	0,	6,	14,	0,	0,	0,
		0,	0,	30,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	6,	14,	0,	30,	0,
		30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	6,	15,	0,	0,  0,
		0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	6,	15,	0,	0,	0,
		27,	26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27
	};
	if (!this->load(2, "../Assets/backyardmap.png", sf::Vector2u(16, 16), map, 25, 19))    //path to file, dimension of one tile, table with map, width, height
	{
		std::cout << " The map hasn't been loaded correctly";
	}
}

void Map::LoadGardenMap()
{
	const int map[] =
	{
		0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,  0,   0,  0,	0,	0,	30,	0,	0,	0,	0,	30,	0,	0,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31, 31,	31,	31,	31,	31,	33,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	33,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	33,	0,
		30,	32,	31,	31,	31,	31, 31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	33,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	33,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	33,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31, 31, 31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	33,	0,
		0,	32,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31,	31, 31,31,	31,	31,	31,31,	31,	31,	31,	31,	33,	0,
		0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	6,	25,	15,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		2,	2,	4,  2,	4,	4,	4,	2,	4,	4,	2,	25,	25,	14,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		11,	10,	11, 11,	10,	10,	11,	11,	10,	10,	11,	11,	10,	23,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	30,	0,	0,
		0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,
		0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,
		0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	30,	0,	0,	0,	0,
	    27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27, 26, 27
	};
	if (!this->load(2, "../Assets/backyardmap.png", sf::Vector2u(16, 16), map, 25, 19))    //path to file, dimension of one tile, table with map, width, height
	{
		std::cout << " The map hasn't been loaded correctly";
	}
}

void Map::LoadHouseMap()
{
	const int map[] =
	{
		19,	4,	5,	6,	7,	8,	9,	10,	11,	5,	6,	5,	6,	7,	9,	11,	9,	11,	9,	8,	5,	6,	11,	11,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	16,	18,
		19,	0,	12,	13,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	12,	13,	0,	0,	0,	18,
		19,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	1,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	1,	2,	1,	0,	0,	0,	0,	13,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	16,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	1,	2,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	2,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	2,	0,	0,	0,	0,	0,	0,	0,	0,	0,	12,	0,	18,
		19,	0,	0,	0,	0,	1,	2,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	1,	0,	0,	13,	0,	18,
		19,	15,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
		19,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	23,	24,	25,	0,	0,	0,	0,	0,	0,	0,	0,	0,	18,
	};
	if (!this->load(1, "../Assets/housemap.png", sf::Vector2u(32, 32), map, 25, 19))    //path to file, dimension of one tile, table with map, width, height
	{
		std::cout << " The map hasn't been loaded correctly";
	}
}

Map::Map()
{

}

Map::~Map()
{
}

bool Map::load(int scale, const std::string & tileset, sf::Vector2u tileSize, const int * tiles, unsigned int width, unsigned int height)
{
	// load the tileset texture
	if (!m_tileset.loadFromFile(tileset))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (unsigned int i = 0; i < width; ++i)
		for (unsigned int j = 0; j < height; ++j)
		{
			// get the current tile number
			int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
			int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x * scale, j * tileSize.y * scale);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x * scale, j * tileSize.y * scale);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x * scale, (j + 1) * tileSize.y * scale);
			quad[3].position = sf::Vector2f(i * tileSize.x * scale, (j + 1) * tileSize.y * scale);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
		}

	return true;
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}

void Map::update(const double & dt)
{
	// here we change the details of the map or the entire map
}

void Map::render(sf::RenderTarget * target)
{
	target->draw(*this);
}


