#ifndef _MENU_H_
#define _MENU_H_

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "ShowAlgorithm.h"
#include "Tickbox.h"
#include "InputField.h"
#include "InfoWindow.h"

class Menu : public sf::Drawable
{
public:
	Menu(sf::Font& font);
	void updateMenu(sf::RenderWindow& window, sf::Event event);
	std::vector<int> getSortings();
	bool isStarted(sf::RenderWindow& window);
	bool isExited(sf::RenderWindow& window);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	Button m_StartButton;
	Button m_ExitButton;

	sf::Text m_textMenu;
	sf::Text m_textBubble;
	sf::Text m_textInsertion;
	sf::Text m_textSelection;
	sf::Text m_textQuick;
	sf::Text m_textMerge;

	TickBox m_tickBoxB;
	TickBox m_tickBoxI;
	TickBox m_tickBoxS;
	TickBox m_tickBoxQ;
	TickBox m_tickBoxM;

	mutable InfoWindow m_infoBubble;
	mutable InfoWindow m_infoInsertion;
	mutable InfoWindow m_infoSelection;
	mutable InfoWindow m_infoQuick;
	mutable InfoWindow m_infoMerge;

	InputField m_inputDataSizeBubble;
	InputField m_inputDataSizeInsertion;
	InputField m_inputDataSizeSelection;
	InputField m_inputDataSizeQuick;
	InputField m_inputDataSizeMerge;
};

#endif