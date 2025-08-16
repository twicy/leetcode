#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <limits>
#include <climits>

using namespace std;

struct Edge {
	int from;
	int to;
	int weight;
};

void print_graph(vector<vector<Edge>> &graph) {
	for (int i = 0; i < graph.size(); i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			auto [from, to, weight] = graph[i][j];
			printf("%d -> %d = %d\n", from, to, weight);
		}
	}
}

void print_vec(vector<int> &vec) {
	for (int i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

void construct_path(vector<int> &parents, int start, int end) {
	stack<int> stk;
	stk.push(end);
	int parent = parents[end];
	while (parent != start) {
		if (parent == -1) {
			printf("Error constructing path\n");
			return;
		}
		stk.push(parent);
		parent = parents[parent];
	}
	printf("Constructing Path\n");
	stk.push(parent);
	while (!stk.empty() && stk.size() != 1) {
		printf("%d -> ", stk.top());
		stk.pop();
	}
	printf("%d\n", stk.top());
}

int a_star(vector<vector<Edge>> &graph, int start, int end, function<int(int, int)> h) {
	vector<int> tocome(graph.size(), INT_MAX);
	vector<int> total(graph.size());
	vector<int> parents(graph.size());

	priority_queue<pair<int, int>,
			vector<pair<int, int>>,
			greater<pair<int, int>>> pq;

	tocome[start] = 0;
	total[start] = h(start, end);
	pq.push(make_pair(total[start], start));
	while (!pq.empty()) {
		auto [est, curr] = pq.top();
		pq.pop();
		if (curr == end) {
			construct_path(parents, start, end);
			print_vec(total);
			return est;
		}
		for (auto [from, to, weight] : graph[curr]) {
			int tentative_cost = tocome[from] + weight;
			if (tentative_cost < tocome[to]) {
				tocome[to] = tentative_cost;
				parents[to] = from;
				total[to] = tentative_cost + h(to, end);
				pq.push(make_pair(total[to], to));
			}
		}
	}
	print_vec(total);
	return -1;
}

int h_zero(int start, int end) {
	return 0;
}

int main () {
	int start, end;
	cin >> start >> end;
	int V, E;
	cin >> V >> E;
	vector<vector<Edge>> graph(V);
	for (int i = 0; i < E; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		graph[from].push_back({from, to, weight});
	}
	// print_graph(graph);
	int ret = a_star(graph, start, end, h_zero);
	if (ret < 0) {
		printf("Error constructing graph from %d to %d\n", start, end);
	} else {
		printf("Total cost of travelling from %d to %d is %d\n", start, end, ret);
	}
	return 0;
}
