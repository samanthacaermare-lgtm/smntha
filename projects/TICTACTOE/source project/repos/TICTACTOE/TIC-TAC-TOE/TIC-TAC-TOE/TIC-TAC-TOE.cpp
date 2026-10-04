#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#include <optional>
#include <memory>

enum class GameState {
    Menu,
    Playing,
    GameOver
};

enum class CellState {
    Empty,
    X,
    O
};

enum class Player {
    X,
    O
};

class Button {
public:
    sf::RectangleShape shape;
    std::unique_ptr<sf::Text> text;
    sf::Color normalColor;
    sf::Color hoverColor;

    Button(float x, float y, float width, float height, const std::string& label, const sf::Font& font) {
        shape.setPosition(x, y);
        shape.setSize(sf::Vector2f(width, height));
        normalColor = sf::Color(80, 80, 120);
        hoverColor = sf::Color(120, 120, 180);
        shape.setFillColor(normalColor);
        shape.setOutlineThickness(4);
        shape.setOutlineColor(sf::Color(40, 40, 60));

        text = std::make_unique<sf::Text>();
        text->setFont(font);
        text->setString(label);
        text->setCharacterSize(24);
        text->setFillColor(sf::Color::White);

        sf::FloatRect textBounds = text->getLocalBounds();
        text->setOrigin(textBounds.left + textBounds.width / 2.0f,
            textBounds.top + textBounds.height / 2.0f);
        text->setPosition(x + width / 2.0f, y + height / 2.0f);
    }

    bool isHovered(sf::Vector2i mousePos) const {
        return shape.getGlobalBounds().contains(static_cast<float>(mousePos.x),
            static_cast<float>(mousePos.y));
    }

    void update(sf::Vector2i mousePos) {
        if (isHovered(mousePos)) {
            shape.setFillColor(hoverColor);
        }
        else {
            shape.setFillColor(normalColor);
        }
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
        window.draw(*text);
    }
};

class TicTacToe {
private:
    std::array<CellState, 9> board;
    Player currentPlayer;
    std::optional<Player> winner;
    bool isDraw;

public:
    TicTacToe() {
        reset();
    }

    void reset() {
        board.fill(CellState::Empty);
        currentPlayer = Player::X;
        winner = std::nullopt;
        isDraw = false;
    }

    bool makeMove(int cell) {
        if (cell < 0 || cell >= 9 || board[cell] != CellState::Empty || winner.has_value() || isDraw) {
            return false;
        }

        board[cell] = (currentPlayer == Player::X) ? CellState::X : CellState::O;

        if (checkWin()) {
            winner = currentPlayer;
        }
        else if (checkDraw()) {
            isDraw = true;
        }
        else {
            currentPlayer = (currentPlayer == Player::X) ? Player::O : Player::X;
        }

        return true;
    }

    bool checkWin() const {
        const int winPatterns[8][3] = {
            {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
            {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
            {0, 4, 8}, {2, 4, 6}
        };

        CellState current = (currentPlayer == Player::X) ? CellState::X : CellState::O;

        for (const auto& pattern : winPatterns) {
            if (board[pattern[0]] == current &&
                board[pattern[1]] == current &&
                board[pattern[2]] == current) {
                return true;
            }
        }
        return false;
    }

    bool checkDraw() const {
        for (const auto& cell : board) {
            if (cell == CellState::Empty) {
                return false;
            }
        }
        return true;
    }

    CellState getCell(int index) const { return board[index]; }
    Player getCurrentPlayer() const { return currentPlayer; }
    std::optional<Player> getWinner() const { return winner; }
    bool getIsDraw() const { return isDraw; }
    bool isGameOver() const { return winner.has_value() || isDraw; }
};

void drawPixelX(sf::RenderWindow& window, float x, float y, float size, sf::Color color) {
    float thickness = size / 5.0f;

    sf::RectangleShape line1(sf::Vector2f(size * 1.2f, thickness));
    line1.setOrigin(size * 0.6f, thickness / 2.0f);
    line1.setPosition(x + size / 2.0f, y + size / 2.0f);
    line1.setRotation(45.0f);
    line1.setFillColor(color);

    sf::RectangleShape line2(sf::Vector2f(size * 1.2f, thickness));
    line2.setOrigin(size * 0.6f, thickness / 2.0f);
    line2.setPosition(x + size / 2.0f, y + size / 2.0f);
    line2.setRotation(-45.0f);
    line2.setFillColor(color);

    window.draw(line1);
    window.draw(line2);
}

void drawPixelO(sf::RenderWindow& window, float x, float y, float size, sf::Color color) {
    float radius = size / 2.0f - 10.0f;
    float thickness = size / 10.0f;

    sf::CircleShape outer(radius);
    outer.setPosition(x + 10.0f, y + 10.0f);
    outer.setFillColor(sf::Color::Transparent);
    outer.setOutlineThickness(thickness);
    outer.setOutlineColor(color);

    window.draw(outer);
}

int main() {
    const unsigned int WINDOW_WIDTH = 600;
    const unsigned int WINDOW_HEIGHT = 700;
    const float BOARD_OFFSET_Y = 100.0f;
    const float CELL_SIZE = 180.0f;
    const float BOARD_PADDING = 30.0f;

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Pixel TicTacToe", sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("pixel_font.ttf")) {
        return 1;
    }

    GameState gameState = GameState::Menu;
    TicTacToe game;

    Button startButton(200, 300, 200, 60, "START", font);
    Button exitButton(200, 400, 200, 60, "EXIT", font);
    Button playAgainButton(150, 620, 140, 50, "PLAY AGAIN", font);
    Button menuButton(310, 620, 140, 50, "MENU", font);

    sf::Text titleText;
    titleText.setFont(font);
    titleText.setString("TIC TAC TOE");
    titleText.setCharacterSize(48);
    titleText.setFillColor(sf::Color(200, 200, 255));
    titleText.setStyle(sf::Text::Bold);
    sf::FloatRect titleBounds = titleText.getLocalBounds();
    titleText.setOrigin(titleBounds.left + titleBounds.width / 2.0f,
        titleBounds.top + titleBounds.height / 2.0f);
    titleText.setPosition(WINDOW_WIDTH / 2.0f, 150.0f);

    sf::Text turnText;
    turnText.setFont(font);
    turnText.setCharacterSize(28);
    turnText.setFillColor(sf::Color::White);

    sf::Text resultText;
    resultText.setFont(font);
    resultText.setCharacterSize(32);
    resultText.setFillColor(sf::Color(255, 220, 100));

    sf::Color bgColor(30, 30, 50);
    sf::Color gridColor(100, 100, 150);
    sf::Color xColor(255, 100, 100);
    sf::Color oColor(100, 200, 255);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    if (gameState == GameState::Menu) {
                        if (startButton.isHovered(mousePos)) {
                            gameState = GameState::Playing;
                            game.reset();
                        }
                        else if (exitButton.isHovered(mousePos)) {
                            window.close();
                        }
                    }
                    else if (gameState == GameState::Playing || gameState == GameState::GameOver) {
                        if (!game.isGameOver()) {
                            float boardStartX = BOARD_PADDING;
                            float boardStartY = BOARD_OFFSET_Y;

                            for (int row = 0; row < 3; ++row) {
                                for (int col = 0; col < 3; ++col) {
                                    float cellX = boardStartX + col * CELL_SIZE;
                                    float cellY = boardStartY + row * CELL_SIZE;

                                    sf::FloatRect cellBounds(sf::Vector2f(cellX, cellY), sf::Vector2f(CELL_SIZE, CELL_SIZE));
                                    if (cellBounds.contains(static_cast<float>(mousePos.x),
                                        static_cast<float>(mousePos.y))) {
                                        game.makeMove(row * 3 + col);
                                    }
                                }
                            }
                        }

                        if (game.isGameOver()) {
                            gameState = GameState::GameOver;

                            if (playAgainButton.isHovered(mousePos)) {
                                game.reset();
                                gameState = GameState::Playing;
                            }
                            else if (menuButton.isHovered(mousePos)) {
                                game.reset();
                                gameState = GameState::Menu;
                            }
                        }
                    }
                }
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        startButton.update(mousePos);
        exitButton.update(mousePos);
        playAgainButton.update(mousePos);
        menuButton.update(mousePos);

