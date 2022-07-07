#pragma once
#include "IState.h"
#include "IMessageHandler.h"
#include "MenuItemRenderer.h"
#include "HorizontalMenuRenderer.h"
#include "Sound.h"

class MenuStateMachine;

enum class AudioModeItems
{
	Classic,
	Meme
};

class AudioModeState : public virtual IState, public virtual IMessageHandler
{
private:

	MenuStateMachine* statemachine;
	HorizontalMenuRenderer horizontalrenderer;
	MenuItemRenderer classicitem;
	MenuItemRenderer memeitem;
	vector<AudioModeItems> itemslist;
	const Sound& woosh;
	const Sound& cancel;
	const Sound& selectsound;
	const Sound& editsound;
	int currentitem;

	// Methods
	void ActivateItem(int index);

public:

	AudioModeState(MenuStateMachine* _statemachine);

	virtual void Enter() override final;
	virtual void Leave() override final;
	virtual void Update() override final;
	virtual bool HandleMessage(const IOModule_IOMessage& msg) override;
};
