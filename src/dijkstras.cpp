#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <string>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;


class Tile {
    public:
        char name;
        int cost;
        Tile(char name, int cost) : name(name), cost(cost) {}
};

class Map {
    public:
        int rows, cols;
        vector<vector<char>> grid;
        Map(int rows, int cols) : rows(rows), cols(cols) {
            grid.resize(rows, vector<char>(cols));
        }
};

struct Position {
    int row, col;
    Position(int row, int col) : row(row), col(col) {}
};

struct Node {
    Position pos;
    int distance;
    Node(Position pos, int distance) : pos(pos), distance(distance) {}
    bool operator<(const Node &other) const { return distance > other.distance; }
};

// Define a list of valid movement directions
vector<Position> directions = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

// Checks if a given position is within the bounds of the map
bool isValid(int row, int col, const Map& map) {
    return row >= 0 && row < map.rows && col >= 0 && col < map.cols;
}

void dijkstras(const Map& map, const unordered_map<char, int>& tileCosts, const Position& start, const Position& end) {

    // Initialize distance and previous matrices, and priority queue for Dijkstra's
    vector<vector<int>> distances(map.rows, vector<int>(map.cols, numeric_limits<int>::max()));
    vector<vector<Position>> previous(map.rows, vector<Position>(map.cols, {-1, -1}));
    priority_queue<Node> pq;

    // Set the distance of the starting position to 0 and add it to the priority queue
    distances[start.row][start.col] = 0;
    pq.emplace(start, 0);

    while (!pq.empty()) {

        // Pop the node with the smallest distance from the priority queue
        Node current = pq.top();
        pq.pop();

        // If the current position is the end position, break out of the loop
        if (current.pos.row == end.row && current.pos.col == end.col) break;

        // Loop over each direction and check if it leads to a valid position on the map
        for (size_t i = 0; i < directions.size(); i++) {
            int newRow = current.pos.row + directions[i].row;
            int newCol = current.pos.col + directions[i].col;

            if (isValid(newRow, newCol, map)) {

                // Calculate the new distance and update if it is smaller than the previous distance
                int newDistance = current.distance + tileCosts.at(map.grid[current.pos.row][current.pos.col]);
                if (newDistance < distances[newRow][newCol]) {
                    distances[newRow][newCol] = newDistance;
                    previous[newRow][newCol] = current.pos;
                    pq.emplace(Position(newRow, newCol), newDistance);
                }
            }
        }
    }

    // Print the shortest distance to the end position
    cout << distances[end.row][end.col] << '\n';

    // Build the shortest path by following the previous nodes from the end position to the start position
    vector<Position> path;
    Position pos = end;
    while (pos.row != -1 && pos.col != -1) {
        path.push_back(pos);
        pos = previous[pos.row][pos.col];
    }

    // Print the positions in the shortest path, in reverse order
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i].row << " " << path[i].col << '\n';
    }
}


int main() {

    // Read the number of tile types and their costs
    int numTiles;
    cin >> numTiles;
    unordered_map<char, int> tileCosts;
    for (int i = 0; i < numTiles; i++) {
        char tileName;
        int tileCost;
        cin >> tileName >> tileCost;
        tileCosts[tileName] = tileCost;
    }

    // Read the dimensions and layout of the map
    int rows, cols;
    cin >> rows >> cols;
    Map map(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> map.grid[i][j];
        }
    }

    // Read the starting and ending positions of the runner
    int startRow, startCol, endRow, endCol;
    cin >> startRow >> startCol >> endRow >> endCol;
    Position start(startRow, startCol);
    Position end(endRow, endCol);

    // Call Dijkstra's algorithm with the input data
    dijkstras(map, tileCosts, start, end);

    return 0;
}