        window.clear(bgColor);

        if (gameState == GameState::Menu) {
            window.draw(titleText);
            startButton.draw(window);
            exitButton.draw(window);
        }
        else {
            float boardStartX = BOARD_PADDING;
            float boardStartY = BOARD_OFFSET_Y;

            for (int i = 1; i < 3; ++i) {
                sf::RectangleShape vLine(sf::Vector2f(6, CELL_SIZE * 3));
                vLine.setPosition(boardStartX + i * CELL_SIZE - 3, boardStartY);
                vLine.setFillColor(gridColor);
                window.draw(vLine);

                sf::RectangleShape hLine(sf::Vector2f(CELL_SIZE * 3, 6));
                hLine.setPosition(boardStartX, boardStartY + i * CELL_SIZE - 3);
                hLine.setFillColor(gridColor);
                window.draw(hLine);
            }

            for (int row = 0; row < 3; ++row) {
                for (int col = 0; col < 3; ++col) {
                    float cellX = boardStartX + col * CELL_SIZE + 20;
                    float cellY = boardStartY + row * CELL_SIZE + 20;
                    float symbolSize = CELL_SIZE - 40;

                    CellState cell = game.getCell(row * 3 + col);
                    if (cell == CellState::X) {
                        drawPixelX(window, cellX, cellY, symbolSize, xColor);
                    }
                    else if (cell == CellState::O) {
                        drawPixelO(window, cellX, cellY, symbolSize, oColor);
                    }
                }
            }

            if (!game.isGameOver()) {
                std::string turnStr = (game.getCurrentPlayer() == Player::X) ? "Player X's Turn" : "Player O's Turn";
                turnText.setString(turnStr);
                turnText.setFillColor((game.getCurrentPlayer() == Player::X) ? xColor : oColor);
                sf::FloatRect turnBounds = turnText.getLocalBounds();
                turnText.setOrigin(turnBounds.left + turnBounds.width / 2.0f,
                    turnBounds.top + turnBounds.height / 2.0f);
                turnText.setPosition(WINDOW_WIDTH / 2.0f, 50.0f);
                window.draw(turnText);
            }
            else {
                if (game.getWinner().has_value()) {
                    std::string winStr = (game.getWinner().value() == Player::X) ? "Player X Wins!" : "Player O Wins!";
                    resultText.setString(winStr);
                    resultText.setFillColor((game.getWinner().value() == Player::X) ? xColor : oColor);
                }
                else {
                    resultText.setString("It's a Draw!");
                    resultText.setFillColor(sf::Color(200, 200, 200));
                }
                sf::FloatRect resultBounds = resultText.getLocalBounds();
                resultText.setOrigin(resultBounds.left + resultBounds.width / 2.0f,
                    resultBounds.top + resultBounds.height / 2.0f);
                resultText.setPosition(WINDOW_WIDTH / 2.0f, 50.0f);
                window.draw(resultText);

                playAgainButton.draw(window);
                menuButton.draw(window);
            }
        }

        window.display();
    }

    return 0;
}