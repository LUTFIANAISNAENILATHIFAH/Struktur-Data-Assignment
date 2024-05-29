# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Arvinanto Bahtiar</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. [Program Graph]

```C++
#include <iostream>
#include <iomanip>
using namespace std;
string simpul[7] = {
    "Ciamis",
    "Bandung",
    "Bekasi",
    "tasikmalaya",
    "Cianjur",
    "Purwokerto",
    "Yogyakarta"};
int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}};
void tampilGraph()
{
    for (int baris = 0; baris < 7; baris++)
    {
        cout << " " << setiosflags(ios::left) << setw(15)
             << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++)
        {
            if (busur[baris][kolom] != 0)
            {
                cout << " " << simpul[kolom] << "(" << busur[baris][kolom]
                     << ")";
            }
        }
        cout << endl;
    }
}
int main()
{
    tampilGraph();
    return 0;
}
```

Kode di atas menghasilkan representasi graf berbobot, yang menggambarkan hubungan antara berbagai simpul (kota) dalam sebuah graf dengan bobot jarak di 
antara kota-kota tersebut. Dalam implementasi ini, setiap simpul direpresentasikan oleh sebuah nama kota, dan setiap busur (edge) antara simpul-simpul memiliki bobot 
yang menunjukkan jarak atau biaya untuk mencapai simpul tujuan. Fungsi tampilGraph bertanggung jawab untuk menampilkan graf secara terstruktur. 
Melalui perulangan, fungsi ini mencetak setiap simpul beserta daftar simpul-simpul yang terhubung dengannya dan bobot jaraknya. Penggunaan 
setiosflags(ios::left) dan setw(15) membantu menyusun tampilan agar lebih rapi dan terstruktur. Dalam contoh ini, keluaran dari program akan menampilkan setiap kota, diikuti oleh
daftar kota-kota terhubung yang terdapat dalam graf beserta bobot jarak antara kota-kota tersebut. Misalnya, kota "Ciamis" terhubung dengan "Bandung" dengan 
bobot 7 dan "Bekasi" dengan bobot 8. Ini memberikan gambaran visual yang jelas tentang hubungan antara kota-kota dalam graf tersebut.


### 2. [Program tree]

