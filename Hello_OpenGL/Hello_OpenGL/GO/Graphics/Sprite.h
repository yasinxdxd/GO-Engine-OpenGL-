#pragma once
#ifndef GO_SPRITE_H
#define GO_SPRITE_H

#include "Graphics/Renderable.h"
#include "Graphics/Texture.h"


namespace go
{

	class Sprite : public go::Renderable
	{
	public:
		Sprite();
		Sprite(go::Texture& texture);


		void setTexture(Texture& texture);
		void setPosition(Vec2f) override;
		void setSize(Vec2f) override;
		Vec2f getPosition() override;
		Vec2f getSize() override;
	
	
	private:
		virtual void draw(go::Vec2ui windowSize) override;

	private:
		Texture* m_Texture;
	};

}


#endif //GO_SPRITE_H