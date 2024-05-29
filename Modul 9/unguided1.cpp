// Lutfiana Isnaeni Lathifsh
// 2311102165

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Mendefinisikan struktur untuk menyimpan simpul dan bobot
struct Node {
    string lutfiana_2311102165_name;
    vector<pair<string, int>> lutfiana_2311102165_neighbors;
};

// Fungsi untuk menampilkan matriks kedekatan
void lutfiana_2311102165_printAdjacencyMatrix(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); ++i) {
        for (int j = 0; j < adj.size(); ++j) {
            if (adj[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// Fungsi untuk menghitung jarak terpendek menggunakan algoritma Dijkstra
vector<int> lutfiana_2311102165_dijkstra(const vector<vector<int>>& adj, int start) {
    // Menginisialisasi jarak dan status untuk semua simpul
    vector<int> lutfiana_2311102165_dist(adj.size(), INT_MAX);
    vector<bool> lutfiana_2311102165_visited(adj.size(), false);

    // Menandai simpul awal sebagai jarak 0
    lutfiana_2311102165_dist[start] = 0;

    // Mengulangi sampai semua simpul dikunjungi
    for (int i = 0; i < adj.size(); ++i) {
        // Menemukan simpul yang belum dikunjungi dengan jarak terpendek
        int u = -1;
        for (int j = 0; j < adj.size(); ++j) {
            if (!lutfiana_2311102165_visited[j] && (u == -1 || lutfiana_2311102165_dist[j] < lutfiana_2311102165_dist[u])) {
                u = j;
            }
        }

        // Menandai simpul u sebagai dikunjungi
        if (u == -1) break; // Jika tidak ada simpul yang bisa dijangkau
        lutfiana_2311102165_visited[u] = true;

        // Memperbarui jarak simpul tetangga
        for (int v = 0; v < adj.size(); ++v) {
            if (adj[u][v] != INT_MAX && lutfiana_2311102165_dist[v] > lutfiana_2311102165_dist[u] + adj[u][v]) {
                lutfiana_2311102165_dist[v] = lutfiana_2311102165_dist[u] + adj[u][v];
            }
        }
    }

    return lutfiana_2311102165_dist;
}

int main() {
    // Mendapatkan jumlah simpul dari pengguna
    int lutfiana_2311102165_numNodes;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> lutfiana_2311102165_numNodes;

    // Menginisialisasi vektor simpul
    vector<Node> lutfiana_2311102165_nodes(lutfiana_2311102165_numNodes);

    // Mendapatkan nama simpul dari pengguna
    for (int i = 0; i < lutfiana_2311102165_numNodes; ++i) {
        cout << "Silakan masukan nama simpul " << i + 1 << ": ";
        cin >> lutfiana_2311102165_nodes[i].lutfiana_2311102165_name;
    }

    // Mendapatkan bobot antar simpul dari pengguna
    for (int i = 0; i < lutfiana_2311102165_numNodes; ++i) {
        for (int j = 0; j < lutfiana_2311102165_numNodes; ++j) {
            int lutfiana_2311102165_weight;
            cout << lutfiana_2311102165_nodes[i].lutfiana_2311102165_name << "-->" << lutfiana_2311102165_nodes[j].lutfiana_2311102165_name << ": ";
            cin >> lutfiana_2311102165_weight;
            lutfiana_2311102165_nodes[i].lutfiana_2311102165_neighbors.push_back({lutfiana_2311102165_nodes[j].lutfiana_2311102165_name, lutfiana_2311102165_weight});
        }
    }

    // Membangun matriks kedekatan
    vector<vector<int>> lutfiana_2311102165_adj(lutfiana_2311102165_numNodes, vector<int>(lutfiana_2311102165_numNodes));
    for (int i = 0; i < lutfiana_2311102165_numNodes; ++i) {
        for (int j = 0; j < lutfiana_2311102165_numNodes; ++j) {
            lutfiana_2311102165_adj[i][j] = INT_MAX;
            for (const auto& neighbor : lutfiana_2311102165_nodes[i].lutfiana_2311102165_neighbors) {
                if (neighbor.first == lutfiana_2311102165_nodes[j].lutfiana_2311102165_name) {
                    lutfiana_2311102165_adj[i][j] = neighbor.second;
                    break;
                }
            }
        }
    }

    // Menampilkan matriks kedekatan
    cout << "\nMatriks Kedekatan:\n";
    lutfiana_2311102165_printAdjacencyMatrix(lutfiana_2311102165_adj);

    // Mendapatkan simpul awal dari pengguna
    int lutfiana_2311102165_startNode;
    cout << "\nSilakan masukan simpul awal (1 hingga " << lutfiana_2311102165_numNodes << "): ";
    cin >> lutfiana_2311102165_startNode;

    if (lutfiana_2311102165_startNode < 1 || lutfiana_2311102165_startNode > lutfiana_2311102165_numNodes) {
        cout << "Simpul awal tidak valid!\n";
        return 1;
    }

    // Menghitung jarak terpendek ke semua simpul
    vector<int> lutfiana_2311102165_dist = lutfiana_2311102165_dijkstra(lutfiana_2311102165_adj, lutfiana_2311102165_startNode - 1);

    // Menampilkan jarak terpendek ke semua simpul
    cout << "\nJarak Terpendek dari simpul " << lutfiana_2311102165_nodes[lutfiana_2311102165_startNode - 1].lutfiana_2311102165_name << ":\n";
    for (int i = 0; i < lutfiana_2311102165_dist.size(); ++i) {
        cout << "Ke " << lutfiana_2311102165_nodes[i].lutfiana_2311102165_name << ": ";
        if (lutfiana_2311102165_dist[i] == INT_MAX) {
            cout << "Tidak terjangkau\n";
        } else {
            cout << lutfiana_2311102165_dist[i] << "\n";
        }
    }

    return 0;
}