```C++
#include <iostream>
using namespace std;
// PROGRAM BINARY TREE
// Deklarasi Pohon
struct Pohon
{
    char data;
    Pohon *left, *right, *parent; // pointer
};
// pointer global
Pohon *root;
// Inisialisasi
void init()
{
    root = NULL;
}
bool isEmpty()
{
    return root == NULL;
}
Pohon *newPohon(char data)
{
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}
void buatNode(char data)
{
    if (isEmpty())
    {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    }
    else
    {
        cout << "\nPohon sudah dibuat" << endl;
    }
}
Pohon *insertLeft(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->left != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kiri!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child "
                "kiri << node->data << endl";
                return baru;
        }
    }
}
Pohon *insertRight(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    }
    else
    {
        if (node->right != NULL)
        {
            cout << "\nNode " << node->data << " sudah ada child kanan!"
                 << endl;
            return NULL;
        }
        else
        {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child'"
                "kanan " << node->data << endl;
                return baru;
        }
    }
}
void update(char data, Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        else
        {
            char temp = node->data;
            node->data = data;
            cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}
void retrieve(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData node : " << node->data << endl;
        }
    }
}
void find(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    }
    else
    {
        if (!node)
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        else
        {
            cout << "\nData Node : " << node->data << endl;
            cout << "Root : " << root->data << endl;
            if (!node->parent)
                cout << "Parent : (tidak punya parent)" << endl;
            else
                cout << "Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << "Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling : " << node->parent->right->data << endl;
            else
                cout << "Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << "Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan : " << node->right->data << endl;
        }
    }
}
// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            cout << " " << node->data << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}
// inOrder
void inOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            inOrder(node->left);
            cout << " " << node->data << ", ";
            inOrder(node->right);
        }
    }
}
// postOrder
void postOrder(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data << ", ";
        }
    }
}
// Hapus Node Tree
void deleteTree(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        if (node != NULL)
        {
            if (node != root)
            {
                if (node->parent->left == node)
                    node->parent->left = NULL;
                else if (node->parent->right == node)
                    node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root)
            {
                delete root;
                root = NULL;
            }
            else
            {
                delete node;
            }
        }
    }
}
// Hapus SubTree
void deleteSub(Pohon *node)
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!" << endl;
    else
    {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data << " berhasil dihapus."
             << endl;
    }
}
// Hapus Tree
void clear()
{
    if (isEmpty())
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    else
    {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}
// Cek Size Tree
int size(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            return 1 + size(node->left) + size(node->right);
        }
    }
}
// Cek Height Level Tree
int height(Pohon *node)
{
    if (isEmpty())
    {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    }
    else
    {
        if (!node)
        {
            return 0;
        }
        else
        {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan)
            {
                return heightKiri + 1;
            }
            else
            {
                return heightKanan + 1;
            }
        }
    }
}
// Karakteristik Tree
void characteristic()
{
    int s = size(root);
    int h = height(root);
    cout << "\nSize Tree : " << s << endl;
    cout << "Height Tree : " << h << endl;
    if (h != 0)
        cout << "Average Node of Tree : " << s / h << endl;
    else
        cout << "Average Node of Tree : 0" << endl;
}
int main()
{
    init();
    buatNode('A');
    Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI,
        *nodeJ;
    nodeB = insertLeft('B', root);
    nodeC = insertRight('C', root);
    nodeD = insertLeft('D', nodeB);
    nodeE = insertRight('E', nodeB);
    nodeF = insertLeft('F', nodeC);
    nodeG = insertLeft('G', nodeE);
    nodeH = insertRight('H', nodeE);
    nodeI = insertLeft('I', nodeG);
    nodeJ = insertRight('J', nodeG);
    update('Z', nodeC);
    update('C', nodeC);
    retrieve(nodeC);
    find(nodeC);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    cout << "InOrder :" << endl;
    inOrder(root);
    cout << "\n"
         << endl;
    cout << "PostOrder :" << endl;
    postOrder(root);
    cout << "\n"
         << endl;
    characteristic();
    deleteSub(nodeE);
    cout << "\nPreOrder :" << endl;
    preOrder(root);
    cout << "\n"
         << endl;
    characteristic();
}
```

Kode di atas digunakan untuk mengelola binary tree, sebuah struktur data pohon biner di mana setiap node memiliki paling banyak 
dua anak (left dan right). Program ini memungkinkan pengguna untuk membuat, menghapus, memperbarui, dan menelusuri (traversal) pohon biner. Selain itu, 
program ini juga menyediakan fungsi tambahan seperti pengecekan apakah pohon biner kosong, pencarian dan penampilan informasi tentang suatu node, serta 
penghapusan seluruh pohon. Dengan menggunakan program ini, pengguna dapat dengan mudah membuat, mengelola, dan menelusuri pohon biner sesuai kebutuhan 
aplikasi mereka, seperti dalam implementasi struktur data, pemrosesan bahasa alami, atau masalah optimasi kombinatorial.

## Unguided 

### 1. [Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.]

```C++
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
```

#### Output:
![240302_00h00m06s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%209/SS/ss%20output%20unguided%201.png)

Kode di atas digunakan untuk menghitung jarak terpendek antara simpul-simpul dalam sebuah graf berbobot menggunakan algoritma Dijkstra. Pengguna 
memasukkan jumlah simpul, nama-nama simpul, serta bobot antar simpul, yang digunakan untuk membangun matriks kedekatan graf. Setelah itu, pengguna memilih 
simpul awal, dan program menghitung serta menampilkan jarak terpendek dari simpul awal ke setiap simpul lainnya. Program ini berguna untuk aplikasi seperti 
navigasi, routing jaringan, dan optimasi logistik, membantu menemukan rute optimal dalam berbagai konteks.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/LUTFIANAISNAENILATHIFAH/Struktur-Data-Assignment/blob/main/Modul%209/SS/ss%20full%20koding%20unguided%201.png)


### 2. [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan! ]

C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}

#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)



## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002
