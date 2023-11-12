#include "Menu.h"

Menu::Menu(sf::Font& font)
{
	sf::VideoMode screen = sf::VideoMode::getFullscreenModes()[0];
	m_textMenu.setFont(font);
	m_textMenu.setString("Menu");
	m_textMenu.setCharacterSize(150);
	m_textMenu.setStyle(sf::Text::Style::Bold);
	m_textMenu.setPosition((screen.width / 2) - m_textMenu.getGlobalBounds().width / 2, 0);

	//TickBoxes
	m_tickBoxB.setSize(100);
	m_tickBoxB.setPosition(sf::Vector2f(70, m_textMenu.getGlobalBounds().top + m_textMenu.getGlobalBounds().height + 50));

	m_tickBoxI.setSize(100);
	m_tickBoxI.setPosition(sf::Vector2f(70, m_tickBoxB.getPosition().y + m_tickBoxB.getSize() + 50));

	m_tickBoxS.setSize(100);
	m_tickBoxS.setPosition(sf::Vector2f(70, m_tickBoxI.getPosition().y + m_tickBoxI.getSize() + 50));

	m_tickBoxQ.setSize(100);
	m_tickBoxQ.setPosition(sf::Vector2f(70, m_tickBoxS.getPosition().y + m_tickBoxS.getSize() + 50));

	m_tickBoxM.setSize(100);
	m_tickBoxM.setPosition(sf::Vector2f(70, m_tickBoxQ.getPosition().y + m_tickBoxQ.getSize() + 50));


	//Names
	m_textBubble.setFont(font);
	m_textBubble.setString("Bubble sort");
	m_textBubble.setCharacterSize(100);
	m_textBubble.setOrigin(m_textBubble.getGlobalBounds().left, m_textBubble.getGlobalBounds().top);
	m_textBubble.setScale(1, float(m_tickBoxB.getSize()) / float(m_textBubble.getGlobalBounds().height));
	m_textBubble.setPosition((screen.width / 2) - (m_textBubble.getGlobalBounds().width / 2) - 100, m_tickBoxB.getPosition().y);

	m_textInsertion.setFont(font);
	m_textInsertion.setString("Insertion sort");
	m_textInsertion.setCharacterSize(100);
	m_textInsertion.setOrigin(m_textInsertion.getGlobalBounds().left, m_textInsertion.getGlobalBounds().top);
	m_textInsertion.setScale(1, float(m_tickBoxI.getSize()) / float(m_textInsertion.getGlobalBounds().height));
	m_textInsertion.setPosition((screen.width / 2) - (m_textInsertion.getGlobalBounds().width / 2) - 100, m_tickBoxI.getPosition().y);

	m_textSelection.setFont(font);
	m_textSelection.setString("Selection sort");
	m_textSelection.setCharacterSize(100);
	m_textSelection.setOrigin(m_textSelection.getGlobalBounds().left, m_textSelection.getGlobalBounds().top);
	m_textSelection.setScale(1, float(m_tickBoxS.getSize()) / float(m_textSelection.getGlobalBounds().height));
	m_textSelection.setPosition((screen.width / 2) - (m_textSelection.getGlobalBounds().width / 2) - 100, m_tickBoxS.getPosition().y);

	m_textQuick.setFont(font);
	m_textQuick.setString("Quick sort");
	m_textQuick.setCharacterSize(100);
	m_textQuick.setOrigin(m_textQuick.getGlobalBounds().left, m_textQuick.getGlobalBounds().top);
	m_textQuick.setScale(1, float(m_tickBoxQ.getSize()) / float(m_textQuick.getGlobalBounds().height));
	m_textQuick.setPosition((screen.width / 2) - (m_textQuick.getGlobalBounds().width / 2) - 100, m_tickBoxQ.getPosition().y);

	m_textMerge.setFont(font);
	m_textMerge.setString("Merge sort");
	m_textMerge.setCharacterSize(100);
	m_textMerge.setOrigin(m_textMerge.getGlobalBounds().left, m_textMerge.getGlobalBounds().top);
	m_textMerge.setScale(1, float(m_tickBoxM.getSize()) / float(m_textMerge.getGlobalBounds().height));
	m_textMerge.setPosition((screen.width / 2) - (m_textMerge.getGlobalBounds().width / 2) - 100, m_tickBoxM.getPosition().y);

	//InfoWindow
	m_infoBubble.setPosition(sf::Vector2f(m_textBubble.getPosition().x + (m_textBubble.getGlobalBounds().width) + 20, m_tickBoxB.getPosition().y));
	m_infoBubble.setSize(m_tickBoxB.getSize());
	m_infoBubble.setCharacterSize(10);
	m_infoBubble.setTextPositionRelativeCursor(InfoWindow::LeftDown);
	m_infoBubble.setText("Texts/BubbleSort.txt", font);

	m_infoInsertion.setPosition(sf::Vector2f(m_textInsertion.getPosition().x + (m_textInsertion.getGlobalBounds().width) + 20, m_tickBoxI.getPosition().y));
	m_infoInsertion.setSize(m_tickBoxI.getSize());
	m_infoInsertion.setCharacterSize(10);
	m_infoInsertion.setTextPositionRelativeCursor(InfoWindow::LeftDown);
	m_infoInsertion.setText("Texts/InsertionSort.txt", font);

	m_infoSelection.setPosition(sf::Vector2f(m_textSelection.getPosition().x + (m_textSelection.getGlobalBounds().width) + 20, m_tickBoxS.getPosition().y));
	m_infoSelection.setSize(m_tickBoxS.getSize());
	m_infoSelection.setCharacterSize(10);
	m_infoSelection.setTextPositionRelativeCursor(InfoWindow::LeftDown);
	m_infoSelection.setText("Texts/SelectionSort.txt", font);

	m_infoQuick.setPosition(sf::Vector2f(m_textQuick.getPosition().x + (m_textQuick.getGlobalBounds().width) + 20, m_tickBoxQ.getPosition().y));
	m_infoQuick.setSize(m_tickBoxQ.getSize());
	m_infoQuick.setCharacterSize(10);
	m_infoQuick.setTextPositionRelativeCursor(InfoWindow::LeftUp);
	m_infoQuick.setText("Texts/QuickSort.txt", font);

	m_infoMerge.setPosition(sf::Vector2f(m_textMerge.getPosition().x + (m_textMerge.getGlobalBounds().width) + 20, m_tickBoxM.getPosition().y));
	m_infoMerge.setSize(m_tickBoxM.getSize());
	m_infoMerge.setCharacterSize(10);
	m_infoMerge.setTextPositionRelativeCursor(InfoWindow::LeftUp);
	m_infoMerge.setText("Texts/MergeSort.txt", font);

	//inputFlield
	m_inputDataSizeBubble.setSize(sf::Vector2f(380, m_tickBoxB.getSize()));
	m_inputDataSizeBubble.setPosition(sf::Vector2f(screen.width - m_inputDataSizeBubble.getSize().x - 50, m_tickBoxB.getPosition().y));
	m_inputDataSizeBubble.setFont(font);

	m_inputDataSizeInsertion.setSize(sf::Vector2f(380, m_tickBoxB.getSize()));
	m_inputDataSizeInsertion.setPosition(sf::Vector2f(screen.width - m_inputDataSizeInsertion.getSize().x - 50, m_tickBoxI.getPosition().y));
	m_inputDataSizeInsertion.setFont(font);

	m_inputDataSizeSelection.setSize(sf::Vector2f(380, m_tickBoxB.getSize()));
	m_inputDataSizeSelection.setPosition(sf::Vector2f(screen.width - m_inputDataSizeSelection.getSize().x - 50, m_tickBoxS.getPosition().y));
	m_inputDataSizeSelection.setFont(font);

	m_inputDataSizeQuick.setSize(sf::Vector2f(380, m_tickBoxB.getSize()));
	m_inputDataSizeQuick.setPosition(sf::Vector2f(screen.width - m_inputDataSizeQuick.getSize().x - 50, m_tickBoxQ.getPosition().y));
	m_inputDataSizeQuick.setFont(font);

	m_inputDataSizeMerge.setSize(sf::Vector2f(380, m_tickBoxB.getSize()));
	m_inputDataSizeMerge.setPosition(sf::Vector2f(screen.width - m_inputDataSizeBubble.getSize().x - 50, m_tickBoxM.getPosition().y));
	m_inputDataSizeMerge.setFont(font);

	m_StartButton.setTextOfButton(font, "Start");
	m_StartButton.setSize(sf::Vector2f(300, 100));
	m_StartButton.setPosition(sf::Vector2f((screen.width / 2) - (m_StartButton.getSize().x / 2), m_tickBoxM.getPosition().y + m_tickBoxM.getSize() + 30));
	m_StartButton.setColorOfText(sf::Color::White);
	m_StartButton.setColorOfButton(sf::Color(0, 0, 0, 128));
}

