#include "HitEffect.h"

void HitEffect::Initialize(uint32_t texture, uint32_t anim, uint32_t animMax, 
	uint32_t flame, uint32_t flameMax, Vector2 pos, Vector2 size)
{
	texture_ = texture;
	anim_ = anim;
	animMax_ = animMax;
	flame_ = flame;
	flameMax_ = flameMax;
	pos_ = pos;
	size_ = size;
}

void HitEffect::Update()
{
	flame_++;
	if (flame_ >= flameMax_) {
		anim_++;
		flame_ = 0;
	}
}

void HitEffect::Draw()
{
	Novice::DrawQuad(int(pos_.x), int(pos_.y), int(pos_.x + size_.x), int(pos_.y), 
		int(pos_.x), int(pos_.y + size_.y), int(pos_.x + size_.x), int(pos_.y + size_.y), 
		int(anim_ * size_.x), 0, int(size_.x), int(size_.y), texture_, WHITE);
}
