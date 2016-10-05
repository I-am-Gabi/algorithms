#include <stdio.h>
#include <vector>
#include <bitset>
#include <queue>
/*
 * CARTOG11
 * Given a city map linked by highways, determine the distance between a pair of most distant cities.   
 * Restrictions adopted: (a) all roads are two-way; (B) all roads have 1km, and therefore 
 * all road connecting the two cities have the same length; (C) all road connects only two cities, 
 * and (d) given any two cities A and B, there is only one way to get the starting B, and vice versa.
 * The president of the SBC decided to ask your help to write a computer program that, given a map by 
 * following the above restrictions, return the answer. Thus, he can generate a template to send along 
 * with the challenge.

 * Input
 * The first line of the input contains an integer N representing the number of cities on the map. 
 * Each of the N-1 input lines contains the following two integers A and B indicating that there 
 * is a road between cities A and B.

 * Output
 * The only line of the output contains an integer indicating the distance between a pair of distant cities.

 * source: http://br.spoj.com/problems/CARTOG11/
 */
using namespace std;
int max_distance = 0;

int bfs(int u, vector<vector<int> > adjacent_list) {
  unsigned long vertices = adjacent_list.size();
  int max_node = 0;

  queue<int> queue;

  vector<int> visited;
  visited.assign(vertices, 0);

  vector<int> distance;
  distance.assign(vertices, -1);

  visited[u] = 1;
  distance[u] = 0;
  queue.push(u);

  while(!queue.empty()) {
    int u = queue.front();
    queue.pop();
    for (int i = 0; i < (int) adjacent_list[u].size(); i++) {
      int v = adjacent_list[u][i];
      if (!visited[v]) {
        visited[v] = 0;
        distance[v] = distance[u] + 1;
        if (distance[v] > max_distance) {
          max_distance = distance[v];
          max_node = v;
        }
        queue.push(v);
      }
    }
  }

  return max_node;
}

int main() {
  int nodes, u, v;

  scanf("%d", &nodes);

  vector<vector<int> > adjacent_list;
  adjacent_list.assign(nodes, vector<int>());

  while (--nodes) {
    scanf("%d %d", &u, &v);
    --u, --v;
    adjacent_list[u].push_back(v);
  }


  int max_node = bfs(0, adjacent_list);
  bfs(max_node, adjacent_list);
  printf("%d\n", max_distance);
  return 0;
}
