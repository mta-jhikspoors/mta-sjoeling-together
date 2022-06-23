#include "TitleRenderer.h"
#include "File.h"
#include "Main.h"
#include <cmath>
#include "Voronoi.h"
#include "glm/vec2.hpp"
#include "glm/geometric.hpp"

#define FIRST_START_TIME			500
#define SHORT_START_TIME			500
#define TITLE_FADE_DURATION			4000
#define CREDIT_START_TIME			2000	// From title start time
#define CREDIT_FADE_IN_DURATION		500
#define CREDIT_FADE_SHOW_DURATION	2000
#define CREDIT_FADE_OUT_DURATION	500
#define CREDIT_TEXT_COLOR			Color(120, 120, 120)
#define KEY_TEXT_COLOR				Color(200, 200, 200)
#define TITLE_COLOR					Color(255, 25, 0)
#define VORONOI_COLOR				Color(255, 25, 0)
#define SPLASH_FADE_DISTANCE		3

// List of credits to display below the title
vector<String> CREDITS { "PROVIDED BY SKILLSLAB" };

TitleRenderer::TitleRenderer() :
	image(Main::GetResources().GetImage("title.dds")),
	pressbuttontext("PRESS ANY BUTTON TO START", Main::GetResources().Smallest(), HorizontalAlign::Center, VerticalAlign::Bottom),
	creditstext(Main::GetResources().Smallest(), HorizontalAlign::Center, VerticalAlign::Bottom),
	showkeyinfo(false),
	asbackground(false),
	creditindex(0),
	playtitlemusic(nullptr),
	temporalditheroffset(0),
	keyflashstate(false)
{
	voronoi.Clear(BLACK);
}

void TitleRenderer::BeginFirstStart()
{
	titlestarttime = Clock::now() + ch::milliseconds(FIRST_START_TIME);
	creditstarttime = titlestarttime + ch::milliseconds(CREDIT_START_TIME);
	laststeptime = Clock::now() + ch::milliseconds(FIRST_START_TIME);
	showkeyinfo = false;
	creditindex = 0;
	creditstext.SetText(CREDITS[creditindex]);
	SetupSplashes();
}

void TitleRenderer::BeginReturnToTitle()
{
	titlestarttime = Clock::now() + ch::milliseconds(SHORT_START_TIME);
	creditstarttime = titlestarttime + ch::milliseconds(CREDIT_START_TIME);
	laststeptime = Clock::now() + ch::milliseconds(SHORT_START_TIME);
	showkeyinfo = false;
	creditindex = 0;
	creditstext.SetText(CREDITS[creditindex]);
	SetupSplashes();
}

void TitleRenderer::SetupSplashes()
{
	// The curve which the splash must progress along
	splashdistance = tweeny::from(0.0f).to(64.0f).during(TITLE_FADE_DURATION).via(easing::cubicOut);

	// Pick splash points
	Rect sr1 = Rect(11, 6, 36, 21);
	Rect sr2 = Rect(48, 4, 35, 22);
	Rect sr3 = Rect(83, 2, 30, 20);
	splashpoints.clear();
	splashpoints.push_back(Point(Random(sr1.x, sr1.x + sr1.width), Random(sr1.y, sr1.y + sr1.height)));
	splashpoints.push_back(Point(Random(sr2.x, sr2.x + sr2.width), Random(sr2.y, sr2.y + sr2.height)));
	splashpoints.push_back(Point(Random(sr3.x, sr3.x + sr3.width), Random(sr3.y, sr3.y + sr3.height)));
}

void TitleRenderer::Render(Canvas& canvas)
{
	TimePoint now = Clock::now();
	if(now < titlestarttime)
		return;

	// Play/repeat the title music
	if(playtitlemusic)
		playtitlemusic();

	// Render the voronoi
	float timesec = static_cast<float>(ch::ToMilliseconds(now - titlestarttime)) / 1000.0f;
	temporalditheroffset++;
	for(int y = 0; y < DISPLAY_HEIGHT; y++)
	{
		for(int x = 0; x < DISPLAY_WIDTH; x++)
		{
			// Don't redraw every pixel every frame, that is too expensive.
			if(((x ^ y ^ temporalditheroffset) & 0x03) == 0)
			{
				byte v = Voronoi::PixelShader(x, DISPLAY_HEIGHT - y, timesec);
				Color c = VORONOI_COLOR;
				c.ModulateRGB(v);
				voronoi.SetPixel(x, y, c);
			}
		}
	}

	// Time in milliseconds since the start of animation
	uint64 t = ch::ToMilliseconds(now - titlestarttime);
	int dt = static_cast<int>(ch::ToMilliseconds(now - laststeptime));
	laststeptime = now;
	float splashdistancevalue = splashdistance.step(dt);

	// Draw the title screen
	for(int y = 0; y < DISPLAY_HEIGHT; y++)
	{
		for(int x = 0; x < DISPLAY_WIDTH; x++)
		{
			Color v = voronoi.GetPixel(x, y);
			Color i = image.GetColor(x, y);

			float d = 0.5f;

			v.r = round(v.r * d);
			v.g = round(v.g * d);
			v.b = round(v.b * d);

			if (i.r == 0 && i.g == 0 && i.b == 0) canvas.SetPixel(x, y, v); 
			else canvas.SetPixel(x, y, i);
		}
	}

	if(asbackground)
	{
		// Reset the credits time just in case we go back to the title screen
		creditstarttime = Clock::now();
	}
	else if(Clock::now() >= creditstarttime)
	{
		if(creditindex < CREDITS.size())
		{
			t = ch::ToMilliseconds(Clock::now() - creditstarttime);

			// Calculate translucency at this time
			float credits_alpha;
			if(t < CREDIT_FADE_IN_DURATION)
				credits_alpha = (static_cast<float>(t) / CREDIT_FADE_IN_DURATION) * 255.0f;
			else if(t < (CREDIT_FADE_IN_DURATION + CREDIT_FADE_SHOW_DURATION))
				credits_alpha = 255.0f;
			else
				credits_alpha = 255.0f - (static_cast<float>(t - CREDIT_FADE_IN_DURATION - CREDIT_FADE_SHOW_DURATION) / CREDIT_FADE_OUT_DURATION) * 255.0f;

			// Show credits
			Color c = CREDIT_TEXT_COLOR;
			Color co = BLACK;
			c.a = static_cast<byte>(std::clamp(credits_alpha, 0.0f, 255.0f));
			co.a = c.a;
			creditstext.DrawOutlineBlend(canvas, Point(64, 34), 1, co);
			creditstext.DrawBlend(canvas, Point(64, 34), c);

			// Next credits?
			if(t >= (CREDIT_FADE_IN_DURATION + CREDIT_FADE_SHOW_DURATION + CREDIT_FADE_OUT_DURATION))
			{
				creditindex++;
				if(creditindex < CREDITS.size())
					creditstext.SetText(CREDITS[creditindex]);
				creditstarttime = Clock::now();
			}
		}
		else
		{
			// Flash info
			if(keyflashstate)
			{
				pressbuttontext.DrawOutlineMask(canvas, Point(64, 34), 1, BLACK);
				pressbuttontext.DrawMask(canvas, Point(64, 34), KEY_TEXT_COLOR);
			}
		}
	}
}