void Menu::updateMenu(sf::RenderWindow& window, sf::Event event)
{
	if (event.type == event.MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
	{
		m_tickBoxB.setState(sf::Mouse::getPosition(window));
		m_tickBoxI.setState(sf::Mouse::getPosition(window));
		m_tickBoxS.setState(sf::Mouse::getPosition(window));
		m_tickBoxQ.setState(sf::Mouse::getPosition(window));
		m_tickBoxM.setState(sf::Mouse::getPosition(window));
	}

	if (m_tickBoxB.getState())
		m_inputDataSizeBubble.input(sf::Mouse::getPosition(window), event);
	else
		m_inputDataSizeBubble.clear();

	if (m_tickBoxI.getState())
		m_inputDataSizeInsertion.input(sf::Mouse::getPosition(window), event);
	else
		m_inputDataSizeInsertion.clear();

	if (m_tickBoxS.getState())
		m_inputDataSizeSelection.input(sf::Mouse::getPosition(window), event);
	else
		m_inputDataSizeSelection.clear();

	if (m_tickBoxQ.getState())
		m_inputDataSizeQuick.input(sf::Mouse::getPosition(window), event);
	else
		m_inputDataSizeQuick.clear();

	if (m_tickBoxM.getState())
		m_inputDataSizeMerge.input(sf::Mouse::getPosition(window), event);
	else
		m_inputDataSizeMerge.clear();

	m_infoBubble.isMouseInIcon(sf::Mouse::getPosition(window));
	m_infoInsertion.isMouseInIcon(sf::Mouse::getPosition(window));
	m_infoSelection.isMouseInIcon(sf::Mouse::getPosition(window));
	m_infoQuick.isMouseInIcon(sf::Mouse::getPosition(window));
	m_infoMerge.isMouseInIcon(sf::Mouse::getPosition(window));
}

std::vector<int> Menu::getSortings()
{
	std::vector<int> sortings(5, -1);

	if (m_tickBoxB.getState())
	{
		if (m_inputDataSizeBubble.getText() == "")
			sortings[0] = 100;
		else
			sortings[0] = std::stoi(m_inputDataSizeBubble.getText());
	}

	if (m_tickBoxI.getState())
	{
		if (m_inputDataSizeInsertion.getText() == "")
			sortings[1] = 100;
		else
			sortings[1] = std::stoi(m_inputDataSizeInsertion.getText());
	}

	if (m_tickBoxS.getState())
	{
		if (m_inputDataSizeSelection.getText() == "")
			sortings[2] = 100;
		else
			sortings[2] = std::stoi(m_inputDataSizeSelection.getText());
	}

	if (m_tickBoxQ.getState())
	{
		if (m_inputDataSizeQuick.getText() == "")
			sortings[3] = 100;
		else
			sortings[3] = std::stoi(m_inputDataSizeQuick.getText());
	}

	if (m_tickBoxM.getState())
	{
		if (m_inputDataSizeMerge.getText() == "")
			sortings[4] = 100;
		else
			sortings[4] = std::stoi(m_inputDataSizeMerge.getText());
	}

	return sortings;
}

bool Menu::isStarted(sf::RenderWindow& window)
{
	return m_StartButton.isPressed(sf::Mouse::getPosition(window));
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_textMenu);
	target.draw(m_StartButton);

	target.draw(m_tickBoxB);
	target.draw(m_tickBoxI);
	target.draw(m_tickBoxS);
	target.draw(m_tickBoxQ);
	target.draw(m_tickBoxM);

	target.draw(m_textBubble);
	target.draw(m_textInsertion);
	target.draw(m_textSelection);
	target.draw(m_textQuick);
	target.draw(m_textMerge);

	target.draw(m_inputDataSizeBubble);
	target.draw(m_inputDataSizeInsertion);
	target.draw(m_inputDataSizeSelection);
	target.draw(m_inputDataSizeQuick);
	target.draw(m_inputDataSizeMerge);

	target.draw(m_infoBubble);
	target.draw(m_infoInsertion);
	target.draw(m_infoSelection);
	target.draw(m_infoQuick);
	target.draw(m_infoMerge);
}
