# Catan Game README

## Introduction
This project is a digital implementation of the popular board game "Catan." The game involves resource management, trading, building, and strategy. Players compete to be the first to reach 10 points through various actions such as building roads, settlements, cities, and using development cards.

## Game Rules

### Game Board
- The game board is constructed from 19 hexagons.
- Each hexagon has a type ("wood," "brick," "sheep," "stone," "wheat") and a number between 2 and 12.

### Development Cards
Players can purchase "Development Cards" which cost:
- 1 "sheep"
- 1 "stone"
- 1 "wheat"

Types of Development Cards:
1. **Monopoly** – The player chooses a resource, and all other players must give him this resource.
2. **Build 2 Roads** – The player can build 2 roads without paying.
3. **Year of Plenty** – The player chooses 2 resources to get from the bank.
4. **Knight** – A player who has 3 "Knight" cards gets 2 points for having the "largest army."
5. **Victory Point** – The player gets 1 point.

### Building
Players can build roads, settlements, and cities.
- **Road**: Costs 1 "wood" and 1 "brick." It must be connected to one of the player's settlements, cities, or roads.
- **Settlement**: Costs 1 "wood," 1 "brick," 1 "sheep," and 1 "wheat." It must be connected to one of the player's roads and separated by at least 2 roads from any other settlement. A settlement gives the player 1 point.
- **City**: Costs 3 "stone" and 2 "wheat." Upgrading a settlement to a city results in losing 1 point from the settlement and gaining 2 points from the city.

### Resources
- When a player rolls the dice, all players receive resources based on the dice result. For example, if a 6 is rolled, all players with settlements or cities adjacent to a hexagon numbered 6 receive the resource of that hexagon.

## Playing the Game

### Setup
- Each player starts the game by placing 2 settlements and 2 connected roads. Players receive resources from the second settlement they place.
- The order of players is chosen randomly at the beginning of the game.

### Turn Sequence
1. **Roll Dice**: The player rolls the dice, and all players receive resources based on the result.
2. **Actions**: The current player can:
   - Build a road, settlement, or city.
   - Trade with other players or the bank (4 cards of the same resource type can be traded for 1 card of a chosen type).
   - Buy or use a "Development Card."
3. **Robber**: If the dice result is 7, each player with more than 7 cards must discard half of them.
4. **End Turn**: The player ends their turn, and play moves to the next player.

### Winning the Game
- The game ends when a player reaches at least 10 points.

## Classes Hierarchy

### Board
- Represents the game board with vertices and edges.

### Place
- Represents the vertices on the board.

### Card
- Represents all types of "Development Cards."

### Player
- Represents the players in the game.

### Catan
- Represents the game itself.

### Demo
- Shows a simulation of one game from start to end.

### Game
- Runs the game.

### Test
- Tests the game functions.

## Important Functions

### Catan Class
- **firstTurn(Player\* player)**: Handles the first turn of the player, asking them to place the first settlements and roads in the right order.
- **updateResources(int dice)**: Updates resources for all players based on the dice result.
- **buyDevelopmentCard(Player\* player)**: Checks if the player has enough resources to buy a development card and processes the purchase.
- **useDevelopmentCard(Player\* player)**: Asks the player which card to use and checks if the player has it. If so, uses the card.
- **endTurn()**: Moves the turn to the next player and returns a pointer to that player.

### Player Class
- **placeRoad(unsigned int from, unsigned int to, Board\* board)**: Checks if the position of the road is valid and, if so, builds it on the board.
- **placeSettlement(unsigned int place, Board\* board)**: Checks if the position of the settlement is valid and, if so, builds it on the board.
- **placeCity(unsigned int place, Board\* board)**: Checks if the position of the city is valid and, if so, builds it on the board.
- **trade(Player\* otherPlayer, string give, string get, int giveNum, int getNum)**: Checks if the trade is valid and, if so, makes the trade.
- **tradeBank(string give, string get)**: Checks if the player has at least 4 cards of the "give" type and, if so, makes the trade.

## Conclusion
This digital version of Catan offers a comprehensive and immersive experience of the classic board game. With detailed class structures and functions, players can enjoy a seamless and strategic gameplay experience.
