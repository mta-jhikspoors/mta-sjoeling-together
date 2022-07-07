#pragma once
#include "Tools.h"
#include "IRenderer.h"
#include "Text.h"
#include "GameDefines.h"
#include "ParticleOverlayRenderer.h"

class MultiplayerHUDRenderer final : public virtual IRenderer
{
private:

	// Text to render
	Text player1score;
	Text player2score;
	Text pucks;
	Text player1label;
	Text player2label;
	Text puckslabel;
	Text pointtext[8];
	TweenXY pointprogress[8];
	vector<int> points;
	const Image& texture;
	std::array<Text, GAME_GATES> gatenumbers;
	std::array<bool, GAME_GATES> gaterequired;
	ParticleEffect gateparticles;
	TimePoint fadeoutstart;
	TimePoint laststeptime;
	TimePoint scoresettime;

	// Methods
	void DrawGateLine(Canvas& canvas, int startx, int endx, Color color);
	void SpawnGateEffectBig(int startx, int endx);
	void SpawnGateEffectSmall(int startx, int endx);
	void SpawnGateParticle(int x, int y, int centerx, Color color);
	void FloatPoints(String text, int x, int y);

public:

	MultiplayerHUDRenderer(ParticleOverlayRenderer& particlesoverlay);

	virtual void Render(Canvas& canvas) override;
	void SetScorePlayer1(int newscore) { player1score.SetText(String::From(newscore)); }
	void SetScorePlayer2(int newscore) { player2score.SetText(String::From(newscore)); }
	void SetPucks(int numpucks) { pucks.SetText(String::From(numpucks)); }
	void SetRequiredGates(bool* gates);
	void Show() { fadeoutstart = TimePoint(); }
	void Hide() { fadeoutstart = Clock::now(); }
	void ScoreRequiredGate(int gate);
	void ScoreGate(int gate);
	void ScoreSet();
};
