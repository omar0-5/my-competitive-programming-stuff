For an n × m grid:
horizontal segments=(n+1)m
vertical segments=(m+1)n
total segments = 2nm + n + m
GRID CHEATSHEET FOR COMPETITIVE PROGRAMMING

1) Basic meaning
n = number of rows
m = number of columns
grid[i][j] => row i, column j

Valid cell:
0 <= i < n
0 <= j < m

If input is 1-indexed:
x--, y--;

--------------------------------------------------

2) Boundary check

bool inside(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

--------------------------------------------------

3) 4 directions: up, down, left, right

int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};

Use for:
- adjacent cells
- Manhattan movement
- BFS / DFS
- shortest path without diagonals

Loop:

for(int d = 0; d < 4; d++){
    int nx = x + dx4[d];
    int ny = y + dy4[d];

    if(inside(nx, ny, n, m)){
        // valid neighbor
    }
}

--------------------------------------------------

4) 8 directions: includes diagonals

int dx8[8] = {-1,-1,-1,0,0,1,1,1};
int dy8[8] = {-1,0,1,-1,1,-1,0,1};

Use for:
- diagonals allowed
- 8-connected components
- king moves

--------------------------------------------------

5) Line checking directions

int dxLine[4] = {0, 1, 1, 1};
int dyLine[4] = {1, 0, 1, -1};

These mean:
right
down
down-right diagonal
down-left diagonal

Use for:
- checking k in a row
- horizontal / vertical / diagonal winning lines

Example:

for(int d = 0; d < 4; d++){
    int cnt = 0;
    int x = i, y = j;

    while(inside(x, y, n, m) && grid[x][y] == color){
        cnt++;
        x += dxLine[d];
        y += dyLine[d];
    }

    if(cnt >= k){
        // found winning line
    }
}

--------------------------------------------------

6) Grid as a graph

Each cell = node
Neighbors = edges

Number of nodes = n * m

If n,m <= 1000:
n * m can be 1,000,000

Usually okay:
O(n * m)

Dangerous:
O(n * m * k) if k is large

Impossible:
O((n * m)^2)

--------------------------------------------------

7) BFS on grid

Use BFS for:
- shortest path
- minimum moves
- distance from source
- spreading problems
- multi-source BFS

queue<pair<int,int>> q;
vector<vector<int>> dist(n, vector<int>(m, -1));

q.push({sx, sy});
dist[sx][sy] = 0;

while(!q.empty()){
    auto [x, y] = q.front();
    q.pop();

    for(int d = 0; d < 4; d++){
        int nx = x + dx4[d];
        int ny = y + dy4[d];

        if(inside(nx, ny, n, m) && dist[nx][ny] == -1){
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

--------------------------------------------------

8) DFS / Flood Fill

Use for:
- connected components
- islands
- reachable cells
- regions

Recursive DFS:

void dfs(int x, int y){
    vis[x][y] = true;

    for(int d = 0; d < 4; d++){
        int nx = x + dx4[d];
        int ny = y + dy4[d];

        if(inside(nx, ny, n, m) && !vis[nx][ny]){
            dfs(nx, ny);
        }
    }
}

Warning:
For large grids like 1000 x 1000, recursive DFS may cause stack overflow.
Use BFS or iterative DFS instead.

--------------------------------------------------

9) 2D prefix sum

Use for:
- fast rectangle sum queries
- subgrid sums

Build:

vector<vector<long long>> pref(n + 1, vector<long long>(m + 1, 0));

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        pref[i + 1][j + 1] = grid[i][j]
                            + pref[i][j + 1]
                            + pref[i + 1][j]
                            - pref[i][j];
    }
}

Sum of rectangle (r1,c1) to (r2,c2), inclusive:

long long sum = pref[r2 + 1][c2 + 1]
              - pref[r1][c2 + 1]
              - pref[r2 + 1][c1]
              + pref[r1][c1];

--------------------------------------------------

10) Manhattan distance

For 4-direction movement:

dist = abs(x1 - x2) + abs(y1 - y2)

--------------------------------------------------

11) Chebyshev distance

For 8-direction movement:

dist = max(abs(x1 - x2), abs(y1 - y2))

--------------------------------------------------

12) Flattening grid cells

Convert (i,j) to one ID:

id = i * m + j;

Convert ID back:

i = id / m;
j = id % m;

Useful for:
- DSU on grid
- graph representation

--------------------------------------------------

13) Lexicographic tie-breaking

Lowest coordinate means:

(r1,c1) is better than (r2,c2) if:
r1 < r2
or
r1 == r2 and c1 < c2

If scanning normally:

for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        // first best is already lexicographically smallest
    }
}

Then only update when value is strictly better, not equal.

--------------------------------------------------

14) Common mistakes

- Mixing rows and columns
- Using n for both rows and columns in n x m grid
- Forgetting x--, y-- for 1-indexed input
- Checking 4 directions when diagonals are allowed
- Using recursive DFS on huge grids
- Forgetting boundary checks
- Using int for large sums
- Doing O(n*m*k) when k can be big
- Confusing grid[x][y] where x is row and y is column

--------------------------------------------------

15) Must-memorize template

int dx4[4] = {-1, 1, 0, 0};
int dy4[4] = {0, 0, -1, 1};

int dx8[8] = {-1,-1,-1,0,0,1,1,1};
int dy8[8] = {-1,0,1,-1,1,-1,0,1};

int dxLine[4] = {0, 1, 1, 1};
int dyLine[4] = {1, 0, 1, -1};

bool inside(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

--------------------------------------------------

Main idea:
Most grid problems are one of these:
1. Scan all cells
2. Check neighbors
3. BFS shortest path
4. DFS connected components
5. Check lines
6. Use prefix sums
7. Use DP on grid
8. Use DSU after flattening cells