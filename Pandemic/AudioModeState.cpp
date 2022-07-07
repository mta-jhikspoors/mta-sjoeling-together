#include "AudioModeState.h"
#include "MenuStateMachine.h"
#include "Main.h"

#define	VALUE_SPACING	18

AudioModeState::AudioModeState(MenuStateMachine* _statemachine) :
	statemachine(_statemachine),
	classicitem("CLASSIC AUDIO"),
	memeitem("MEME AUDIO"),
	woosh(Main::GetResources().GetSound("woosh1.wav")),
	cancel(Main::GetResources().GetSound("cancel.wav")),
	selectsound(Main::GetResources().GetSound("select.wav")),
	editsound(Main::GetResources().GetSound("change.wav")),
	currentitem(0)
{
}

void AudioModeState::Enter()
{
	// Set up the items which we show
	horizontalrenderer.Clear();
	itemslist.clear();
	horizontalrenderer.AddItem(&classicitem);
	horizontalrenderer.AddItem(&memeitem);
	itemslist.push_back(AudioModeItems::Classic);
	itemslist.push_back(AudioModeItems::Meme);

	horizontalrenderer.SetAtIndex(0);
	horizontalrenderer.ShowArrows(true);
	currentitem = 0;

	statemachine->GetVerticalRenderer()->AddItem(&horizontalrenderer);

	Main::GetButtons().SetAllMenuLEDsOn();
}

void AudioModeState::Leave()
{
	statemachine->GetVerticalRenderer()->RemoveItem(&horizontalrenderer);

	// Turn all button LEDs off
	Main::GetButtons().SetAllMenuLEDsOff();
}

void AudioModeState::Update()
{
}

bool AudioModeState::HandleMessage(const IOModule_IOMessage& msg)
{
	switch (msg.which_Content)
	{
	case IOModule_IOMessage_LeftButtonPressed_tag:
		if (currentitem == 0)
			currentitem = static_cast<int>(itemslist.size()) - 1;
		else
			currentitem--;
		horizontalrenderer.MoveToIndex(currentitem, false);
		woosh.Play();
		return true;

	case IOModule_IOMessage_RightButtonPressed_tag:
		if (currentitem == static_cast<int>(itemslist.size()) - 1)
			currentitem = 0;
		else
			currentitem++;
		horizontalrenderer.MoveToIndex(currentitem, true);
		woosh.Play();
		return true;

	case IOModule_IOMessage_AcceptButtonPressed_tag:
		ActivateItem(currentitem);
		return true;

	case IOModule_IOMessage_CancelButtonPressed_tag:
		statemachine->ChangeState(statemachine->GetOptionsState());
		cancel.Play();
		return true;

	default:
		return false;
	}
}

void AudioModeState::ActivateItem(int index)
{
	// Change the value
	switch (itemslist[index])
	{
	case AudioModeItems::Classic:
		selectsound.Play();
		Main::GetResources().SetAudioPrefix("");
		statemachine->ChangeState(statemachine->GetOptionsState());
		break;

	case AudioModeItems::Meme:
		selectsound.Play();
		Main::GetResources().SetAudioPrefix("meme_");
		statemachine->ChangeState(statemachine->GetOptionsState());
		break;

	default:
		NOT_IMPLEMENTED;
	}
}
